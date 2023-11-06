#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5010;
typedef pair<int , int> PII;
int f[N];
PII q[N];
int n;
int main()
{
    cin >> n;
    for (int i = 1 ; i <= n ; i ++ )    cin >> q[i].first >> q[i].second; //输入两岸的序列，是一个散列对应关系
    sort(q , q + n + 1);       //sort函数默认排序数组下标0~n - 1 ，需要排序到n，所以要+1
    int res = 0;
    //转化为一维问题，只用考虑北岸即可
    for (int i = 1 ; i <= n ; i ++ )
    {
        f[i] = 1;
        for (int j = 1 ; j < i ; j ++ )
            if(q[j].second < q[i].second)
                f[i] = max (f[i] , f[j] + 1);
    }
    for (int i = 1 ; i <= n ; i ++ )     
        res = max (res , f[i]);
    cout << res << endl;
    return 0;
}
