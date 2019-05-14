section .data
	null_str	db "(null)"
	newline		db 0x0a

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp

	push rsi
	push rdi
	test rdi, rdi
	jz _null
	call _ft_strlen
	mov rdx, rax
	mov rsi, rdi

_print_str:
	mov rax, 0x2000004
	mov rdi, 1
	syscall
	mov rax, 0x2000004
	mov rdi, 1
	mov rdx, 1
	mov rsi, newline
	syscall
	mov rax, 10
	pop rdi
	pop rsi
	pop rbp
	ret

_null:
	mov rsi, null_str
	mov rdx, 6
	jmp _print_str
