/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:20:35 by uxmancis          #+#    #+#             */
/*   Updated: 2023/06/10 12:36:58 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_duplicate (int *arr, int len)
{
	int	i;
	int y; 

	i = 0;
	while (i < len)
	{
		y = i + 1;
		while (y < len)
		{
			if (arr[i] == arr[y])
            {
                printf("Duplicate location, i = %d | y = %d\n", i, y);
                return (1); //duplicated integers have been found
            }
            y++;
		}
		i++;
	}
    return (0);
}

int main(void)
{
    int arr[] = {123, 888, 999, -22, -22, -22789, 9, 9, 9, 9, -9};
    if (ft_duplicate (arr, 11) == 1)
        printf("Yes, duplicated integers\n");
    else
        printf("everything OK! NO duplicate\n");
    return (0);
}