.model small
.stack 1000h

.data
; sizeof buffer
rdsz    db  255
; read strlen
strlen  db        ?
; buffer area
rdstr   db 255 dup(0)

crlf    db  0dh, 0ah, "$"
equal   db " = ", "$"
times   db " * ", "$"
einvch  db        "error: invalid charactor", "$"
enumlg  db        "error: number is too large", "$"
enumsm  db        "error: number is too small", "$"

wrtbuf  db        100 dup(0)
hexstr  db        "0123456789ABCDEF"
prompt  db        "Input the starting number: ", "$"

.code

print   macro      msg
        mov     ah, 09h
        mov     dx, offset msg
        int     21h
        endm

println macro    msg
        print   msg
        print   crlf
        endm

exit    macro       code
        mov     ah, 4ch
        mov     al, code
        int     21h
        endm

panic   macro      errmsg, code
        println errmsg
        exit    code
        endm

gets    proc
        ; DOS function: gets()
        mov     ah, 0ah
        mov     dx, offset rdsz
        int     21h
        ; wrap
        print   crlf
        ret
gets    endp

; dword ptr [bx] *= ax
u32mul  proc
        push    bp
        mov     bp, sp
        sub     sp, 10

        ; save multipler
        mov     [bp-2], ax

        ; println       times

        ; lower 16 bits
        mov     ax, ss:[bx]
        mul     word ptr [bp-2]
        ; result in (dx ax)
        mov     [bp-4], dx
        mov     [bp-6], ax

        ; higher 16 bits
        mov     ax, ss:[bx+2]
        mul     word ptr [bp-2]
        jc      u32muloverflow
        ; result in (dx ax)
        mov     [bp-8], dx
        mov     [bp-10], ax

        ; [bx+2] = [bp-4] + [bp-10]
        mov     ax, [bp-4]
        add     ax, [bp-10]
        ; panics if result overflows
        jc      u32muloverflow
        mov     ss:[bx+2], ax

        ; [bx] = [bp-6]
        mov     ax, [bp-6]
        mov     ss:[bx], ax

        mov     sp, bp
        pop     bp
        ret
u32muloverflow:
        panic   enumlg, 1
u32mul  endp

; dword ptr [bx] /= ax
; remainders in dx
u32div  proc
        push    bp
        mov     bp, sp
        sub     sp, 2

        ; save ax
        mov     [bp-2], ax

        ; calculate (0 [bx+2]) / ax
        mov     dx, 0
        mov     ax, ss:[bx+2]
        div     word ptr [bp-2]
        ; ax = (0 [bx+2]) / [bp-2]
        ; dx = (0 [bx+2]) % [bp-2]
        mov     ss:[bx+2], ax

        ; calculate (dx [bx]) / ax
        mov     ax, ss:[bx]
        div     word ptr [bp-2]
        ; ax = (dx [bx]) / [bp-2]
        ; dx = (dx [bx]) % [bp-2]
        mov     ss:[bx], ax
        ; lets keep dx as remainder

        mov     sp, bp
        pop     bp
        ret
u32div  endp

; parse u32 from rdstr buffer
; result in [bx]
r32dec  proc
        push    bp
        mov     bp, sp
        push    si
        push    cx

        ; dword x = 0
        mov     word ptr ss:[bx+2], 0
        mov     word ptr ss:[bx], 0

        mov     si, 0        ; si = position read
        mov     cx, 0        ; cx = loop times
        mov     cl, strlen
        jcxz    rdscanend   ; move to rdscanend if empty
rdscan:
        ; x = x * 0ah
        mov     ax, 0ah
        call    u32mul

        mov     ax, 0
        mov     al, rdstr[si]
        ; if al < '0' goto rdeinvch
        cmp     al, 30h
        jb      rdeinvch
        ; if al > '9' goto rdeinvch
        cmp     al, 39h
        ja      rdeinvch
        ; al -= 30h
        xor     al, 30h

        ; x = x + ax
        add     word ptr ss:[bx], ax
        adc     word ptr ss:[bx+2], 0
        jc      rdeovfl

        inc     si
        loop    rdscan
rdscanend:
        ; recover environments
        pop     cx
        pop     si
        mov     sp, bp
        pop     bp
        ret
rdeinvch:
        panic   einvch, 1
rdeovfl:
        panic   enumlg, 1
r32dec  endp

r32hex  proc
        push    bp
        mov     bp, sp

        mov     word ptr ss:[bx+2], 0
        mov     word ptr ss:[bx], 0

        ; check if is starting from 0x
        cmp     rdstr[0], '0'
        jne     r32hexisnothex
        cmp     rdstr[1], 'x'
        jne     r32hexisnothex

r32hexishex:
        mov     si, 2        ; si = position
        mov     cx, 0        ; cx = loop times
        mov     cl, strlen
        sub     cl, 2
        jcxz    r32hexreturn
r32hexishexloop:
        mov     al, rdstr[si]

        ; check if al is a valid hex
        cmp     al, '0'
        jb      r32hexishexisnotdigit
        cmp     al, '9'
        ja      r32hexishexisnotdigit
        xor     al, 30h
        jmp     r32hexishexcontinue
r32hexishexisnotdigit:
        cmp     al, 'a'
        jb      r32hexishexisnotlower
        cmp     al, 'f'
        ja      r32hexishexisnotlower
        sub     al, 57h
        jmp     r32hexishexcontinue
r32hexishexisnotlower:
        cmp     al, 'A'
        jb      r32hexishexisnotupper
        cmp     al, 'F'
        ja      r32hexishexisnotupper
        sub     al, 37h
        jmp     r32hexishexcontinue
r32hexishexisnotupper:
        panic   einvch, 1
r32hexishexcontinue:
        ; left shift [bx] 4 times
        shl     word ptr ss:[bx], 1
        rcl     word ptr ss:[bx+2], 1
        shl     word ptr ss:[bx], 1
        rcl     word ptr ss:[bx+2], 1
        shl     word ptr ss:[bx], 1
        rcl     word ptr ss:[bx+2], 1
        shl     word ptr ss:[bx], 1
        rcl     word ptr ss:[bx+2], 1
        ; [bx] += ax
        or      byte ptr ss:[bx], al
        inc     si
        loop    r32hexishexloop

        jmp     r32hexreturn
r32hexisnothex:
        ; just invoke r32dec
        call    r32dec

r32hexreturn:
        mov     sp, bp
        pop     bp
        ret
r32hex  endp

w32hex  proc
        push    di
        push    si
        push    ax
        push    cx
        push    dx

        mov     wrtbuf[0], '0'
        mov     wrtbuf[1], 'x'
        mov     di, 2
        mov     dl, 0        ; dl = 0: should skip if zero

        ; first byte
        mov     ax, ss:[bx+2]
        mov     cx, 4
w32hexloop1:
        rol     ax, 1
        rol     ax, 1
        rol     ax, 1
        rol     ax, 1
        mov     si, ax
        and     si, 0fh
        ; dx = dx | si
        or      dx, si
        ; if !dl
        test    dl, dl
        ; then skip output
        jz      w32hexloop1continue
        mov     dh, hexstr[si]
        mov     wrtbuf[di], dh
        inc     di
w32hexloop1continue:
        loop    w32hexloop1

        ; second byte
        mov     ax, ss:[bx]
        mov     cx, 4
w32hexloop2:
        rol     ax, 1
        rol     ax, 1
        rol     ax, 1
        rol     ax, 1
        mov     si, ax
        and     si, 0fh
        ; dx = dx | si
        or      dx, si
        ; if !dl
        test    dl, dl
        ; then skip output
        jz      w32hexloop2continue
        mov     dh, hexstr[si]
        mov     wrtbuf[di], dh
        inc     di
w32hexloop2continue:
        loop    w32hexloop2

        ; add a single zero if di = 2
        cmp     di, 2
        ja      w32hexskipaddzero
        mov     wrtbuf[di], 30h
        inc     di

w32hexskipaddzero:
        ; add trailing $
        mov     wrtbuf[di], 24h
        ; print it
        print   wrtbuf

        pop     dx
        pop     cx
        pop     ax
        pop     si
        pop     di
        ret
w32hex  endp

w16hex  proc
        push    bp
        mov     bp, sp
        sub     sp, 4
        mov     word ptr [bp-2], 0
        mov     word ptr [bp-4], ax
        lea     bx, [bp-4]
        call    w32hex
        mov     sp, bp
        pop     bp
        ret
w16hex  endp

factor  proc
        push    cx
        push    bp
        mov     bp, sp
        sub     sp, 10

        ; dword x = [bx]
        mov     ax, ss:[bx+2]
        mov     [bp-2], ax
        mov     ax, ss:[bx]
        mov     [bp-4], ax

        ; word p = 2
        mov     word ptr [bp-6], 2

        ; print(x)
        lea     bx, [bp-4]
        call    w32hex 

        mov     cx, 0
factorloop:
        ; while (x > 1)
        cmp     word ptr [bp-2], 0
        ja      factorloopbody
        cmp     word ptr [bp-4], 1
        ja      factorloopbody
        jmp     factorloopbreak
factorloopbody:
        ; dx = x % p
        mov     ax, [bp-2]
        mov     [bp-8], ax
        mov     ax, [bp-4]
        mov     [bp-10], ax

        lea     bx, [bp-10]
        mov     ax, [bp-6]
        call    u32div

        ; if (dx != 0) continue
        test    dx, dx
        jnz     factorloopcontinue

        ; x = x / p
        mov     ax, [bp-8]
        mov     [bp-2], ax
        mov     ax, [bp-10]
        mov     [bp-4], ax

        ; if (!cx) print(' = '), ++ cx
        ; else print(' * ')
        jcxz    factorloopcxzthen
        print   times
        jmp     factorloopcxzend
factorloopcxzthen:
        print   equal
        inc     cx
factorloopcxzend:

        ; print(p)
        mov     ax, [bp-6]
        call    w16hex

        jmp     factorloopbody
factorloopcontinue:
        ; p += 1
        inc     word ptr [bp-6]
        ; if p > 0 goback
        jnz     factorloop
        ; otherwise p is overflow, we can break
factorloopbreak:
        ; if x still > 1 then x is a prime
        cmp     word ptr [bp-2], 0
        ja      factorendprime
        cmp     word ptr [bp-4], 1
        ja      factorendprime
        jmp     factorend
factorendprime:

        jcxz    factorcxzthen
        print   times
        jmp     factorcxzend
factorcxzthen:
        print   equal
        inc     cx
factorcxzend:

        ; print(x) as is the final prime
        lea     bx, [bp-4]
        call    w32hex 
factorend:
        print   crlf
        mov     sp, bp
        pop     bp
        pop     cx
        ret
factor  endp

_start  proc
        ; prepare ds & es
        mov     ax, @data
        mov     ds, ax
        mov     es, ax

        mov     bp, sp
        sub     sp, 4

        print   prompt
        call    gets

        lea     bx, [bp-4]
        call    r32hex

        ; if x < 2 panic
        cmp     word ptr [bp-2], 0
        ja      continue
        cmp     word ptr [bp-4], 1
        ja      continue

        panic   enumsm, 1

continue:
        mov     cx, 8

plus1loop:
        push    cx
        lea     bx, [bp-4]
        call    factor

        pop     cx
        add     word ptr [bp-4], 1
        adc     word ptr [bp-2], 0
        loop    plus1loop

        ; end program
        exit    0
_start  endp

end     _start
