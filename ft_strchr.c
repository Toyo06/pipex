/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:08:44 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/17 20:14:47 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c > 127)
		return ((char *)s);
	while (s[i] && s[i] != c)
			i++;
	if (s[i] == c)
		return ((char *) s + i);
	return (NULL);
}
