/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 11:37:36 by saladin       #+#    #+#                 */
/*   Updated: 2021/06/29 09:46:33 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_line
{
	ssize_t	b_read;
	char	*tmp;
}	t_line;

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
