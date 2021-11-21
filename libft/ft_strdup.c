/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:40:47 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/07 23:39:14 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	str_size;

	str_size = ft_strlen(src) + 1;
	cpy = (char *)malloc(str_size * sizeof(char));
	if (cpy)
		ft_memcpy(cpy, src, str_size);
	return (cpy);
}
