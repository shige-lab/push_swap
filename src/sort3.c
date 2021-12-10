/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:10:25 by tshigena          #+#    #+#             */
/*   Updated: 2021/12/10 17:10:56 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_minimum_numbers(t_struct *data)
{
	while (data->a.stack[0] == data->s.stack[data->sorted_index])
	{
		ft_rotate(data, 'a', TRUE);
		data->sorted_index++;
	}
}
