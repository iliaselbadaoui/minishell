/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 13:14:24 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/03 18:58:56 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_init_format(t_format_container *holder)
{
	holder->conv = 0;
	holder->mins = 0;
	holder->prec = 0;
	holder->prec_no_spec = 0;
	holder->star = 0;
	holder->zero = 0;
	ft_init_type(&(holder->type));
}

void	ft_init_type(t_type *type)
{
	type->c = 0;
	type->i = 0;
	type->l = 0;
	type->ui = 0;
	type->s = 0;
}
