/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_disposal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:04:22 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/30 11:21:58 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_struct *data, char a_b, t_bool put_message)
{
	int	tmp;

	if (a_b == 'a')
	{
		tmp = data->a.stack[0];
		data->a.stack[0] = data->a.stack[1];
		data->a.stack[1] = tmp;
		if (put_message == TRUE)
			ft_putendl_fd("sa", 1);
	}
	if (a_b == 'b')
	{
		tmp = data->b.stack[0];
		data->b.stack[0] = data->b.stack[1];
		data->b.stack[1] = tmp;
		if (put_message == TRUE)
			ft_putendl_fd("sb", 1);
	}
}

void	ft_push(t_struct *data, char a_b, t_bool put_message)
{
	if (a_b == 'a')
	{
		ft_push_front(data->a.stack, data->a.size, data->b.stack[0]);
		data->a.size++;
		ft_pop_front(data->b.stack, data->b.size);
		data->b.size--;
		if (put_message == TRUE)
			ft_putendl_fd("pa", 1);
	}
	if (a_b == 'b')
	{
		ft_push_front(data->b.stack, data->b.size, data->a.stack[0]);
		data->b.size++;
		ft_pop_front(data->a.stack, data->a.size);
		data->a.size--;
		if (put_message == TRUE)
			ft_putendl_fd("pb", 1);
	}
}

void	ft_rotate(t_struct *data, char a_b, t_bool put_message)
{
	if (a_b == 'a')
	{
		ft_rotate_front_to_end(data->a.stack, data->a.size);
		if (put_message == TRUE)
			ft_putendl_fd("ra", 1);
	}
	if (a_b == 'b')
	{
		ft_rotate_front_to_end(data->b.stack, data->b.size);
		if (put_message == TRUE)
			ft_putendl_fd("rb", 1);
	}
}

void	ft_reverse_rotate(t_struct *data, char a_b, t_bool put_message)
{
	if (a_b == 'a')
	{
		ft_rotate_end_to_front(data->a.stack, data->a.size);
		if (put_message == TRUE)
			ft_putendl_fd("rra", 1);
	}
	if (a_b == 'b')
	{
		ft_rotate_end_to_front(data->b.stack, data->b.size);
		if (put_message == TRUE)
			ft_putendl_fd("rrb", 1);
	}
}

void	ft_ss_rr_rrr(t_struct *data, char *ss_rr_rrr, t_bool put_message)
{
	if (ft_strncmp(ss_rr_rrr, "ss", 3) == 0)
	{
		ft_swap(data, 'a', FALSE);
		ft_swap(data, 'b', FALSE);
		if (put_message == TRUE)
			ft_putendl_fd("ss", 1);
	}
	if (ft_strncmp(ss_rr_rrr, "rr", 3) == 0)
	{
		ft_rotate(data, 'a', FALSE);
		ft_rotate(data, 'b', FALSE);
		if (put_message == TRUE)
			ft_putendl_fd("rr", 1);
	}
	if (ft_strncmp(ss_rr_rrr, "rrr", 3) == 0)
	{
		ft_reverse_rotate(data, 'a', FALSE);
		ft_reverse_rotate(data, 'b', FALSE);
		if (put_message == TRUE)
			ft_putendl_fd("rrr", 1);
	}
}
