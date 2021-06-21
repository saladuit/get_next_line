/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                 |o_o || |                */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 09:13:47 by saladin       #+#    #+#                 */
/*   Updated: 2021/06/21 12:09:30 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 + len2 > __SIZE_MAX__ - 1)
		return (NULL);
	dest = ft_strnew(len1 + len2);
	if (!dest)
		return (NULL);
	ft_memcpy((void *)dest, s1, ft_strlen(s1));
	ft_memcpy((void *)&(dest[ft_strlen(s1)]), s2, ft_strlen(s2));
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (*p == c)
		{
			return (p);
		}
		p++;
	}
	if (c == '\0')
		return (p);
	return (0);
}

static int	newline(int fd, char **line, char **saved)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(saved[fd]);
	if (ft_strchr(saved[fd], '\n'))
	{
		tmp = ft_strdup((ft_strchr(saved[fd], '\n') + 1));
		*line = ft_substr(saved[fd], 0, (len - (ft_strlen(tmp) + 1)));
		free(saved[fd]);
		saved[fd] = tmp;
		return (1);
	}
	return (0);
}

static int	output(int fd, char **line, char **saved, ssize_t b_read)
{
	if (b_read == -1)
	{
		free(saved[fd]);
		return (-1);
	}
	if (b_read == 0)
		*line = saved[fd];
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[FOPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		b_read;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (saved[fd] == NULL)
		saved[fd] = ft_strdup("");
	b_read = 1;
	while (b_read)
	{
		if (newline(fd, line, saved))
			return (1);
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read <= 0)
			return (output(fd, line, saved, b_read));
		buffer[b_read] = '\0';
		tmp = ft_strjoin(saved[fd], buffer);
		free(saved[fd]);
		saved[fd] = tmp;
	}
	return (0);
}
