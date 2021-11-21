/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:40:39 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/07 23:39:01 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**free_all(char **str, size_t i);
static size_t	set_el_size(char *str, char charset);
static char		*split_str(char *str, char charset, size_t *i);
static int		if_c_is_charset(char c, char charset);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	el;
	size_t	el_size;

	el = 0;
	i = 0;
	if (!s)
		return (NULL);
	el_size = set_el_size((char *)s, c);
	strs = (char **)ft_calloc(el_size + 1, sizeof(*strs));
	if (!strs)
		return (NULL);
	while (el < el_size)
	{
		while ((if_c_is_charset((char)s[i], c) == 0))
			i++;
		strs[el] = split_str((char *)s, c, &i);
		if (!strs[el])
			return (free_all(strs, el));
		el++;
	}
	return (strs);
}

static int	if_c_is_charset(char c, char charset)
{
	if (c == charset)
		return (0);
	if (c == '\0')
		return (-1);
	return (1);
}

static char	*split_str(char *str, char charset, size_t *i)
{
	int		size;
	char	*dest;

	size = 0;
	dest = NULL;
	while (if_c_is_charset(str[*i + size], charset) == 1)
		size++;
	if (size > 0)
	{
		dest = (char *)malloc((size + 1) * sizeof(char));
		if (dest == NULL)
			return (NULL);
		ft_strlcpy(dest, (str + *i), size + 1);
	}
	*i += size;
	return (dest);
}

static size_t	set_el_size(char *str, char charset)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (str[i] != charset && str[i])
		count++;
	while (str[i])
	{
		if (if_c_is_charset(str[i], charset) == -1)
			break ;
		if ((if_c_is_charset(str[i], charset) == 0
				&& if_c_is_charset((str[i + 1]), charset) == 1))
			count++;
		i++;
	}
	return (count);
}

static char	**free_all(char **str, size_t i)
{
	while (i > 0 )
		free(str[--i]);
	free(str);
	return (NULL);
}
