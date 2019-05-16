/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:01:17 by pchadeni          #+#    #+#             */
/*   Updated: 2019/05/16 11:59:57 by pchadeni         ###   ########.fr       */
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
	char str[42];
	char tmp[42];
	char *to_cpy[] = {
		"Cooll",
		"",
		"Martine fait du bateau",
		"Martine fait du bateau",
		"Toto avec Martine"
	};
	size_t	len[] = {
		4,
		1,
		22,
		15,
		17
	};
	int	nb = sizeof(to_cpy) / sizeof(to_cpy[0]);
	int	i = 0;
	int	error = 0;

	while(i < nb)
	{
		memset(str, '\0', 42);
		memset(tmp, '\0', 42);
		ft_memcpy(str, to_cpy[i], len[i]);
		memcpy(tmp, to_cpy[i], len[i]);
		if (strcmp(str, tmp))
		{
			print_error_s(tmp, str, "ft_memcpy");
			error = 1;
		}
		i++;
	}
	if (!error)
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

int	test_cat(void)
{
	int	output;
	int	input;
	int out = dup(1);

	if ((output = open("./cat_to_diff", O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
		return (1);
	if ((input = open("./srcs/ft_cat.s", O_RDONLY)) == -1)
		return (1);

	dup2(output, 1);
	ft_cat(input);
	if (close(output) == -1)
		return (1);
	if (close(input) == -1)
		return (1);
	dup2(out, 1);
	if (system("diff ./cat_to_diff ./srcs/ft_cat.s"))
		printf("Error on ft_cat\n");
	else
		print_success("ft_cats");
	system("rm -rf ./cat_to_diff");
	
	return (0);
}

int	test_puts(int fd)
{
	char	*array[] = {
		NULL,
		"",
		"Martine a la plage",
		"\n\t\0\t",
		"Martine a la montagne",
		" Martine avec des	tabulations		"
	};
	char	buf[2048];
	int		nb = sizeof(array) / sizeof(array[0]);
	size_t	len;

	while (nb != 0)
	{
		len = ft_strlen(array[nb - 1]);
		ft_puts(array[nb - 1]);
		if (read(fd, buf, len + 1) != -1)
		{
			if (strncmp(array[nb - 1], buf, len))
				return (1);
		}
		nb--;
	}
	return (0);
}

int	test_putchar(int fd)
{
	char	buf[1];
	int		i = -128;
	int		res;
	
	while (i < 127)
	{
		res = ft_putchar(i);
		if (read(fd, buf, 1) != -1)
		{
			if (i != buf[0])
				return (1);
		}
		i++;
	}
	return (0);
}

int	write_on_fd(int (*f)(int), char *f_name)
{
	int	fds[2];
	int	out;
	int	res;

	if ((out = dup(1)) == -1)
	{
		printf("Error: cannot duplicate stdout\n");
		return (1);
	}
	if (pipe(fds) == -1)
	{
		printf("Error: cannot create pipe\n");
		return (1);
	}
	if ((dup2(fds[1], 1)) == -1)
	{
		printf("Error: cannot duplicate writing fd\n");
		return (1);
	}
	res = (*f)(fds[0]);
	if (close(fds[0]) == -1 || close(fds[1]) == -1)
	{
		printf("Error: cannot close fd\n");
		return (1);
	}
	if ((dup2(out, 1)) == -1)
	{
		printf("Error: cannot duplicate old stdout\n");
		return (1);
	}
	if (res)
		printf("Error in %s\n", f_name);
	else
		print_success(f_name);
	return (0);
}

int	test_atoi(void)
{
	char *numbers[] = {
		"",
		"123",
		"-123",
		"+345",
		" 3-45",
		"    3 -45",
		" +   3 -45",
		" -   3 -45",
		"    -3 -45",
		"    +-3 -45",
		"+3-45",
		"--234",
		"+-345"
	};
	int	len;
	int	i = 0;
	int	exp;
	int	res;
	int	error;

	len = sizeof(numbers) / sizeof(numbers[0]);
	error = 0;
	while (i < len)
	{
		res = ft_atoi(numbers[i]);
		exp = atoi(numbers[i]);
		if (res != exp && (error = 1))
			print_error_i(exp, res, "ft_atoi");
		i++;
	}
	if (!error)
		print_success("ft_atoi");
	return (0);
}

int	test_pow_int(void)
{
	double	numbers[] = {
		123,
		321,
		0,
		5002,
		-1,
		404,
		-25
	};
	double	powers[] = {
		2,
		3,
		4,
		2,
		3,
		0,
		5
	};
	int n = sizeof(numbers) / sizeof(numbers[0]);
	int	i = 0;
	int	exp;
	int	res;
	int	error = 0;

	while (i < n)
	{
		res = ft_pow_int(numbers[i], powers[i]);
		exp = (int)pow(numbers[i], powers[i]);
		if (res != exp)
		{
			print_error_i(exp, res, "ft_pow_int");
			error = 1;
		}
		i++;
	}
	if (!error)
		print_success("ft_pow_int");
	return (0);
}

int	test_memcmp(void)
{
	char *a1[] = {
		"abc",
		"",
		"not",
		"\n",
		"\0",
		"Equal till now"
	};
	char *a2[] = {
		"abc",
		"",
		"equal",
		"\n",
		"\0",
		"Equal till here"
	};
	size_t	len[] = {
		3,
		1,
		3,
		1,
		1,
		12
	};
	int	nb = sizeof(a1) / sizeof(a1[0]);
	int	i = 0;
	int	exp;
	int	res;
	int error = 0;

	while (i < nb)
	{
		exp = memcmp(a1[i], a2[i], len[i]);
		res = ft_memcmp(a1[i], a2[i], len[i]);
		if (exp != res)
		{
			print_error_i(exp, res, "ft_memcmp");
			error = 1;
		}
		i++;
	}
	if (!error)
		print_success("ft_memcmp");
	return (0);
}

int	test_memccpy(void)
{
	char str[42];
	char tmp[42];
	char *to_cpy[] = {
		"Cooll",
		"",
		"Martine fait du bateau",
		"Martine fait du bateau",
		"Toto avec Martine",
		"Toto qui fait memccpy",
		"Toto qui fait memccpy deux fois"
	};
	size_t	len[] = {
		4,
		1,
		22,
		15,
		17,
		15,
		15
	};
	char	delim[] = {
		'o',
		'a',
		'f',
		'x',
		'M',
		't',
		'T'
	};
	int	nb = sizeof(to_cpy) / sizeof(to_cpy[0]);
	int	i = 0;
	int	error = 0;

	while(i < nb)
	{
		memset(str, '\0', 42);
		memset(tmp, '\0', 42);
		ft_memccpy(str, to_cpy[i], delim[i], len[i]);
		memccpy(tmp, to_cpy[i], delim[i], len[i]);
		if (strcmp(str, tmp))
		{
			print_error_s(tmp, str, "ft_memccpy");
			error = 1;
		}
		i++;
	}
	if (!error)
		print_success("ft_memccpy");
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

	write_on_fd(test_puts, "ft_puts");
	test_strlen();
	test_memset();
	test_memcpy();
	test_strdup();
	test_cat();
  printf("------------------Bonus------------------\n");
	write_on_fd(test_putchar, "ft_putchar");
	test_atoi();
	test_pow_int();
	test_memcmp();
	test_isfn(ft_isupper, isupper, "ft_isupper");
	test_isfn(ft_islower, islower, "ft_islower");
	test_memccpy();
	test_isfn(ft_isblank, isblank, "ft_isblank");
	test_isfn(ft_isspace, isspace, "ft_isspace");
	return (0);
}
