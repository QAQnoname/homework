#include <stdio.h>
#include <stdlib.h>
#define NUM 20 //������� 
#define VertexType int
#define INF 65535
typedef struct Graph {
	VertexType vertex[NUM]; //��Ŷ��������
	int matrix[NUM][NUM] = { 0 }; //�ڽӾ���
	int dis[NUM][NUM];			//���������������������ľ���
	int p[NUM][NUM];	//ǰ����
	int vexnum,arcnum; //vernumΪ���������arcnumΪ����
} Graph;
//��ʼ����ͨͼ 
void CreateG(Graph &G) {
	int v1=0, v2=0,dis=0;
	//���붥����vexnum������arcnum
	scanf("%d %d", &G.vexnum, &G.arcnum);
	for (int i = 1; i <= G.vexnum; ++i) {
		scanf("%d",&G.vertex[i]);
	}
	for (int i = 1; i <= G.vexnum; ++i) {
		for (int j = 1; j <= G.vexnum; ++j) {
			if (i != j) {
				G.matrix[i][j] = INF;
			}
			G.p[i][j] = G.vertex[i];
		}
	}
	//�����v1���㵽v2����ľ���
	for (int i = 1; i <= G.arcnum; ++i) {
		scanf("%d %d %d", &v1, &v2,&dis);
		G.matrix[v1][v2] = dis;
	}
}
//flod�㷨
void Floyd(Graph &G) {
	//���м䶥�����,k���м䶥����±� 
	for (int k = 1; k <= G.vexnum; ++k) {
		//��i�������
		for (int i = 1; i <= G.vexnum; ++i) {
			//����j����
			for (int j = 1; j <= G.vexnum; ++j) {
				//�����i�������������k�м䶥�㣬����j����ľ���С�ڴ�i���㵽j����
				if (G.matrix[i][j] > G.matrix[i][k] + G.matrix[k][j]) {
					G.matrix[i][j] = G.matrix[i][k] + G.matrix[k][j]; //���¾���
					G.p[i][j] = G.vertex[k]; //����ǰ��
				}

			}
		}
	}
	for (int i = 1; i <= G.vexnum; ++i) {
		for (int j = 1; j <= G.vexnum; ++j) {
			printf("%d ",G.matrix[i][j]);
		}
		printf("\n");
	}
}
int main() {
	Graph G;
	CreateG(G);
	Floyd(G);
	return 0;
}

