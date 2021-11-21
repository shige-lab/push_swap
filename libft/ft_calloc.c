/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:38:13 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/07 23:36:20 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*m_size;
	size_t	product;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	product = count * size;
	if (product / count != size)
		return (NULL);
	m_size = malloc(product);
	if (m_size)
		ft_bzero(m_size, product);
	return (m_size);
}
