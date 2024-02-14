#include	<stdio.h>

int	year(int e, int s, int m)
{
	int i;
	
    i = s;
    if (e == 15)
        e = 0;
    if (s == 28)
        s = 0;
    if (m == 19)
        m = 0;
	while (1)
	{
		if (i % 19 == m)
		{
			if (i % 15 == e)
				return (i);
			else
				i += 28 * 19;
		}
		else
			i += 28;
	}
}

int main(void)
{
	int e;
	int s;
	int m;
	
	scanf("%d", &e);
	scanf("%d", &s);
	scanf("%d", &m);

	printf("%d\n", year(e, s, m));
	return (0);
}
