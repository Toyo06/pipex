/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errormess.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 03:54:32 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/18 07:18:37 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	messageerror(int nb, char **argc)
{
	if (nb == 0)
		ft_printf("zsh: Fork error\n");
	if (nb == 1)
		ft_printf("zsh: Not enought arguments\n");
	if (nb == 2)
		ft_printf("zsh: Too much arguments\n");
	if (nb == 3)
		ft_printf("zsh: Problem with pipe\n");
	if (nb == 4)
	{
		ft_printf("zsh: command not found: %s\n", argc[3]);
		exit(127);
	}
	if (nb == 5)
		ft_printf("zsh: Env not found\n");
	if (nb == 6)
	{
		ft_printf("zsh: permission denied: %s", argc[4]);
		exit(1);
	}
	exit(EXIT_FAILURE);
}
