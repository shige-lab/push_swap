/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:48:06 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/30 19:08:13 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// static int	front_correct_position(t_struct *data)
// {
// 	int	i;

// 	i = 0;
// 	while (data->a.stack[0] > data->a.stack[i + 1])
// 		i++;
// 	return (i);
// }

// void	sort_a_front(t_struct *data)
// {
// 	int	front_location;

// 	if (data->a.stack[0] == data->max_num)
// 	{
// 		ft_rotate(data, 'a', TRUE);
// 		return ;
// 	}
// 	front_location = front_correct_position(data);
// 	if (front_location == 1)
// 		ft_swap(data, 'a', TRUE);
// 	else if (front_location == 2)
// 	{
// 		ft_swap(data, 'a', TRUE);
// 		ft_rotate(data, 'a', TRUE);
// 		ft_swap(data, 'a', TRUE);
// 		ft_reverse_rotate(data, 'a', TRUE);
// 	}
// 	else if (front_location == 3)
// 	{
// 		ft_reverse_rotate(data, 'a', TRUE);
// 		ft_swap(data, 'a', TRUE);
// 		ft_rotate(data, 'a', TRUE);
// 		ft_rotate(data, 'a', TRUE);
// 	}
// }

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
