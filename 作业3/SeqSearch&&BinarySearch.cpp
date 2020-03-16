#include <stdio.h>
#include <stdlib.h>
#define NUM 20 //�������
//˳����ң�������������a�����ҵ�ֵvalue�����鳤��n
int SeqSearch(int a[], int value, int n) {
	for (int i = 1; i <= n; i++) {
		//�ж�a[i]�Ƿ���value��ȣ���ȷ����±�i
		if (a[i] == value) {
			return i;
		}
	}
	return 0;
}
//���ֲ��ң�������������a�����ҵ�ֵvalue�����鳤��n
int BinarySearch(int a[], int value, int n)
{
	//ÿ���������ֶ����鿪ͷ�±�low��ĩβ�±�high���м��±�mid
	int low, high, mid;
	low = 1;
	high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		//�ж�a[mid]�Ƿ���value��ȣ���ȷ����±�mid�����㷨
		if (a[mid] == value)
			return mid;
		//�ж�a[mid]�Ƿ����value���ǣ������high
		if (a[mid] > value)
			high = mid - 1;
		//�ж�a[mid]�Ƿ�С��value���ǣ������low
		if (a[mid] < value)
			low = mid + 1;
	}
	return 0;
}
int main() {
	int num,a[NUM] = {0,1,2,3,4,5,6 };
	int length = 6;
	scanf("%d", &num);
	printf("˳����ң�%d\n",BinarySearch(a, num, length));
	printf("���ֲ��ң�%d\n", SeqSearch(a, num, length));
	return 0;
}

