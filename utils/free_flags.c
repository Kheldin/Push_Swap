/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:39:21 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/13 17:41:41 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_flags(t_flags *flags)
{
	free(flags->simple);
	free(flags->medium);
	free(flags->complex);
	free(flags->bench);
	free(flags);
}