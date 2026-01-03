/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:35:14 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/03 22:25:30 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

void rotate(t_list **node, char stack)
{
    t_list *last;
    t_list *first;
    
    if ((*node) == NULL || (*node)->next == NULL)
        return ;
    first = (*node);
    (*node) = first->next;
    last = ft_lstlast(first);
    __builtin_printf("last->content = %d\n", *(int *)last->content);
    last->next = first;
    first->next = NULL;
    if (stack == 'a')
        write(1, "ra\n", 3);
    if (stack == 'b')
        write(1, "rb\n", 3);
}

void rotate_rr(t_list **node_a, t_list **node_b)
{
    rotate(node_a, ' ');
    rotate(node_b, ' ');
    write(1, "rr\n", 3);
}