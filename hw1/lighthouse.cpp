#include <iostream>
#include <cstdlib>
//灯塔坐标结构体
struct Dot{
    int x = 0;
    int y = 0;
};

//qsort要用的比较函数
int cmp(const void* a, const void* b)
{
    Dot* pa = (Dot*)a;
    Dot* pb = (Dot*)b;
    return (int)pa->x - pb->x;   // 从小到大，
}

//灯塔坐标数组
Dot array[4000000] = {0};
//排序用数组
int temp[4000000] = {0};
//灯塔数量和组计数器
int n;
long long count;

//归并排序
void merge(int lo, int mi, int hi){
    int i = lo,j = mi + 1;
    int k = lo;
    //i是前一半的指标，j是后一半的指标, k是temp的指标
	while(i <= mi && j <= hi)
	{
		if(array[i].y < array[j].y)
		{
			temp[k++] = array[i++].y;
			count += hi - j + 1;//求顺序对???
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
//加速
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
//输入数据
    std::cin >> n;
    for (int i = 0; i < n; i++){std::cin >> array[i].x >> array[i].y;}
//对x排序（qsort快排）
    qsort(array, n, sizeof(Dot), cmp);
//归并排序+计算顺序对
    mergesort(0,n);
    std::cout << count;
}
