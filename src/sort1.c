/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:43:24 by tshigena          #+#    #+#             */
/*   Updated: 2021/12/01 01:36:42 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_and_sort_from_small(t_struct *data, int flag)
{
	int	*a_stack;

	a_stack = data->a.stack;
	while (a_stack[data->a.size - 1] > data->b.stack[0] && data->ra_count > 0)
	{
		ft_reverse_rotate(data, 'a', TRUE);
		data->ra_count -= 1;
	}
	while (a_stack[1] < data->b.stack[0]
		&& (a_stack[1] > data->s.stack[2] || flag))
	{
		ft_rotate(data, 'a', TRUE);
		data->ra_count += 1;
	}
	ft_push(data, 'a', TRUE);
	if (a_stack[1] < a_stack[0]
		 && (a_stack[1] != data->s.stack[0] || flag))
		ft_swap(data, 'a', TRUE);
}

void	sort_half_of_block(t_struct *data, int standard, int flag)
{
	if (data->b.stack[0] > standard)
	{
		if (is_rr_from_b(data) == FALSE)
			ft_rotate(data, 'b', TRUE);
		data->rb_count += 1;
	}
	else
	{
		ra_minimum_numbers(data);
		pb_and_sort_from_small(data, flag);
	}
}

void	push_small_2block_to_bottom_of_a(t_struct *data, int d)
{
	while (data->b.size > data->middle_index - data->index_1_8)
		sort_half_of_block(data, data->s.stack[data->index_1_8 - 1], 1);
	ra_minimum_numbers(data);
	while (data->b.size > data->middle_index - data->index_1_4)
	{
		while (data->rb_count)
		{
			if (data->b.stack[0] >= data->s.stack[data->index_1_4])
				ft_reverse_rotate(data, 'b', TRUE);
			else if (data->b.stack[data->b.size - 1] > data->b.stack[0])
				ft_reverse_rotate(data, 'b', TRUE);
			else
				break ;
			data->rb_count--;
		}
		pb_and_sort_from_small(data, 1);
		ra_minimum_numbers(data);
	}
	push_1block_to_bottom_of_a(data, d);
}

void	push_1block_to_bottom_of_a(t_struct *data, int d)
{
	int	b_size;
	int	base;
	int	i;

	i = 0;
	while (i < (d * 2) - 1 && d != 0)
	{
		b_size = data->b.size;
		if (b_size <= data->index_1_8 / d)
			break ;
		base = data->s.stack[data->sorted_index - 1 + data->index_1_8 / d];
		while (data->b.size > b_size - data->index_1_8 / d)
			sort_half_of_block(data, base, 0);
		ra_minimum_numbers(data);
		i++;
	}
	while (data->b.size != 0)
	{
		pb_and_sort_from_small(data, 0);
		ra_minimum_numbers(data);
	}
}

void	split_to_4block_by_size(t_struct *data)
{
	while (data->a.size != data->total_size - data->index_3_4)
	{
		if (data->a.stack[0] < data->s.stack[data->index_3_4])
		{
			ft_push(data, 'b', TRUE);
			is_rr_from_a(data);
		}
		else
			ft_rotate(data, 'a', TRUE);
	}
	while (data->b.stack[0] >= data->s.stack[data->index_1_4])
	{
		if (data->b.stack[0] >= data->middle_num)
		{
			ft_push(data, 'a', TRUE);
		}
		else if (data->b.stack[0] >= data->s.stack[data->index_1_4])
		{
			ft_rotate(data, 'b', TRUE);
		}
	}
}
