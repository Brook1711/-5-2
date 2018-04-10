#include<iostream>
#include<string>
#include <cstdlib>
#include <queue>


using namespace std;

void tran(int n, queue<int> &N)
{
	
	for (int i = 0; i < 16; i++)
	{
		if (n == 0)
		{
			N.push(0);
		}
		else
		{
			N.push(n % 2);
			n /= 2;
		}
		
	}

}

void Move(queue<int> & N)
{
	int tem = 0;
	tem = N.front();
	N.pop();
	N.push(tem);
}

bool equ(queue<int>  N, queue<int>  M)
{
	bool T = true;
	for (int i=0; i < 16; i++)
	{
		int n = N.front();
		int m = M.front();
		N.pop();
		M.pop();
		if (n != m)
		{
			T = false;
			break;
		}
	}
	return T;
}

string judge(int n, int m)
{
	string tem = "NO";
	queue<int> N,M;
	tran(n, N);
	tran(m, M);
	for (int i = 0; i < 16; i++)
	{
		Move(N);
		if (equ(N, M))
			tem = "YES";
	}
	return tem;
}

int main()
{
	int count(0);
	int* n, * m;
	cin >> count;
	n = new int[count];
	m = new int[count];
	for (int i = 0; i < count; i++)
	{
		cin >> n[i] >> m[i];
	}
	for (int i = 0; i < count; i++)
	{
		cout << judge(n[i], m[i]) << endl;
	}
	delete[]n;
	delete[]m;
	system("pause");
	return 0;
}