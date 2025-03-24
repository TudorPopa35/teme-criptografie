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

int cmmdc(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;
	int r;
	while (b)
	{
		r = modulo(a, b);
		a = b;
		b = r;
	}
	return a;
}

int invers(int a, int n)
{
	int q, r, x0 = 1, x1 = 0, copy_n = n;
	a = modulo(a, n);
	while (n != 0)
	{
		r = n;
		q = a / n;
		n = a % n;
		a = r;

		r = x1;
		x1 = x0 - q * x1;
		x0 = r;
	}
	if (a == 1)
		return modulo(x0, copy_n);
	return -1;
}

bool prim(int n)
{
	if (n == 0 || n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (n % 2 == 0)
		return 0;
	for (int i = 3; i <= sqrt(n); i += 2)
		if (n % i == 0)
			return 0;
	return 1;
}







char alfabet[100] = { 0 };
int N = 0;

int da_cod(char c)
{
	for (int i = 0; i < N; ++i)
		if (alfabet[i] == c)
			return i;
	return -1;
}


char da_caracter(int cod)
{
	return alfabet[modulo(cod, N)];
}


void citeste_alfabet(ifstream in)
{
	char c;
	while (in >> noskipws >> c)
	{
		alfabet[N++] = c;
	}
	if (N == 0)
		cout << "Alfabetul dat are 0 caractere" << endl;
}


void criptareCezar(ifstream& in, ofstream out, int k)
{
	char c;
	while (in >> noskipws >> c)
	{
		out << da_caracter(da_cod(c) + k);
	}
}







struct caracter
{
	char c;
	int f;
};


caracter* frecvente(ifstream& in)
{
	caracter vector_frecvente[100] = { 0 };
	char c;
	while (in >> noskipws >> c)
	{
		vector_frecvente[da_cod(c)].c = c;
		vector_frecvente[da_cod(c)].f++;
	}
	bool ordonat = 0;
	while (!ordonat)
	{
		ordonat = 1;
		for (int i = 0; i < N - 1; i++)
		{
			if (vector_frecvente[i].f < vector_frecvente[i + 1].f)
			{
				ordonat = 0;
				caracter temp = vector_frecvente[i];
				vector_frecvente[i] = vector_frecvente[i + 1];
				vector_frecvente[i + 1] = temp;
			}
		}
	}
	return vector_frecvente;
}
