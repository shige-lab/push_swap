/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:43:24 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/22 00:56:30 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


// void	push_a_from_min(t_struct *data, int i)
// {
// 	while (data->b.size != 0)
// 	{
// 		if (data->b.stack[data->b.size - 1] == data->s.stack[i])
// 			ft_reverse_rotate(data, 'b', TRUE);
// 		if (data->b.stack[0] == data->s.stack[i])
// 		{
// 			ft_push(data, 'a');
// 			ft_rotate(data, 'a', TRUE);
// 			i++;
// 		}
// 		else
// 			ft_rotate(data, 'b', TRUE);
// 	}
// }

void	get_b_mini_index(t_struct *data, int b_min)
{
	int i;

	i = 0;
	while (i < data->b.size)
	{
		if (data->b.stack[i] == data->s.stack[b_min])
		{
			data->b.min_index = i;
			break ;
		}
		i++;
	}

}

t_bool	is_rr(t_struct *data)
{
	if (data->a.stack[1] > data->b.stack[0] && data->b.size != 0)
		return (FALSE);
	ft_ss_rr_rrr(data, "rr");
	return (TRUE);
}
void	is_rr_from_a(t_struct *data)
{
	if (!(data->a.stack[0] < data->middle_num))
	{
		if (data->b.stack[0] != data->s.stack[0])
		{
			// printf("2\n");
			ft_ss_rr_rrr(data, "rr");
		}
		else
			ft_rotate(data, 'a', TRUE);
	}
}

void	push_a_from_min(t_struct *data, int i)
{
	int	a_top;

	a_top = data->a.stack[0];
	get_b_mini_index(data, i);
	while (data->b.size != 0 || a_top != data->a.stack[0])
	{
		if (data->b.stack[0] == data->s.stack[i])
		{
			ft_push(data, 'a');
			if (is_rr(data) == FALSE)
				ft_rotate(data, 'a', TRUE);
			i++;
		}
		if (data->a.stack[0] == data->s.stack[i])
		{
			if (is_rr(data) == FALSE)
				ft_rotate(data, 'a', TRUE);
			i++;
		}
		if (data->a.stack[0] > data->b.stack[0] && data->b.size != 0)
		{
			ft_push(data, 'a');
		}
		else if (data->a.stack[1] > data->b.stack[0] && data->b.size != 0)
		{
			// printf("1\n");
			ft_push(data, 'a');
			ft_swap(data, 'a', TRUE);
		}
		else
			ft_rotate(data, 'b', TRUE);
	}
}