#include <bits/stdc++.h>
using namespace std;
//10 10 9 8 7 6 5 4 3 2 1
int merge(int a[],int l,int mid,int r)
{
	int l_len= mid - l;
	int r_len= r-mid-1;
	int l_a[l_len+1];
	int r_a[r_len+1];
	int i,j,k;
	for(i = 0;i <= l_len;i++)
		l_a[i] = a[i+l];
	for(j = 0;j <= r_len;j++)
		r_a[j] = a[j+mid+1];
	k=l;
	i=0;
	j=0;
	while( i <= l_len && j <= r_len)
	{
		if(l_a[i] < r_a[j])
			a[k++]=l_a[i++];
		else
			a[k++]=r_a[j++];
	}
	while(i <= l_len)
		a[k++]=l_a[i++];

	while(j <= r_len)
		a[k++]=r_a[j++];
}

void mergesort(int a[],int l,int r)
{
	int mid;
	if(l < r)
	{
		mid = (l+r) / 2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}

int main()
{
    int n;
    cin >> n;
    int *a = (int *)malloc(n*sizeof(int));
    for(int i = 0;i < n;i++)
        cin >> a[i];

	mergesort(a,0,n-1);

	for(int i = 0;i < n;i++)
		printf("%d ",a[i]);
	return 0;
}
