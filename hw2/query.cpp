//第一题，先排序，然后用二分查找
#include <iostream>
#include <cstdlib>

//放点坐标的数组
int dots[500001] = {0};

//qsort用的compare
int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

//二分查找,这里的high,low都是指标，从0开始;direciton 右 = 1
int binary_search(int target,int lo, int hi)
{
int mid ,left = lo, right = hi;
while(left <= right)
{
mid = left + ((right - left) >> 1);//mid不仅仅是（left+right）/2
if (dots[mid] >= target)
right = mid - 1;
else
left = mid + 1;
}
return left;
}


int main(){
    //输入输出加速
    int n, m;
    scanf("%d %d\n",&n ,&m);
    for (int i = 0; i < n; i++){scanf("%d",&dots[i]);}
    //快排
    qsort(dots, n, sizeof(int), compare);
    //计数
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d\n",&a ,&b);
        int ans = binary_search(b, 0, n-1) - binary_search(a, 0, n-1);
        if(dots[binary_search(b, 0, n-1)] == b){ans++;}
        if(ans < 0){ans = 0;}
        printf("%d\n",ans);
        //为什么加1会多？
    }
    return 0;
}