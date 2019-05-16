section .text
	global _ft_memccpy

_ft_memccpy:
	push rbp
	mov rbp, rsp

	mov rax, rdi
	cld

_copy_char:
	cmp byte [rsi], dl
	movsb
	je _return
	loop _copy_char

_return:
	pop rbp
	ret
