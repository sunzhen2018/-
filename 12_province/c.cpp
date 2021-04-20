#include <iostream>
#include <set>
using namespace std;
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
struct Line
{
	int k_fenzi, k_fenmu, b_fenzi, b_fenmu;
	Line(int x1, int y1, int x2, int y2)
	{
		k_fenzi = y2 - y1;
		k_fenmu = x2 - x1;
		b_fenzi = (x2 - x1) * y1 - (y2 - y1) * x1;
		b_fenmu = x2 - x1;
		int a = gcd(k_fenzi, k_fenmu);
		k_fenzi /= a;
		k_fenmu /= a;
		int b = gcd(b_fenzi, b_fenmu);
		b_fenzi /= b;
		b_fenmu /= b;
	}
};
bool operator<(const Line &x, const Line &y)
{
	if (x.k_fenzi < y.k_fenzi)
	{
		return true;
	}
	else if (x.k_fenzi == y.k_fenzi)
	{
		if (x.k_fenmu < y.k_fenmu)
		{
			return true;
		}
		else if (x.k_fenmu == y.k_fenmu)
		{
			if (x.b_fenzi < y.b_fenzi)
			{
				return true;
			}
			else if (x.b_fenzi == y.b_fenzi)
			{
				if (x.b_fenmu < y.b_fenmu)
				{
					return true;
				}
				else if (x.b_fenmu == y.b_fenmu)
				{
					return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
set<Line> s;
int main()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			for (int k = 0; k < 20; k++)
			{
				for (int p = 0; p < 21; p++)
				{
					if (!(i == k || j == p))
					{
						Line line(i, j, k, p);
						s.insert(line);
					}
				}
			}
		}
	}
	cout << s.size() + 20 + 21;
}
//20*21
//40257
