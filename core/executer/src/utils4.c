/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:21:33 by mait-si-          #+#    #+#             */
/*   Updated: 2021/04/12 14:21:43 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

int	get_error(int ret)
{
	g_error = ret;
	if (ret == -1)
		g_error = 0;
	if (ret == 255)
	{
		ret = -1;
		g_error = 255;
	}
	return (ret);
}
