//顺序表的12个操作以及交集，差集，并集
#include<bits/stdc++.h>

using namespace std;

const int Listsize = 3;
const int Listincrement = 10;

typedef struct _list
{
    int *liist;
    int length;
    int listsize;
    int listincrement;
}sqlist;
//扩展顺序表的空间
sqlist expand(sqlist &L)
{
    L.listsize += L.listincrement;
    sqlist mid;
    mid.liist = new int[L.listsize];
    int i;
    for(i = 0;i < L.listsize;i++)
        mid.liist[i] = L.liist[i];
    mid.listsize = L.listsize;
    mid.listincrement = L.listincrement;
    mid.length = L.length;
    return mid;
}
//构造一个空的线性表L
void initlist(sqlist &L)
{
    L.liist = new int[Listsize];
    L.length  = 0;
    L.listsize = Listsize;
    L.listincrement = Listincrement;
}
//销毁线性表
void destroy(sqlist &L)
{
    delete []L.liist;
}
//将线性表重置为空表
void clearlist(sqlist &L)
{
    L.liist = NULL;
    L.length = 0;
    L.listsize = 0;
    L.listincrement = 0;
}
//判断线性表是否为空
bool listempty(sqlist &L)
{
    if(L.length == 0)
        return true;
    else
        return false;
}
//返回线性表的长度
int listlenth(sqlist &L)
{
    return L.length;
}
//用e返回L中第i个元素的值
int getelem(sqlist &L,int i)
{
    int e = L.liist[i-1];
    return e;
}
//查找L中第一个值与e相同的元素的位序
int locatelem(sqlist &L,int e)
{
    for(int i = 0;i < L.length;i++)
        if(L.liist[i] == e)
            return i+1;
    return 0;
}
//返回前驱
int priorelem(sqlist &L,int crue)
{
    int i;
    for(i = 1;i < L.length;i++)
        if(L.liist[i] == crue)
            break;
    int pre =  L.liist[i-1];
    return pre;
}
//返回后继
int nextelem(sqlist &L,int crue)
{
    int i;
    for(i = 0;i < L.length;i++)
        if(L.liist[i] == crue)
            break;
    int next = L.liist[i+1];
    return next;
}
//在L的第i个元素前插入元素e
void listinsert(sqlist &L,int i,int e)
{
    if(i >= L.listsize)
        L = expand(L);
    for(int j = L.length;j >= i;j--)
    {
        L.liist[j] = L.liist[j-1];
    }
    L.liist[i-1] = e;
    L.length++;
}
//删除L的第i个元素，并用e返回其值
int listdelete(sqlist &L,int i)
{
    int e = L.liist[i-1];
    for(int j = i-1;j < L.length-1;j++)
         L.liist[j] = L.liist[j+1];
    L.length--;
    return e;
}
//依次输出线性表中的每个数据元素
void listtraverse(sqlist &L)
{
    for(int i = 0;i < L.length;i++)
        cout << L.liist[i] <<" ";
    cout << endl;
}

void put(sqlist &L)
{
    int num;//顺序表中的元素，输入-1表示终止顺序表输入
    int i = 0;
    cin >> num;
    while(num != -1)
    {
        if(i >= L.listsize)
           L = expand(L);
        L.liist[i++] = num;
        L.length++;
        cin >> num;
    }
}
//找交集
sqlist both(sqlist &L1,sqlist &L2)
{
    sqlist L3;
    L3.liist = new int[L1.listsize];
    for(int i = 0;i < L1.length;i++)
        L3.liist[i] = L1.liist[i];
    L3.length = L1.length;
    L3.listincrement = L1.listincrement;
    L3.listsize = L1.listsize;
    for(int i = 0;i < L2.length;i++)
    {
        int e = L2.liist[i];
        int flag = locatelem(L3,e);
        if(flag == 0)
            listinsert(L3,L3.length+1,e);
    }
    return L3;
}

sqlist reduce(sqlist &L1,sqlist &L2)//求二者差集
{
    sqlist L3;
    L3.liist = new int[L1.listsize];
    for(int i = 0;i < L1.length;i++)
        L3.liist[i] = L1.liist[i];
    L3.length = L1.length;
    L3.listincrement = L1.listincrement;
    L3.listsize = L1.listsize;
    for(int i = 0;i < L2.length;i++)
    {
        int e = L2.liist[i];
        int flag = locatelem(L3,e);
        if(flag != 0)
            listdelete(L3,flag);
    }
    return L3;
}

sqlist together(sqlist &L1,sqlist &L2)//并集
{
    sqlist L3;
    L3.liist = new int[L1.listsize];
    for(int i = 0;i < L1.length;i++)
        L3.liist[i] = L1.liist[i];
    L3.length = L1.length;
    L3.listincrement = L1.listincrement;
    L3.listsize = L1.listsize;
    for(int i = 0;i < L3.length;i++)
    {
        int e = L3.liist[i];
        int flag = locatelem(L2,e);
        if(flag == 0)
        {
            listdelete(L3,i+1);
        }
    }
    return L3;
}

int main()
{
    sqlist L1,L2;
    initlist(L1);initlist(L2);
    cout << "输入顺序表1:";put(L1);
    cout << "输入顺序表2:";put(L2);

    sqlist c = both(L1,L2);//求并集
    cout << "顺序表1:";
    listtraverse(L1);
    cout << "顺序表2:";
    listtraverse(L2);
    cout << "两个顺序表的交集";
    listtraverse(c);
    cout << endl;

    sqlist d = reduce(L1,L2);//求差集
    cout << "顺序表1:";
    listtraverse(L1);
    cout << "顺序表2:";
    listtraverse(L2);
    cout << "顺序表1差顺序表2:";
    listtraverse(d);
    cout << endl;

    sqlist e = together(L1,L2);//求交集
    cout << "顺序表1:";
    listtraverse(L1);
    cout << "顺序表2:";
    listtraverse(L2);
    cout << "两个顺序表的并集:";
    listtraverse(e);
    cout << endl;

    return 0;
}

