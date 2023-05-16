	.file	"test2.c"
	.text
	.globl	globe
	.bss
	.align 4
	.type	globe, @object
	.size	globe, 4
globe:
	.zero	4
	.text
	.globl	fib
	.type	fib, @function
fib:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	%edi, -20(%rbp)
	cmpl	$1, -20(%rbp)
	jg	.L2
	movl	$1, %eax
	jmp	.L3
.L2:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	fib
	movl	%eax, %ebx
	movl	-20(%rbp), %eax
	subl	$2, %eax
	movl	%eax, %edi
	call	fib
	addl	%ebx, %eax
.L3:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fib, .-fib
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	$8, %edi
	call	fib
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Alpine 12.2.1_git20220924-r10) 12.2.1 20220924"
	.section	.note.GNU-stack,"",@progbits
