/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:40:11 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/07 23:38:29 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)buf)[i] = ch;
		i++;
	}
	return (buf);
}
