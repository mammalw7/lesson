#include <iostream>
using namespace std;
const int N = 2e5 + 10;
int f[N] , q[N] , w[N];
int n , m;
int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ )     cin >> w[i];
    int hh = 0 , tt = 0 , res = 1e9;
    for(int i = 1 ; i <= n ; i ++ )
    {
        while(hh <= tt && q[hh] + m < i)            hh ++;
        f[i] = f[q[hh]] + w[i];
        while(hh <= tt && f[i] <= f[q[tt]])         tt --;
        q[++ tt] = i;
    }
    for(int i = n - m + 1 ; i <= n ; i ++ )         res = min(res , f[i]);
    cout << res << endl;
    return 0;
}
