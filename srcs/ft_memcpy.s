section .text
	global _ft_memcpy

_ft_memcpy:
	push rbp
	mov rbp, rsp

	mov rax, rdi
	cld
	mov rcx, rdx
	rep movsb

	pop rbp
	ret
