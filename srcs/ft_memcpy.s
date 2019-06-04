; void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
; Copy content of memory of src into dst until n

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
