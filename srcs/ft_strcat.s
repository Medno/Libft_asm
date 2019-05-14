section .text
	global _ft_strcat
	extern _ft_strlen

_ft_strcat:
	push rbp
	mov rbp, rsp

	
	call _ft_strlen
	mov rbx, rax


	mov rsp, rbp
	pop rbp
	ret
