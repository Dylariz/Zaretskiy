#include <iostream>
using namespace std;

int main()
{
    int n, summ = 0, res = 0;
    int a, b;
    cin >> a >> b;
	cerr << a << b;
    int max = a;
    for (int i = a; i < b; i++)
    {
        n = i;
        while (n != 0) { summ = summ + (n % 2); n = n / 2; }

        if (i % 10 != 0 && i % 2 == 0 && summ == 5) { res++; max = i; }
        summ = 0;
    }

	if (res == 0) { cout << "0 0"; }
    else { cout << res << " " << max; }
}