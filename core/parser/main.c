/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/14 13:36:50 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>
int		main()
{
	// . ../ path/filename : should be handled
	// syntax_checker(strdup("ilias \"elbadaoui\" \"ilias"));
	syntax_checker(strdup(">> ilias echo \"ilias elbadaoui"));
	// if (check_file(">>>> ilias"))
	// 	printf("TRUE\n");
	// else
	// 	printf("FALSE\n");
	return (0);
}
