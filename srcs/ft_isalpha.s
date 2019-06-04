; int		ft_isalpha(int c);
; Check either the int is an alphabet char

section .text
	global _ft_isalpha

_ft_isalpha:
	push rbp
	mov rbp, rsp

	xor rax, rax
	cmp rdi, 'A'
	jl _return
	cmp rdi, 'z'
	jg _return
	cmp rdi, 'Z'
	jg _lower_case
	mov rax, 1
	jmp _return

_lower_case:
	cmp rdi, 'a'
	jl _return
	mov rax, 1

_return:
    mov rsp, rbp
    pop rbp
	ret
