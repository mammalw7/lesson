#include <iostream>
using namespace std;
const int N = 110;
int w[N][N];
int f[N][N];  // f[i][j] 表示从（1 ，1）所有路径的集合 （不重，不漏）
int n;
int main()
{
    cin >> n;
    while (n -- )
    {
        int r , c;
        cin >> r >> c;
        for (int i = 1 ; i <= r ; i ++ )
            for (int j = 1 ; j <= c ; j ++ )
                cin >> w[i][j];
        
        for (int i = 1 ; i <= r ; i ++ )
            for (int j = 1 ; j <= c ; j ++ )
                f[i][j] = max(f[i - 1][j] , f[i][j - 1]) + w[i][j]; //i - 1 从左边走过来，j - 1 从上面走过来
                
        cout << f[r][c] << endl;
    }
    return 0;
}
