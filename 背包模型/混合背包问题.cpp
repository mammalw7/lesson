// 二进制优化多重背包
#include <iostream>
using namespace std;
const int N = 1010;
int f[N];
int n , m;
int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ )
    {
        int v , w , s;
        cin >> v >> w >> s;
        if(!s)    // 使用完全背包模型
            for(int j = v ; j <= m ; j ++ )
                f[j] = max(f[j] , f[j - v] + w);
        else
        {
            if(s == -1)      s = 1;  //01背包模型为特殊的多重背包模型
            // 用二进制优化
            for(int k = 1 ; k <= s ; k *= 2)
            {
                 for(int j = m ; j >= k * v ; j -- )
                    f[j] = max(f[j]  , f[j - k * v] + k * w);
                 s -= k;
            }

            if(s)          // 去除冗余
            for(int j = m ; j >= s * v ; j -- )
                f[j] = max(f[j] , f[j - s * v] + s * w);
        }       
    }
    cout << f[m] << endl;
}

// 滑动窗口优化多重背包
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010;
int f[N];
int g[N];
int q[N];
int n , m;
int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ )
    {
        int v , w , s;
        cin >> v >> w >> s;
        if(!s)          
            for(int j = v ; j <= m ; j ++ )
                f[j] = max(f[j]  , f[j - v] + w);
        if(s == -1)             s = 1;
        if(s)
        {
           memcpy (g , f , sizeof f);
            for(int j = 0 ; j < v ; j ++ )
            {
                int hh = 0 , tt = -1;
                for(int k = j ; k <= m ; k += v)
                {
                    while(hh <= tt && q[hh] < k - s * v)     hh ++;          //维护滑动窗口
                    while(hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j)/ v * w)   tt --;   // 去除冗余元素
                    q[++ tt] = k;
                    f[k] = g[q[hh]] + (k - q[hh]) / v * w;           //增加的收益
                }
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}