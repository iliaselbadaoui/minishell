/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:21:44 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/10 19:26:02 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		envp_handler(t_string	*envp)
{
	g_envp = (t_string *)malloc(sizeof(t_string) * 256);
	g_envp[255] = NULL;
	while (envp[g_envp_count])
	{
		g_envp[g_envp_count] = ft_strdup(envp[g_envp_count]);
		g_envp_count++;
	}
	
}
