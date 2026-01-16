/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:44:54 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/14 17:52:04 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int	handle_flags(char *arg, t_flags *flags)
{
	if (ft_strncmp(flags->simple, arg, ft_strlen(arg)) == 0
		&& flags->flag_int == -1)
		flags->flag_int = 1;
	else if (ft_strncmp(arg, flags->medium, ft_strlen(arg)) == 0
		&& flags->flag_int == -1)
		flags->flag_int = 10;
	else if (ft_strncmp(arg, flags->complex, ft_strlen(arg)) == 0
		&& flags->flag_int == -1)
		flags->flag_int = 100;
	else if (ft_strncmp(arg, flags->bench, ft_strlen(arg)) == 0
		&& flags->bench_int == -1)
		flags->bench_int = 1;
	else
		return (-1);
	return (1);
}
