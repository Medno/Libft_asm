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
	movzx r9, byte [rdi - 1]
	movzx rcx, byte [rsi - 1]
	mov	rax, r9
	sub	rax, rcx

_return:
	pop rbp
	ret

