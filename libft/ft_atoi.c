/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:37:16 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/24 17:47:02 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

static void	check_space(const char *str, size_t *i);
static int	check_sign(const char *str, size_t *i);
static int	insert_to_str(const char str, long *number);

int	ft_atoi(const char *str)
{
	size_t	i;
	int		minus_flag;
	int		checknum;
	long	number;

	i = 0;
	check_space(str, &i);
	minus_flag = check_sign(str, &i);
	number = 0;
	while (str[i] != '\0')
	{
		checknum = insert_to_str(str[i], &number);
		if (checknum == 0)
			return (0);
		i++;
	}
	number *= minus_flag;
	return ((int)number);
}

static int	insert_to_str(const char str, long *number)
{
	if (ft_isdigit(str))
	{
		if ((*number * 10) + (str - '0') > INT_MAX)
			return (0);
		else
			*number = (*number * 10) + (str - '0');
		return (1);
	}
	return (0);
}

static void	check_space(const char *str, size_t *i)
{
	while (str[*i] != '\0')
	{
		if (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v'
			|| str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
			*i += 1;
		else
			return ;
	}
}

static int	check_sign(const char *str, size_t *i)
{
	int	minus_flag;

	minus_flag = 1;
	if (str[*i] != '-' && str[*i] != '+')
		return (minus_flag);
	else if (str[*i] == '-')
		minus_flag *= -1;
	*i += 1;
	return (minus_flag);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%d\n", ft_atoi("111111111111111"));
// 	return 0;
// }