/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:51:13 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/13 12:07:31 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# define FDS_MAX 1024
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

char	*get_next_line(int fd);
int		ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
void				*ft_calloc(size_t nmemb, size_t size);

#endif