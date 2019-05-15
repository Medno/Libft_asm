section .data
	te db "OUI"

section .text
	global _ft_strdup
	extern _malloc, _ft_strlen, _ft_memcpy, _ft_puts

_ft_strdup:
	push rbp
	mov rbp, rsp

	call _ft_strlen

	push rdi
	mov rdi, rax
	push rax
	call _malloc

	pop rcx
	pop rsi
	cmp rax, 0
	jz _return
	mov rdi, rax
	call _ft_memcpy

_return:
	pop rbp
	ret
