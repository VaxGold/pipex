/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:49:09 by omercade          #+#    #+#             */
/*   Updated: 2021/09/06 18:32:47 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	fd_check(int fd, char *file)
{
	if (fd < 0)
	{
		printf("Error: Cannot open file %s.\n", file);
		exit(0);
	}
	return ;
}
