#include <iostream>
#include <cstring>
using namespace std;
const int N = 20100;
int q[N];
int f[N];
int g[N];
int n , m;
int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++ )
    {
        int v , w , s;
        cin >> v >> w >> s;
        memcpy(g , f , sizeof f);
        for(int j = 0 ; j < v ; j ++ )         // 枚举余数
        {
            int hh = 0 , tt = -1;
            for(int k = j ; k <= m ; k += v)          // 遍历余数为j的体积
            {
                while(hh <= tt && q[hh] < k - s * v)           hh ++ ;
                while(hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w)   tt --; //如果后一个元素比前面的元素大，则原先的元素没必要留，单调队列的去除冗余操作
                q[++ tt] = k;
                f[k] = g[q[hh]] + (k - q[hh]) / v * w;       //增加的收益
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}