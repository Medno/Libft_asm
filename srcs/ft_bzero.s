section .text
	global _ft_bzero

_ft_bzero:
	push rbp
	mov rbp, rsp

	test rdi, rdi
	jz _return

	test rsi, rsi
	jz _return

	xor rcx, rcx
	mov rcx, rsi
	cld
	xor rax, rax
	rep stosb

_return:
	pop rbp
	ret
