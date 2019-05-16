section .text
	global _ft_pow_int

_ft_pow_int:
	push rbp
	mov rbp, rsp

	push rsi
	xor rax, rax
	test rsi, rsi
	jl _return
	jz _one
	lea rax, [rdi]
	mov rcx, rsi
	dec rcx

_rec:
	imul rax, rdi
	loop _rec

_return:
	pop rsi
	pop rbp
	ret	

_one:
	mov rax, 1
	jmp _return
