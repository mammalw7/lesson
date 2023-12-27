#include <iostream>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL s[N];
int n , m;
LL f[N];
int q[N];
LL g(int x)
{
    if(!x)      return 0;
    return f[x - 1] - s[x];
}
int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ )         
    {
        scanf("%lld" , &s[i]);
        s[i] += s[i - 1];
    }
    int hh = 0 , tt = 0;
    for(int i = 1 ; i <= n ; i ++ )
    {
        while(hh <= tt && q[hh] + m < i)            hh ++;
        f[i] = max(f[i - 1] , g(q[hh]) + s[i]);
        while(hh <= tt && g(i) >= g(q[tt]))         tt --;
        q[++ tt] = i;
    }
    cout << f[n] << endl;
    return 0;
}