#include <iostream>
using namespace std;

void reverseArr(int* arr, int len) 
{
	int* _arr = new int[len];

	for (int i = 0; i < len; i++) _arr[i] = arr[i];
	for (int i = 0; i < len; i++) arr[i] = _arr[(len - 1) - i];
}

void math(int n, int m, int *arr, int a = 0, int b = 1)
{
	if (n == 0)
	{
		if (a == m)
		{
			int* temp = new int[a];
			for (int i = 0; i < a; i++) { temp[i] = arr[i]; }

			reverseArr(temp, a);
			for (int i = 0; i < a; i++) { cout << temp[i] << " "; }
			cout << endl;
		}
		return;
	}
	for (int i = n; i >= b; i--)
		if (i >= b) { arr[a] = i; math(n - i, m, arr, a + 1, i); }
	return;
}

int main()
{
	int arr[100], m, n;
	cin >> n;
	if (n != 0)
	{
		for (m = n; m != 0; m--)
			math(n, m, arr);
	}
	else
		cout << 0;
}