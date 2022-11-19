/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 01:31:34 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/18 01:31:35 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		i;

	i = 0;
	if (!src)
		return (0);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
