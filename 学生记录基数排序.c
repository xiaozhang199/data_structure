#include<bits/stdc++.h>

using namespace std;

const int Listsize = 20;
const int Listincrement = 5;
int cnt[10] = {0};

typedef struct _node
{
    int num;
    char name[10];
    int grade;
    int sorrt[2];
}node;

typedef struct _list
{
    node *liist;
    int length;
    int listsize;
    int listincrement;
}sqlist;

//扩展顺序表的空间
sqlist expand(sqlist &L)
{
    L.listsize += L.listincrement;
    sqlist mid;
    mid.liist = new node[L.listsize];
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
    L.liist = new node[Listsize];
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


//基数排序过程
void radix_sort(sqlist &L,sqlist &inter,int n,int i){
    for(int j = 0;j < 10;j++) cnt[j] = 0;
    for(int j = 0;j < n ;j++) cnt[L.liist[j].sorrt[i]]++;
    for(int j = 1;j < 10;j++) cnt[j] += cnt[j-1];
    for(int k = n-1;k >= 0;k--){
        int j = L.liist[k].sorrt[i];
        inter.liist[cnt[j]-1].grade = L.liist[k].grade;
        strcpy(inter.liist[cnt[j]-1].name,L.liist[k].name);
        inter.liist[cnt[j]-1].num = L.liist[k].num;
        inter.liist[cnt[j]-1].sorrt[0] = L.liist[k].sorrt[0];
        inter.liist[cnt[j]-1].sorrt[1] = L.liist[k].sorrt[1];
        cnt[j]--;
    }

}

//对线性表L进行基数排序
void listsort(sqlist &L)
{
    int i = 1;
    sqlist inter;
    initlist(inter);
    inter.length = L.length;
    while(i >= 0){
        radix_sort(L,inter,L.length,i);
        i--;
        if(i >= 0){
            radix_sort(inter,L,L.length,i);i--;
        }
        else
            for(int j = 0;j < L.length;j++){
                L.liist[j].grade = inter.liist[j].grade;
                strcpy(L.liist[j].name,inter.liist[j].name);
                L.liist[j].num = inter.liist[j].num;
                L.liist[j].sorrt[0] = inter.liist[j].sorrt[0];
                L.liist[j].sorrt[1] = inter.liist[j].sorrt[1];
        }
    }
}

//依次输出线性表中的每个数据元素
void listtraverse(sqlist &L)
{
    cout << "名次" << '\t' << "学号" << '\t' << "姓名" << '\t' << "成绩" << endl;
    for(int i = 0;i < L.length;i++)
        cout << i+1 << '\t' << L.liist[i].num << '\t' << L.liist[i].name << '\t' << L.liist[i].grade << endl;
}

void put(sqlist &L)
{
    int n;//顺序表中的元素个数
    int i = 0,j = 1;
    cout << "请输入学生人数：";
    cin >> n;
    cout << endl;
    while(j <= n)
    {
        cout << "请输入第" << j << "个学生的学号:";
        cin >> L.liist[i].num;
        cout << "请输入第" << j << "个学生的姓名:";
        cin >> L.liist[i].name;
        cout << "请输入第" << j << "个学生的成绩:";
        cin >> L.liist[i].grade;
        cout << endl;
        L.liist[i].sorrt[0] = 9 - L.liist[i].grade/10;
        L.liist[i].sorrt[1] = 9 - L.liist[i].grade%10;
        if(i >= L.listsize)
           L = expand(L);
        i++;
        L.length++;
        j++;
    }
}

int main()
{
    sqlist L;
    initlist(L);
    put(L);
    listsort(L);
    listtraverse(L);
    return 0;
}

