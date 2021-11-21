/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:41:03 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/07 23:39:37 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;

	if (dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	if (dst_len < dstsize)
		ft_strlcpy(&dst[dst_len], src, dstsize - dst_len);
	else
		dst_len = dstsize;
	return (dst_len + ft_strlen(src));
}
