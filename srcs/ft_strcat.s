section .text
	global _ft_strcat
	extern _ft_strlen

_ft_strcat:
	push rbp
	mov rbp, rsp

	mov r9, rdi
	mov rdi, rsi
	call _ft_strlen
	push rax
	mov rdi, r9

	call _ft_strlen
	add rdi, rax

	pop rcx
	cld
	rep movsb
	mov byte [rdi], 0
	mov rax, r9

	pop rbp
	ret
