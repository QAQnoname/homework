#include <stdio.h>
#include <stdlib.h>
#define NUM 20  //��������
#define INFINITY 65535  //���������
#define VRType int      //Ȩֵ����
#define VertexType int  //��������

typedef struct {
    VRType arcs[NUM][NUM];                  //�ڽӾ���map�洢��ͨͼ,map[u][v]��ʾ����u��v��Ȩֵ
    int vexnum,arcnum;                      //��¼ͼ�Ķ������ͱ���
}MGraph;

//����������
void CreateUDN(MGraph* G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
	int i,j;
    for(i=0; i<G->vexnum; i++) {
        for (j=0; j<G->vexnum; j++) {
            G->arcs[i][j]=INFINITY;
        }
    }
    for(i=0; i<G->arcnum; i++) {
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);
        G->arcs[v1][v2]=w;
        G->arcs[v2][v1]=w;
    }
}

//�������飬����ÿ��ɸѡ��Ȩֵ��С�ıߵ��ڽӵ�
typedef struct {
    VertexType adjvex;//��¼Ȩֵ��С�ıߵ���ʼ��
    VRType lowcost;//��¼�ñߵ�Ȩֵ
}closedge[NUM];
closedge dist;//����һ��ȫ�����飬��Ϊÿ�������ж���ʹ�õ�
//��dist�������ҳ�Ȩֵ��С�ıߵ������±꣬�Ϳ��Լ���ҵ��˱ߵ��յ㶥�㡣
int mindist(MGraph G,closedge dist){
    int min=INFINITY;
    int min_index=-1;
	int i;
    for(i=1; i<=G.vexnum; i++) {
        //ȨֵΪ0��˵�������Ѿ�������С�������У�Ȼ��ÿ�κ�min�������бȽϣ�����ҳ���С�ġ�
        if (dist[i].lowcost>0 && dist[i].lowcost < min) {
            min=dist[i].lowcost;
            min_index=i;
        }
    }
    //������СȨֵ���ڵ������±�
    return min_index;
}
//����ķ�㷨������GΪ��������uΪ������ѡ������ⶥ����Ϊ��ʼ��
void Prim(MGraph G,VertexType start){
	int i,j,k;
    //���Ƚ������ʼ����ص����бߵ���Ϣ���ߵ���ʼ���Ȩֵ�����븨����������Ӧ��λ�ã����磨1��2���ߣ�adjvexΪ1��lowcostΪ6������dist[2]�У�����������±��ʾ�ñߵĶ���2
	for(i=1; i<=G.vexnum; i++) {
        if (i !=k) {
            dist[i].adjvex=start;
            dist[i].lowcost=G.arcs[start][i];
        }
    }
    //������ʼ���Ѿ���Ϊ��С�����������Ը��������Ӧλ�õ�ȨֵΪ0������������ʱ�Ͳ��ᱻѡ��
    dist[start].lowcost=0;
    //ѡ����һ���㣬�����¸��������е���Ϣ
    for(i=1; i<G.vexnum; i++) {
        //�ҳ�Ȩֵ��С�ı����������±�
        k=mindist(G, dist);
        //���ѡ���·��
        printf("v%d v%d\n",dist[k].adjvex,k);
        //������С�������Ķ���ĸ��������е�Ȩֵ��Ϊ0
        dist[k].lowcost=0;
        //��Ϣ���������д洢����Ϣ�����ڴ�ʱ�����¼�����һ�����㣬��Ҫ�жϣ��ɴ˶�����������������������Ȩֵ�Ƿ��֮ǰ��¼��Ȩֵ��ҪС�������С�������
        for( j=1; j<=G.vexnum; j++) {
            if (G.arcs[k][j]<dist[j].lowcost) {
                dist[j].adjvex=k;
                dist[j].lowcost=G.arcs[k][j];
            }
        }
    }
    printf("\n");
}

int main(){
    MGraph G;
    CreateUDN(&G);
    Prim(G, 1);
}
/*����ʾ��
4,5  //4�����㣬5���� 
1,2,3 //����1��2��֮���ȨֵΪ3 
1,3,1
1,4,2
2,4,3
3,4,2
*/ 

