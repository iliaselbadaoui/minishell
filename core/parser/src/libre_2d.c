/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libre_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:37:21 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:14:13 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	libre_2d(char **arr)
{
	char	**cp;

	if (!arr)
		return ;
	cp = arr;
	while (*arr)
	{
		free(*arr);
		*arr = NULL;
		arr++;
	}
	free(cp);
	cp = NULL;
}
