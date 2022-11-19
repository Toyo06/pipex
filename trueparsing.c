/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trueparsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <sroggens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 04:17:10 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/18 06:51:27 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	seekpath(char **env, t_base *base, char **argc)
{
	int	i;

	i = 0;
	if (!env)
		messageerror(5, argc);
	while (env[i] && ft_strnstr(env[i], "PATH=", 5) == 0)
	{
		if (ft_strnstr(env[i], "PATH=", 5) == 0 && env[i + 1] == NULL)
			messageerror(5, argc);
		i++;
	}
	base->parsing.paths = ft_split(ft_strchr(env[i], '=') + 1, ':');
	i = 0;
}

int	prepcmd1(char **argc, t_base *base, char **env)
{
	int	i;

	i = 0;
	seekpath(env, base, argc);
	if (ft_strnstr(argc[2], "/", ft_strlen(argc[2])))
	{
		base->cmd.cmd1 = ft_split(argc[2], ' ');
		return (3);
	}
	if (ft_strlen(argc[2]) == 0)
	{
		while (base->parsing.paths[i])
		{
			free(base->parsing.paths[i]);
			i++;
		}
		return (1);
	}
	base->cmd.cmd1 = ft_split(argc[2], ' ');
	return (0);
}

int	prepcmd2(char **argc, t_base *base, char **env)
{
	int	i;

	i = 0;
	seekpath(env, base, argc);
	if (ft_strnstr(argc[3], "/", ft_strlen(argc[3])))
	{
		base->cmd.cmd2 = ft_split(argc[3], ' ');
		return (3);
	}
	if (ft_strlen(argc[3]) == 0)
	{
		while (base->parsing.paths[i])
		{
			free(base->parsing.paths[i]);
			i++;
		}
		messageerror(4, argc);
	}
	if (argc[3] != NULL)
		base->cmd.cmd2 = ft_split(argc[3], ' ');
	return (0);
}

int	finalparsing1(char **env, t_base *base, char **argc)
{
	int	i;

	i = 0;
	base->parsing.check1 = prepcmd1(argc, base, env);
	if (base->parsing.check1 == 3)
		return (checkabsolu1(base));
	while (base->parsing.paths[i] && base->parsing.check1 != 1)
	{
		addbackslash1(base);
		base->parsing.finalpath = ft_strjoin(base->parsing.slash,
				base->cmd.cmd1[0]);
		free(base->parsing.slash);
		if (access(base->parsing.finalpath, F_OK) == 0)
		{
			freeallbis(base, i);
			return (1);
		}
		free(base->parsing.finalpath);
		i++;
	}
	ft_printf("zsh: command not found: %s\n", argc[2]);
	return (0);
}

int	finalparsing2(char **env, t_base *base, char **argc)
{
	int	i;

	i = 0;
	base->parsing.check2 = prepcmd2(argc, base, env);
	if (base->parsing.check2 == 3)
		return (checkabsolu2(base, argc));
	while (base->parsing.paths[i])
	{
		addbackslash2(base);
		base->parsing.finalpath = ft_strjoinbis(base->parsing.slash,
				base->cmd.cmd2[0]);
		free(base->parsing.slash);
		if (access(base->parsing.finalpath, F_OK) == 0)
		{
			freeallbis(base, i);
			return (1);
		}
		free(base->parsing.finalpath);
		i++;
	}
	messageerror(4, argc);
	return (0);
}
