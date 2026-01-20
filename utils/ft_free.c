/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:00:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/20 15:53:33 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bench.h"
#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	ft_free_stack_and_flags(t_flags *flags, t_list *stack_a,
			t_list *stack_b)
{
	free(flags);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}

void	ft_free_no_stack_a(t_flags *flags, int ac)
{
	if (ac != 1)
		ft_putendl_fd("Error", 2);
	free(flags);
}
