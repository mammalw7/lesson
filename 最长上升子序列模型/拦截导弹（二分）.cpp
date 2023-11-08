#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1100;
int f[N] , g[N];
int main()
{
    int len = 0 , cnt = 0;
    int a;
    while(cin >> a)
    {
        //pos1 表示以a结尾的最长下降子序列长度
        int pos1 = upper_bound(f , f + len , a , greater<int> ()) - f;
        if (pos1 == len)    f[len ++] = a;        //开创一套新的导弹系统
        else                f[pos1] = a;          //使a成为当前导弹系统的最后一位
        
        int pos2 = lower_bound(g , g + cnt , a) - g;
        if (pos2 == cnt)    g[cnt ++ ] = a;
        else                g[pos2] = a;
        
    }
    cout << len << endl << cnt << endl;
    return 0;
}