#include	<iostream>

using namespace std;

int	a[64][64];
int	visited[64][64];
int	n;
int	q;
int	dr[4] = {-1, 0, 1, 0};
int	dc[4] = {0, -1, 0, 1};

int	power_of_2(int num)
{
	int	result;

	result = 1;
	for (int i = 1; i <= num; i++)
		result *= 2;
	return result;
}

void	rotate(int l);

int	is_surrounded(int r, int c)
{
	if (r == 0)
		if (c == 0 && c == n - 1)
			return (0);
	else if (r == n - 1)
		if (c == 0 && c == n - 1)
			return (0);
	int	cnt;

	cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int new_r = r + dr[i];
		int	new_c = c + dc[i];

		if (new_r >= 0 && new_r <= n - 1 && new_c >= 0 && new_c <= n - 1)
		{
			if (a[new_r][new_c] > 0)
				cnt++;
		}
	}
	if (cnt >= 3)
		return (1);
	else
		return (0);
}

void	decrease_not_surrounded(void)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] > 0 && is_surrounded(i, j) == 0)
				a[i][j]--;
		}
	}
}

int	total_sum(void)
{
	int	result;

	result = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			result += a[i][j];
	return (result);
}

int	dfs(int start_r, int start_c)
{
	int	result = 1;
	
}

int	biggest(void)
{
	int	result;

	result = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (visit[i][j] == 0 && a[i][j] != 0)
			{
				int	dfs_result = dfs(i, j);
				if (dfs_result > result)
					result = dfs_result;
			}
		}
	}
	return (result);
}

int	main(void)
{
	int	l;

	cin >> n >> q;
	n = power_of_2(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < q; i++)
	{
		cin >> l;
		rotate(l);
		decrease_not_surrounded();
	}
	cout << total_sum() << "\n" << biggest() << "\n";
	return (0);
}
