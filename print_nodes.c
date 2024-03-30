#include "push_swap.h"

void	prt_n(t_nodes *a, t_nodes *b)
{
	if (a != 0)
	{
		printf ("nodes A \n");
		while (a)
		{
			printf("index : %i, value : %i\n", a->index, a->value);
			printf("next pointr %p\n", a->next);
			a = a->next;
		}
	}
	if (b != 0)
	{
		printf ("nodes B \n");
		while (b)
		{
			printf("index : %i, value : %i\n", b->index, b->value);
                        printf("next pointr %p\n", b->next);
			b = b->next;
		}
	}
}


