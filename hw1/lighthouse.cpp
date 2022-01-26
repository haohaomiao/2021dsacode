#include <iostream>
#include <cstdlib>
//��������ṹ��
struct Dot{
    int x = 0;
    int y = 0;
};

//qsortҪ�õıȽϺ���
int cmp(const void* a, const void* b)
{
    Dot* pa = (Dot*)a;
    Dot* pb = (Dot*)b;
    return (int)pa->x - pb->x;   // ��С����
}

//������������
Dot array[4000000] = {0};
//����������
int temp[4000000] = {0};
//�����������������
int n;
long long count;

//�鲢����
void merge(int lo, int mi, int hi){
    int i = lo,j = mi + 1;
    int k = lo;
    //i��ǰһ���ָ�꣬j�Ǻ�һ���ָ��, k��temp��ָ��
	while(i <= mi && j <= hi)
	{
		if(array[i].y < array[j].y)
		{
			temp[k++] = array[i++].y;
			count += hi - j + 1;//��˳���???
		}
		else
			temp[k++] = array[j++].y;
	}
	while(i <= mi)
		temp[k++] = array[i++].y;
	while(j <= hi)
		temp[k++] = array[j++].y;
	for(int h = lo;h <= hi; h++)
		array[h].y = temp[h];
}
void mergesort(int lo,int hi)
{
	int mid=(lo+hi)/2;
	if(lo<hi)
	{
		mergesort(lo,mid);
		mergesort(mid+1,hi);
		merge(lo,mid,hi);
	}
}
int main(){
//����
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
//��������
    std::cin >> n;
    for (int i = 0; i < n; i++){std::cin >> array[i].x >> array[i].y;}
//��x����qsort���ţ�
    qsort(array, n, sizeof(Dot), cmp);
//�鲢����+����˳���
    mergesort(0,n);
    std::cout << count;
}
