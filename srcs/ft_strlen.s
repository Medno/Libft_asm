section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp

	push rdi
	mov rcx, -1
	xor rax, rax
	cld
	repnz scasb
	mov rax, rdi
	pop rdi
	sub rax, rdi
	dec rax

	mov rsp, rbp
	pop rbp
	ret
