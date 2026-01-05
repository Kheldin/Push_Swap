/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrogard <anrogard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:04:58 by kacherch          #+#    #+#             */
/*   Updated: 2026/01/05 21:54:23 by anrogard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define FDS_MAX 1024
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

int		ft_atoi(const char *nptr);

void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strtrim(char const *s1, char const *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_memcmp(const void *s1, const void *s2, size_t n);

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del));
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*ft_lstmap(t_list *lst, int(*f)(int), void (*del)(int));

char	*get_next_line(int fd);
int		ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);

int	ft_printf(const char *format, ...)
	__attribute__ ((format (printf, 1, 2)));
int	ft_putchar_printf(char c, int *counter);
int	print_unsigned(unsigned int nb, int *counter);
int	print_hexl(unsigned int nb, int *counter);
int	print_hexu(unsigned int nb, int *counter);
int	ft_putstr_printf(char *str, int *counter);
int	do_operation(char c, va_list args, int *counter);

#endif