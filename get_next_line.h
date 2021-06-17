/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 11:37:36 by saladin       #+#    #+#                 */
/*   Updated: 2021/03/18 15:55:40 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXTLINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stddef.h>

typedef struct s_line
{
	char	*temp;
	int		i;
} t_line;

int		get_next_line(int fd, char **line);
char	*ft_strnew(size_t size);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, int i);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif
