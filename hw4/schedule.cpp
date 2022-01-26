#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define Parent(i) ((i-1)>>1)
#define Lchild(i) ((i<<1)+1)
#define Rchild(i) ((i+1)<<1)
const int MAXSIZE = 1e7 + 5;
struct Node1
{
    long long int data1;
    char data2[10];
    Node1&operator=(const Node1&a)
	{
		data1 = a.data1;
		strcpy(data2, a.data2);
		return*this;
    }
    friend bool operator<(Node1 x, Node1 y)
    {
        if (x.data1 != y.data1)
            return x.data1 < y.data1;
        if (strcmp(x.data2, y.data2) < 0)return true;
		else return false;
    }
} h[MAXSIZE];
int n = 0;
void up(int);
void down(int);
void Extract();
void Ins(Node1);
int main()
{
    int a, b;
    Node1 x;
    scanf("%d %d", &a, &b);
    long long int p = 1;
    for (int i = 0; i < 32; i++)
        p *= 2;
    for (int i = 0; i < a; i++)
    {
        scanf("%lld %s", &x.data1, x.data2);
        Ins(x);
    }
    while (b-- && n >= 1)
    {
        printf("%s\n", h[1].data2);
        x = h[1];
        x.data1 *= 2;
        Extract();
        if (x.data1 < p)
            Ins(x);
    }
    return 0;
}

void Ins(Node1 data1)
{
    n += 1;
    h[n] = data1;
    up(n);
}
void Extract()
{

    h[1] = h[n];
    n -= 1;
    down(1);
}
void down(int p)
{
    int temp = p * 2;
    while (temp <= n)
    {
        if (temp < n && h[temp + 1] < h[temp])
            temp++;
        if (h[temp] < h[p])
        {
            swap(h[p], h[temp]);
            p = temp;
            temp *= 2;
        }
        else
            break;
    }
}
void up(int p)
{
    while (p > 1)
    {
        if (h[p] < h[p / 2])
        {
            swap(h[p], h[p / 2]);
            p /= 2;
        }
        else
            break;
    }
}
