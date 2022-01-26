//��һ�⣬������Ȼ���ö��ֲ���
#include <iostream>
#include <cstdlib>

//�ŵ����������
int dots[500001] = {0};

//qsort�õ�compare
int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

//���ֲ���,�����high,low����ָ�꣬��0��ʼ;direciton �� = 1
int binary_search(int target,int lo, int hi)
{
int mid ,left = lo, right = hi;
while(left <= right)
{
mid = left + ((right - left) >> 1);//mid�������ǣ�left+right��/2
if (dots[mid] >= target)
right = mid - 1;
else
left = mid + 1;
}
return left;
}


int main(){
    //�����������
    int n, m;
    scanf("%d %d\n",&n ,&m);
    for (int i = 0; i < n; i++){scanf("%d",&dots[i]);}
    //����
    qsort(dots, n, sizeof(int), compare);
    //����
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d\n",&a ,&b);
        int ans = binary_search(b, 0, n-1) - binary_search(a, 0, n-1);
        if(dots[binary_search(b, 0, n-1)] == b){ans++;}
        if(ans < 0){ans = 0;}
        printf("%d\n",ans);
        //Ϊʲô��1��ࣿ
    }
    return 0;
}