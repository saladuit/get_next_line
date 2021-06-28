/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                          |o_o || |                */
/*                                                    +:+ +:+         +:+     */
/*   By: saladin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:37:09 by saladin           #+#    #+#             */
/*   Updated: 2021/06/17 16:16:34 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	ft_tester(char *file)
{
	int fd;
	int read_code;
	char *line = 0;

	fd = open(file, O_RDONLY);
	printf("file descriptor: [%d]\t\n", fd);
	if (fd < 0)
	{
		printf("\nerror opening file\n");
		return (0);
	}
	read_code = 1;
	while (read_code > 0)
	{
		read_code = get_next_line(fd, &line);
		printf("return gnl: [%d]\t string:%s\n", read_code, line);
		free(line);
	}
	close(fd);
	return (0);
}

// // 						#######	MAIN	########

int	main(void)
{
	int user_input;

	printf("\n\t\tMAIN MENU\n\n");
	printf("enter 1 for empty file\n");
	printf("enter 2 for one_letter file\n");
	printf("enter 3 for one_line file\n");
	printf("enter 4 for two_lines file\n");
	printf("enter 5 for big file\n");
	printf("enter 6 for big file on one line\n");
	printf("enter 7 for non existent file\n\n");
	scanf("%d", &user_input);
	switch (user_input)
	{
	case 1:
		printf("Does an empty file work correctly?\n\n");
		ft_tester("empty.txt");
		break;
	case 2:
		printf("Does one letter work correctly?\n\n");
		ft_tester("one_letter.txt");
		break;
	case 3:
		printf("Does one line work correctly?\n\n");
		ft_tester("one_line.txt");
		break;
	case 4:
		printf("Do two lines work correctly?\n\n");
		ft_tester("two_lines.txt");
		break;
	case 5:
		printf("Does a big file work correctly?\n\n");
		ft_tester("ipsum.txt");
		break;
	case 6:
		printf("Does a big file on one line work correctly?\n\n");
		ft_tester("ipsum_one_line.txt");
		break;
	case 7:
		printf("Does a non existent file work correctly?\n\n");
		ft_tester("file_does_not_exist.txt");
		break;
	case 8:
		printf("Wrong Input Makefile GNL_lover");
		ft_tester("../GNL_lover/Makefile");
		break;
	default:
		printf("Invalid input\n\n");
		break;
	}
	return 0;
}
