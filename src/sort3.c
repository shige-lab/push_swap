/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:38:49 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/26 21:54:10 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
