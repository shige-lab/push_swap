/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num_dx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:29:46 by tshigena          #+#    #+#             */
/*   Updated: 2021/12/01 13:46:01 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nummber_of_digits(unsigned long long n, int base);
static void	put_num(unsigned long long n, int base, int x);

size_t	put_num_dx(unsigned long long n, int base, int x)
{
	put_num(n, base, x);
	return (nummber_of_digits(n, base));
}

static int	nummber_of_digits(unsigned long long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n = n / base;
	}
	return (i);
}

static void	put_num(unsigned long long n, int base, int x)
{
	int		first_num;
	char	c;

	c = 0;
	first_num = n % base;
	n = n / base;
	if (n > 0)
		put_num_dx(n, base, x);
	if (0 <= first_num && first_num <= 9)
		c = '0' + first_num;
	else if (first_num > 9)
	{
		if (x == 'X')
			c = 'A' + (first_num - 10);
		else
			c = 'a' + (first_num - 10);
	}
	write(1, &c, 1);
}
