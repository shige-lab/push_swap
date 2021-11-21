/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_is_correct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:43:25 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/19 00:18:57 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	sort_is_correct(t_struct *data)
{
	int	i;

	i = 0;
	while (i + 1 < data->total_size)
	{
		if (data->a.stack[i] >= data->a.stack[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
