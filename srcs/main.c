/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:01:17 by pchadeni          #+#    #+#             */
/*   Updated: 2019/05/15 14:32:12 by pchadeni         ###   ########.fr       */
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
	char	*str = strdup("I'm not null");
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
	printf("str: %s\n", str);
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
/*
int	test_puts(void)
{
	int		i = 0;
	char	*to_display = {
		NULL,
		"",
		"Martine a la plage",
		"Martine fait du ski",
		"Martine voyage"
	}
	while (i < 5)
	{
		printf("Value of puts: %d\n");
	}
	printf("Value of puts: %d\n", puts(NULL));
	printf("Value of puts: %d\n", puts(""));
	printf("Value of puts: %d\n", puts("toto a la plage"));
	printf("Value of puts: %d\n", puts("toto"));
	printf("Value of puts: %d\n", puts("toto a la mer"));
	printf("Value of ft_puts: %d\n", ft_puts(NULL));
	printf("Value of ft_puts: %d\n", ft_puts(""));
	printf("Value of ft_puts: %d\n", ft_puts("toto a la plage"));
	printf("Value of ft_puts: %d\n", ft_puts("toto a la montagne"));
	return (0);
}
*/
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
	printf("Memset: |%s|\n", str);
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
	printf("Memcpy: |%s|\n", str);
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

int	main(void)
{
	test_isfn(ft_isalpha, isalpha, "ft_isalpha");
	test_isfn(ft_isdigit, isdigit, "ft_isdigit");
	test_isfn(ft_isalnum, isalnum, "ft_isalnum");
	test_isfn(ft_isascii, isascii, "ft_isascii");
	test_isfn(ft_isprint, isprint, "ft_isprint");
	test_isfn(ft_tolower, tolower, "ft_tolower");
	test_isfn(ft_toupper, toupper, "ft_toupper");

	test_bzero();
	test_strlen();
//	test_puts();
	test_strcat();
	test_memset();
	test_memcpy();
	//test_strdup();
	test_cat();
	write_on_fd(test_puts, "ft_puts");
	write_on_fd(test_putchar, "ft_putchar");
	test_atoi();
	return (0);
}
