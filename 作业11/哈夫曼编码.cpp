#include<stdio.h>
#include<stdlib.h> 
#define LENGTH 6

typedef int ElemType;

typedef struct HuffmanTreeNode {
	ElemType data;  //���������нڵ��Ȩֵ
	struct HuffmanTreeNode* left;
	struct HuffmanTreeNode* right;
}HuffmanTreeNode, *PtrHuffman;


/**
 * ������������
 */
PtrHuffman createHuffmanTree(ElemType arr[]) {
	PtrHuffman ptrArr[LENGTH];
	PtrHuffman ptr, pRoot = NULL;

	for (int i = 0; i < LENGTH; i++) {  //��ʼ���ṹ��ָ������,������ÿһ��Ԫ��Ϊһ���ṹ��ָ������
		ptr = (PtrHuffman)malloc(sizeof(HuffmanTreeNode));
		ptr->data = arr[i];
		ptr->left = ptr->right = NULL;
		ptrArr[i] = ptr;
	}

	for (int i = 1; i < LENGTH; i++) {  //���� n-1 ��ѭ��������������  
		//k1��ʾɭ���о�����СȨֵ�����������±�,k2Ϊ����С���±�
		int k1 = -1, k2;
		for (int j = 0; j < LENGTH; j++) {
			if (ptrArr[j] != NULL && k1 == -1) {
				k1 = j;
				continue;
			}
			if (ptrArr[j] != NULL) {
				k2 = j;
				break;
			}
		}
		//��ָ�������е�ָ��ָ�����Сֵ��ֵ��������Ϊk1��,��Сֵ��ֵ��������Ϊk2��
		for (int j = k2; j < LENGTH; j++) {
			if (ptrArr[j] != NULL) {
				if (ptrArr[j]->data < ptrArr[k1]->data) {
					k2 = k1;
					k1 = j;
				}
				else if (ptrArr[j]->data < ptrArr[k2]->data) {
					k2 = j;
				}
			}
		}
		//����СȨֵ���ʹ���СȨֵ������һ������,pRootָ���������
		pRoot = (PtrHuffman)malloc(sizeof(HuffmanTreeNode));
		pRoot->data = ptrArr[k1]->data + ptrArr[k2]->data;
		pRoot->left = ptrArr[k1];
		pRoot->right = ptrArr[k2];

		ptrArr[k1] = pRoot; //��ָ��������ָ�븳��ptrArrָ��������k1λ��
		ptrArr[k2] = NULL; //k2λ��Ϊ��
	}

	return pRoot;
}
/**
 * ������������(Ҷ�ӽڵ㰴����ʽ���δ�ӡ�����)
 */
void HuffmanCoding(PtrHuffman &ptrTree, int len) {
	//��̬�ֲ������൱��ȫ�ֱ���(ֻ��ֻ��������������ܷ���,�������������Ǻ�ȫ�ֱ�������)�����˳�֮���������,����ֻ�ڵ�һ�ν����ʱ������ʼ��,�Ժ��������ʼ�����,����ԭ����ֵ
	static int arr[20];
	if (ptrTree != NULL) {
		if (ptrTree->left == NULL && ptrTree->right == NULL) {
			printf("������Ϊ%d�ı���: ", ptrTree->data);
			for (int i = 0; i < len; i++) {
				printf("%d", arr[i]);
			}
			printf("\n");
		}
		else {
			arr[len] = 0;
			HuffmanCoding(ptrTree->left, len + 1);
			arr[len] = 1;
			HuffmanCoding(ptrTree->right, len + 1);
		}
	}
}



/**
 * ���Գ������
 */
int main() {
	ElemType arr[] = { 3,9,5,12,6,15 };
	PtrHuffman pRoot = createHuffmanTree(arr);  //����ָ������������ڵ��ָ��

	printf("==========���ڵ�Ĺ�����������==========\n");
	HuffmanCoding(pRoot, 0);
	printf("\n");

	return 0;
}
