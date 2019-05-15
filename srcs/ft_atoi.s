section .text
	global _ft_atoi
	extern _ft_strlen, _ft_isdigit, _ft_puts

_ft_atoi:
	push rbp
	mov rbp, rsp

	test rdi, rdi
	jz _return
	
	mov rsi, rdi
	xor rcx, rcx
	call _ft_strlen
	mov rcx, rax
	cld

	mov rbx, 1
	xor rdx, rdx
	xor rax, rax

_is_sp
	cmp byte [rsi], ' '
	je _sp

_sign:
	cmp byte [rsi], '+'
	je _pos
	cmp byte [rsi], '-'
	je _neg

_convert:
	lodsb
	push rax
	push rdi
	mov rdi, rax
	call _ft_isdigit
	test rax, rax
	jz _not_digit
	pop rdi
	pop rax
	add rdx, rax
	sub rdx, 48

	cmp rcx, 1
	jz _end

	push rsi
	lodsb
	push rax
	push rdi
	mov rdi, rax
	call _ft_isdigit
	test rax, rax
	jz _next_not_digit
	pop rdi
	pop rax
	pop rsi

	imul rdx, 10
	loop _convert

_end:
	mov rax, rdx
	imul rax, rbx

_return:
	pop rbp
	ret

_next_not_digit:
	pop rsi
	pop rdi
	pop rax
	mov rax, rdx
	imul rax, rbx
	jmp _return

_not_digit:
	pop rdi
	pop rax
	mov rax, rdx
	imul rax, rbx
	jmp _return

_neg:
	mov rbx, -1
	lodsb
	loop _convert

_pos:
	lodsb
	loop _convert

_sp:
	lodsb
	loop _is_sp
