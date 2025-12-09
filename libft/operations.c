/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:14:56 by kacherch          #+#    #+#             */
/*   Updated: 2025/11/13 16:32:43 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_putchar_printf(char c, int *counter)
{
	int	tmp;

	tmp = write(1, &c, 1);
	if (tmp == -1)
		return (-1);
	*counter += tmp;
	return (0);
}

int	ft_putstr_printf(char *str, int *counter)
{
	int	i;

	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*counter += 6;
		return (0);
	}
	i = 0;
	while (str[i])
	{
		if (ft_putchar_printf(str[i], counter) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	print_unsigned(unsigned int nb, int *counter)
{
	if (nb > 9)
		print_unsigned(nb / 10, counter);
	if (ft_putchar_printf((nb % 10) + '0', counter) == -1)
		return (-1);
	return (0);
}

int	print_hexl(unsigned int nb, int *counter)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb > 15)
		print_hexl(nb / 16, counter);
	if (ft_putchar_printf(hex[nb % 16], counter) == -1)
		return (-1);
	return (0);
}

int	print_hexu(unsigned int nb, int *counter)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (nb > 15)
		print_hexu(nb / 16, counter);
	if (ft_putchar_printf(hex[nb % 16], counter) == -1)
		return (-1);
	return (0);
}
