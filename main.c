/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <sroggens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 02:24:05 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/18 07:12:14 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argv, char **argc, char **envp)
{
	t_base	base;

	if (argv < 5)
		messageerror(1, argc);
	if (argv > 5)
		messageerror(2, argc);
	base.fd.fd[0] = open(argc[1], O_RDONLY);
	base.fd.fd[1] = open(argc[4], O_WRONLY);
	if (base.fd.fd[1] < 0 && access(argc[4], F_OK) == 0)
		messageerror(6, argc);
	base.fd.fd[1] = open(argc[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (base.fd.fd[0] < 0)
		ft_printf("zsh: no such file or directory: %s\n", argc[1]);
	if (pipe(base.end.end) != 0)
		messageerror(3, argc);
	parent1(&base, envp, argc);
	free(base.parsing.paths);
	close(base.end.end[1]);
	parent2(&base, envp, argc);
	free(base.parsing.paths);
	close(base.end.end[0]);
	waitpid(base.fork.fork1, NULL, 0);
	waitpid(base.fork.fork2, NULL, 0);
}
