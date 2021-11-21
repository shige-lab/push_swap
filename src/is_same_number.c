/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:41:47 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/19 01:55:47 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	is_same_number(t_struct data, int number, int number_location)
{
	int	i;

	i = 0;
	while (i < number_location)
	{
		if (data.a.stack[i] == number)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
