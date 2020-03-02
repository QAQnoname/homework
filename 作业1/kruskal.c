#include <stdio.h>
#include <stdlib.h>
#define NUM 20 //������� 
#define VertexType int
typedef struct edge{
    VertexType adjvex; //��ʼ�� 
    VertexType end;		//�յ� 
    VertexType arcs;  //Ȩֵ 
} edge[NUM];
//���帨������
typedef struct {
    VertexType value;//��������
    int sign;//ÿ�����������ļ���
}Dist[NUM];
Dist dist;
//qsort��������ʹ�ã�ʹedges�ṹ���еı߰���Ȩֵ��С��������
int cmp(const void *a,const void*b){
    return  ((struct edge*)a)->arcs-((struct edge*)b)->arcs;
}
//��ʼ����ͨͼ 
void CreateUDN(edge *edges,int *vexnum,int *arcnum){
    int i;
	scanf("%d,%d",&(*vexnum),&(*arcnum));
	for (i=1; i<(*vexnum); i++) {
        dist[i].sign=i;
    }
    for (i=1 ; i<=(*arcnum); i++) {
        scanf("%d,%d,%d",&(*edges)[i].adjvex,&(*edges)[i].end,&(*edges)[i].arcs);
    }
}

int main(){
    int arcnum,vexnum,i,j;
    edge edges;
    CreateUDN(&edges,&vexnum,&arcnum);
    //����ͨ���е����б߽����������򣬽���Ա�����edges������
    qsort(edges+1, arcnum, sizeof(edges[0]), cmp);
    //����һ���յĽṹ�����飬���ڴ����С������
    edge minTree;
    //����һ�����ڼ�¼��С�������бߵ������ĳ���
    int num=1;
    //�������еı�
    for (i=1; i<=arcnum; i++) {
        //�ҵ��ߵ���ʼ����ͽ�������������dist�е�λ��
        int initial= edges[i].adjvex;
        int end= edges[i].end;
        //�������λ�ô����Ҷ���ı�ǲ�ͬ��˵������һ�������У����������·
        if (initial!=-1&& end!=-1&&dist[initial].sign!=dist[end].sign) {
            //��¼�ñߣ���Ϊ��С����������ɲ���
            minTree[num]=edges[i];
            //����+1
            num++;
            //���¼����������Ķ�����ȫ������Ϊһ����
            for (j=1; j<=vexnum; j++) {
                if (dist[j].sign==dist[end].sign) {
                    dist[j].sign=dist[initial].sign;
                }
            }
            //���ѡ��ıߵ������Ͷ��������1��֤����С�������Ѿ��γɣ��˳�ѭ��
            if (num==vexnum) {
                break;
            }
        }
    }
    //������
    for (i=1; i<vexnum; i++) {
        printf("%d,%d\n",minTree[i].adjvex,minTree[i].end);
    }
    return 0;
}

 
/*����ʾ��
4,5  	//4�����㣬5���� 
1,2,3 	//����1��2��֮���ȨֵΪ3
1,3,1
1,4,2
2,4,3
3,4,2
*/ 

