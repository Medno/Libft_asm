section .data
	SYS_STDOUT	equ	1
	SYS_WRITE	equ	0x02000004

section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp

	cmp rdi, 0
	jle _null
	mov rax, rdi
	
_while:
	cmp byte [rax], 0
	jz _return
	inc rax
	jmp _while

_null:
	xor rax, rax
	pop rbp
	ret

_return:
	sub rax, rdi

	pop rbp
	ret
