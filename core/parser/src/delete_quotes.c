/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:11:13 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 12:42:58 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_string	delete_quotes(t_string str)
{
	t_string	no_quote;

	no_quote = substring(str, 1, ft_strlen(str) - 2);
	return (no_quote);
}

t_string	variable_name_extracter(t_string str)
{
	t_string	no_dollar;

	no_dollar = substring(str, 1, ft_strlen(str) - 1);
	return (no_dollar);
}
