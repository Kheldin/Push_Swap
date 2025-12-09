/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:14:44 by kacherch          #+#    #+#             */
/*   Updated: 2025/11/18 14:41:56 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_sizet(size_t nb, int *counter)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb > 15)
		print_sizet(nb / 16, counter);
	if (ft_putchar_printf(hex[nb % 16], counter) == -1)
		return (-1);
	return (0);
}

static int	print_hex_adress(size_t adress, int *counter)
{
	if (!adress)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		*counter += 5;
		return (0);
	}
	if (ft_putstr_printf("0x", counter) == -1)
		return (-1);
	if (print_sizet(adress, counter) == -1)
		return (-1);
	return (0);
}

static int	ft_putnbr_printf(long nb, int *counter)
{
	if (nb < 0)
	{
		if (ft_putchar_printf('-', counter) == -1)
			return (-1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_printf(nb / 10, counter);
	if (ft_putchar_printf((nb % 10) + '0', counter) == -1)
		return (-1);
	return (0);
}

int	do_operation(char c, va_list args, int *counter)
{
	int	state;

	state = 0;
	if (c == 'd' || c == 'i')
		state = ft_putnbr_printf(va_arg(args, int), counter);
	else if (c == 'u')
		state = print_unsigned(va_arg(args, unsigned int), counter);
	else if (c == 'c')
		state = ft_putchar_printf(va_arg(args, int), counter);
	else if (c == 's')
		state = ft_putstr_printf(va_arg(args, char *), counter);
	else if (c == '%')
		state = ft_putchar_printf('%', counter);
	else if (c == 'x')
		state = print_hexl(va_arg(args, unsigned int), counter);
	else if (c == 'X')
		state = print_hexu(va_arg(args, unsigned int), counter);
	else if (c == 'p')
	{
		state = print_hex_adress(va_arg(args, unsigned long), counter);
	}
	return (state);
}
