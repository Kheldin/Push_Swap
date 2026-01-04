/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:35:14 by anrogard          #+#    #+#             */
/*   Updated: 2026/01/04 17:49:24 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void rotate(t_list **node, char stack)
{
    t_list *last;
    t_list *first;
    
    if ((*node) == NULL || (*node)->next == NULL)
        return ;
    first = (*node);
    (*node) = first->next;
    last = ft_lstlast(first);
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

void reverse_rotate(t_list **node, char stack)
{
    t_list *last;
    t_list *first;
    t_list  *penultimate;

    if ((*node) == NULL || (*node)->next == NULL)
        return ;
    penultimate = (*node);
    first = (*node);
    last = (*node);
    while (last->next)
    {
        penultimate = last;
        last = last->next;
    }    
    penultimate->next = NULL;
    last->next = first;
    (*node) = last;
    if (stack == 'a')
        write(1, "rra\n", 4);
    if (stack == 'b')
        write(1, "rrb\n", 4);
}
void reverse_rotate_rr(t_list **node_a, t_list **node_b)
{
    reverse_rotate(node_a, ' ');
    reverse_rotate(node_b, ' ');
    write(1, "rrr\n", 3);
}