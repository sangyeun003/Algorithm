#include	<iostream>

using namespace std;

char	wheels[4][9];

// clockwise
void	rotate(int n)
{
	char	temp;

	temp = wheels[n - 1][7];
	for (int i = 7; i > 0; i--)
		wheels[n - 1][i] = wheels[n - 1][i - 1];
	wheels[n - 1][0] = temp;
}

// counter clockwise
void	rotate_counter(int n)
{
	char	temp;

	temp = wheels[n - 1][0];
	for (int i = 1; i < 8; i++)
		wheels[n - 1][i - 1] = wheels[n - 1][i];
	wheels[n - 1][7] = temp;
}

void	rotate1(int dir)
{
	if (dir == 1)	// 시계 방향
	{
		if (wheels[0][2] != wheels[1][6])
		{
			if (wheels[1][2] != wheels[2][6])
			{
				if (wheels[2][2] != wheels[3][6])
				{
					rotate_counter(4);
				}
				rotate(3);
			}
			rotate_counter(2);
		}
		rotate(1);
	}
	else if (dir == -1)	// 반시계 방향
	{
		if (wheels[0][2] != wheels[1][6])
		{
			if (wheels[1][2] != wheels[2][6])
			{
				if (wheels[2][2] != wheels[3][6])
				{
					rotate(4);
				}
				rotate_counter(3);
			}
			rotate(2);
		}
		rotate_counter(1);
	}
}

void	rotate2(int dir)
{
	if (dir == 1)	// 시계 방향
	{
		if (wheels[1][2] != wheels[2][6])
		{
			if (wheels[2][2] != wheels[3][6])
			{
				rotate(4);
			}
			rotate_counter(3);
		}
		if (wheels[1][6] != wheels[0][2])
		{
			rotate_counter(1);
		}
		rotate(2);
	}
	else if (dir == -1)	// 반시계 방향
	{
		if (wheels[1][2] != wheels[2][6])
		{
			if (wheels[2][2] != wheels[3][6])
			{
				rotate_counter(4);
			}
			rotate(3);
		}
		if (wheels[1][6] != wheels[0][2])
		{
			rotate(1);
		}
		rotate_counter(2);
	}
}

void	rotate3(int dir)
{
	if (dir == 1)	// 시계 방향
	{
		if (wheels[2][2] != wheels[3][6])
		{
			rotate_counter(4);
		}
		if (wheels[2][6] != wheels[1][2])
		{
			if (wheels[1][6] != wheels[0][2])
			{
				rotate(1);
			}
			rotate_counter(2);
		}
		rotate(3);
	}
	else if (dir == -1)	// 반시계 방향
	{
		if (wheels[2][2] != wheels[3][6])
		{
			rotate(4);
		}
		if (wheels[2][6] != wheels[1][2])
		{
			if (wheels[1][6] != wheels[0][2])
			{
				rotate_counter(1);
			}
			rotate(2);
		}
		rotate_counter(3);
	}
}

void	rotate4(int dir)
{
	if (dir == 1)	// 시계 방향
	{
		if (wheels[3][6] != wheels[2][2])
		{
			if (wheels[2][6] != wheels[1][2])
			{
				if (wheels[1][6] != wheels[0][2])
				{
					rotate_counter(1);
				}
				rotate(2);
			}
			rotate_counter(3);
		}
		rotate(4);
	}
	else if (dir == -1)	// 반시계 방향
	{
		if (wheels[3][6] != wheels[2][2])
		{
			if (wheels[2][6] != wheels[1][2])
			{
				if (wheels[1][6] != wheels[0][2])
				{
					rotate(1);
				}
				rotate_counter(2);
			}
			rotate(3);
		}
		rotate_counter(4);
	}
}

int	cal_scores(void)
{
	int	total;

	total = 0;
	if (wheels[0][0] == '1')
		total += 1;
	if (wheels[1][0] == '1')
		total += 2;
	if (wheels[2][0] == '1')
		total += 4;
	if (wheels[3][0] == '1')
		total += 8;
	return (total);
}

int	main(void)
{
	int	k;
	int	n;
	int	dir;
	
	for (int i = 0; i < 4; i++)
		cin >> wheels[i];
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n >> dir;
		if (n == 1)
			rotate1(dir);
		else if (n == 2)
			rotate2(dir);
		else if (n == 3)
			rotate3(dir);
		else if (n == 4)
			rotate4(dir);
	}
	cout << cal_scores();
	return (0);
}
