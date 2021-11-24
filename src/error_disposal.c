/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_disposal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:32:15 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/24 17:37:05 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	error_exit(char *message)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(message, 1);
	exit (1);
}

void	error_exit_with_free(t_struct *data, char *message)
{
	free(data->a.stack);
	free(data->b.stack);
	free(data->s.stack);
	error_exit(message);
}