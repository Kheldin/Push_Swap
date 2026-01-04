/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:49:53 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/03 21:36:12 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

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