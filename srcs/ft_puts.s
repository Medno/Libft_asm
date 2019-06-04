; int		ft_puts(const char *s);
; Display the s string or (null) if s is NULL pointer

section .data
	null_str	db "(null)"
	newline		db 0x0a

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp

	test rdi, rdi
	jz _null
	call _ft_strlen			; Get the str length
	mov rdx, rax			; Save length
	mov rsi, rdi

_print_str:
	mov rax, 0x2000004
	mov rdi, 1
	syscall
	jc _error
	mov rax, 0x2000004
	mov rdi, 1
	mov rdx, 1
	lea rsi, [rel newline]
	syscall
	jc _error
	mov rax, 10

_return:
	pop rbp
	ret

_error:
	mov rax, -1
	jmp _return

_null:
	lea rsi, [rel null_str]
	mov rdx, 6
	jmp _print_str
