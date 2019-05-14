section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp

	mov rcx, -1
	mov rbx, rdi
	xor al, al
	cld
	repnz scasb
	mov rax, rdi
	sub rax, rbx
	dec rax

	mov rsp, rbp
	pop rbp
	ret
