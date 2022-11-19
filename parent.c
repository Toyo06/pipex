/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <sroggens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 03:53:04 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/18 07:10:23 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent1(t_base *base, char **envp, char **argc)
{
	base->parsing.checkvalid1 = finalparsing1(envp, base, argc);
	if (base->parsing.checkvalid1)
	{
		base->fork.fork1 = fork();
		if (base->fork.fork1 < 0)
			messageerror(0, argc);
		else if (base->fork.fork1 == 0)
		{
			dup2(base->fd.fd[0], 0);
			dup2(base->end.end[1], 1);
			close(base->end.end[0]);
			close(base->end.end[1]);
			execve(base->parsing.finalpath, base->cmd.cmd1, envp);
		}
	}
}

void	parent2(t_base *base, char **envp, char **argc)
{
	if (access(base->parsing.finalpath, F_OK) == 0)
		free(base->parsing.finalpath);
	base->parsing.checkvalid2 = finalparsing2(envp, base, argc);
	if (base->parsing.checkvalid2)
	{
		base->fork.fork2 = fork();
		if (base->fork.fork2 < 0)
			messageerror(0, argc);
		else if (base->fork.fork2 == 0)
		{
			dup2(base->fd.fd[1], 1);
			dup2(base->end.end[0], 0);
			execve(base->parsing.finalpath, base->cmd.cmd2, envp);
		}
	}
}
