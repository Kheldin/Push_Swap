/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:18:58 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/06 11:18:59 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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