#include <stdio.h>
#include <stdlib.h>
#define NUM 20 //�������
int a[NUM]= { 0,11,3,22,4 }, b[NUM];
void merge(int start, int end, int mid) {
	int i = start, j = mid + 1,k=start;//����i=1,j=2,mid=1
	while (i <= mid && j <= end)//i<=mid,j<=end
		//��2��������С������������һ��������,����2������Ϊ1������11��3
		if (a[i] <= a[j])
			b[k++] = a[i++];//��3��������b��
		else
			b[k++] = a[j++];
	//���˳�ѭ���������ʣ�࣬Ҳ�����ұ�ʣ�࣬��Ϊ����ĳ�������е�ֵ����һ�������е�����ֵ����
	//���ʣ��
	while (i<=mid){
		b[k++] = a[i++];
	}
	//�ұ�ʣ�࣬������11ʣ�࣬��11��������b��
	while (j <= end) {
		b[k++] = a[j++];
	}
	//���ź�����������¸�ֵ��a
	for (i = start; i <= end; i++) {
		a[i] = b[i];
	}
}
void mergeSort(int start, int end) {
	if (start < end) {
		//mid=�����м��ֵ���±�(start + end) / 2
		int mid = (start + end) / 2;
		//����mid�ָ�����Ϊ��start��mid���ͣ�mid+1��end�����ݹ�ָ�ֱ�������еĳ���Ϊ1
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		//�ݹ����merge�������й鲢����
		merge(start, end, mid);
	}
}
int main() {
	mergeSort(1, 4);
	//�������������a
	for (int i = 1; i < 5; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}


