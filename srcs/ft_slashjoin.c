/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slashjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:11:19 by omercade          #+#    #+#             */
/*   Updated: 2021/09/07 17:41:10 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_slashjoin(const char *str1, const char *str2)
{
	char	*aux;
	char	*res;

	aux = ft_strjoin(str1, "/");
	res = ft_strjoin(aux, str2);
	secure_freedom(aux);
	return (res);
}
