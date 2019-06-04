; void	ft_cat(int fd);
; Display the content of the corresponding fd (including stdin)

%define BUF_SIZE 50

section .bss
	buf resb BUF_SIZE

section .text
	global _ft_cat

_ft_cat:
	push rbp
	mov rbp, rsp

_read_fd:
	lea rsi, [rel buf]	; Assign the buffer into rsi
	mov rdx, BUF_SIZE	; Read on BUF_SIZE
	mov rax, 0x2000003	; Read syscall value
	syscall
	jc _return

	push rax			; Value readed
	push rdi			; Save the fd
	mov rdx, rax
	mov rdi, 1
	mov rax, 0x2000004	; Write the corresponding content
	syscall
	pop rdi
	pop rax
	jc _return

	cmp rax, BUF_SIZE	; If we read less than BUF_SIZE, we are at the end of the file
	jnb _read_fd

_return:
	pop rbp
	ret
