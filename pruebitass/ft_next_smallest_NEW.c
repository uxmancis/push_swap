/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_smallest_NEW.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:04:33 by uxmancis          #+#    #+#             */
/*   Updated: 2023/06/12 20:18:28 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_value_next_smallest_NEW (int *stack_b, int len_b, int travel_nb)
{
    int numof_smaller_or_same_values;
    int i;
    int *arr_smaller_values_tmp;
    int keep_len_b;
    int y;
    int biggest_among_smallers;

    keep_len_b = len_b;
    numof_smaller_or_same_values = 0;
    i = 0;
    while (len_b > 0)
    {
        if (stack_b[i] <= travel_nb)
            numof_smaller_or_same_values++;
        i++;
        len_b --;
    }
    printf("numof_smaller_or_same_values = %d\n", numof_smaller_or_same_values);
    arr_smaller_values_tmp = malloc(sizeof(int) * numof_smaller_or_same_values);
    i = 0;
    y = 0;
    while (keep_len_b > 0)
    {
        if (stack_b[i] <= travel_nb)
        {
            arr_smaller_values_tmp[y] = stack_b[i];
            printf("arr[%d] = %d\n", i, arr_smaller_values_tmp[i]);
            y++;
        }
        i++;
        keep_len_b--;
    }
    printf("hello\n");
    i = 0;
    y = 0;
    biggest_among_smallers = arr_smaller_values_tmp[y];
    while (numof_smaller_or_same_values > 0)
    {
        printf("biggest_among_smallers = %d\n", biggest_among_smallers);
        if (arr_smaller_values_tmp[y] > biggest_among_smallers)
            biggest_among_smallers = arr_smaller_values_tmp[y];
        y++;
        numof_smaller_or_same_values--;
    }
    return (biggest_among_smallers);
}

int main (void)
{
    int *arr;
    arr = malloc(sizeof(int) * 5);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;

    printf("next smallest = %d\n", ft_value_next_smallest_NEW(arr,5,3));
    free (arr);
    return (0);
}