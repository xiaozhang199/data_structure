#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;

const int maxsize = 100;
const int queueincrecement = 10;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

typedef struct _queue{
    BiTree *elem;
    int front;
    int rear;
    int queuesize;
    int increment;
}sqqueue;

//初始化循环队列
void initqueue(sqqueue &Q,int Maxsize = maxsize,int Queueincrecement = queueincrecement){
    Q.elem = new BiTree [Maxsize+1];
    Q.queuesize = Maxsize+1;
    Q.increment = Queueincrecement;
    Q.front = Q.rear = 0;
}

//扩展循环队列的元素个数
void increcement(sqqueue &Q){
    BiTree *a = new BiTree[Q.queuesize+Q.increment];
    for(int k = 0; k < Q.queuesize;k++)
        a[k] = Q.elem[(Q.front+k)%Q.queuesize];
    delete [] Q.elem;
    Q.elem = a;
    Q.queuesize += Q.increment;
    Q.front = 0;
    Q.rear = Q.queuesize-1;
}

//返回循环队列中的元素个数
int queuelength(sqqueue Q){
    return (Q.rear + Q.queuesize - Q.front)%Q.queuesize;
}

//删除对头元素并用e返回其值
bool dequeue(sqqueue &Q,BiTree &e){
    if(Q.front == Q.rear) return false;
    e = Q.elem[Q.front];
    Q.front = (Q.front+1)%Q.queuesize;
    return true;
}
//取对头元素的值
bool gethead(sqqueue Q,BiTree &s){
    if(Q.rear == Q.front) return false;
    s = Q.elem[Q.front];
    return true;
}
//插入值为e的队尾元素
void enqueue(sqqueue &Q,BiTree e){
    if((Q.rear+1)%Q.queuesize == Q.front) increcement(Q);
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear+1)%Q.queuesize;
}


//先序创建
void CreateBiTree(BiTree &T) {
	char ch;
	cin >> ch;
	if(ch == '#')
		T = NULL;
	else {
		T=new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
//中序遍历
void traverse1(BiTree T) {
	if(T) {
		traverse1(T->lchild);
		cout << T->data << " ";
		traverse1(T->rchild);
	}
}
//后序遍历
void traverse2(BiTree T) {
	if(T) {
		traverse2(T->lchild);
		traverse2(T->rchild);
		cout << T->data << " ";
	}
}
//层次遍历
void traverse3(BiTree T) {
    sqqueue Q;
	initqueue(Q);
	enqueue(Q,T);
	BiTree s;
	while(!(Q.front == Q.rear))
	{
	    gethead(Q,s);
		cout << s->data <<" ";
		if(s->lchild != NULL)
			enqueue(Q, s->lchild );
		if(s->rchild != NULL)
			enqueue(Q, s->rchild );
		dequeue(Q,s);
	}
}
//数据：ab#de###c##
int main()
{
	BiTree a;
	cout<<"请输入二叉树的元素：";
	CreateBiTree(a);
    cout<<"\n中序遍历:\n";
	traverse1(a);
	cout<<"\n后序遍历：\n";
    traverse2(a);
    cout<<"\n层次遍历：\n";
    traverse3(a);
	return 0;

}


