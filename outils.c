/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:34:08 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/17 21:25:35 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		lenword1;
	int		lenword2;
	char	*str;

	i = -1;
	if (s1 && s2)
	{
		lenword1 = ft_strlen(s1);
		lenword2 = ft_strlen(s2);
		str = calloc((lenword1 + lenword2 + 1), 1);
		if (str == 0)
			return (0);
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
			str[lenword1 + i] = s2[i];
		str[lenword1 + i] = 0;
		return (str);
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == 0)
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	freeall(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
}

char	*ft_strjoinbis(char *s1, char *s2)
{
	int		i;
	int		lenword1;
	int		lenword2;
	char	*str;

	i = -1;
	if (s1 && s2)
	{
		lenword1 = ft_strlen(s1);
		lenword2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (lenword1 + lenword2 + 1));
		if (str == 0)
			return (0);
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
			str[lenword1 + i] = s2[i];
		str[lenword1 + i] = 0;
		return (str);
	}
	free(s1);
	return (NULL);
}
