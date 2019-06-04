; int		ft_isascii(int c);
; Check either the int is in ascii table (between 0 and 127)

section .text
	global _ft_isascii

_ft_isascii:
	push rbp
	mov rbp, rsp

	xor rax, rax
	cmp rdi, 0
	jl _return
	cmp rdi, 0177o
	jg _return
	inc rax
	jmp _return

_return:
	pop rbp
	ret
