#include <iostream>

using namespace std;

int a_la_b_mod_c(int a, int b, int c)
{
	int p = 1;
	a = a % c;
	while (b)
	{
		if (b % 2)
			p = (p * a) % c;
		b /= 2;
		a = (a * a) % c;
	}
	return p;
}

int modulo(int k, int n)
{
	if (n > 0 && k >= 0)
		return k % n;
	if (n > 0 && k < 0)
		return k % n + n;
	if (n < 0 && k >= 0)
		return k % n;
	if (n < 0 && k < 0)
		return k % n - n;
	if (n == 0)
		return -1;
}
