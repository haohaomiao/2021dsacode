#include<iostream>
#include<cstring>
#define HASHSIZE 600001
using namespace std;
struct Slot {//ÿ��Ͱ��Ӧ�Ĳ�λ���洢��ͻ����ӳ�䵽ͬһ��ַ�Ҳ��ظ����ַ�����ʵ���ַ�ָ�룩 
	char* data;//������洢�ַ�ָ�� 
	bool repeat;//��־���б��ַ����Ƿ��ظ�
	Slot* succ;//��� 
}buckets[HASHSIZE];//Ͱ���飨ɢ�б� 
char name[41];
void Insert(int addr, char* s) {//����Ӧ��ַ�в����ͻ���ַ�����ʵ���ַ�ָ�룩 
	Slot* t = new Slot;
	t->data = s; t->repeat = false;//��ʼ����ǰ�ַ�����δ�ظ� 
	t->succ = buckets[addr].succ;//����ͷ�巨 
	buckets[addr].succ = t;
}
int HashCode(char* s) {//ɢ����ת�����ַ���ת���֣� 
	int sum = 0, len = strlen(s);
	for (int i = 0; i<len; i++)//����ʽ��� 
		sum += (i + 1)*(s[i] - 'a'+1);
	return sum;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){		
		scanf("%s", name);
		int addr = HashCode(name) % HASHSIZE;//���ӳ�䵽�ĵ�ַ 
		Slot* p = buckets[addr].succ;//�ӵ�ǰͰ�ĵ�1����λ��ʼ 
		while (p)//�������в�λ����ͻ�ĵ�Ԫ�� 
		if (!strcmp(p->data, name)) {//����ǰ��λ���ַ����ظ� 
			if (!p->repeat) {//��鵱ǰ��λ���ַ����Ƿ��ظ�
				p->repeat = true;//��δ�ظ������־Ϊ���ظ��� 
				puts(name);//����ظ��ַ��� 
			}break;//���ظ���������ԣ������Ƿ��ظ���������ֹ���� 
		}
		else p = p->succ;
		if (!p)Insert(addr, name);//����ǰ��λ�գ�����в��� 
	}
	return 0;

}