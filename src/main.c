/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:47:23 by tshigena          #+#    #+#             */
/*   Updated: 2021/12/08 20:53:49 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	data;

	if (argc < 3)
		return (0);
	data.total_size = argc - 1;
	data.a.size = data.total_size;
	agrv_to_a_stack(&data, argv);
	if (diff(data, 0) == 0)
		return (0);
	push_swap(&data);
	ft_free_stacks(data);
	return (0);
}
