/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:30:47 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/06 13:52:36 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

// void    insertion_sort(t_list **stack_a, t_list **stack_b)
// {
//     int i;
//     int k;

//     i = 0;
//     k = 0;
//     while ((*stack_a))
//     {
//         if (i > 1)
//         {
//             k = i;
//             while (((*stack_a)->content) < ((*stack_b)->content))
//             {
//                 rotate(stack_b, 'b');
//                 if ((*stack_b)->next == NULL || k == 0)
//                     break ;
//             }
//         }
//         if (i > 1)
//             push(stack_a, &(*stack_b)->next, 'b');
//         else
//             push(stack_a, stack_b, 'b');
//         i++;
//     }
// }

// int position_temp(t_list *temp, t_list **stack_a)
// {
//     t_list *current;
//     int position;

//     position = 0;
//     current = *stack_a;
//     while (current)
//     {
//         if (current == temp)
//             return (position);
//         position++;
//         current = current->next;
//     }
//     return (-1);
// }

void	selection_sort(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;
    t_list *current;
	int stack_a_size;
    int position;
    int diff;
    int pos_temp;
    
    current = *stack_a;
    stack_a_size = ft_lstsize(current);
    while (stack_a_size > 0)
    {
        current = *stack_a;
        temp = current;
        position = 0;
        pos_temp = 0;
        while (current)
        {
            if ((current)->content < temp->content)
            {
                temp = current;
                pos_temp = position;
            }
            current = current->next;
            position++;
        }
        diff = stack_a_size - pos_temp;git 
        if (pos_temp <= stack_a_size / 2)
        {
            while (pos_temp--)
                rotate(stack_a, 'a');
        }
        else
            while(diff > 0)
        {
                reverse_rotate(stack_a, 'a');
                diff--;
        }
        push(stack_a, stack_b, 'b');
        stack_a_size--;
    }
}
