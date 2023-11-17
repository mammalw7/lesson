#include <iostream>
using namespace std;
const int N = 11 , M = 16;
int f[N][M];                  //因为要输出具体方案，所以不能做一维优化
int w[N][M];          
int n , m;
int way[N];                   //记录子公司获得的设备台数（即体积）
int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ )
        for(int j = 1 ; j <= m ; j ++ )
            cin >> w[i][j];
    
    for(int i = 1 ; i <= n ; i ++ )
        for(int j = 1 ; j <= m ; j ++ )
            for(int k = 0 ; k <= j ; k ++ )
                f[i][j] = max(f[i][j] , f[i - 1][j - k] + w[i][k]);
    
    cout << f[n][m] << endl;
                
    int j = m;
    for(int i = n ; i >= 1 ; i --)
        for(int k = 0 ; k <= j ; k ++ )
            if(f[i][j] == f[i - 1][j - k] + w[i][k])
            {
                way[i] = k;
                j -= k;
                break;
            }
            
    for(int i = 1 ; i <= n ; i ++ )     cout << i << ' ' << way[i] << endl;
    return 0;
}
