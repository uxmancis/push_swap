#include "push_swap.h"

void put_arr(int *stack)
{
	int i;
	int	*tmp;

	tmp = stack;
	i = 0;
	while((*tmp))
	{
		printf("stack[%d] = %d\n", i, *tmp);
		i++;
		tmp++;
	}		
}