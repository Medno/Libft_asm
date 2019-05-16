section .text
	global _ft_isupper

_ft_isupper:
	push rbp
	mov rbp, rsp

	xor rax, rax
	cmp rdi, 'A'
	jl _return
	cmp rdi, 'Z'
	jg _return
	mov rax, 1

_return:
	pop rbp
	ret
