/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebitas9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:10:43 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/14 16:12:16 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char move_type(char *str)
{
	int i;
	char type; 

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == 'a' || str[i] == 'b')
		{
			if (str[i] == 'a')
			{
				type = 'a';
				return (type);
			}
			if (str[i] == 'b')
			{
				type = 'b';
				return (type);
			}
		}
		i++;
	}
	return (0);
}

int main(void)
{
    char *move;
    char type;

    move = "sb";
    type = move_type(move);
    printf("type = %c\n", type);
    return (0);
}