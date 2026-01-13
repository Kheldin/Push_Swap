/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:51:13 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/13 17:20:20 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# define FDS_MAX 1024
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../libft/includes/libft.h"

char	*get_next_line(int fd);
int		ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size); // operations_checker

void	reverse_rotate_checker(t_list **node);
void	rotate_checker(t_list **node);
void	push_checker(t_list **first_a, t_list **first_b, char stack);

#endif