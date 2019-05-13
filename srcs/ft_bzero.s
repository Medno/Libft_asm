section .data
	msg db "1"

section .text
	global _ft_bzero

_ft_bzero:
	push rbp
	mov rbp, rsp

	test rdi, rdi
	jz _return

	mov rbx, rdi

	test rsi, rsi
	jz _return

	xor ecx, ecx
	mov ecx, 10
	cld
	jmp _set_to_zero

_set_to_zero:
	mov r8, rdi
mov rax, 0x2000004 ; write
mov rdi, 1 ; stdout
mov rsi, r8
mov rdx, 3
syscall
mov rdi, r8
	stosb
	inc rdi
	pop rcx
	loop _set_to_zero

_return:
	mov rsp, rbp
	pop rbp
	ret
