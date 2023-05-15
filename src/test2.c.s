.file "test2.c.s"
.text 
.globl globe
.bss
.align 4
.size, 4
.type globe, @object
globe:
.zero 4
.text 
.globl fib
.type fib, @function
.text 
.globl main
.type main, @function
.BB0:
fib:
.BB1:
pushq %rbp
movq %rsp, %rbp
subq $0, %rsp
movq 8(%rbp), %rax
movq $2, %r10
cmp %rax, %r10
jl .BB2
jge .BB3
.BB2:
movq $1, %rax
leave
ret
jmp .BB4
.BB3:
movq 8(%rbp), %rax
movq $1, %r10
subq %rax, %r10
movq %r10, %rax
pushq %rax
pushq %rax
pushq %r10
pushq %r11
call fib
popq %r11
popq %r10
popq %rax
movq 8(%rbp), %r10
movq $2, %r11
subq %r10, %r11
movq %r11, %rax
pushq %rax
pushq %rax
pushq %r10
pushq %r11
call fib
popq %r11
popq %r10
popq %rax
addq %error, %rax
movq %rax, %rax
movq %%s %rax
leave
ret
.BB4:
main:
.BB5:
pushq %rbp
movq %rsp, %rbp
subq $8, %rsp
pushq $8
pushq %rax
pushq %r10
pushq %r11
call fib
popq %r11
popq %r10
popq %rax
movq %rax, -8(%rbp)
movq -8(%rbp), %rax
leave
ret
