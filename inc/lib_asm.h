/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_asm.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 09:34:49 by pchadeni          #+#    #+#             */
/*   Updated: 2019/05/16 12:17:42 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_ASM_H
# define LIB_ASM_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <math.h>

#define RED "\033[01;31m"
#define GREEN "\033[01;32m"
#define EOC "\033[0m"
#define BOLD "\033[01m"

void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlen(const char *s);
int		ft_puts(const char *s);
char	*ft_strcat(char *restrict s1, const char *restrict s2);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char	*ft_strdup(const char *s1);
void	ft_cat(int fd);
int		ft_putchar(int c);
int		ft_atoi(char *str);
int		ft_pow_int(int n, int pow);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_islower(int c);
int		ft_isupper(int c);
void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int		ft_isblank(int c);
int		ft_isspace(int c);

void	print_success(char *f_name, int n);
void	print_error_s(char *exp, char *res, char *f_name);
void	print_error_i(int exp, int res, char *f_name);
void	print_error_zu(size_t exp, size_t res, char *f_name);

#endif
