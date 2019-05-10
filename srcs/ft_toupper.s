section .text
	global _ft_toupper

_ft_toupper:
	push rbp
	mov rbp, rsp

	mov rax, rdi
	cmp rdi, 'a'
	jl _return
	cmp rdi, 'z'
	jg _return
	sub rax, 32
	jmp _return

_return:
	pop rbp
	ret
