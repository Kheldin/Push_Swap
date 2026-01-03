/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:39 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/03 18:53:54 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>
#include "libft/includes/libft.h"

/*
	if argc == 2: 
		- we have a single string containing numbers | Use split
	if args > 2:
		- each number is a single string  | Just create a node and push to the stack
	
	if an error happen, free stacks and EXIT_FAILURE
*/
void	*ft_free_split(char **buffer)
{
	int	i;

	i = 0;
	while(buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
	return (NULL);
}

char	**one_arg(char **argv)
{
	int		i;
	int		j;
	char	**buffer;

	i = 0;
	buffer = ft_split(argv[1], ' ');
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{
			if (!ft_isdigit(buffer[i][j]))
			{
				ft_free_split(buffer);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (buffer);
}

t_list	*create_list(char **buffer)
{
	int	i;
	int	number;
	t_list	*head;

	i = 0;
	head = NULL;
	while (buffer[i])
	{
		number = ft_atoi(buffer[i]);
		ft_printf("number = %d\n", number);
		if (!head)
			head = ft_lstnew(&number);
		else
			ft_lstadd_back(&head, ft_lstnew(&number));
		i++;	
	}
	return head;
}

void	*input_parser(int argc, char *argv[])
{
	t_list *stack_a;
	int		i;
	char 	**buffer;

	i = 0;
	stack_a = NULL;
	buffer = NULL; // a delete
	if (argc == 2)
		buffer = one_arg(argv);
	if (!buffer)
		return (NULL);
	stack_a = create_list(buffer);
	return ((void *)stack_a);
}

int	main (int argc, char *argv[])
{
	int	i;
	t_list *stack_a;

	i = 0;
	stack_a = input_parser(argc, argv);
	if (!stack_a)
	{
		write(2, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	while (stack_a)
	{
		printf("%d\n", *(int *)stack_a->content);
		stack_a =stack_a->next;
	}

	return (EXIT_SUCCESS);
}