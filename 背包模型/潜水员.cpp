#include <iostream>
#include <cstring>
using namespace std;
const int N = 22 , M = 80;
int f[N][M];
int n , m , K;
int main()
{
    cin >> n >> m >> K;
    memset (f , 0x3f , sizeof f);
    f[0][0] = 0;
    while(K --)
    {
        int v1 , v2 , w;
        cin >> v1 >> v2 >> w;
        for(int i = n ; i >= 0 ; i -- )
            for(int j = m ; j >= 0 ; j -- )
                f[i][j] = min(f[i][j] , f[max(0 , i - v1)][max(0 , j - v2)] + w);
    }
    
    cout << f[n][m] << endl;
    return 0;
}
