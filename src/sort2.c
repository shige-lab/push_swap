/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:38:49 by tshigena          #+#    #+#             */
/*   Updated: 2021/12/10 17:10:36 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_to_4block_by_size_for_over_300(t_struct *data)
{
	while (data->a.size != data->total_size - data->index_3_4)
	{
		if (data->a.stack[0] < data->s.stack[data->index_3_4])
		{
			ft_push(data, 'b', TRUE);
			rb_2nd_smallest_block_or_rr_if_possible(data);
		}
		else
			ft_rotate(data, 'a', TRUE);
	}
	while (data->b.stack[0] < data->s.stack[data->index_1_4] \
			|| data->b.stack[0] >= data->middle_num)
	{
		if (data->b.stack[0] >= data->middle_num)
		{
			ft_push(data, 'a', TRUE);
		}
		else if (data->b.stack[0] < data->s.stack[data->index_1_4])
		{
			ft_rotate(data, 'b', TRUE);
		}
	}
	while (data->b.stack[0] >= data->s.stack[data->index_1_4])
		ft_push(data, 'a', TRUE);
}

void	push_quater_to_b(t_struct *data)
{
	if (data->a.stack[0] == data->s.stack[data->sorted_index])
	{
		ft_rotate(data, 'a', TRUE);
		data->sorted_index++;
	}
	else
		ft_push(data, 'b', TRUE);
}

t_bool	is_rr_from_b(t_struct *data)
{
	if (data->a.stack[0] == data->s.stack[data->sorted_index])
	{
		ft_ss_rr_rrr(data, "rr", TRUE);
		data->sorted_index++;
		return (TRUE);
	}
	return (FALSE);
}

void	rb_2nd_smallest_block_or_rr_if_possible(t_struct *data)
{
	if (data->b.stack[0] >= data->s.stack[data->index_1_4] \
			&& data->b.stack[0] < data->middle_num)
	{
		if (!(data->a.stack[0] < data->index_3_4))
		{
			ft_ss_rr_rrr(data, "rr", TRUE);
		}
		else
			ft_rotate(data, 'b', TRUE);
	}
}

void	rb_smallest_block_or_rr_if_possible(t_struct *data)
{
	if (data->b.stack[0] < data->s.stack[data->index_1_4])
	{
		if (!(data->a.stack[0] < data->index_3_4))
		{
			ft_ss_rr_rrr(data, "rr", TRUE);
		}
		else
			ft_rotate(data, 'b', TRUE);
	}
}
