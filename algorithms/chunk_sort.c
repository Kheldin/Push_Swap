/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogard-antoine <rogard-antoine@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:24:29 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/08 14:58:35 by rogard-anto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int	ft_sqrt(int numbers)
{
	int	n;

	n = 1;
	while (n * n < numbers)
		n++;
	return (n);
}

void    push_chunk(t_list **stack_a, t_list **stack_b, int max, int minimum)
{
    int i;
    int size;

    i = 0;
    size = ft_lstsize(*stack_a);
    while (i < size)
    {
		// ft_printf("minimum = %d\n", minimum);
		// ft_printf("max = %d\n", max);
        if ((*stack_a)->index < max && (*stack_a)->index >= minimum)
			push(stack_a, stack_b, 'b');
        else
            rotate(stack_a, 'a');
        i++;
    }
}

void    chunk_sort(t_list **stack_a, t_list **stack_b)
{
    int stack_a_size;
    int chunks;
    int size;
    int i_chunks;

    stack_a_size = ft_lstsize(*stack_a);
    chunks = ft_sqrt(stack_a_size); 
    i_chunks = chunks + 1;
    while (i_chunks > 0)
    {
        push_chunk(stack_a, stack_b, stack_a_size, stack_a_size - chunks + 1);
        i_chunks--;
		stack_a_size--;
    }
    size = ft_lstsize(*stack_a);
    while (size > 0)
    {
        push(stack_a, stack_b, 'b');
        size--;
    }
	selection_sort_chunk(stack_a, stack_b);
}