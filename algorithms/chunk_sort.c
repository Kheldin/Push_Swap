/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:24:29 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/07 23:53:12 by anrogard         ###   ########.fr       */
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

void    push_chunk(t_list **stack_a, t_list **stack_b, int limit)
{
    int i;
    int size;

    i = 0;
    size = ft_lstsize(*stack_a);
    while (i < size)
    {
        if ((*stack_a)->index < limit)
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
    i_chunks = 1;
    while (i_chunks <= chunks)
    {
        selection_sort(stack_a, stack_b, chunks);
        i_chunks++;
    }
    size = ft_lstsize(*stack_a);
    while (size > 0)
    {
        push(stack_b, stack_a, 'b');
        size--;
    }
    final_push_selection(stack_a, stack_b);
}