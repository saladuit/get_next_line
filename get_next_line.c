/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                 |o_o || |                */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 09:13:47 by saladin       #+#    #+#                 */
/*   Updated: 2021/06/22 14:28:29 by safoh        \___)=(___/                 */
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

static char	*ft_strchr(const char *s, int c)
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

int	newline(int fd, char **line, char **saved, t_line *data)
{
	size_t len;

	len = ft_strlen(saved[fd]);
	if (ft_strchr(saved[fd], '\n'))
	{
		data->tmp = ft_strdup((ft_strchr(saved[fd], '\n') + 1));
		if (data->tmp == NULL)
		{
			free(saved[fd]);
			return (-1);
		}
		*line = ft_substr(saved[fd], 0, (len - (ft_strlen(data->tmp) + 1)));
		free(saved[fd]);
		if (*line == NULL)
			return (-1);
		saved[fd] = data->tmp;
		return (1);
	}
	return (0);
}

int	output(int fd, char **line, char **saved, t_line *data)
{
	if (data->b_read < 0)
		return (-1);
	else if (data->b_read == 0)
		return (0);
	else
		return (newline(fd, line, saved, data));
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[FOPEN_MAX] = {NULL};
	char		buffer[BUFFER_SIZE + 1];
	t_line		data;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
	{
		line[0] = NULL;
		return (-1);
	}
	data.b_read = 1;
	while (data.b_read)
	{
		data.b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[data.b_read] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup(buffer);
		else
		{
			data.tmp = ft_strjoin(saved[fd], buffer);
			free(saved[fd]);
			if (!data.tmp)
				return (-1);
			saved[fd] = data.tmp;
		}
		if (ft_strchr(saved[fd], '\n'))
			break ;
	}
	return (output(fd, line, saved, &data));
}
