.model tiny
.stack 100h

.data
buffsize     db  80            ; size of input area
strlen       db  ?             ; number of chars input
buffer       db  80 dup(0)     ; input chars stored here
crlf         db  0Dh, 0Ah, "$" ; \r \n $

equal        db  " = $"
times        db  " * $"

panic_prefix db  "thread 'main' panicked at '", "$"
panic_suffix db  "' on main.asm:114", "$"

panic_invalid_charactor db "invalid charactor", "$"
panic_unreachable db "unreachable", "$"
panic_todo        db "todo", "$"
trace_string      db "trace!", 0Dh, 0Ah, "$"

print_buffer db 80 dup(0)

; variables
int_n       dd  0h
int_m       dd  0h
short_p     dw  0000h, 0000h

__overflow_buffer db "=== OVERFLOW!!! ===$"

.code
  org   100h

; panic program
; @param AL return code
; @param DX panic text offset
panic proc
  push  ax
  push  dx
  ; print panic prefix
  mov   ah, 09h
  mov   dx, offset panic_prefix
  int   21h
  ; print panic content
  pop   dx
  int   21h
  ; print panic suffix
  mov   dx, offset panic_suffix
  int   21h
  ; exit program
  pop   ax
  mov   ah, 4Ch
  int   21h
panic endp

todo proc
  mov   ax, 01h
  mov   dx, offset panic_todo
  call  panic
todo endp

unreachable proc
  mov   ax, 01h
  mov   dx, offset panic_unreachable
  call  panic
unreachable endp

trace proc
  push  ax
  push  dx
  mov   ax, 0900h
  mov   dx, offset trace_string
  int   21h
  pop   dx
  pop   ax
  ret
trace endp

; gets function
; read string from stdin into buffer
; @return strlen read charactors len
; @return buffer results
gets proc
  ; save workspace
  push  ax
  push  dx
  ; DOS function: input a string
  mov   ah, 0Ah
  mov   dx, offset buffsize
  int   21h
  ; go to next screen line
  mov   ah, 09h
  mov   dx, offset crlf
  int   21h
  ; recover registers
  pop   dx
  pop   ax
  ; return
  ret
gets endp

; calculate [bx] times ax
; @param [bx] 32-bit number
; @param ax 16-bit number
; @result write back [bx] 32-bit result
uint32_mul proc
  ; save workspace
  push  ax
  push  cx
  push  dx
  ; ==> 1. calucate low 16 bits times ax
  mov   cx, ax ; save ax in cx
  ; multiply ax with low 16 bits
  mul   word ptr [bx]
  ; higher 16 bit placed in dx, lower 16 bits placed in ax
  mov   [bx], ax ; result lower 16 bits is got
  push  dx ; push higher 16 bits to stack
  ; ==> 2. calculate high 16 bits times ax
  mov   ax, cx ; recover ax from cx
  ; multiply ax with high 16 bits
  mul   word ptr [bx+2]
  ; higher 16 bits placed in dx, drop it
  ; lower 16 bits placed in ax
  pop   [bx+2] ; higher 16 bits from previous mul
  ; add this lower 16-bits to result higher 16-bits
  add   [bx+2], ax
  ; recover workspace
  pop   dx
  pop   cx
  pop   ax
  ret
uint32_mul endp

; calculate [bx] add ax
; @param [bx] source u32 number
; @param ax add number
; @return [bx] write back
uint32_add proc
  ; lower 16 bits add ax
  add   word ptr [bx], ax
  ; add carry to higher 16 bits
  adc   word ptr [bx+2], 0h
  ret
uint32_add endp

; [bx] = [bx] / ax
; ax   = remainder
uint32_div proc
  ; save workspace
  push  cx
  push  dx
  ; calculate [bx] higher 16-bits
  mov   cx, ax
  mov   dx, 0
  mov   ax, [bx+2]
  div   cx
  ; now ax is result higher 16-bits
  mov   [bx+2], ax
  ; dx is previous remainder, let's keep it
  mov   ax, [bx]
  div   cx
  ; now ax is the result lower 16-bits
  mov   [bx], ax
  ; now dx is the final remainder
  mov   ax, dx
  ; recover workspace
  pop   dx
  pop   cx
  ret
uint32_div endp

; set [bx] uint32 to 0
uint32_zero proc
  mov   word ptr [bx], 0
  mov   word ptr [bx+2], 0
  ret
uint32_zero endp


; parse uint32 number
; @param [dx] str buffer
; @param [bx] output dword offset
scan_uint32 proc
  ; save workspaces
  push  ax
  push  cx

  mov   si, 0
  mov   ax, 0
  mov   cx, 0
  mov   cl, strlen
scan_uint32_for_char:
  ; al = buffer[si]
  mov   al, buffer[si]
  ; if al < '0' panic
  cmp   al, 30h
  jb    scan_uint32_panic_invalid_charactor
  ; if al > '9' panic
  cmp   al, 39h
  ja    scan_uint32_panic_invalid_charactor
  ; al = al ^ 30h
  xor   al, 30h
  ; [bx] = [bx] * 10
  push  ax
  mov   ax, 0Ah
  call  uint32_mul
  pop   ax
  ; [bx] = [bx] + ax
  call  uint32_add
  ; ++ si, for loop
  inc   si
  cmp   si, cx
  ; if si < strlen goto scan_uint32_for_char
  jb    scan_uint32_for_char
  ; else return number
  jmp   scan_uint32_return

scan_uint32_panic_invalid_charactor:
  ; panic invalid charactor
  mov   al, 01h
  mov   dx, offset panic_invalid_charactor
  call  panic

scan_uint32_return:
  ; recover workspace
  pop   cx
  pop   ax
  ; return to parent function
  ret
scan_uint32 endp

; print [bx] in decimal
print_uint32 proc
  ; save workspace
  push  ax
  push  cx
  push  dx
  mov   ax, [bx]
  push  ax
  mov   ax, [bx+2]
  push  ax
  push  bx

  mov   si, 0
print_uint32_divide_loop_condition:
  ; while number != 0
  cmp   word ptr [bx], 0
  jne   print_uint32_divide_loop
  cmp   word ptr [bx+2], 0
  jne   print_uint32_divide_loop
  jmp   print_uint32_divide_loop_break
print_uint32_divide_loop:
  ; ax = number % 10
  ; number = number / 10
  mov   ax, 0Ah
  call  uint32_div
  ; al = al ^ 0x30
  xor   al, 30h
  ; print_buffer[si] = al
  mov   print_buffer[si], al
  ; ++ si
  inc   si
  jmp   print_uint32_divide_loop_condition
print_uint32_divide_loop_break:
  ; if si is 0, we should inc in order to output a zero
  cmp   si, 0
  jne   print_uint32_add_trailing
  mov   print_buffer[si], 30h
  inc   si
print_uint32_add_trailing:
  ; print_buffer[si] = '$'
  mov   print_buffer[si], 24h

  ; ==> reverse(print_buffer, print_buffer + si)
  mov   bx, 0
  dec   si

  cmp   bx, si
  jnb   print_uint32_reverse_loop_break
print_uint32_reverse_loop:
  mov   al, print_buffer[si]
  mov   ah, print_buffer[bx]
  mov   print_buffer[bx], al
  mov   print_buffer[si], ah
  inc   bx
  dec   si
  cmp   bx, si
  jb    print_uint32_reverse_loop
print_uint32_reverse_loop_break:

  ; ==> puts(print_buffer)
  mov   ax, 0900h
  mov   dx, offset print_buffer
  int   21h

  ; recover workspace
  pop   bx
  pop   ax
  mov   [bx+2], ax
  pop   ax
  mov   [bx], ax
  pop   dx
  pop   cx
  pop   ax
  ret
print_uint32 endp

; copy [bx] to [si]
uint32_copy proc
  push  ax
  mov   ax, [bx]
  mov   [si], ax
  mov   ax, [bx+2]
  mov   [si+2], ax
  pop   ax
  ret
uint32_copy endp

main proc
  ; move @data to ds
  mov   ax, @data
  mov   ds, ax

  ; get line
  call  gets
  ; get user input line with number
  mov   dx, offset buffer
  mov   bx, offset int_n
  call  scan_uint32

  ; print n
  mov   bx, offset int_n
  call  print_uint32
  mov   dx, offset equal

  ; p = 2
  mov   short_p, 2h
main_outer_loop_condition:
  ; while n > 1:
  mov   bx, offset int_n
  cmp   word ptr [bx+2], 0h
  ja    main_outer_loop
  cmp   word ptr [bx], 1h
  ja    main_outer_loop
  jmp   main_outer_loop_break
main_outer_loop:
main_inner_loop_condition:
  ;   while n % p == 0:
  ; int_m = int_n
  mov   bx, offset int_n
  mov   si, offset int_m
  call  uint32_copy
  ; ax = int_m % p
  ; int_m = int_m / p
  mov   bx, offset int_m
  mov   ax, short_p
  call  uint32_div
  ; if ax == 0 goto loop
  cmp   ax, 0
  je    main_inner_loop
  ; else break
  jmp   main_inner_loop_break
main_inner_loop:
  ;     n /= p
  ; we can move int_m back to int_n
  mov   bx, offset int_m
  mov   si, offset int_n
  call  uint32_copy
  ;     print(' = ' / ' * ')
  mov   ax, 0900h
  int   21h
  mov   dx, offset times
  ;     print(p)
  mov   bx, offset short_p
  call  print_uint32
  jmp   main_inner_loop_condition
main_inner_loop_break:
  ;   p += 1
  add   short_p, 1
  jmp   main_outer_loop_condition
main_outer_loop_break:

  ; end program with exit code 0
  mov   ax, 4C00h
  int   21h
main endp

end  main

