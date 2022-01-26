#include<stdio.h>
 
int PreOrder[4000001] = {0};
int PostOrder[4000001] = {0};
/** BinaryTree DS */
typedef struct BinaryTree
{
	int key;
	BinaryTree *lson;
	BinaryTree *rson;
}BinaryTree;


int Array_Find( int *A, int begin, int end, int key)
{
	for( int i=begin; i<end; i++) {
		if( key == A[i]) return i;
	}
	
	return -1;
}


BinaryTree *GetBinaryTree( int  *PreOrder, int pbegin, int pend,  
                           int *PostOrder, int tbegin, int tend)  
{  
    if( pbegin>=pend || tbegin>=tend) return NULL;   // ����, �޽ڵ����  
      
    BinaryTree *Root = new BinaryTree;         // �����ڶ���, ��������ʱ������ʧ  
    *Root = { PreOrder[pbegin], NULL, NULL};   // ������ڵ�  
      
    if( pbegin+1==pend) return Root;   // �����������������  
    int lr = Array_Find( PostOrder, tbegin, tend, PreOrder[pbegin+1]); // leftsonRoot position in PostOrder
      
    // ȷ���������������� ǰ������������, �ݹ���� */  
    Root->lson = GetBinaryTree( PreOrder, pbegin+1, (lr+1-tbegin)+pbegin+1, PostOrder, tbegin, lr+1);  
    Root->rson = GetBinaryTree( PreOrder, (lr+1-tbegin)+pbegin+1, pend, PostOrder, lr+1, tend-1);  
      
    return Root;  
}
  

void InOrderTraverse(BinaryTree *root)
{
    if (root== NULL)
        return;
    InOrderTraverse(root->lson);
    printf("%d ", root->key);
    InOrderTraverse(root->rson);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &PreOrder[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &PostOrder[i]);
	BinaryTree *Root = GetBinaryTree( PreOrder, 0, n, PostOrder, 0, n);
	InOrderTraverse(Root);
	
	return 0;
}