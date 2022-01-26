#include <iostream>
//最大的数据大小
#define MAXSIZE 1600001
//数据类型，这里就是int
typedef int datatype;

//栈的类，使用最简单的数组实现
class Stack{
public:
    //初始化？但是有可能不对
    datatype data[MAXSIZE] = {0};
    //-1表示数组空了？这个是栈顶元素的位置，也可以用来表示栈的大小(可能有问题)
    int toppos = -1;
    void push(int ID){
        toppos++;
        data[toppos] = ID;
    }
    void pop(){
        //提高速度
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        data[toppos] = 0;
        toppos--;
        if(toppos < -1){
            std::cout << "Error!toppos < 0";
        }
    }
    datatype gettop(){
        return data[toppos];
    }
};

int answer[MAXSIZE*2] = {0};//0是push,1是pop
int count = 0;
Stack S;
//判断是否是可行序列
bool istrue(Stack B_, int n, int maxs_){
    int i = 1;
    for(int k = 1; k <= n; k++){
        while(S.toppos == -1 || B_.data[k - 1] != S.data[S.toppos]){
            if(i>n) return false;
		    else{
                S.push(i++);
                if(S.toppos+1 > maxs_){return false;};
                answer[count] = 0;
                count++;
            }
        }		
        S.pop();
        answer[count] = 1;
        count++;
	} 
    return true;
}

Stack B;
int main(){
    //提高速度
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    //记得S不能超过m
    int n; int maxs;

    //输入部分可能还有空间，看看够不够（未改）
    std::cin >> n >> maxs;
    for(int i = 0; i < n; i++){
        //std::cin >> B.data[n-1-i];
        int temp;
        std::cin >> temp;
        B.push(temp);
    }

    if(!istrue(B, n, maxs)){
        std::cout << "No";
    }
    else{
        for (int i = 0; i < count; i++){
            if(answer[i] == 0){std::cout << "push" << "\n";}
            else{std::cout << "pop" << "\n";}
        }
    }
    return 0;
}