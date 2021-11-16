//洛谷p7910--先不管
//由小到大排

//1.设置哨兵
#include <bits/stdc++.h>

using namespace std;
//10 10 8 9 2 6 7 8 2 5 4
int main()
{
    int n;
    cin >> n;
    int *a;
    a = (int *)malloc((n+1)*sizeof(int));
    for(int i = 1;i < n;i++){
        cin >> a[i];
    }
    int j;
    for(int i = 2;i < n;i++){
        a[0] = a[i];
        for(j = i-1;j >= 1;j--){
            if(a[j] > a[0])
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = a[0];
    }
    for(int i = 1;i <= n;i++)
        cout << a[i] << " ";
    return 0;
}

//2.不设置哨兵
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int *a;
    a = (int *)malloc((n)*sizeof(int));
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 1;i < n;i++){
        for(int j = i;j >= 1;j--){
            if(a[j] < a[j-1]){
                int t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
            }
        }
    }

    for(int i = 0;i < n;i++)
        cout << a[i] << " ";

    return 0;
}

























