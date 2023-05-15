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
.globl func
.type func, @function
.text 
.globl main
.type main, @function
.BB0:
func:
.BB1:
pushq %rbp
movq %rsp, %rbp
subq %32, %rsp
movl $32, 16(%rbp)
movl $64, 24(%rbp)
movq 8(%rbp), %rax
movq $3, %r10
cmp %rax, %r10
jg .BB2
jle .BB3
.BB2:
movl $32, 8(%rbp)
jmp .BB4
.BB3:
movq 8(%rbp), %rax
movq $1, %r10
addq %rax, %r10
movq %r10, %rax
movl %rax, 8(%rbp)
.BB4:
movq 8(%rbp), %rax
leave
ret
main:
.BB5:
pushq %rbp
movq %rsp, %rbp
subq %0, %rsp
movl $10, -8(%rbp)
movq -16(%rbp), %rax
movq $0, %r10
cmp %rax, %r10
jg .BB6
jle .BB7
.BB6:
movl $100, -16(%rbp)
jmp .BB8
.BB7:
movl $10, -24(%rbp)
movl $32, -32(%rbp)
.BB8:
pushl $3
pushl $2
pushl $1
movq %rax %r12
movq %r10 %r13
call func
movq %r12 %r10
movq %r13 %r11
movl %rax, -8(%rbp)
pushl -8(%rbp)
pushl $0
movq %rax %r12
movq %r10 %r13
call printf@PLT
movq %r12 %r10
movq %r13 %r11
movl $0
leave
ret
