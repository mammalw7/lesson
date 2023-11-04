#include <iostream>
using namespace std;
const int N = 55;
int w[N][N] , f[2 * N][N][N];
int n , m;
int main()
{
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++ )
        for(int j = 1 ; j <= m ; j ++ )
            cin >> w[i][j];
    
    for (int k = 1 + 1 ; k <= n + m ; k ++ )
        for(int i1 = 1 ; i1 <= n ; i1 ++ ) 
            for(int i2 = 1 ; i2 <= n ; i2 ++ )
            {
                int j1 = k - i1 , j2 = k - i2;
                if(j1 >= 1 && j2 >= 1 && j1 <= m && j2 <= m)
                {
                
                    int t = w[i1][j1];
                    if(i1 != i2)        t += w[i2][j2];
                    int &x = f[k][i1][i2]; 
                    x = max(x , f[k - 1][i1][i2 - 1] + t);
                    x = max(x , f[k - 1][i1][i2] + t);
                    x = max(x , f[k - 1][i1 - 1][i2] + t);
                    x = max(x , f[k - 1][i1 - 1][i2 - 1] + t);
                }
            }
    cout << f[n + m][n][n] << endl;
    return 0;
}
