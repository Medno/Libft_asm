/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:01:17 by pchadeni          #+#    #+#             */
/*   Updated: 2019/05/14 15:32:51 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

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

int	test_isfn(int (*f)(int), int (*real)(int), char *f_name)
{
	int	i;

	i = -127;
	while (i != 255)
	{
		if ((*f)(i) != (*real)(i))
		{
			printf("%sError%s in %s%s%s function for index %d. Expected : %d, Get: %d\n",
			RED, EOC, BOLD, f_name, EOC, i, (*real)(i), (*f)(i));
			return (1);
		}
		i++;
	}
	printf("%s%s%s tests passed with %ssuccess%s\n", BOLD, f_name, EOC, GREEN, EOC);
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
		if (i != 0 && ft_strlen(array[i]) != strlen(array[i]))
		{
			printf("%sError%s in %s%s%s function for index %d. Expected : %zu, Get: %zu\n",
			RED, EOC, BOLD, "ft_strlen", EOC, i, strlen(array[i]), ft_strlen(array[i]));
			printf("Str: |%s|\n", array[i]);
			printf("len: |%zu|\n", ft_strlen(array[i]));
			printf("len: |%zu|\n", ft_strlen(array[i]));
			printf("len: |%zu|\n", strlen(array[i]));
			return (1);
		}
		i++;
	}
	printf("%s%s%s tests passed with %ssuccess%s\n", BOLD, "ft_strlen", EOC, GREEN, EOC);
	return (0);
}

int	test_bzero(void)
{
	char *str = strdup("I'm not null");
	char buf[6] = "*****";

	printf("Bzero of size 0: |%s|\n", str);
	ft_bzero(buf, 5);
	write(1, buf, 5);
	printf("Bzero incoming...\n");
	ft_bzero(str, 5);
	printf("Bzero exited\n");
	write(1, str, strlen(str));
	printf("%s%s%s tests passed with %ssuccess%s\n", BOLD, "ft_bzero", EOC, GREEN, EOC);
	return (0);
}

int	test_puts(void)
{
	printf("Value of puts: %d\n", puts(NULL));
	printf("Value of puts: %d\n", puts(""));
	printf("Value of puts: %d\n", puts("toto a la plage"));
	printf("Value of puts: %d\n", puts("toto"));
	printf("Value of puts: %d\n", puts("toto a la mer"));
	ft_puts(NULL);
	ft_puts("");
	printf("Value of ft_puts: %d\n", ft_puts("toto a la plage"));
	printf("Value of ft_puts: %d\n", ft_puts("toto a la mer"));
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
		printf("%sError%s in %s%s%s function. Expected : %s, Get: %s\n",
		RED, EOC, BOLD, "ft_strcat", EOC, "123459870", str);
	else
		printf("%s%s%s tests passed with %ssuccess%s\n",
			BOLD, "ft_strcat", EOC, GREEN, EOC);

	return (0);
}

int	test_memset(void)
{
	char str[10];

	ft_memset(str, '\0', 10);
	ft_memset(str, 'a', 5);
	printf("Memset: |%s|\n", str);
	if (strcmp(str, "aaaaa"))
		printf("%sError%s in %s%s%s function. Expected : %s, Get: %s\n",
		RED, EOC, BOLD, "ft_memset", EOC, "aaaaa", str);
	else
		printf("%s%s%s tests passed with %ssuccess%s\n",
			BOLD, "ft_memset", EOC, GREEN, EOC);
	return (0);
}

int	test_memcpy(void)
{
	char str[10];
	char to_cpy[5] = "Cooll";

	ft_memset(str, '\0', 10);
	ft_memcpy(str, to_cpy, 4);
	printf("Memcpy: |%s|\n", str);
	if (strcmp(str, "Cool"))
		printf("%sError%s in %s%s%s function. Expected : %s, Get: %s\n",
		RED, EOC, BOLD, "ft_memcpy", EOC, "Cool", str);
	else
		printf("%s%s%s tests passed with %ssuccess%s\n",
			BOLD, "ft_memcpy", EOC, GREEN, EOC);
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
	test_puts();
	test_strcat();
	test_memset();
	test_memcpy();
	return (0);
}
