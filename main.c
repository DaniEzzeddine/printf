#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
	printf("{%*c}", -15, 0);
	printf("\n");
	printf("--------------\n");
	printf("--------------\n");
	ft_printf("{%*c}", -15, 0);


}