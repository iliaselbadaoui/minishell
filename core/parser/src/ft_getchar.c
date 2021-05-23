/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:29:29 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:52:26 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int	ft_getchar(void)
{
	char			c;
	int				total;
	struct termios	term;
	struct termios	init;

	total = 0;
	tcgetattr(0, &term);
	tcgetattr(0, &init);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
	while (read(0, &c, 1) <= 0)
		;
	total += c;
	while (read(0, &c, 1) > 0)
		total += c;
	tcsetattr(0, TCSANOW, &init);
	return (total);
}
