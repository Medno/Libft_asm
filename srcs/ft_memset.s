section .text
	global _ft_memset

_ft_memset:
	push rbp
	mov rbp, rsp

	mov r9, rdi
	xor rax, rax
	mov rax, rsi
	mov rcx, rdx
	cld
	rep stosb

	mov rax, r9

	pop rbp
	ret
