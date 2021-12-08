/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:39:33 by omercade          #+#    #+#             */
/*   Updated: 2021/09/06 18:22:07 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	if (s != 0)
	{
		i = 0;
		while (s[i] != 0)
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
