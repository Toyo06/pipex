/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <sroggens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:14:42 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/18 06:14:01 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_cmd
{
	char	**cmd1;
	char	**cmd2;
}			t_cmd;

typedef struct s_parsing
{
	char	**paths;
	int		check1;
	int		check2;
	char	*finalpath;
	int		checkvalid1;
	int		checkvalid2;
	char	**paths2;
	char	*slash;
}				t_parsing;

typedef struct s_fork
{
	int		fork1;
	int		fork2;
}				t_fork;

typedef struct s_fd
{
	int		fd[2];
}				t_fd;

typedef struct s_end
{
	int	end[2];
}				t_end;

typedef struct s_base
{
	t_parsing	parsing;
	t_end		end;
	t_fd		fd;
	t_cmd		cmd;
	t_fork		fork;
}				t_base;

//---------------------main.c------------
int		main(int argv, char **argc, char **envp);
//-------------------outils.c------------
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	freeall(char **list);
char	*ft_strjoinbis(char *s1, char *s2);
//------------------printfpipex2.c-------
void	ft_selectnextwords(va_list params, char txt, int *count);
//------------------printfpipex.c--------
void	ft_putcharprintf(char c, int *counter);
int		ft_printf(const char *txt, ...);
//------------------parent.c-------------
void	parent1(t_base *base, char **envp, char **argc);
void	parent2(t_base *base, char **envp, char **argc);
//------------------splitpipex.c---------
char	**ft_split(char const *s, char c);
//------------------errorness.c----------
void	messageerror(int nb, char **argc);
//-------------------trueparsing.c-------
int		finalparsing2(char **env, t_base *base, char **argc);
int		finalparsing1(char **env, t_base *base, char **argc);
int		prepcmd2(char **argc, t_base *base, char **env);
int		prepcmd1(char **argc, t_base *base, char **env);
void	seekpath(char **env, t_base *base, char **argc);
//------------------ft_strchr.c----------
char	*ft_strchr(const char *s, int c);
//------------------ft_bzero.c-----------
void	ft_bzero(void *s, size_t n);
void	addbackslash1(t_base *base);
void	addbackslash2(t_base *base);
void	freeallbis(t_base *base, int i);
//------------------ft_calloc.c----------
void	*ft_calloc(size_t nbel, size_t size);
//------------------ft_strdup.c----------
char	*ft_strdup(const char *src);
//------------------absolucmd.c---------
int		checkabsolu1(t_base *base);
int		checkabsolu2(t_base *base, char **argc);
#endif
