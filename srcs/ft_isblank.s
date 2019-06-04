; int		ft_isblank(int c);
; Check either the int is a blank character

section .text
	global _ft_isblank

_ft_isblank:
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
	jne _return
	mov rax, 1
	jmp _return
