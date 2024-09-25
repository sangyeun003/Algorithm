#include	<iostream>
#include	<string>

using namespace std;

int	arabia_to_num(string s)
{
	int	result;

	result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'I')
		{
			if (i + 1 < s.length() && s[i + 1] == 'V')
			{
				result += 4;
				i++;
			}
			else if (i + 1 < s.length() && s[i + 1] == 'X')
			{
				result += 9;
				i++;
			}
			else
				result += 1;
		}
		else if (s[i] == 'X')
		{
			if (i + 1 < s.length() && s[i + 1] == 'L')
			{
				result += 40;
				i++;
			}
			else if (i + 1 < s.length() && s[i + 1] == 'C')
			{
				result += 90;
				i++;
			}
			else
				result += 10;
		}
		else if (s[i] == 'C')
		{
			if (i + 1 < s.length() && s[i + 1] == 'D')
			{
				result += 400;
				i++;
			}
			else if (i + 1 < s.length() && s[i + 1] == 'M')
			{
				result += 900;
				i++;
			}
			else
				result += 100;
		}
		else if (s[i] == 'M')
		{
			result += 1000;
		}
		else if (s[i] == 'V')
		{
			result += 5;
		}
		else if (s[i] == 'L')
		{
			result += 50;
		}
		else if (s[i] == 'D')
		{
			result += 500;
		}
	}
	return (result);
}

string	num_to_arabia(int n)
{
	string	result;
	int		thousands;
	int		hundreds;
	int		tens;
	int		ones;

	thousands = n / 1000;
	hundreds = n % 1000 / 100;
	tens = n % 100 / 10;
	ones = n % 10;
	for (int i = 0; i < thousands; i++)
		result.append("M");
	if (hundreds == 4)
		result.append("CD");
	else if (hundreds == 9)
		result.append("CM");
	else
	{
		if (hundreds >= 5)
		{
			result.append("D");
			hundreds -= 5;
		}
		for (int i = 0; i < hundreds; i++)
			result.append("C");
	}
	if (tens == 4)
		result.append("XL");
	else if (tens == 9)
		result.append("XC");
	else
	{
		if (tens >= 5)
		{
			result.append("L");
			tens -= 5;
		}
		for (int i = 0; i < tens; i++)
			result.append("X");
	}
	if (ones == 4)
		result.append("IV");
	else if (ones == 9)
		result.append("IX");
	else
	{
		if (ones >= 5)
		{
			result.append("V");
			ones -= 5;
		}
		for (int i = 0; i < ones; i++)
			result.append("I");
	}
	return (result);
}

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string	arabia;
	int		result;

	result = 0;
	for (int i = 0; i < 2; i++)
	{
		cin >> arabia;
		result += arabia_to_num(arabia);
	}
	cout << result << "\n" << num_to_arabia(result);
	return (0);
}
