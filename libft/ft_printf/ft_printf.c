/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:54:12 by tshigena          #+#    #+#             */
/*   Updated: 2021/12/01 13:46:01 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	select_format(char c, va_list ap);
static int		is_overflow(int str_len, size_t printed_len);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		str_lens;

	i = 0;
	str_lens = 0;
	va_start(ap, format);
	while (format[i] && str_lens >= 0)
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			str_lens = is_overflow(str_lens, select_format(format[i + 1], ap));
			i++;
		}
		else
			str_lens = is_overflow(str_lens, print_c(format[i]));
		i++;
	}
	va_end(ap);
	return (str_lens);
}

static int	is_overflow(int str_len, size_t printed_len)
{
	if (printed_len >= INT_MAX || str_len + printed_len >= INT_MAX)
		return (-1);
	return (str_len + printed_len);
}

static size_t	select_format(char c, va_list ap)
{
	size_t	size;

	size = 0;
	if (c == 'c')
		size += print_c(va_arg(ap, int));
	else if (c == 's')
		size += print_s(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		size += print_d(va_arg(ap, int));
	else if (c == 'u')
		size += print_u(va_arg(ap, unsigned int));
	else if (c == 'p')
		size += print_p(va_arg(ap, unsigned long long));
	else if (c == 'x' || c == 'X')
		size += print_x(c, va_arg(ap, unsigned int));
	else if (c == '%')
		size += print_c('%');
	return (size);
}
