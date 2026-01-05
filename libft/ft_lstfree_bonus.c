/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:53:09 by kacherch          #+#    #+#             */
/*   Updated: 2025/12/02 20:45:35 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	(void)del;
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del))
{
	t_list	*tmp;

	(void)del;
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(int ))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, int(*f)(int), void (*del)(int))
{
	t_list	*new;
	t_list	*new_list;
	int		content;

	(void)del;
	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (!new)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new);
		lst = lst->next;
	}
	return (new_list);
}
