section .text
	global _ft_putchar

_ft_putchar:
	push rbp
	mov rbp, rsp

	push rdi
	mov rax, 0x2000004
	mov rdx, 1
	lea rsi, [rsp]
	mov rdi, 1
	syscall
	jc _error

_return:
	pop rax
	pop rbp
	ret

_error:
	mov rax, -1
