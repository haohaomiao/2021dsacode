//���⣺������string����ô��
#include <cstdio>
#include <string>
#include <string.h>
char input[50];
//ɢ�б�ڵ�
struct node{
    node* next;
    char* code;
    bool ifrepeat;
}buckets[600001];

/*void Insert(int addr, std::string s) {//����Ӧ��ַ�в����ͻ���ַ�����ʵ���ַ�ָ�룩 
	node* t = new node;
	t->code = s; t->ifrepeat = false;//��ʼ����ǰ�ַ�����δ�ظ� 
	t->next = buckets[addr].next;//����ͷ�巨 
	buckets[addr].next = t;
}*/
int HashCode(char* s) {//ɢ����ת�����ַ���ת���֣� 
	int sum = 0, len = strlen(s);
	for (int i = 0; i<len; i++)//����ʽ��� 
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
