; void	ft_bzero(void *s, size_t n);
; Put a \0 on every value of s until n

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
	mov rcx, rsi	; Put the length on the counter register
	cld
	xor rax, rax
	rep stosb		; Loop over all values on rdi, putting rax (0)

_return:
	pop rbp
	ret
