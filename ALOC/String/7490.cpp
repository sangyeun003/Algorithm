#include	<iostream>
#include	<string>
#include	<string.h>

using namespace std;

int		t;
int		n;
string	s = "10203040506070809";
string	signals = " +-";

int	calculate(string s)
{
	int	result;
	int	temp_num;
	int	temp_signal;

	result = 0;
	temp_signal = '+';
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+' || s[i] == '-')
			temp_signal = s[i];
		else if (s[i] >= '1' && s[i] <= '9')
		{
			if (i <= s.length() - 2 && s[i + 1] == ' ')
			{
				temp_num = s[i] - '0';
				i += 2;
				while (i < s.length() && s[i] != '+' && s[i] != '-')
				{
					if (s[i] >= '1' && s[i] <= '9')
					{
						temp_num *= 10;
						temp_num += s[i] - '0';
					}
					i++;
				}
				if (temp_signal == '-')
					temp_num *= -1;
				result += temp_num;
				temp_signal = s[i];
			}
			else
			{
				if (temp_signal == '-')
					result += -1 * (s[i] - '0');
				else
					result += s[i] - '0';
			}
		}
	}
	return (result);
}

void	backtracking(int depth, int n, string formula)
{
	if (depth == 2 * n - 1)
	{
		if (calculate(formula) == 0)
		{
			cout << formula << "\n";
		}
		return ;
	}
	if (depth % 2 == 1)
	{
		for (int j = 0; j < 3; j++)
		{
			formula[depth] = signals[j];
			backtracking(depth + 2, n, formula);
		}
	}
}

void	zero(int n)
{
	string	formula;
	
	formula.append(s, 0, 2 * n - 1);
	backtracking(1, n, formula);
}

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		zero(n);
		cout << "\n";
	}
	return (0);
}
