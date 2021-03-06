/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 12:47:10 by saladin       #+#    #+#                 */
/*   Updated: 2021/06/29 11:34:47 by safoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*p;

	p = (char *)malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s, ft_strlen((char *)s) + 1);
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	size += 1;
	if (size == __SIZE_MAX__)
		return (NULL);
	str = malloc(size);
	if (!str)
		return (NULL);
	while (size > 0)
	{
		(str)[size - 1] = (char)0;
		size--;
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= (size_t)start)
		return (ft_strdup(""));
	dest = ft_strnew(len);
	if (!dest)
		return (NULL);
	ft_memcpy((void *)dest, (void *)&(s[start]), len);
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = dest;
	s = src;
	if (dest == src && dest == 0)
		return (NULL);
	while (n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}
