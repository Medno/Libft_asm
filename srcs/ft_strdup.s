section .text
	global _ft_strdup
	extern _malloc, _ft_strlen, _ft_memcpy

_ft_strdup:
	push rbp
	mov rbp, rsp



	pop rbp
	ret
