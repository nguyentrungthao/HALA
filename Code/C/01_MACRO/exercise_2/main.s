	.file	"main.c"
	.text
	.globl	_sum
	.def	_sum;	.scl	2;	.type	32;	.endef
_sum:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%d\12\0"
LC2:
	.ascii "%f\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
	movl	$2, 44(%esp)
	movl	$3, 40(%esp)
	movl	44(%esp), %edx
	movl	40(%esp), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	fldl	LC1
	fstpl	32(%esp)
	movl	$3, 28(%esp)
	fildl	28(%esp)
	faddl	32(%esp)
	fstpl	4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$3, 4(%esp)
	movl	$2, (%esp)
	call	_sum
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.section .rdata,"dr"
	.align 8
LC1:
	.long	-858993459
	.long	1073794252
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
