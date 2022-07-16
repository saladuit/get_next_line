/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 09:13:47 by saladin       #+#    #+#                 */
/*   Updated: 2021/06/29 11:34:22 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	if (!s)
		return (NULL);
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

static int	newline(char **line, char **saved, t_line *data)
{
	size_t	len;

	len = 0;
	while ((*saved)[len] != '\n' && (*saved)[len] != '\0')
		len++;
	if ((*saved)[len] == '\n')
	{
		*line = ft_substr(*saved, 0, len);
		data->tmp = ft_strdup(&((*saved)[len + 1]));
		free(*saved);
		*saved = data->tmp;
	}
	else
	{
		*line = ft_strdup(*saved);
		if (*saved != NULL)
		{
			free(*saved);
			*saved = NULL;
		}
	}
	if (!*line)
		return (-1);
	return (1);
}

static int	output(int fd, char **line, char **saved, t_line *data)
{
	if (data->b_read < 0)
		return (-1);
	else if (data->b_read == 0 && !ft_strchr(saved[fd], '\n'))
	{
		*line = ft_strdup(saved[fd]);
		if (!*line)
		{
			free(saved[fd]);
			saved[fd] = NULL;
			return (-1);
		}
		if (saved[fd] != NULL)
		{
			free(saved[fd]);
			saved[fd] = NULL;
		}
		return (0);
	}
	else
		return (newline(line, &saved[fd], data));
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[FOPEN_MAX] = {NULL};
	char		buffer[BUFFER_SIZE + 1];
	t_line		data;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	data.b_read = 1;
	while (data.b_read && !ft_strchr(saved[fd], '\n'))
	{
		data.b_read = read(fd, buffer, BUFFER_SIZE);
		if (data.b_read == -1)
			return (-1);
		buffer[data.b_read] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup(buffer);
		else
		{
			data.tmp = ft_strjoin(saved[fd], buffer);
			free(saved[fd]);
			saved[fd] = data.tmp;
		}
		if (!saved[fd])
			return (-1);
	}
	return (output(fd, line, saved, &data));
}
