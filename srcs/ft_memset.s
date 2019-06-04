; void	*ft_memset(void *b, int c, size_t len);
; Set c value over b until len

section .text
	global _ft_memset

_ft_memset:
	push rbp
	mov rbp, rsp

	mov r9, rdi		; Save pointer of b
	xor rax, rax
	mov rax, rsi
	mov rcx, rdx
	cld
	rep stosb

	mov rax, r9		; Return pointer of b

	pop rbp
	ret
