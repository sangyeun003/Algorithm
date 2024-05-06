#include	<stdio.h>

int main(void)
{
	int n;
	int k;
	int coin[10];
	int count;
	
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);
	count = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		count += k / coin[i];
		k %= coin[i];
	}
	printf("%d\n", count);
	return (0);
}
