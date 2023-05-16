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
subq $8, %rsp
movq 16(%rbp), %rax
movq $2, %r10
cmp %r10, %rax
jl .BB2
jge .BB3
.BB2:
movq $1, %rax
leave
ret
jmp .BB4
.BB3:
subq $16,%rsp
movq 16(%rbp), %rax
movq $1, %r10
subq %r10, %rax
movq %rax, %rax
pushq %rax
addq $24,%rsp
pushq %rax
pushq %r10
subq $8,%rsp
call fib
popq %r11
popq %r10
movq %rax, -8(%rbp)
subq $16,%rsp
movq 16(%rbp), %rax
movq $2, %r10
subq %r10, %rax
movq %rax, %rax
pushq %rax
addq $24,%rsp
pushq %rax
pushq %r10
subq $8,%rsp
call fib
popq %r11
popq %r10
movq -8(%rbp), %r10
addq %r10, %rax
movq %rax, %rax
movq %rax, %rax
leave
ret
.BB4:
main:
.BB5:
pushq %rbp
movq %rsp, %rbp
subq $8, %rsp
subq $16,%rsp
pushq $6
addq $24,%rsp
pushq %rax
pushq %r10
subq $8,%rsp
call fib
popq %r11
popq %r10
movq %rax, -8(%rbp)
movq -8(%rbp), %rax
leave
ret
