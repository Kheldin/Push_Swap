/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags->c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:44:54 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/16 18:21:26 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int	handle_flags(char *arg, t_flags *flags)
{
	if (ft_strncmp(SIMPLE_FLAG, arg, ft_strlen(arg)) == 0
		&& flags->flag_int == NO_FLAGS)
		flags->flag_int = 1;
	else if (ft_strncmp(arg, MEDIUM_FLAG, ft_strlen(arg)) == 0
		&& flags->flag_int == NO_FLAGS)
		flags->flag_int = 10;
	else if (ft_strncmp(arg, COMPLEX_FLAG, ft_strlen(arg)) == 0
		&& flags->flag_int == NO_FLAGS)
		flags->flag_int = 100;
	else if (ft_strncmp(arg, BENCH_FLAG, ft_strlen(arg)) == 0
		&& flags->bench_int == NO_FLAGS)
		flags->bench_int = 1;
	else if (ft_strncmp(arg, ADAPTIVE_FLAG, ft_strlen(arg)) == 0
		&& flags->flag_int == NO_FLAGS)
		flags->flag_int = 1000;
	else
		return (-1);
	return (1);
}
