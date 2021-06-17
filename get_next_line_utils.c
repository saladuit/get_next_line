/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                           |o_o || |                */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 12:47:10 by saladin       #+#    #+#                 */
/*   Updated: 2021/06/16 12:33:38 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *p;

	if (nmemb == 0 || size == 0)
	{
		size = 1;
		nmemb = 1;
	}
	p = (void*)malloc(nmemb * size);
	if (p == 0)
		return (0);
	ft_bzero(p, nmemb * size);
	return (p);
}
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

char	*ft_strndup(const char *s, int i)
{
	char *p;

	p = (char *)malloc(i + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s, i + 1);
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

void	*ft_memalloc(size_t size)
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	res;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	res = 0;
	i = 0;
	if (size == 0)
		return (s_len);
	if (size > d_len)
		res = d_len + s_len;
	else
		res = s_len + size;
	while (i + d_len < size - 1 && src[i])
	{
		dst[i + d_len] = src[i];
		i++;
	}
	dst[i + d_len] = '\0';
	return (res);
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
	unsigned	char			*d;
	unsigned	const	char	*s;

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
