section .text
	global _ft_isprint

_ft_isprint:
	push rbp
	mov rbp, rsp

	xor rax, rax
	cmp rdi, ' '
	jl _return
	cmp rdi, '~'
	jg _return
	inc rax
	jmp _return

_return:
	pop rbp
	ret
