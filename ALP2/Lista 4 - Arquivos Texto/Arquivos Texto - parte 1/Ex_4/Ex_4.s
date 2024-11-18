	.file	"Ex_4.c"
	.text
	.section	.rodata
.LC0:
	.string	"r"
.LC1:
	.string	"../html.html"
.LC2:
	.string	"w+"
.LC3:
	.string	"../descartado.txt"
	.text
	.globl	abrir_arquivo
	.type	abrir_arquivo, @function
abrir_arquivo:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	leaq	.LC2(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	abrir_arquivo, .-abrir_arquivo
	.globl	fechar_arquivo
	.type	fechar_arquivo, @function
fechar_arquivo:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	fechar_arquivo, .-fechar_arquivo
	.globl	voltar_ao_inicio
	.type	voltar_ao_inicio, @function
voltar_ao_inicio:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	rewind@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	voltar_ao_inicio, .-voltar_ao_inicio
	.globl	extrair_tags
	.type	extrair_tags, @function
extrair_tags:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$320, %rsp
	movq	%rdi, -312(%rbp)
	movq	%rsi, -320(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -292(%rbp)
	jmp	.L5
.L11:
	leaq	-272(%rbp), %rax
	movl	$60, %esi
	movq	%rax, %rdi
	call	strchr@PLT
	movq	%rax, -288(%rbp)
	jmp	.L6
.L9:
	movq	-288(%rbp), %rax
	movl	$62, %esi
	movq	%rax, %rdi
	call	strchr@PLT
	movq	%rax, -280(%rbp)
	cmpq	$0, -280(%rbp)
	je	.L7
	movl	$1, -292(%rbp)
	movq	-280(%rbp), %rax
	subq	-288(%rbp), %rax
	addq	$1, %rax
	movq	%rax, %rsi
	movq	-320(%rbp), %rdx
	movq	-288(%rbp), %rax
	movq	%rdx, %rcx
	movq	%rsi, %rdx
	movl	$1, %esi
	movq	%rax, %rdi
	call	fwrite@PLT
	movq	-320(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc@PLT
	movq	-280(%rbp), %rax
	addq	$1, %rax
	movl	$60, %esi
	movq	%rax, %rdi
	call	strchr@PLT
	movq	%rax, -288(%rbp)
	jmp	.L6
.L7:
	movl	$1, -292(%rbp)
.L6:
	cmpq	$0, -288(%rbp)
	je	.L8
	cmpl	$0, -292(%rbp)
	je	.L9
.L8:
	movl	$0, -292(%rbp)
.L5:
	movq	-312(%rbp), %rdx
	leaq	-272(%rbp), %rax
	movl	$256, %esi
	movq	%rax, %rdi
	call	fgets@PLT
	testq	%rax, %rax
	je	.L13
	cmpl	$0, -292(%rbp)
	je	.L11
.L13:
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L12
	call	__stack_chk_fail@PLT
.L12:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	extrair_tags, .-extrair_tags
	.globl	apresentar_arquivo
	.type	apresentar_arquivo, @function
apresentar_arquivo:
.LFB4:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	voltar_ao_inicio
	jmp	.L15
.L16:
	movsbl	-1(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
.L15:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	fgetc@PLT
	movb	%al, -1(%rbp)
	cmpb	$-1, -1(%rbp)
	jne	.L16
	movl	$10, %edi
	call	putchar@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	apresentar_arquivo, .-apresentar_arquivo
	.section	.rodata
.LC4:
	.string	"Arquivo inexistente"
.LC5:
	.string	"Entrou em organizar"
	.text
	.globl	organizar_cod
	.type	organizar_cod, @function
organizar_cod:
.LFB5:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	leaq	-16(%rbp), %rdx
	leaq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	abrir_arquivo
	movq	-8(%rbp), %rax
	testq	%rax, %rax
	je	.L18
	movq	-16(%rbp), %rax
	testq	%rax, %rax
	jne	.L19
.L18:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L20
.L19:
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	extrair_tags
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	apresentar_arquivo
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fechar_arquivo
	nop
.L20:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	organizar_cod, .-organizar_cod
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	organizar_cod
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
