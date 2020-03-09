#include <stdio.h>
#include <stdlib.h>
#define NUM 20 //������� 
#define VertexType char
#define INF 65535
typedef struct Graph {
	VertexType vertex[NUM]; //��Ŷ��������
	int matrix[NUM][NUM] = { 0 }; //�ڽӾ���
	int vexnum,arcnum; //vernumΪ���������arcnumΪ����
} Graph;
typedef struct VisitedVertex {
	//��¼���������Ƿ���ʹ���1��ʾ���ʹ���0δ����
	int already_arr[NUM] = { 0 };
	//ÿ���±��Ӧ��ֵΪǰһ�������±�
	int p[NUM];
	//�������㵽�������ж���ľ���
	int dis[NUM] = { 0 };
	//���³������㵽index����ľ���
	void updateDis(int index,int len) {
		dis[index] = len;
	}
	//����pre��������ǰ��Ϊindex����
	void updatePre(int pre, int index) {
		p[pre] = index;
	}
	//���س������㵽index����ľ���
	int getDis(int index) {
		return dis[index];
	}
}VisitedVertex;
//��ʼ����ͨͼ 
void CreateG(Graph &G,VisitedVertex &vx) {
	VertexType v1, v2;
	int m;
	//���붥����vexnum������arcnum
	scanf("%d %d", &G.vexnum, &G.arcnum);
	getchar();
	for (int i = 1; i <= G.vexnum; ++i) {
		scanf("%c",&G.vertex[i]);
		getchar();
	}
	for (int i = 1; i <= G.arcnum; i++) {
		for (int j = 1; j <= G.arcnum; j++) {
			G.matrix[i][j] = INF;
		}
	}
	//�����v1���㵽v2����ľ���
	for (int i = 1; i <= G.arcnum; ++i) {
		scanf("%c %c %d", &v1, &v2,&m);
		getchar();
		G.matrix[(int)v1-96][(int)v2-96] = m;
	}
	for (int i = 1; i<= G.arcnum; i++) {
		vx.dis[i] = INF;
	}
}
//���³������㵽index����ľ���
//flod�㷨
void dsj(Graph &G, VisitedVertex &vx) {
	int len = 0;
	VertexType start,end;
	scanf("%c %c", &start,&end);
	int index = start - 96;
	vx.already_arr[index]=1;
	vx.dis[index] = 0;
	for (int j = 1; j <= G.vexnum; j++) {
		len = vx.getDis(index)+G.matrix[index][j];
		if (vx.already_arr[j] == 0 && len < vx.getDis(j)) {
			vx.updatePre(j, index);
			vx.updateDis(j, len);
		}
	}	
	for (int i = 1; i < G.vexnum; i++) {
		int min = INF;
		for (int i = 1; i <= G.vexnum; i++) {
			if (vx.already_arr[i] == 0 && vx.dis[i] < min) {
				min = vx.dis[i];
				index = i;
			}
		}
		vx.already_arr[index] = 1;
		for (int j = 1; j <= G.vexnum; j++) {
			len = vx.getDis(index) + G.matrix[index][j];
			if (vx.already_arr[j] == 0 && len < vx.getDis(j)) {
				vx.updatePre(j, index);
				vx.updateDis(j, len);
			}
		}
	}
	printf("%d\n", vx.dis[(int)end-96]);
}
int main() {
	Graph G;
	VisitedVertex vx;
	CreateG(G,vx);
	dsj(G, vx);
	return 0;
}


/*����ʾ��
8 11
a
b
c
d
e
f
g
h
a b 1
b d 2
c a 2
d c 1
d f 8
e d 2
e g 2
f e 2
g f 3
g h 3
h f 2
a h
*/


