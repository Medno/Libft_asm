section .text
	global _ft_isspace

_ft_isspace:
	push rbp
	mov rbp, rsp

	xor rax, rax
	cmp rdi, ' '
	jne _tab
	mov rax, 1

_return: 
	pop rbp
	ret

_tab:
	cmp rdi, 9
	jg _nl
	jl _return
	mov rax, 1
	jmp _return

_nl:
	cmp rdi, 13
	jg _return
	mov rax, 1
	jmp _return
