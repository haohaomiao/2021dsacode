#include "cmath"
#include "cstdio"

using namespace std;

const int MAXSIZE = 1e6 + 5;
const int mod = 1e6 - 5;

struct node
{
    int x, length;
};
node q[MAXSIZE];
int arr[4][MAXSIZE];

/*void Insert(int x, int y, int *total)
{
    *total = *total + 1;
    arr[0][*total] = y;
    arr[1][*total] = arr[2][x];
    arr[2][x] = *total;
    arr[3][y]++;
}*/

/*void Sort(int *max, int n)
{
    
}*/

int main()
{
    int n, m;
    int max = 0;
    int total;
    scanf("%d %d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        //Insert
        total = total + 1;
        arr[0][total] = v;
        arr[1][total] = arr[2][u];
        arr[2][u] = total;
        arr[3][v]++;
    }
    //Sort
    int head = 0, tail = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[3][i] == 0)
        {
            q[tail] = {i, 1};
            tail = (tail + 1) % mod;
        }
    }
    while (head != tail)
    {
        node x = q[head++];
        head %= mod;
        if (x.length > max)
            max = x.length;
        for (int i = arr[2][x.x]; i; i = arr[1][i])
        {
            int y = arr[0][i];
            if (--arr[3][y] == 0)
            {
                q[tail] = {y, x.length + 1};
                tail = (tail + 1) % mod;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
