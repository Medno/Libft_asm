section .text
	global _ft_memset

_ft_memset:
	push rbp
	mov rbp, rsp

	xor rax, rax
	mov rax, rsi
	mov rcx, rdx
	cld
	rep stosb

	mov rax, rdi

	pop rbp
	ret
