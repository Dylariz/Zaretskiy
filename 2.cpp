#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b;
	int t, y, q = 1;
	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		if (i % 2 == 0)
		{
			y = (int)sqrt(i);
			q = 1;

			for (int j = 2; j <= y; j++)
			{
				if (i % j != 0)
					continue;

				if (j % 2 == 0) q++;
				t = i / j;

				if (t % 2 == 0) { q++; if (j == t) q--; }
				if (q > 3) break;
			}
			if (q == 3) { cout << i << endl; }
		}
	}
}