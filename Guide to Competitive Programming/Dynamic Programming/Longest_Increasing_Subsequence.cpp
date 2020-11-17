#include <iostream>
using namespace std;



void longestIncreasingSub(int a[], int n, int length[])
{
    for (int i = 0;i<n;i++)
    {
        length[i] = 1;
        for (int j = 0; j<i;j++)
        {
            if (a[j]<a[i])
                length[i] = max(length[i], length[j]+1);
        }
    }
}

int main()
{
    int a[] = {6,2,5,1,7,4,3,8};
    int length[8];
    longestIncreasingSub(a,8,length);
    for (int i = 0;i<8;i++)
    {
        cout<<length[i]<<"  ";
    }
}

