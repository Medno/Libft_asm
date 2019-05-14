section .text
	global _ft_strcat
	extern _ft_strlen, _ft_puts

_ft_strcat:
	push rbp
	mov rbp, rsp

	push rdi
	mov rdi, rsi
	call _ft_strlen
	mov rcx, rax
	pop rdi
	push rcx

	call _ft_strlen
	mov rbx, rax
	add rdi, rbx

	pop rcx
	cld
	rep movsb
	mov rax, rdi

	pop rbp
	ret
