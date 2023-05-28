/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebitas7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:17:13 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/13 16:46:55 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void put_matrix (char **list_moves)
{
	int x; 
	int y;
    
	x = 0;
	while(list_moves[x][0] != '\0')
	{
        //printf("jaja");
		y = 0;
		while(list_moves[x][y] != '\0')
		{
			write(1, &list_moves[x][y], 1);
            y++;
		}
		write(1, "\n", 1);
		x++;
	}
}

char **list_moves(int numof_moves_top_stack, char *move_type_top_stack, int numof_moves_org_b, char *move_type_org_b)
{
	char **list;

    list = malloc(sizeof(char *) * 4); //4 = 1 (top_stack) + 1 (org_b) + 1 pb + '\0'
    list[0] = malloc(sizeof(char)*3);
    list[1] = malloc(sizeof(char)*3);
    list[2] = malloc(sizeof(char)*3);
    list[3] = malloc(sizeof(char)*1);
    list[0][0] = 'r';
    list[0][1] = 'a';
    list[0][2] = '\0';
    list[1][0] = 'r';
    list[1][1] = 'b';
    list[1][2] = '\0';
    list[2][0] = 'p';
    list[2][1] = 'b';
    list[2][2] = '\0';
    list[3][0]= '\0';
    put_matrix(list);
    return (list);
}

int main(void)
{
    list_moves(2,"ra", 3, "rb");
    return(0);
}