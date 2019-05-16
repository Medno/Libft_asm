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
	movzx rbx, byte [rdi - 1]
	movzx rcx, byte [rsi - 1]
	mov	rax, rbx
	sub	rax, rcx

_return:
	pop rbp
	ret

