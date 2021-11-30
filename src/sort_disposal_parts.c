/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_disposal_parts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:39:55 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/30 19:19:52 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_front(int *data, int data_size, int insert)
{
	int	i;

	if (data == NULL)
		return ;
	i = data_size;
	while (i > 0)
	{
		data[i] = data[i - 1];
		i--;
	}
	data[0] = insert;
}

void	ft_pop_front(int *data, int data_size)
{
	int	i;

	if (data == NULL)
		return ;
	i = 0;
	while (i + 1 < data_size)
	{
		data[i] = data[i + 1];
		i++;
	}
	data[i] = 0;
}

void	ft_rotate_front_to_end(int *data, int data_size)
{
	int	i;
	int	tmp;

	if (data == NULL)
		return ;
	i = 0;
	tmp = data[i];
	while (i + 1 < data_size)
	{
		data[i] = data[i + 1];
		i++;
	}
	data[i] = tmp;
}

void	ft_rotate_end_to_front(int *data, int data_size)
{
	int	i;
	int	tmp;

	if (data == NULL)
		return ;
	i = data_size - 1;
	tmp = data[i];
	while (i > 0)
	{
		data[i] = data[i - 1];
		i--;
	}
	data[i] = tmp;
}
