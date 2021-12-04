/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:37:16 by tshigena          #+#    #+#             */
/*   Updated: 2021/12/01 14:36:56 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(const char *str, size_t *i);
static int	insert_to_str(const char str, long *number);

int	ft_atoi_simple(const char *str)
{
	size_t	i;
	int		minus_flag;
	int		checknum;
	long	number;

	i = 0;
	minus_flag = check_sign(str, &i);
	number = 0;
	while (str[i] != '\0')
	{
		checknum = insert_to_str(str[i], &number);
		if (checknum == 0)
			break ;
		if (checknum == -1)
		{
			if (number * minus_flag == INT_MIN)
				return (INT_MIN);
			return (0);
		}
		i++;
	}
	number *= minus_flag;
	return ((int)number);
}

static int	insert_to_str(const char str, long *number)
{
	if (ft_isdigit(str))
	{
		*number = (*number * 10) + (str - '0');
		if (*number - INT_MAX > 0)
			return (-1);
		return (1);
	}
	return (0);
}

static int	check_sign(const char *str, size_t *i)
{
	int	minus_flag;

	minus_flag = 1;
	if (str[*i] != '-')
		return (minus_flag);
	else
		minus_flag *= -1;
	*i += 1;
	return (minus_flag);
}
