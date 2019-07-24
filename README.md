# Libft_asm

42 school project: recoding several functions of libc in ASM (NASM)

## Setup

Launch the Makefile command in the root repository : `make`

When `libfts.a` is ready to use, you can compile your files with gcc including : `-L'path to libfts.a' -lfts`

### Prototypes in the archive

```c
int   ft_atoi(char *str);
void  ft_bzero(void *s, size_t n);
int   ft_isalpha(int c);
int   ft_isdigit(int c);
int   ft_isalnum(int c);
int   ft_isascii(int c);
int   ft_isprint(int c);
int   ft_isprint(int c);
int   ft_islower(int c);
int   ft_isupper(int c);
int   ft_tolower(int c);
int   ft_toupper(int c);
int   ft_isblank(int c);
int   ft_isspace(int c);
int   ft_puts(const char *s);
void  *ft_memset(void *b, int c, size_t len);
void  *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void  *ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int   ft_memcmp(const void *s1, const void *s2, size_t n);
char  *ft_strdup(const char *s1);
char  *ft_strcat(char *restrict s1, const char *restrict s2);
size_t  ft_strlen(const char *s);
int   ft_putchar(int c);
int   ft_pow_int(int n, int pow);

void  ft_cat(int fd);
```
