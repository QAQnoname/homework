#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;//ͼ�Ķ�����
int M;//ɫ����
class Color
{
	friend int mColoring(int, int, int **);
private:
	bool Ok(int k);
	void Backtrack(int t);
	int n;		//ͼ�Ķ�����
	int	m;		//���õ���ɫ��
	int	**a;	//ͼ���ڽӾ���
	int	*x;		//��ǰ��
	long sum;	//��ǰ���ҵ��Ŀ�m��ɫ������
};
int mColoring(int n, int m, int **a);
int main()
{
	cout << "������ͼG�Ķ������Ͳ�ɫ��:" << endl;
	cin>>N>>M; 
	int **a = new int *[N + 1];
	for (int i = 1; i <= N; i++)
	{
		a[i] = new int[N + 1];
	}
	cout << "������ͼG���ڽӾ���:" << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> a[i][j];
		}
		cout << endl;
	}
	int sum=mColoring(N, M, a);
	if(sum>0) 
	{
		cout << "ͼG����ɫ�������£�" << endl;
		cout << "��m=" << M << "ʱ��ͼG�Ŀ�����ɫ������ĿΪ��" << sum << endl;
	}
	else
		cout<<"NO"<<endl;
	for (int i = 1; i <= N; i++)
	{
		delete[] a[i];
	}
	delete[]a;
}


void Color::Backtrack(int t)
{
	if (t > n)
	{
		//�����һ���㱻��ɫ�󣬴�ʱi����n�������е���Ⱦɫ���
		sum++;
		//��ӡ�����ַ����Ľ��
		for (int i = 1; i <= n; i++)
			cout << x[i] << " ";
		cout << endl;
	}
	else
	{
		//��ʼ��һ���������ɫ��ͬʱ�ж�������ԣ�
		for (int i = 1; i <= m; i++)
		{
			//���ĵ�ͼ��m����ɫ
			x[t] = i;
			//��������ɫ���У���ִ�н������ε���ɫ
			if (Ok(t)) Backtrack(t + 1);
			//���õ�ָ���ԭ����״̬
			x[t] = 0;
		}
	}
}


bool Color::Ok(int k)// �����ɫ������
{
	for (int j = 1; j <= n; j++)
	{
		if ((a[k][j] == 1) && (x[j] == x[k])) //��������ɫ��ͬ
		{
			return false;
		}
	}
	return true;
}


int mColoring(int n, int m, int **a)
{
	Color X;
	//��ʼ��X
	X.n = n;
	X.m = m;
	X.a = a;
	X.sum = 0;
	int *p = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		p[i] = 0;
	}
	X.x = p;
	X.Backtrack(1);
	delete[]p;
	return X.sum;
}
/*
����ʾ����
4 3
0 1 1 1
1 0 0 1
1 0 0 1
1 1 1 0
*/ 
