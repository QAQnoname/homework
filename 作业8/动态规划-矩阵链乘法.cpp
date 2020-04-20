#include<stdio.h>
int MAX = 10000;
#define M 7
void MatrixChain(int *p, int Length, int m[][M], int s[][M])
{
	int t, n = Length-1;
	for (int i = 1; i <= n; i++) m[i][i] = 0;
	for (int r = 2; r <= n; r++) 	/* �������ĳ��� */
	{
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;         /* �ȼ��� l=j-i+1 */
			m[i][j] = m[i+1][j]+ p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i+1; k <= j - 1; k++)
			{
				t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}
void print(int s[][M], int i, int j)
{
	if (i == j) printf("A%d", i);
	else
	{
		printf("(");
		print(s, i, s[i][j]);
		print(s, s[i][j] + 1, j);
		printf(")");
	}
}
int main()
{
	int p[M] = { 5,6,2,9,7,6 };
	int m[M][M], s[M][M];
	MatrixChain(p, 6, m, s);
	printf("��n=5ʱ���Ž�Ϊ:\n%d",m[1][5]);
	printf("\n���Ż�����Ϊ��\n");
	print(s, 1, 5);
	return 0;
}
/*
ʾ�� 
��n=5ʱ���Ž�Ϊ:
330
���Ż�����Ϊ��
((A1A2)((A3A4)A5))
*/
