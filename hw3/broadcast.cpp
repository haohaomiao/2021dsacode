#include <iostream>
#include <cstdio>
#define MAX 1000000

using namespace std;
//ʹ���ڽӱ�洢ͼ
 struct EdgeNode /*�߱���*/
{
    int adjvex; //�洢�ڽӶ����Ӧ�±�
    struct EdgeNode *nex;//ָ����һ���ڽӵ�
};

struct VertexNode //�������
{
    int castType;//�㲥״̬ 1
    bool isVisted;
    int data;//����
    EdgeNode *firstEdge;//�߱�ͷָ��
};
struct Graph
{
    VertexNode adjList[MAX];//��������
    int numVertexs;//������
    int numEdges;//����

}graph;

void unit(int n){//��ʼ����������
    for(int i=0;i<n;i++)
    {
        graph.adjList[i].data = i+1;//�����1��ʼ
        graph.adjList[i].isVisted = false;
        graph.adjList[i].firstEdge = NULL;
    }
}

VertexNode queue[MAX];//ģ�����
int head=0;
int tail =0;
int queuesize=0;

void BFS(){
    //BFS
    bool ifpos = true;
    for(int i=0;i<graph.numVertexs;i++)
    {
        if(!graph.adjList[i].isVisted)
        {
            graph.adjList[i].isVisted = true;
            graph.adjList[i].castType = 1;//�㲥����
            queue[tail++] = graph.adjList[i];//������
            queuesize++;
            while(queuesize!=0)
            {
                VertexNode node = queue[head++];//ȡ�������е�һ�����
                queuesize--;
                EdgeNode *pn = node.firstEdge;
                while( pn != NULL)
                {
                    if(!graph.adjList[pn->adjvex].isVisted)//���δ���ʹ�
                    {
                        graph.adjList[pn->adjvex].isVisted = true;
                        graph.adjList[pn->adjvex].castType = -node.castType;//��װ��ͬ���͹㲥
                        queue[tail++] = graph.adjList[pn->adjvex];//���
                        queuesize++;

                    }
                    else
                    {
                        if(node.castType == graph.adjList[pn->adjvex].castType)
                        {
                            //������
                            ifpos = false;
                            break;
                        }
                    }
                    pn = pn->nex;
                }
            }
        }
    }        
    //����
    if(ifpos)
    printf("1");
    else
    printf("-1");
    
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    graph.numVertexs = n;
    graph.numEdges = m;
    if(m<=1)
    {
        printf("1");
        return 0;
    }
    unit(n);
    int a,b;
    for(int i=0;i<m;i++)//������Ϣ�������ڽӱ�
    {
        scanf("%d%d",&a,&b);//����С��20km�Ľ�㣨��ׯ����Ϊ�б���ͨ
        EdgeNode *ea = new EdgeNode;
        EdgeNode *eb = new EdgeNode;
        ea->adjvex = b-1;//�±��0��ʼ
        eb->adjvex = a-1;
        ea->nex = NULL;
        eb->nex = NULL;
        EdgeNode *pa = graph.adjList[a-1].firstEdge;//����ͼ һ���߸����������
        EdgeNode *pb = graph.adjList[b-1].firstEdge;
        if( pa == NULL)
        {
            graph.adjList[a-1].firstEdge = ea;
        }
        else
        {
            while( pa->nex != NULL)
            {
                pa = pa->nex;
            }
            pa->nex = ea;
        }
        if( pb == NULL)
        {
            graph.adjList[b-1].firstEdge = eb;
        }
        else
        {
            while( pb->nex != NULL)
            {
                pb = pb->nex;
            }
            pb->nex = eb;
        }
    }
    BFS();
    return 0;
}
