section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp

	xor rax, rax
	test rdi, rdi
	jz _return
	push rdi
	mov rcx, -1
	cld
	repnz scasb
	mov rax, rdi
	pop rdi
	sub rax, rdi
	dec rax

_return:
	pop rbp
	ret
