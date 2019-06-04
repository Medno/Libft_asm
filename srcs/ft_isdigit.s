; int		ft_isdigit(int c);
; Check either the int is an integer char

section .text
	global _ft_isdigit

_ft_isdigit:
	push rbp
	mov rbp, rsp

	xor rax, rax
	cmp rdi, '0'
	jl _return
	cmp rdi, '9'
	jg _return
	mov rax, 1
	jmp _return
	
_return:
	mov rsp, rbp
	pop rbp
	ret
