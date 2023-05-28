/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebitas6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:41:44 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/13 14:21:15 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int len_arr(int *arr)
{
    int len; 

    len = 0;
    while(arr[len])
    {
        printf("bai\n");
        len++; 
    }
    return (len);
}

void put_str(char *str)
{
	int len;

	len = 0;
	while(str[len] != '\0')
	{
		write(1, &str[len], 1);
		len++;
	}
    write(1, "\n", 1);
}

int main(void)
{
    int *arr;
    int len;
    char *str;

    arr = malloc(sizeof(int)*4);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;

    str = "uxue";
    len = len_arr(arr);
    printf("len = %d\n", len);
    put_str(str);
    return (0);
}