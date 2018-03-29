#include <iostream>
#include<fstream>
#include<vector>

using namespace std;
int strLen = 0;

void adjustHeap(vector<int>*,int);
void numSwap(vector<int>* ,int ,int );
bool GetLeftChild(vector<int>*,int);
bool GetRightChild(vector<int>*,int);

void heapSort(vector<int>* tarray)
{
    //创建小根堆
    int i = 0;
    int startIndex = strLen/2;
    while((startIndex - i) >= 0)
    {
        adjustHeap(tarray,startIndex - i);
        i++;
    }
}

void adjustHeap(vector<int>* tarray,int n)
{
    if(n > strLen/2)
    {
        return ;
    }
    if((*tarray)[n] > (*tarray)[2 * n + 1])
    {
        numSwap(tarray,n,2 * n + 1);
        adjustHeap(tarray,2 * n + 1);
    }
    if(2 * n + 2 > strLen)
    {
        return;
    }
    if((*tarray)[n] > (*tarray)[2 * n + 2])
    {
        numSwap(tarray,n,2 * n + 2);
        adjustHeap(tarray,2 * n + 2);
    }
}
void numSwap(vector<int>* vtr,int n,int m)
{
    int t = (*vtr)[n];
    (*vtr)[n] = (*vtr)[m];
    (*vtr)[m] = t;
}

void GetLDR(vector<int>* vtr,int n)//中序遍历
{
    GetLeftChild(vtr,n);
    cout<<(*vtr)[n];
    GetRightChild(vtr,n);

}
bool GetLeftChild(vector<int>* vtr,int n)
{
    if(2 * n + 1 <= strLen)
    {
        GetLDR(vtr,2 * n + 1);
    }
}
bool GetRightChild(vector<int>* vtr,int n)
{
    if(2 * n + 2 <= strLen)
    {
        GetLDR(vtr,2 * n + 2);
    }
}
int main()
{
    ifstream in("input.txt");
    vector<int> arrayInt;
    int tempi;
    while(!in.eof())
    {
        in>>tempi;
        arrayInt.push_back(tempi);
        strLen++;
    }
    in.close();
    strLen -= 1;
    cout<<arrayInt.size()<<endl;
    heapSort(&arrayInt);
    int i = 0;
    for(;i <= strLen;i ++)
    {
        cout<<arrayInt[i];
    }
        cout<<endl;
    GetLDR(&arrayInt,0);

    char c;
    cin>>c;
    return 0;
}
