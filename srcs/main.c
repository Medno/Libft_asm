/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:01:17 by pchadeni          #+#    #+#             */
/*   Updated: 2019/05/15 14:58:57 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_asm.h"

void	print_success(char *f_name)
{
	printf("%s%s%s tests passed with %ssuccess%s\n",
		BOLD, f_name, EOC, GREEN, EOC);
}

void	print_error_s(char *exp, char *res, char *f_name)
{
	printf("%sError%s in %s%s%s function. Exp : |%s|, Get: |%s|\n",
		RED, EOC, BOLD, f_name, EOC, exp, res);
}

void	print_error_i(int exp, int res, char *f_name)
{
	printf("%sError%s in %s%s%s function. Exp : |%d|, Get: |%d|\n",
		RED, EOC, BOLD, f_name, EOC, exp, res);
}

void	print_error_zu(size_t exp, size_t res, char *f_name)
{
	printf("%sError%s in %s%s%s function. Exp : |%zu|, Get: |%zu|\n",
		RED, EOC, BOLD, f_name, EOC, exp, res);
}

int	test_bzero(void)
{
	char	str[13] = "I'm not null";
	char	buf[6] = "*****";
	int		i;

	i = 0;
	ft_bzero(buf, 5);
	write(1, buf, 5);
	ft_bzero(str, 5);
	write(1, str, 5);
	while (i < 5)
	{
		if (str[i])
			print_error_s("", str, "ft_bzero");
		if (buf[i])
			print_error_s("", buf, "ft_bzero");
		i++;
	}
	print_success("ft_bzero");
	return (0);
}

int	test_strcat(void)
{
	char str[10] = "";
	char to_cat[4] = "987";

	ft_strcat(str, "12345");
	ft_strcat(str, to_cat);
	ft_strcat(str, "0");
	if (strcmp(str, "123459870"))
		print_error_s("123459870", str, "ft_strcat");
	else
		print_success("ft_strcat");
	return (0);
}


int	test_isfn(int (*f)(int), int (*real)(int), char *f_name)
{
	int	i;

	i = -127;
	while (i != 255)
	{
		if ((*f)(i) != (*real)(i))
		{
			print_error_i((*real)(i), (*f)(i), f_name);
			return (1);
		}
		i++;
	}
	print_success(f_name);
	return (0);
}

int	test_puts(void)
{
	int		i = 0;
	char	*to_display[] = {
		NULL,
		"",
		"Martine a la plage",
		"Martine fait du ski",
		"Martine voyage"
	};
	int exp, res;

	while (i < 5)
	{
		printf("----------------------Start of printing----------------------\n");
		exp = puts(to_display[i]);
		res = ft_puts(to_display[i]);
		printf("---------------------- End of printing ----------------------\n");
		if (exp != res)
			print_error_i(exp, res, "ft_puts");
		i++;
	}
	return (0);
}

int	test_strlen(void)
{
	char *array[] = {
		NULL,
		"",
		"\n",
		"Hello",
		"qwertyuiopasdfghjklzxcvbnm"
	};
	int	i = 0;

	while (i < 5)
	{
		if ((!i && ft_strlen(array[i]))
			|| (i != 0 && ft_strlen(array[i]) != strlen(array[i])))
		{
			print_error_zu(strlen(array[i]), ft_strlen(array[i]), "ft_strlen");
			return (1);
		}
		i++;
	}
	print_success("ft_strlen");
	return (0);
}

int	test_memset(void)
{
	char str[10];

	ft_memset(str, '\0', 10);
	ft_memset(str, 'a', 5);
	if (strcmp(str, "aaaaa"))
		print_error_s("aaaaa", str, "ft_memset");
	else
		print_success("ft_memset");
	return (0);
}

int	test_memcpy(void)
{
	char str[10];
	char to_cpy[5] = "Cooll";

	memset(str, '\0', 10);
	ft_memcpy(str, to_cpy, 4);
	if (strcmp(str, "Cool"))
		print_error_s("Cool", str, "ft_memcpy");
	else
		print_success("ft_memcpy");
	return (0);
}

int	test_strdup(void)
{
	char	*str;
	char	*to_dup[] = {
		NULL,
		"",
		"\n\n\nNewline overflow\n\n\n",
		"Did the test passed ?"
	};
	int		i;
	int		passed;

	i = 0;
	passed = 1;
	while (i < 4)
	{
		str = ft_strdup(to_dup[i]);
		if ((!i && str) || (i != 0 && strcmp(str, to_dup[i])))
		{
			print_error_s(to_dup[i], str, "ft_strdup");
			passed = 0;
		}
		if (str)
			free(str);
		i++;
	}
	if (passed)
		print_success("ft_strdup");
	return (0);
}

int	test_cat(char *file)
{
	int	filefd;

	if ((filefd = open(file, O_RDONLY)) == -1)
		return (1);
	ft_cat(filefd);
	if (close(filefd) == -1)
		return (1);
	ft_cat(-1);
//	ft_cat(0);
	return (0);
}

int	main(void)
{
	test_bzero();
	test_strcat();
	test_isfn(ft_isalpha, isalpha, "ft_isalpha");
	test_isfn(ft_isdigit, isdigit, "ft_isdigit");
	test_isfn(ft_isalnum, isalnum, "ft_isalnum");
	test_isfn(ft_isascii, isascii, "ft_isascii");
	test_isfn(ft_isprint, isprint, "ft_isprint");
	test_isfn(ft_tolower, tolower, "ft_tolower");
	test_isfn(ft_toupper, toupper, "ft_toupper");

	test_puts();
	test_strlen();
	test_memset();
	test_memcpy();
	test_strdup();
	test_cat(__FILE__);
	return (0);
}
