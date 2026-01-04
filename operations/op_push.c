/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:49:53 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/04 16:56:57 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void push(t_list **first_a, t_list **first_b, char stack)
{
    t_list *temp;
    
    if (stack == 'a')
    {
        if ((*first_b) == NULL)
            return ;
        temp = (*first_b);
        (*first_b) = (*first_b)->next;
        ft_lstadd_front(first_a, temp);
        write(1, "pa\n", 3);
    }
    if (stack == 'b')
    {
        if ((*first_a) == NULL)
            return ;
        temp = (*first_a);
        (*first_a) = (*first_a)->next;
        ft_lstadd_front(first_b, temp);
        write(1, "pb\n", 3);
    }
}
