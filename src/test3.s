	.file	"test3.c"
	.text
	.globl	a
	.bss
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.zero	4
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.zero	4
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$32, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	$32, 8(%ebp)
	movl	$5, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, -16(%ebp)
	cmpl	$4, -20(%ebp)
	jle	.L2
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	$32, -8(%ebp)
.L2:
	cmpl	$2, -20(%ebp)
	jg	.L3
	movl	$64, -4(%ebp)
.L3:
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB1:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE1:
	.ident	"GCC: (Alpine 12.2.1_git20220924-r10) 12.2.1 20220924"
	.section	.note.GNU-stack,"",@progbits
