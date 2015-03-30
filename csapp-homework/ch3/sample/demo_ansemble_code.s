	.section	__TEXT,__text,regular,pure_instructions
	.globl	_sum
	.align	4, 0x90
_sum:                                   ## @sum
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp4:
	.cfi_def_cfa_register %rbp
	addl	%esi, %edi
	addl	%edi, _accum(%rip)
	movl	%edi, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_accum                  ## @accum
.zerofill __DATA,__common,_accum,4,2

.subsections_via_symbols
