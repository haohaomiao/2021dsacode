#include<iostream>
#include<cstring>
#define HASHSIZE 600001
using namespace std;
struct Slot {//每个桶对应的槽位，存储冲突，即映射到同一地址且不重复的字符串（实则字符指针） 
	char* data;//数据项，存储字符指针 
	bool repeat;//标志，判别字符串是否重复
	Slot* succ;//后继 
}buckets[HASHSIZE];//桶数组（散列表） 
char name[41];
void Insert(int addr, char* s) {//在相应地址中插入冲突的字符串（实则字符指针） 
	Slot* t = new Slot;
	t->data = s; t->repeat = false;//初始化当前字符串从未重复 
	t->succ = buckets[addr].succ;//链表头插法 
	buckets[addr].succ = t;
}
int HashCode(char* s) {//散列码转换（字符串转数字） 
	int sum = 0, len = strlen(s);
	for (int i = 0; i<len; i++)//多项式求和 
		sum += (i + 1)*(s[i] - 'a'+1);
	return sum;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){		
		scanf("%s", name);
		int addr = HashCode(name) % HASHSIZE;//获得映射到的地址 
		Slot* p = buckets[addr].succ;//从当前桶的第1个槽位开始 
		while (p)//遍历所有槽位（冲突的单元） 
		if (!strcmp(p->data, name)) {//若当前槽位的字符串重复 
			if (!p->repeat) {//检查当前槽位的字符串是否重复
				p->repeat = true;//若未重复，则标志为已重复过 
				puts(name);//输出重复字符串 
			}break;//若重复过，则忽略，无论是否重复过，皆终止遍历 
		}
		else p = p->succ;
		if (!p)Insert(addr, name);//若当前槽位空，则进行插入 
	}
	return 0;

}