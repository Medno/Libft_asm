; char	*ft_strcat(char *restrict s1, const char *restrict s2);
; Concatenate s2 into s1

section .text
	global _ft_strcat
	extern _ft_strlen

_ft_strcat:
	push rbp
	mov rbp, rsp

	mov r9, rdi			; Save value of s1
	mov rdi, rsi
	call _ft_strlen		; Get the length of s2
	push rax
	mov rdi, r9

	call _ft_strlen		; Get the length of s1
	add rdi, rax		; Go to the end of s1

	pop rcx
	cld
	rep movsb			; Copy value of s2 into the end of s1
	mov byte [rdi], 0	; Add final \0
	mov rax, r9

	pop rbp
	ret
