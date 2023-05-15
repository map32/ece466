.file "test2.c.s"
.text 
.globl globe
.bss
.align 4
.size 4
.type globe, @object
globe:
.zero 4
.text 
.globl main
.type main, @function
.BB0:
main:
.BB1:
pushq %rbp
movq %rsp, %rbp
subq %16, %rsp
movl $300, globe(%rip)
movl $100, external(%rip)
movl $4, 12(%rbp)
movq $5, %rax
movq globe(%rip), %r10
addq %rax, %r10
movq %r10, %rax
movl %rax, 8(%rbp)
movq 8(%rbp), %rax
movl %rax, -8(%rbp)
leaq 8(%rbp), %rax
movq -8(%rbp), %r10
movq (%r10), %r10
movl %rax, (%r10)
leaq globe(%rip), %rax
movl %rax, -8(%rbp)
movq -8(%rbp), %rax
movl %rax, globe(%rip)
movq -8(%rbp), %rax
movq (%rax), %rax
movl %rax, -8(%rbp)
movq $3, %rax
movq 8(%rbp), %r11
mulq %rax
movq %rax, %rax
movl %rax, 8(%rbp)
movq $3, %rax
movq $5, %movq $%d, %%%s

divq %rax
movq %rax, %rax
movl %rax, 8(%rbp)
movl %error, 8(%rbp)
movl %error, 8(%rbp)
movl %error, 8(%rbp)
movl %error, 8(%rbp)
movl $0]nleave
ret
