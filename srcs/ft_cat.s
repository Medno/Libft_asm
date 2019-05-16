%define BUF_SIZE 50

section .bss
	buf resb BUF_SIZE

section .text
	global _ft_cat

_ft_cat:
	push rbp
	mov rbp, rsp

	cmp rdi, 0
	jl _return

_read_fd:
	lea rsi, [rel buf]
	mov rdx, BUF_SIZE
	mov rax, 0x2000003
	syscall

	push rax
	push rdi

	mov rdx, rax
	mov rdi, 1
	mov rax, 0x2000004
	syscall

	pop rdi
	pop rax
	cmp rax, BUF_SIZE
	jnb _read_fd

_return:
	pop rbp
	ret
