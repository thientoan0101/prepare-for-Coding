#include <iostream>
using namespace std;

#define N 10

void input(int a[][N], int n)
{
    for (int i = 0; i< n;i++)
        for (int j = 0;j<n;j++)
            cin>>a[i][j];
}

void output(int a[][N], int n)
{
    for (int i = 0; i< n;i++)
    {
        for (int j = 0;j<n;j++)
            cout<<a[i][j]<<"  ";
        cout<<endl;
    }
}

void findPathsInGrid(int a[][N], int n, int T[][N])
{
    for (int i = 1; i <=n;i++)
        for (int j = 1;j<=n;j++)
        {
            T[i][j] = max(T[i-1][j], T[i][j-1]) + a[i-1][j-1];
        }
}

void trace(int a[][N], int n, int T[][N])
{
    int i = n, j = n;
    while (i>0 && j>0)
    {
        cout << a[i-1][j-1]<<"  ";
        if (T[i][j] - a[i-1][j-1] == T[i][j-1]) j--;
        else i--;
    }
}

int main()
{
   int a[N][N], T[N][N] = {0};
   input(a,5);
   findPathsInGrid(a,5,T);
   cout<<endl;
   trace(a,5,T);
   output(T,6);
}

