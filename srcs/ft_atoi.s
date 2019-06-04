; int		ft_atoi(char *str);
; Convert a string into an integer

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
	call _ft_strlen		; Get total length of str
	mov rcx, rax		; Put the length into the counter register
	cld

	mov r9, 1			; Index of the final sign
	xor rdx, rdx		; Total result
	xor rax, rax		; Tmp value that get edited over every char

_is_sp:
	cmp byte [rsi], ' '	; Loop over spaces
	je _sp

_sign:
	cmp byte [rsi], '+'	; Catch positive sign
	je _pos
	cmp byte [rsi], '-'	; Catch negative sign
	je _neg

_convert:
	lodsb				; Put the char in rax, increment rsi
	push rax
	push rdi
	mov rdi, rax
	call _ft_isdigit	; Check either the char is a digit
	test rax, rax
	jz _not_digit		; If not we save the previous value and return
	pop rdi
	pop rax
	add rdx, rax		; Add the corresponding char in rdx
	sub rdx, 48			; Sub the ascii value

	cmp rcx, 1			; If the counter is one, we are at the end of the str
	jz _end

	push rsi			; Check if the next char is a digit
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

	imul rdx, 10		; Multiply the result by 10
	loop _convert

_end:
	mov rax, rdx		; Put the result on the return register
	imul rax, r9		; Multiply by the sign index

_return:
	pop rbp
	ret

_next_not_digit:
	pop rsi
	pop rdi
	pop rax
	mov rax, rdx
	imul rax, r9
	jmp _return

_not_digit:
	pop rdi
	pop rax
	mov rax, rdx
	imul rax, r9
	jmp _return

_neg:
	mov r9, -1		; Edit the sign of the sign index
	lodsb
	loop _convert

_pos:
	lodsb
	loop _convert

_sp:
	lodsb			; Increment index str until there is no more space
	loop _is_sp
