section .data
	msg db "1"

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

_set_to_zero:
	mov byte [rdi + rcx - 1], 0
	loop _set_to_zero

_return:
	mov rsp, rbp
	pop rbp
	ret
