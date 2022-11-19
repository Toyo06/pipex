/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:00:40 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/17 23:37:45 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*z;

	z = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*z = 0;
		z++;
		n--;
	}
}

void	addbackslash1(t_base *base)
{
	static int	i;

	base->parsing.slash = ft_strjoin(base->parsing.paths[i], "/");
	free(base->parsing.paths[i]);
	i++;
}

void	addbackslash2(t_base *base)
{
	static int	j;

	base->parsing.slash = ft_strjoin(base->parsing.paths[j], "/");
	free(base->parsing.paths[j]);
	j++;
}

void	freeallbis(t_base *base, int i)
{
	while (base->parsing.paths[i])
	{
		i++;
		if (base->parsing.paths[i])
			free(base->parsing.paths[i]);
	}
}
