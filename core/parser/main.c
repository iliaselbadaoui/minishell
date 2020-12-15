/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/15 12:59:43 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>
int		main()
{
	// . ../ path/filename : should be handled
	// syntax_checker(strdup("ilias \"elbadaoui\" \"ilias"));
	if (syntax_checker(strdup("echo ilias | echo")))
	{
		out("IT'S WORKING");
	}
	// if (check_file(">>>> ilias"))
	// 	printf("TRUE\n");
	// else
	// 	printf("FALSE\n");
	return (0);
}
