/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolucmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 06:03:31 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/18 06:42:51 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	checkabsolu1(t_base *base)
{
	int	i;

	i = 0;
	while (base->parsing.paths[i])
	{
		free(base->parsing.paths[i]);
		i++;
	}
	base->parsing.finalpath = ft_strdup(base->cmd.cmd1[0]);
	if (access(base->parsing.finalpath, F_OK) == 0)
		return (1);
	else
	{
		ft_printf("zsh: no such file or directory: %s\n",
			base->parsing.finalpath);
		free(base->parsing.finalpath);
	}
	return (0);
}

int	checkabsolu2(t_base *base, char **argc)
{
	base->parsing.finalpath = ft_strdup(base->cmd.cmd2[0]);
	if (access(base->parsing.finalpath, F_OK) == 0)
		return (1);
	else
		messageerror(4, argc);
	return (0);
}
