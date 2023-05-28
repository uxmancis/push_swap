/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebitas11.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:40:53 by uxmancis          #+#    #+#             */
/*   Updated: 2023/05/15 18:52:08 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct bothstacks
{
    int a;
    int b;
}   t_both;

t_both put (int a, int b)
{
    t_both v1;

    v1.a = a;
    v1.b = 2;
    return (v1);
}

int main(void)
{
    t_both v1;
    int a;
    int b;

    a = 1;
    b = 1;
    v1 = put(a, b);
    printf("v1.a = %d\n", v1.a);
    printf("v1.b = %d\n", v1.b);
    return (0);
}