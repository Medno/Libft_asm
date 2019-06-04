; size_t	ft_strlen(const char *s);
; Get the length of s

section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp

	xor rax, rax
	test rdi, rdi
	jz _return
	push rdi
	mov rcx, -1		; Put a negative number in order to not be stopped in repnz
	cld
	repnz scasb		; Go through s
	mov rax, rdi
	pop rdi
	sub rax, rdi	; Compare the last position of rdi and rdi
	dec rax

_return:
	pop rbp
	ret
