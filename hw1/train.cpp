#include <iostream>
//�������ݴ�С
#define MAXSIZE 1600001
//�������ͣ��������int
typedef int datatype;

//ջ���࣬ʹ����򵥵�����ʵ��
class Stack{
public:
    //��ʼ���������п��ܲ���
    datatype data[MAXSIZE] = {0};
    //-1��ʾ������ˣ������ջ��Ԫ�ص�λ�ã�Ҳ����������ʾջ�Ĵ�С(����������)
    int toppos = -1;
    void push(int ID){
        toppos++;
        data[toppos] = ID;
    }
    void pop(){
        //����ٶ�
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

int answer[MAXSIZE*2] = {0};//0��push,1��pop
int count = 0;
Stack S;
//�ж��Ƿ��ǿ�������
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
    //����ٶ�
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    
    //�ǵ�S���ܳ���m
    int n; int maxs;

    //���벿�ֿ��ܻ��пռ䣬������������δ�ģ�
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