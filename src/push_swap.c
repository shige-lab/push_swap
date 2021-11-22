/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:20:31 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/23 02:26:03 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap_3(t_struct *data)
{
	t_stack	a;
	int		*a_stack;

	get_standard_value_3(&data->a);
	a = data->a;
	a_stack = a.stack;
	if (a_stack[1] == a.min_num && a_stack[2] == a.max_num)
		ft_swap(data, 'a', TRUE);
	else if (a_stack[2] == a.min_num && a_stack[0] == a.max_num)
	{
		ft_swap(data, 'a', TRUE);
		ft_reverse_rotate(data, 'a', TRUE);
	}
	else if (a_stack[1] == a.min_num && a_stack[0] == a.max_num)
		ft_rotate(data, 'a', TRUE);
	else if (a_stack[0] == a.min_num && a_stack[1] == a.max_num)
	{
		ft_swap(data, 'a', TRUE);
		ft_rotate(data, 'a', TRUE);
	}
	else if (a_stack[2] == a.min_num && a_stack[1] == a.max_num)
		ft_reverse_rotate(data, 'a', TRUE);
}

void	push_swap_3_reverse(t_struct *data)
{
	t_stack	b;
	int		*b_stack;

	get_standard_value_3(&data->b);
	b = data->b;
	b_stack = b.stack;
	if (b_stack[2] == b.min_num && b_stack[1] == b.max_num)
		ft_swap(data, 'b', TRUE);
	else if (b_stack[0] == b.min_num && b_stack[2] == b.max_num)
	{
		ft_swap(data, 'b', TRUE);
		ft_reverse_rotate(data, 'b', TRUE);
	}
	else if (b_stack[0] == b.min_num && b_stack[1] == b.max_num)
		ft_rotate(data, 'b', TRUE);
	else if (b_stack[1] == b.min_num && b_stack[0] == b.max_num)
	{
		ft_swap(data, 'b', TRUE);
		ft_rotate(data, 'b', TRUE);
	}
	else if (b_stack[1] == b.min_num && b_stack[2] == b.max_num)
		ft_reverse_rotate(data, 'a', TRUE);
}

void	push_swap_under_6(t_struct *data)
{
	while (data->a.size != 3)
	{
		if (data->a.stack[data->a.size - 1] < data->middle_num)
			ft_reverse_rotate(data, 'a', TRUE);
		else if (data->a.stack[0] < data->middle_num)
			ft_push(data, 'b'); 
		else
			ft_rotate(data, 'a', TRUE);
	}
	push_swap_3(data);
	if (data->b.size == 2)
	{
		if (data->b.stack[0] == data->min_num)
			ft_swap(data, 'b', TRUE);
		ft_push(data, 'a');
	}
	if (data->b.size == 3)
	{
		push_swap_3_reverse(data);
		ft_push(data, 'a');
		ft_push(data, 'a');
	}
	ft_push(data, 'a');
	if (data->a.stack[0] > data->a.stack[1])
		ft_swap(data, 'a', TRUE);
}

void	push_swap_over_7(t_struct *data)
{
	while (data->a.size != data->total_size - data->q3_4_index)
	{
		if (data->a.stack[0] < data->s.stack[data->q3_4_index])
		{
			ft_push(data, 'b');
			is_rr_from_a(data);
		}
		else
			ft_rotate(data, 'a', TRUE);
	}
	// push_a_from_min(data, 0);
	push_a_from_min2(data);
	push_quater_to_b(data);
	// push_a_from_min(data, data->middle_index);
	// printf(" a_size = %d\n",data->a.size, data->middle_index);
}

void	push_swap(t_struct *data)
{
	if (data->total_size == 2)
	{
		if (data->a.stack[0] == data->max_num)
			ft_swap(data, 'a', TRUE);
		return ;
	}
	if (data->total_size == 3)
		push_swap_3(data);
	else if (data->total_size < 7)
		push_swap_under_6(data);
	else
		push_swap_over_7(data);
}