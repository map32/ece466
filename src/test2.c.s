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
subq %16, %rsp
movl $32, 12(%rbp)
movl $64, 16(%rbp)
movq 8(%rbp), %rax
movq $3, %movq $%d, %%%s

cmp %rax, %r10
jg .BB2
jle .BB3
.BB2:
movl $32, 8(%rbp)
.BB3:
movq 8(%rbp), %rax
movq $1, %movq $%d, %%%s

addq %rax, %r10
movq %r10, %rax
movl %rax, 8(%rbp)
jmp .BB4
.BB4:
movq 8(%rbp), %rax
leave
ret
main:
.BB5:
pushq %rbp
movq %rsp, %rbp
subq %0, %rsp
movl $10, -4(%rbp)
movq -8(%rbp), %rax
movq $0, %movq $%d, %%%s

cmp %rax, %r10
jg .BB6
jle .BB7
.BB6:
movl $100, -8(%rbp)
.BB7:
movl $10, -12(%rbp)
movl $32, -16(%rbp)
jmp .BB8
.BB8:
movl $0]nleave
ret
