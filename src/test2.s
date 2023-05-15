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
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$300, globe(%rip)
	movl	$100, external(%rip)
	movl	$4, -36(%rbp)
	movl	globe(%rip), %eax
	addl	$5, %eax
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	cltq
	movq	%rax, -16(%rbp)
	leaq	-20(%rbp), %rax
	movl	%eax, %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	leaq	globe(%rip), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	%eax, globe(%rip)
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	cltq
	movq	%rax, -16(%rbp)
	movl	-20(%rbp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, -20(%rbp)
	movl	$0, -20(%rbp)
	movl	$3, -20(%rbp)
	movl	-20(%rbp), %eax
	andl	$5, %eax
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	xorl	$5, %eax
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	orl	$5, %eax
	movl	%eax, -20(%rbp)
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Alpine 12.2.1_git20220924-r10) 12.2.1 20220924"
	.section	.note.GNU-stack,"",@progbits
