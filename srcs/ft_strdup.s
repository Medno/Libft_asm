section .text
	global _ft_strdup
	extern _malloc, _ft_strlen, _ft_memcpy

_ft_strdup:
	push rbp
	mov rbp, rsp

	test rdi, rdi
	jz _return
	call _ft_strlen

	push rdi
	push rax
	mov rdi, rax
	call _malloc

	pop rdx
	pop rsi
	test rax, rax
	jz _return
	mov rdi, rax
	call _ft_memcpy
	push rax
	add rax, rdx
	mov byte [rax], 0
	pop rax

_return:
	pop rbp
	ret
