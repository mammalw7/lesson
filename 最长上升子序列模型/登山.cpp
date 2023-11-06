#include <iostream>
using namespace std;
const int N = 1100;
int a[N];
int n;
int f[N] , g[N];            //f[N]为登山 ， g[N]为下山
int main()
{
    cin >> n;
    for (int i = 1 ; i <= n ; i ++ )     cin >> a[i];
    //上山
    for (int i = 1 ; i <= n ; i ++ )
    {
        f[i] = 1;
        for(int j = 1 ; j < i ; j ++ )
            if(a[j] < a[i])
                f[i] = max (f[i] , f[j] + 1);
    }
    //下山
    for (int i = n ; i ; i -- )
    {
        g[i] = 1;
        for (int j = n ; j > i ; j -- )
            if(a[j] < a[i])
                g[i] = max(g[i] , g[j] + 1);
    }
    int res = 0;
    for (int i = 1 ; i <= n ; i ++ )    res = max(res , f[i] + g[i] - 1);
    cout << res << endl;
    return 0;
}
