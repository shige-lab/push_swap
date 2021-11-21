/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:43:24 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/20 21:46:22 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



void	push_a_from_min(t_struct *data, int i)
{
	while (data->b.size != 0)
	{
		if (data->b.stack[data->b.size - 1] == data->s.stack[i])
			ft_reverse_rotate(data, 'b', TRUE);
		if (data->b.stack[0] == data->s.stack[i])
		{
			ft_push(data, 'a'); 
			ft_rotate(data, 'a', TRUE);
			i++;
		}
		else
			ft_rotate(data, 'b', TRUE);
	}
}