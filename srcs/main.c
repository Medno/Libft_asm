/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:01:17 by pchadeni          #+#    #+#             */
/*   Updated: 2019/05/13 17:51:07 by pchadeni         ###   ########.fr       */
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
		if (ft_strlen(array[i]) == 1000)
		{
			printf("%sError%s in %s%s%s function for index %d. Expected : %zu, Get: %zu\n",
			RED, EOC, BOLD, "ft_strlen", EOC, i, strlen(array[i]), ft_strlen(array[i]));
			return (1);
		}
		i++;
	}
	printf("%s%s%s tests passed with %ssuccess%s\n", BOLD, "ft_strlen", EOC, GREEN, EOC);
	return (0);
}

int	test_bzero(void)
{
	char *str = "I'm not null";

	ft_bzero(NULL, 10);
	ft_bzero(str, 0);
	printf("Bzero of size 0: |%s|\n", str);
	printf("Bzero incoming...\n");
	ft_bzero(str, 5);
	printf("Bzero exited\n");
	write(1, str, strlen(str));
	printf("\n");
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
	return (0);
}
