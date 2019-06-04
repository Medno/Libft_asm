; char	*ft_strdup(const char *s1);
; Allocate a copy of s1

section .text
	global _ft_strdup
	extern _malloc, _ft_strlen, _ft_memcpy

_ft_strdup:
	push rbp
	mov rbp, rsp

	test rdi, rdi
	jz _return
	call _ft_strlen		; Get the length of s1

	push rdi
	push rax
	mov rdi, rax
	call _malloc		; Allocate enough memory to store the new string

	pop rdx
	pop rsi
	test rax, rax
	jz _return
	mov rdi, rax
	call _ft_memcpy		; Call memcpy to put the content of s1 in the new string
	push rax
	add rax, rdx		; Go at the end of the new string in order to put the final \0
	mov byte [rax], 0
	pop rax

_return:
	pop rbp
	ret
