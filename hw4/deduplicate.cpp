//问题：试试用string会怎么样
#include <cstdio>
#include <string>
#include <string.h>
char input[50];
//散列表节点
struct node{
    node* next;
    char* code;
    bool ifrepeat;
}buckets[600001];

/*void Insert(int addr, std::string s) {//在相应地址中插入冲突的字符串（实则字符指针） 
	node* t = new node;
	t->code = s; t->ifrepeat = false;//初始化当前字符串从未重复 
	t->next = buckets[addr].next;//链表头插法 
	buckets[addr].next = t;
}*/
int HashCode(char* s) {//散列码转换（字符串转数字） 
	int sum = 0, len = strlen(s);
	for (int i = 0; i<len; i++)//多项式求和 
		sum += 2*(s[i] - 'a'+1);
	return sum;
}

int main(){
    int n;
    scanf("%d",n);
    for (int i = 0; i < n; i++){
        scanf("%s",input);

    }
}

/*int hashcode(char be_hash[40])
{
	int length= strlen(be_hash);
	int num = 0;
	for (auto i = 0; i < length; i++)
	{
		num += (be_hash[i] - 96)*(i+1);
	}
	return num;
}*/
