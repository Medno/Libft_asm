section .text
	global _ft_islower

_ft_islower:
	push rbp
	mov rbp, rsp

	xor rax, rax
	cmp rdi, 'a'
	jl _return
	cmp rdi, 'z'
	jg _return
	mov rax, 1

_return:
	pop rbp
	ret
