/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:11:18 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/05 18:42:43 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_strlen(const char *str)
{
	int	len;

	if (!str)
		return (6);
	len = 0;
	while (str[len] != '\0')
	{
		if (str[len + 1] == '\0')
			return (len + 1);
		else if (str[len + 2] == '\0')
			return (len + 2);
		else if (str[len + 3] == '\0')
			return (len + 3);
		else if (str[len + 4] == '\0')
			return (len + 4);
		else if (str[len + 5] == '\0')
			return (len + 5);
		else if (str[len + 6] == '\0')
			return (len + 6);
		else if (str[len + 7] == '\0')
			return (len + 7);
		len += 8;
	}
	return (len);
}
