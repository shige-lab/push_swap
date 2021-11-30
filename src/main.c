/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:47:23 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/30 19:18:22 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	data;

	if (argc < 3)
		return (0);
	data = (t_struct){0};
	data.total_size = argc - 1;
	data.a.size = data.total_size;
	put_argv_to_a(&data, argv);
	push_swap(&data);
	ft_free_stacks(data);
	// system ("leaks push_swap");
	return (0);
}