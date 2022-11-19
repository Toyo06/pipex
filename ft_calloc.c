/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:46:36 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/17 21:25:12 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t nbel, size_t size)
{
	void	*ptr;
	size_t	total;

	total = nbel * size;
	ptr = malloc(total);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, total);
	return (ptr);
}
