/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                           |o_o || |                */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 12:47:10 by saladin       #+#    #+#                 */
/*   Updated: 2021/06/21 12:18:10 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char *ptr;

	ptr = (char*)s;
	while (n > 0)
	{
		(ptr)[n - 1] = ((char)c);
		n--;
	}
	return (s);
}

char	*ft_strdup(const char *s)
{
	char *p;

	p = (char *)malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s, ft_strlen((char *)s) + 1);
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

static void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == __SIZE_MAX__)
		return (NULL);
	str = (char *)ft_memalloc(size + 1);
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
