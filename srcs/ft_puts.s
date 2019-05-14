section .data
	null_str db "(null)", 0x0a

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp

	test rdi, rdi
	jz _null
	call _ft_strlen
	mov rdx, rax
	mov rsi, rdi

_print_str:
	mov rax, 0x2000004
	mov rdi, 1
	syscall
	pop rbp
	ret

_null:
	mov rsi, null_str
	mov rdx, 7
	jmp _print_str
