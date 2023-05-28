/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebitas8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:25:05 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/14 14:30:11 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*DESCRIPTION
strcmp function compares str1 and str2. 
Returns:
1: NOT the same, they are different
0: 100% same str.
------------------------------------------------*/
int strcmp (const char *str1, const char *str2)
{
	int i; 
	
	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else
			return(1);
	}
	return (0);
}

void decide_move(char *move_type) //cambiaré el prototipo a int *decide_move, porque como lo utilizaré para llamar a los movimientos, voy a querer recibir los stacks modificados.
{
	//put_str(move_type);
	if(strcmp(move_type, "sa") == 0)
	{
		printf("sa\n");
		//call to the movement
		//print the move_typ
	}
	/*if(move_type == "ra")
		printf("ra\n");
	if(move_type == "rra")
		printf("rra\n");
	if(move_type == "pa")
		printf("pa\n");
	if(move_type == "sb")
		printf("sb\n");
	if(move_type == "rb")
		printf("rb\n");
	if(move_type == "rrb")
		printf("rrb\n");
	if(move_type == "pb")
		printf("pb\n");*/
}

int main(void)
{
    char *move_type;
    int result;

    move_type = "sa";
    //result = strcmp(str1, str2);
    decide_move(move_type);
    //printf("result = %d\n", result);
    return (0);
}