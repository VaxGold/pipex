/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:17:34 by omercade          #+#    #+#             */
/*   Updated: 2021/09/08 17:34:51 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**env_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (ft_split(ft_substr
					(envp[i], 5, ft_strlen(envp[i]) - 5), ':'));
		i++;
	}
	return (NULL);
}

char	*path_finder(char *cmd, char **envp)
{
	int		i;
	char	*cmd_route;
	char	**mypaths;

	if (access(cmd, F_OK) != 0)
	{
		mypaths = env_paths(envp);
		i = -1;
		while (mypaths[++i])
		{
			cmd_route = ft_slashjoin(mypaths[i], cmd);
			if (access(cmd_route, F_OK) == 0)
			{
				free_2d(mypaths);
				return (cmd_route);
			}
			secure_freedom(cmd_route);
		}
		free_2d(mypaths);
	}
	return (cmd);
}
