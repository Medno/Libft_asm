section .text
	global _ft_tolower

_ft_tolower:
	push rbp
	mov rbp, rsp

	mov rax, rdi
	cmp rdi, 'A'
	jl _return
	cmp rdi, 'Z'
	jg _return
	add rax, 32
	jmp _return

_return:
	pop rbp
	ret
