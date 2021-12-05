/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:54:50 by tshigena          #+#    #+#             */
/*   Updated: 2021/12/01 13:46:01 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	print_d(int d)
{
	if (d < 0)
	{
		write(1, "-", 1);
		return (1 + put_num_dx(d * -1UL, 10, 0));
	}
	return (put_num_dx(d, 10, 0));
}