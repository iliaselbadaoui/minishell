/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:40:55 by ielbadao          #+#    #+#             */
/*   Updated: 2019/11/21 11:26:37 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_match_conversion(char conv)
{
	char	*pattern;

	pattern = "cspdiuxX%";
	if (ft_strchr(pattern, conv))
		return (1);
	return (0);
}
