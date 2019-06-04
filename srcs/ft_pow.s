; int		ft_pow_int(int n, int pow);
; Compute n power pow (integer value)

section .text
	global _ft_pow_int

_ft_pow_int:
	push rbp
	mov rbp, rsp

	push rsi
	xor rax, rax
	test rsi, rsi
	jl _return		; Cannot handle negative power
	jz _one			; Power of zero, return 1
	lea rax, [rdi]
	mov rcx, rsi
	dec rcx

_rec:
	imul rax, rdi	; Save result of the multiplication to rax (final result)
	loop _rec

_return:
	pop rsi
	pop rbp
	ret	

_one:
	mov rax, 1
	jmp _return
