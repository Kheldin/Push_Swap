/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:12:32 by kacherch          #+#    #+#             */
/*   Updated: 2025/11/13 16:25:35 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libft.h"

int	is_valid_format(char c)
{
	char	*valid_format;

	valid_format = "cspdiuxX%";
	while (*valid_format)
	{
		if (*valid_format == c)
			return (1);
		valid_format++;
	}
	return (0);
}

int	ft_strlen_printf(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counter;
	int		state;

	counter = 0;
	if (!format)
		return (-1);
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && is_valid_format(format[i + 1]))
			state = do_operation(format[++i], args, &counter);
		else if (format[i] != '%')
			state = ft_putchar_printf(format[i], &counter);
		if (state == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (counter);
}
