/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:48:06 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/30 19:09:05 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_location_p(int *data, int data_size, int insert, int p)
{
	int	i;

	if (data == NULL)
		return ;
	i = data_size;
	while (i > p)
	{
		data[i] = data[i - 1];
		i--;
	}
	data[i] = insert;
}

t_bool	sort_s(t_struct *data, int number, int number_location)
{
	int	i;

	i = 0;
	if (number_location == 0)
	{
		data->s.stack[0] = number;
		return (TRUE);
	}
	while (i < number_location)
	{
		if (data->s.stack[i] == number)
			return (FALSE);
		if (data->s.stack[i] < number)
			i++;
		else
		{
			ft_push_location_p(data->s.stack, number_location, number, i);
			return (TRUE);
		}
	}
	data->s.stack[i] = number;
	return (TRUE);
}
