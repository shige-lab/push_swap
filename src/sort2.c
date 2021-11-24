/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:43:24 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/24 20:34:29 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	is_rr(t_struct *data)
{
	if (data->a.stack[0] == data->s.stack[data->sorted_index])
	{
			ft_ss_rr_rrr(data, "rr");
			data->sorted_index++;
			return (TRUE);
	}
	return (FALSE);
}

void	is_rr_from_a(t_struct *data)
{
	if (data->b.stack[0] < data->s.stack[data->index_1_4])
	{
		if (!(data->a.stack[0] < data->index_3_4))
		{
			ft_ss_rr_rrr(data, "rr");
		}
		else
			ft_rotate(data, 'b', TRUE);
	}
}

void	ra_minimum_numbers(t_struct *data)
{
	while (data->a.stack[0] == data->s.stack[data->sorted_index])
	{
		ft_rotate(data, 'a', TRUE);
		data->sorted_index++;
	}
}

void	pb_and_sort_from_small(t_struct *data, int *count, int flag)
{
	while (data->a.stack[data->a.size - 1] > data->b.stack[0] && *count > 0)
	{
		ft_reverse_rotate(data, 'a', TRUE);
		*count-= 1;
	}
	while (data->a.stack[1] < data->b.stack[0]
		 &&( data->a.stack[1] > data->s.stack[2] || flag))
	{
		ft_rotate(data, 'a', TRUE);
		*count+= 1;
	}
	ft_push(data, 'a');
	if (data->a.stack[1] < data->a.stack[0]
		 && (data->a.stack[1] != data->s.stack[0] || flag))
		ft_swap(data, 'a', TRUE);
}

void	sort_half_of_block(t_struct *data, int *ra_count, int *rb_count, int base)
{
	if (data->b.stack[0] >= data->s.stack[base - data->index_1_8])
	
	{
		if (is_rr(data) == FALSE)
			ft_rotate(data, 'b', TRUE);
		*rb_count+= 1;
	}
	else
	{
		ra_minimum_numbers(data);
		if (base == data->index_1_4)
			pb_and_sort_from_small(data, &*ra_count, 1);
		else
			pb_and_sort_from_small(data, &*ra_count, 0);
	}
}

void	push_small_2block_to_bottom_of_a(t_struct *data)
{
	int	ra_count;
	int	rb_count;

	ra_count = 0;
	rb_count = 0;
	while (data->b.size != data->middle_index / 2 + data->index_1_8)
		sort_half_of_block(data, &ra_count, &rb_count, data->index_1_4);
	ra_minimum_numbers(data);
	while (data->b.size >= data->index_1_4)
	{
		while (rb_count)
		{
			if (data->b.stack[0] >= data->s.stack[data->index_1_4])
				ft_reverse_rotate(data, 'b', TRUE);
			else if (data->b.stack[data->b.size - 1] > data->b.stack[0])
				ft_reverse_rotate(data, 'b', TRUE);
			else
				break;
			rb_count--;
		}
		pb_and_sort_from_small(data, &ra_count, 1);
		ra_minimum_numbers(data);
	}
	push_small_1block_to_bottom_of_a(data, data->middle_index);
}
 
void	push_small_1block_to_bottom_of_a(t_struct *data, int base)
{
	int	ra_count;
	int	rb_count;
	int	i;

	i = 0;
	ra_count = 0;
	rb_count = 0;
	while (data->b.size != data->index_1_8)
		sort_half_of_block(data, &ra_count, &rb_count, base);
	ra_minimum_numbers(data);
	while (data->b.size > 0)
	{
		pb_and_sort_from_small(data, &ra_count, 0);
		ra_minimum_numbers(data);
	}
}

void	split_to_4block_by_size(t_struct *data)
{
	while (data->a.size != data->total_size - data->index_3_4)
	{
		if (data->a.stack[0] < data->s.stack[data->index_3_4])
		{
			ft_push(data, 'b');
			is_rr_from_a(data);
		}
		else
			ft_rotate(data, 'a', TRUE);
	}
	while (data->b.stack[0] >= data->s.stack[data->index_1_4])
	{
		if (data->b.stack[0] >= data->middle_num)
		{
			ft_push(data, 'a');
		}
		else if (data->b.stack[0] >= data->s.stack[data->index_1_4])
		{
			ft_rotate(data, 'b', TRUE);
		}
	}
}

void	push_quater_to_b(t_struct *data)
{
	if (data->a.stack[0] == data->s.stack[data->sorted_index])
		{
			ft_rotate(data, 'a', TRUE);
			data->sorted_index++;
		}
		else
			ft_push(data, 'b');
}
