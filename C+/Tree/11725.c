#include	<stdio.h>

int	main(void)
{
	int	n;
	int	parent[100001] = {0};
	int	node1;
	int	node2;

	scanf("%d", &n);
	parent[1] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &node1, &node2);
		if (parent[node1] == 0)
			parent[node1] = node2;
		else
			parent[node2] = node1;
	}
	for (int i = 2; i <= n; i++)
		printf("%d\n", parent[i]);
	return (0);
}


/*
입력
11
1 3
9 10
1 9
3 7
3 4
7 6
2 11
5 2
7 5
7 8
    
출력
11
1
3
7
7
3
7
1
0
0

답
5
1
3
7
7
3
7
1
9
2
*/