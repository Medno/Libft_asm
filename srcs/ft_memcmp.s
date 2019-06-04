; int		ft_memcmp(const void *s1, const void *s2, size_t n);
; Compare two contents of memory until n

section .text
	global _ft_memcmp

_ft_memcmp:
	push rbp
	mov rbp, rsp

	cld
	xor rax, rax
	mov rcx, rdx
	repe cmpsb
	je _return
	movzx r9, byte [rdi - 1]	; Save last value of rdi
	movzx rcx, byte [rsi - 1]	; Save last value of rsi
	mov	rax, r9
	sub	rax, rcx				; Compare both last values

_return:
	pop rbp
	ret

