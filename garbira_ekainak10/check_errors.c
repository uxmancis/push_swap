/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:43:44 by uxmancis          #+#    #+#             */
/*   Updated: 2023/06/10 16:02:37 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
                return (1);
            y++;
		}
		i++;
	}
    return (0);
}

int next_position_with_int (char **argv, int x, int y, int counter_previous, int keep_len_arg)
{
	int n;

	//printf("line 33 | y = %d\n", y);
    y = y + counter_previous;
	n = 0;
    //printf("line 35 | y = %d | argv[%d][%d] = %c\n", y, x, y, argv[x][y]);
	while (ft_isdigit(argv[x][y]) == 0 && y < keep_len_arg)
	{
        //printf("line 41 | bucle barruan | y = %d | keep_len_arg = %d | argv[%d][%d] = %c\n", y, keep_len_arg, x, y, argv[x][y]);
		n++;
		y++;
	}
    //printf("line 42 | y = %d | n = %d\n", y, n);
    if (y >= (keep_len_arg - 1)) //si la posición ya es mayor al len, es decir, si ya nos hemos pasado el largo del argumento
        return (0);
    //printf("line 45 | la posición del comienzo del próximo primer dígito del int, y = %d\n", y);
	return (y);
}

/*DESCRIPTION:
Rellena el str con los caracteres que componen nuestro futuro int. Así, genera
el str que le mandaremos a atoi.
____________________________*/
char *fill_str(char **argv, int x, int y, char *str, int counter)
{
	int	i;
	//int len_arg;

	//printf("line 63 | inside fill_str\n");
	i = 0;
	while (counter > 0)
	{
		//printf("line 66 || dentro de fill_str || x = %d || y = %d || argv[%d][%d] = %c\n", x, y, x, y, argv[x][y]);
		str[i] = argv[x][y];
		i++;
		y++;
		counter--;
	}
	//printf("x = %d | y = %d\n", x, y);
	str[i] = '\0';
	//printf("str = %s\n", str);
	return (str);
}

                    
/*DESCRIPTION:
fill_stack function updates list_pre_checker2 by filling it with values
-----------------------------------------------------------------*/
int *fill_stack (int *list_pre_checker2, int argc, char **argv)
{
    //int *stack_a;
    int x;
    int y;
    int a;
    int b;
    char *str;
    int counter;
    int m;
    int len_arg;
    int keep_len_arg;


    //printf("kaixo kaixo estamos en fill_stack\n");
    x = 1;
    a = 0;
    m = 0;
    //printf("argc = %d\n", argc);
    while(x < argc) // argc - 1 num.ºde argumentos que recorrer en total
    {
        //printf("1ST BUCLE IN\n");
        len_arg = ft_strlen(argv[x]);
        keep_len_arg = len_arg;
		//printf("line 135 | len_arg = %d\n", len_arg);
        y = 0;
        //printf("argumentu berri honekin hasi aurretik, EGOERA: x = %d | y = %d | argv[%d][%d] = %c\n", x, y, x, y, argv[x][y]);
        while(len_arg > 0 ) //1. siempre primero dentro del mismo argumento
        {
            while(ft_isdigit(argv[x][y]) == 0)
                y++;
            //printf("2ND BUCLE IN\n");
            if(ft_isdigit(argv[x][y]) == 1) //tantas veces como n.º de caracteres tenga cada número, entrará aquí. Ej.: si el int es -8, entrará 2 veces. Si el int es 1234, entrará 4 veces
            {
				//printf("3RD CONDITION\n");
                counter = numof_digits(argv, x, y, len_arg);
                //printf("numof_digits of int = %d\n", counter);
                str = malloc(sizeof(char) * (counter + 1)); //+1 = `para el final nulo
                str = fill_str(argv, x, y, str, counter);
                //printf("antes de atoi2, char *str = %s\n", str);
				//printf("m = %d\n", m);
                list_pre_checker2[m] = atoi(str);
				//printf("line 198 | m = %d | after atoi | list_pre_checker2[%d] = %d\n", m, m, list_pre_checker2[m]);
                free (str);
                //printf("line 200 | successful free, nos salimos del if\n");
            }
            m++;
            //printf("line 204 | y = %d | keep_len_arg = %d\n", y, keep_len_arg);
            y = next_position_with_int(argv, x, y, counter, keep_len_arg); //next_position_with_int devuelve 0 si ya ha acabado el argumento = entonces vamos a x++ next argumento, si no, nos devuelve la posición en la que habrá un siguiente int dentro de nuestro argumento actual
            //printf("line 207 | y = %d\n", y);
            if (y == 0)
            {
                //printf("nohemoh pazao del argumentoo, ya no hay más integers aquí, vamonoh to the next argumento!\n");
                break;
            }
			//printf("line 173 | len_arg = %d | x = %d | y = %d\n", len_arg, x, y);
			//printf("line 203 | y means NEXT POSITION OF SAME ARGUMENT WHERE NEXT INT WILL START, y = %d\n", y);
            len_arg--;
			//printf("line 176 | hurrengo buelta eman aurretik: m = %d | x = %d | y = %d | len_arg = %d | argv[%d][%d] = %c\n", m, x, y, len_arg, x, y, argv[x][y]);
        }
        x++;
		//printf("line 178 | NEXT argumentora! :) \n");
    }
	return (list_pre_checker2);
}

/*DESCRIPTION: 
numof_int functions returns the number of integers we will find along the arguments, 
which means, the len of our stack_a. 

In our case, we will also use this len for defining the size of stack_b.
------------------------------------------------------------------------------------*/
int numof_int(int argc, char **argv)
{
	int	x;
	int	y;
	int	counter;
	int len_arg;

	x = 1;
    counter = 0;
    //printf("line 248 || argc = %d |||||||| and x = %d\n", argc, x);
    while(x < argc)
    {
        //printf("line 182 || x = %d\n", x);
        //printf("yes\n");
        //y = 0;
        len_arg = ft_strlen(argv[x]);
        //printf("line 188 || len_arg = %d\n", len_arg);
        y = 0;
        while(len_arg > 0) //1. siempre primero dentro del mismo argumento
        {
            //printf("hellowis\n");
            //printf("line 190 || x = %d || y = %d\n", x, y);
            if(argv[x][y] != ' ')
            {
                //printf("line 193                  || x = %d || y=%d || argv[x][y] = %c\n", x, y, argv[x][y]);
                counter++; //en cuanto encuentre algo distinto al espacio (negativo o digito), sumar counter
                while(argv[x][y] != ' ' && len_arg > 0)
                {
                    //printf("sartu da, x = %d eta y = %d eta len_arg = %d\n", x, y, len_arg);
                    y++;
                    len_arg--;
                }
                //printf("counter = %d\n", counter);
               
            }
            y++;
            len_arg--;
        }
        x++;
        //printf("&&&&&& line 278 || kanpuan gare || counter lleva %d hemos estado en x = %d, y vamos a x = %d\n", counter, (x-1), x);
    }
    //printf("---------------------------------->>>>>>>>>>>> counter FINALLY = %d\n", counter);
	return(counter);
}

/*DESCRIPTION:
checker_2 makes sure that there are no duplicated numbers along the arguments.
It returns error(1) or not error(0) after analysing arguments.
How?
1. Convert arguments in integers of an array
    1.0 counts how many integers are among arguments. Variable used: counter
    1.1 allocates "counter" size memory for int *stack_a with malloc.
    1.1 splits numbers of arguments through identifying spaces. Every space = split!
    1.2 each number = 1 position of array as integer
2. Compares integers (is there any value repeated? YES/NO)

//para que entre aquí ya solo tienen que ser los siguientes: (checker_1)
- dígitos
- espacios
- negativos

1: error found
0: NO error found, OK!
---------------------------------------------------------------------------*/
int checker_last(int argc, char **argv)
{
    //int x;
    //int y;
    //int counter;
    int *list_pre_checker2;
    int len_stack;

    len_stack = numof_int(argc, argv);
	//printf("line 369 | len_stack = %d\n", len_stack);
	list_pre_checker2 = malloc(sizeof(int)*len_stack);
    //printf("kaixo estamos aquí\n");
    list_pre_checker2 = fill_stack(list_pre_checker2, argc, argv); //así rellenenan los números en cada posición del array list_pre_checker_2. Si no hay duplicados, este se convertirá en el stack_a. En caso contrario, error. Le pasamos la dirección de list
	//printf("linr 373 | len_stack = %d | list_pre_checker2: \n", len_stack);
    //put_arr(list_pre_checker2, len_stack);
	if (ft_duplicate(list_pre_checker2, len_stack) == 1)
	{
		//printf("sí hay duplicados\n");
		return (1);
	}
	else
		return (0);
}

/*DESCRIPTION:
checker_1 makes sure that only digits (0-9), space ' ' and negative sign '-'
are found along the arguments and returns a integer indicating whether if
the error has been found or not.
1: error found
0: NO error found, OK!
---------------------------------------------------------------------------*/
int	checker_1(int argc, char **argv)
{
	int x;
	int y;

	x = 1;
	y = 0;
	while (x < argc)
	{
		y = 0;
		while (argv[x][y] != '\0')
		{
			if (ft_isdigit(argv[x][y]) == 1 || argv[x][y] == (char)32)
			{
				//printf("yes\n");
				y++;
			}
			else
			{
				//printf("x = %d\ny = %d\n", x, y);
				return (1);
			}
		}
		x++;
	}
	return (0);
}

int checkers_index (int argc, char **argv)
{
	if (checker_1(argc, argv) == 0)
	{
		if (checker_last(argc, argv) == 0)
		{
			return (0); //esto es que ha pasado todos los errores, vamos!
		}
		else
			return (1);
	}
	else
		return (1);
}
