/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfpipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 07:11:35 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/16 18:12:50 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putcharprintf(char c, int *counter)
{
	write(2, &c, 1);
	(*counter)++;
}

int	ft_printf(const char *txt, ...)
{
	int		i;
	int		count;
	va_list	params;

	va_start(params, txt);
	i = 0;
	count = 0;
	while (txt[i])
	{
		if (txt[i] == '%')
		{
			i++;
			ft_selectnextwords(params, txt[i], &count);
		}
		else
			ft_putcharprintf(txt[i], &count);
		i++;
	}
	va_end(params);
	return (count);
}
