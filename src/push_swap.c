/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:20:31 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/26 20:59:38 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_3(t_struct *data)
{
	int		*a_stack;
	int		max;
	int		min;

	a_stack = data->a.stack;
	max = data->s.stack[data->total_size - 1];
	min = data->s.stack[data->b.size];
	if (a_stack[1] == min && a_stack[2] == max)
		ft_swap(data, 'a', TRUE);
	else if (a_stack[2] == min && a_stack[0] == max)
	{
		ft_swap(data, 'a', TRUE);
		ft_reverse_rotate(data, 'a', TRUE);
	}
	else if (a_stack[1] == min && a_stack[0] == max)
		ft_rotate(data, 'a', TRUE);
	else if (a_stack[0] == min && a_stack[1] == max)
	{
		ft_swap(data, 'a', TRUE);
		ft_rotate(data, 'a', TRUE);
	}
	else if (a_stack[2] == min && a_stack[1] == max)
		ft_reverse_rotate(data, 'a', TRUE);
}

void	push_swap_3_reverse(t_struct *data)
{
	int		*b_stack;
	int		b_max;

	b_stack = data->b.stack;
	b_max = data->s.stack[2];
	if (b_max == b_stack[2])
	{
		ft_reverse_rotate(data, 'b', TRUE);
		ft_push(data, 'a');
	}
	else if (b_max == b_stack[1])
	{
		ft_swap(data, 'b', TRUE);
		ft_push(data, 'a');
	}
	else
		ft_push(data, 'a');
	ft_push(data, 'a');
}

void	push_swap_under_6(t_struct *data)
{
	int	a_stack_min;

	a_stack_min = data->s.stack[data->total_size - 3];
	while (data->a.size != 3)
	{
		if (data->a.stack[data->a.size - 1] < a_stack_min)
			ft_reverse_rotate(data, 'a', TRUE);
		if (data->a.stack[0] < a_stack_min)
		{
			ft_push(data, 'b');
			if (data->b.stack[0] < data->b.stack[1] && data->b.size != 1)
				ft_swap(data, 'b', TRUE);
		}
		else
			ft_rotate(data, 'a', TRUE);
	}
	push_swap_3(data);
	while (data->b.size)
		ft_push(data, 'a');
	if (data->a.stack[0] > data->a.stack[1])
		ft_swap(data, 'a', TRUE);
}

void	push_swap_over_7(t_struct *data)
{
	int	 denominator;

	if (data->total_size >= 300)
		denominator = 3;
	else if (data->total_size >= 100)
		denominator = 2;
	else
		denominator = 1;
	split_to_4block_by_size(data);
	push_small_2block_to_bottom_of_a(data, denominator);
	while (data->a.stack[0] < data->s.stack[data->index_3_4])
	{
		push_quater_to_b(data);
	}
	push_small_1block_to_bottom_of_a(data, denominator);
	while (data->a.stack[0] != data->s.stack[0])
		push_quater_to_b(data);
	push_small_1block_to_bottom_of_a(data, denominator);
}

void	push_swap(t_struct *data)
{
	if (data->total_size == 2)
	{
		if (data->a.stack[0] == data->max_num)
			ft_swap(data, 'a', TRUE);
	}
	else if (data->total_size == 3)
		push_swap_3(data);
	else if (data->total_size <= 6)
		push_swap_under_6(data);
	else
		push_swap_over_7(data);
}
