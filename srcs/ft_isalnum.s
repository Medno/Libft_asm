section .text
	global _ft_isalnum
	extern _ft_isalpha, _ft_isdigit

_ft_isalnum:
	push rbp
	mov rbp, rsp

	call _ft_isalpha
	cmp rax, 1
	je _return
	call _ft_isdigit
	jmp _return

_return:
	pop rbp
	ret
