/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:52:36 by omercade          #+#    #+#             */
/*   Updated: 2021/09/09 19:19:23 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static void	father_process(int *fd, char **xarg, char **envp)
{
	int		fd_outfile;
	char	*cmd_route;
	char	**cmd_arg;

	fd_outfile = open(xarg[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	fd_check(fd_outfile, xarg[4]);
	dup2(fd_outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fd_outfile);
	cmd_arg = ft_split(xarg[3], ' ');
	cmd_route = path_finder(ft_strdup(cmd_arg[0]), envp);
	if (execve(cmd_route, cmd_arg, envp) == -1)
	{
		 ft_putstr_fd("Error: Command#2 not found.\n", 2);
		secure_freedom(cmd_route);
		free_2d(cmd_arg);
	}
}

static void	child_process(int *fd, char **xarg, char **envp)
{
	int		fd_infile;
	char	*cmd_route;
	char	**cmd_arg;

	fd_infile = open(xarg[1], O_RDONLY);
	fd_check(fd_infile, xarg[1]);
	dup2(fd_infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fd_infile);
	cmd_arg = ft_split(xarg[2], ' ');
	cmd_route = path_finder(ft_strdup(cmd_arg[0]), envp);
	if (execve(cmd_route, cmd_arg, envp) == -1)
	{
		 ft_putstr_fd("Error: Command#1 not found.\n", 2);
		secure_freedom(cmd_route);
		free_2d(cmd_arg);
	}
}

int	main(int narg, char **xarg, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (narg != 5)
		perror("Arguments: ");
	else
	{
		status = 0;
		pipe(fd);
		pid = fork();
		if (pid < 0)
			perror("Error: Fork error.\n");
		else if (!pid)
			child_process(fd, xarg, envp);
		else
		{
			father_process(fd, xarg, envp);
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
