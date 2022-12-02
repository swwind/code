.model small
.stack 1000h

.data
; sizeof buffer
rdsz  db  255
; read strlen
strlen  db  ?
; buffer area
rdstr  db  255 dup(0)

crlf  db  0dh, 0ah, "$"
equal  db  " = ", "$"
times  db  " x ", "$"
einvch  db  "error: invalid charactor", "$"
enumlg  db  "error: number is too large", "$"
enumsm  db  "error: number is too small", "$"

wrtbuf  db  100 dup(0)
hexstr  db  "0123456789abcdef"

.code

print  macro  msg
  mov  ah, 09h
  mov  dx, offset msg
  int  21h
  endm

println  macro  msg
  print  msg
  print  crlf
  endm

exit  macro  code
  mov  ah, 4ch
  mov  al, code
  int  21h
  endm

panic  macro  errmsg, code
  println  errmsg
  exit  code
  endm

gets  proc
  ; DOS function: gets()
  mov  ah, 0ah
  mov  dx, offset rdsz
  int  21h
  ; wrap
  print  crlf
  ret
gets  endp

; dword ptr [bx] *= ax
u32mul  proc
  push  bp
  mov  bp, sp
  sub  sp, 10

  ; save multipler
  mov  [bp-2], ax

  ; println  times

  ; lower 16 bits
  mov  ax, ss:[bx]
  mul  word ptr [bp-2]
  ; result in (dx ax)
  mov  [bp-4], dx
  mov  [bp-6], ax

  ; higher 16 bits
  mov  ax, ss:[bx+2]
  mul  word ptr [bp-2]
  jc  u32muloverflow
  ; result in (dx ax)
  mov  [bp-8], dx
  mov  [bp-10], ax

  ; [bx+2] = [bp-4] + [bp-10]
  mov  ax, [bp-4]
  add  ax, [bp-10]
  ; panics if result overflows
  jc  u32muloverflow
  mov  ss:[bx+2], ax

  ; [bx] = [bp-6]
  mov  ax, [bp-6]
  mov  ss:[bx], ax

  mov  sp, bp
  pop  bp
  ret
u32muloverflow:
  panic  enumlg, 1
u32mul  endp

; dword ptr [bx] /= ax
; remainders in dx
u32div  proc
  push  bp
  mov  bp, sp
  sub  sp, 2

  ; save ax
  mov  [bp-2], ax

  ; calculate (0 [bx+2]) / ax
  mov  dx, 0
  mov  ax, ss:[bx+2]
  div  word ptr [bp-2]
  ; ax = (0 [bx+2]) / [bp-2]
  ; dx = (0 [bx+2]) % [bp-2]
  mov  ss:[bx+2], ax

  ; calculate (dx [bx]) / ax
  mov  ax, ss:[bx]
  div  word ptr [bp-2]
  ; ax = (dx [bx]) / [bp-2]
  ; dx = (dx [bx]) % [bp-2]
  mov  ss:[bx], ax
  ; lets keep dx as remainder

  mov  sp, bp
  pop  bp
  ret
u32div  endp

; parse u32 from rdstr buffer
; result in [bx]
r32dec  proc
  push  bp
  mov  bp, sp
  push  si
  push  cx

  ; dword x = 0
  mov  word ptr ss:[bx+2], 0
  mov  word ptr ss:[bx], 0

  mov  si, 0    ; si = position read
  mov  cx, 0    ; cx = loop times
  mov  cl, strlen
  jcxz  rdscanend  ; move to rdscanend if empty
rdscan:
  ; x = x * 0ah
  mov  ax, 0ah
  call  u32mul

  mov  ax, 0
  mov  al, rdstr[si]
  ; if al < '0' goto rdeinvch
  cmp  al, 30h
  jb  rdeinvch
  ; if al > '9' goto rdeinvch
  cmp  al, 39h
  ja  rdeinvch
  ; al -= 30h
  xor  al, 30h

  ; x = x + ax
  add  word ptr ss:[bx], ax
  adc  word ptr ss:[bx+2], 0
  jc  rdeovfl

  inc  si
  loop  rdscan
rdscanend:
  ; recover environments
  pop  cx
  pop  si
  mov  sp, bp
  pop  bp
  ret
rdeinvch:
  panic  einvch, 1
rdeovfl:
  panic  enumlg, 1
r32dec  endp

w32hex  proc
  push  di
  push  si
  push  ax
  push  cx
  push  dx

  mov  wrtbuf[0], '0'
  mov  wrtbuf[1], 'x'
  mov  di, 2

  ; first byte
  mov  ax, ss:[bx+2]
  mov  cx, 4
w32hexloop1:
  rol  ax, 1
  rol  ax, 1
  rol  ax, 1
  rol  ax, 1
  mov  si, ax
  and  si, 0fh
  mov  dl, hexstr[si]
  mov  wrtbuf[di], dl
  inc  di
  loop  w32hexloop1

  ; second byte
  mov  ax, ss:[bx]
  mov  cx, 4
w32hexloop2:
  rol  ax, 1
  rol  ax, 1
  rol  ax, 1
  rol  ax, 1
  mov  si, ax
  and  si, 0fh
  mov  dl, hexstr[si]
  mov  wrtbuf[di], dl
  inc  di
  loop  w32hexloop2

  ; printf
  mov  wrtbuf[di], 24h
  print  wrtbuf

  pop  dx
  pop  cx
  pop  ax
  pop  si
  pop  di
  ret
w32hex  endp

; write dword ptr [bx] in dec
w32dec  proc
  push  ax
  push  cx
  push  dx
  push  si
  push  di
  push  bp
  mov  bp, sp
  sub  sp, 4

  ; copy dword x
  mov  ax, ss:[bx+2]
  mov  [bp-2], ax
  mov  ax, ss:[bx]
  mov  [bp-4], ax

  mov  di, 0
w32decdivwhile:
  ; while (dword ptr [bp-4] != 0)
  cmp  word ptr [bp-2], 0
  jne  w32decdivbody
  cmp  word ptr [bp-4], 0
  jne  w32decdivbody
  jmp  w32decdivend
w32decdivbody:
  ; dword ptr [bp-4] /= 10
  ; ax = remainder
  lea  bx, [bp-4]
  mov  ax, 0ah
  call  u32div
  mov  ax, dx

  ; al = al + 30h
  xor  al, 30h
  mov  wrtbuf[di], al
  inc  di
  jmp  w32decdivwhile
w32decdivend:
  ; add a zero if di == 0
  test  di, di
  jnz  w32decadddollar
  mov  wrtbuf[di], 30h
  inc  di
w32decadddollar:
  ; add dollar to end
  mov  wrtbuf[di], 24h

  ; reverse wrtbuf[0..di]
  mov  si, 0
  dec  di
  jz  w32decrevend
w32decrevloop:
  ; swap(wrtbuf[si], wrtbuf[di])
  mov  al, wrtbuf[di]
  xchg  al, wrtbuf[si]
  mov  wrtbuf[di], al

  ; si ++; di --;
  inc  si
  dec  di

  ; if si < di loop again
  cmp  si, di
  jb  w32decrevloop
w32decrevend:
  print  wrtbuf

  mov  sp, bp
  pop  bp
  pop  di
  pop  si
  pop  dx
  pop  cx
  pop  ax
  ret
w32dec  endp

w16dec  proc
  push  bp
  mov  bp, sp
  sub  sp, 4
  mov  ax, 0
  mov  [bp-2], ax
  mov  ax, ss:[bx]
  mov  [bp-4], ax
  lea  bx, [bp-4]
  call  w32dec
  mov  sp, bp
  pop  bp
  ret
w16dec  endp

factor  proc
  push  bp
  mov  bp, sp
  sub  sp, 10

  ; dword x = [bx]
  mov  ax, ss:[bx+2]
  mov  [bp-2], ax
  mov  ax, ss:[bx]
  mov  [bp-4], ax

  ; word p = 2
  mov  word ptr [bp-6], 2

  ; print(x)
  lea  bx, [bp-4]
  call  w32dec

  mov  cx, 0
factorloop:
  ; while (x > 1)
  cmp  word ptr [bp-2], 0
  ja  factorloopbody
  cmp  word ptr [bp-4], 1
  ja  factorloopbody
  jmp  factorloopbreak
factorloopbody:
  ; dx = x % p
  mov  ax, [bp-2]
  mov  [bp-8], ax
  mov  ax, [bp-4]
  mov  [bp-10], ax
  
  lea  bx, [bp-10]
  mov  ax, [bp-6]
  call  u32div

  ; if (dx != 0) continue
  test  dx, dx
  jnz  factorloopcontinue

  ; x = x / p
  mov  ax, [bp-8]
  mov  [bp-2], ax
  mov  ax, [bp-10]
  mov  [bp-4], ax

  ; if (!cx) print(' = '), ++ cx
  ; else print(' * ')
  jcxz  factorloopcxzthen
  print  times
  jmp  factorloopcxzend
factorloopcxzthen:
  print  equal
  inc  cx
factorloopcxzend:

  ; print(p)
  lea  bx, [bp-6]
  call  w16dec

  jmp  factorloopbody
factorloopcontinue:
  ; p += 1
  inc  word ptr [bp-6]
  ; if p > 0 goback
  jnz  factorloop
  ; otherwise p is overflow, we can break
factorloopbreak:
  ; if x still > 1 then x is a prime
  cmp  word ptr [bp-2], 0
  ja  factorendprime
  cmp  word ptr [bp-4], 1
  ja  factorendprime
  jmp  factorend
factorendprime:

  jcxz  factorcxzthen
  print  times
  jmp  factorcxzend
factorcxzthen:
  print  equal
  inc  cx
factorcxzend:

  ; print(x) as is the final prime
  lea  bx, [bp-4]
  call  w32dec
factorend:
  print  crlf
  mov  sp, bp
  pop  bp
  ret
factor  endp

_start  proc
  ; prepare ds & es
  mov  ax, @data
  mov  ds, ax
  mov  es, ax

  mov  bp, sp
  sub  sp, 4

  call  gets

  lea  bx, [bp-4]
  call  r32dec

  ; if x < 2 panic
  cmp  word ptr [bp-2], 0
  ja  continue
  cmp  word ptr [bp-4], 1
  ja  continue

  panic  enumsm, 1

continue:
  lea  bx, [bp-4]
  call  factor

  ; end program
  exit  0
_start  endp

end  _start
