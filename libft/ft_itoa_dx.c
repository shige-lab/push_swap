/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_dx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:29:46 by tshigena          #+#    #+#             */
/*   Updated: 2021/12/01 14:11:16 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*add_char(char *dest, const char c);
static int	nummber_of_digits(unsigned long long n, int base);
static void	int_to_str(unsigned long long n, char *str_num, int base);

char	*ft_itoa_dx(unsigned long long n, int base)
{
	char	*str_num;

	str_num = (char *)ft_calloc(nummber_of_digits(n, base) + 1, sizeof(char));
	if (!str_num)
		return (NULL);
	int_to_str(n, str_num, base);
	return (str_num);
}

static int	nummber_of_digits(unsigned long long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		i++;
		n = n / base;
	}
	return (i);
}

static void	int_to_str(unsigned long long n, char *str_num, int base)
{
	int		last_num;
	char	c;

	c = 0;
	if (n < 0)
		n *= -1;
	last_num = n % base;
	n = n / base;
	if (n > 0)
		int_to_str(n, str_num, base);
	if (0 <= last_num && last_num <= 9)
		c = '0' + last_num;
	else if (last_num > 9)
		c = 'a' + (last_num - 10);
	str_num = add_char(str_num, c);
}

static char	*add_char(char *dest, const char c)
{
	unsigned long long	i;

	i = ft_strlen(dest);
	if (c != '\0')
	{
		dest[i] = c;
		dest[++i] = '\0';
	}
	return (dest);
}
