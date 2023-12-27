#include <iostream>
using namespace std;
const int N = 3e5 + 10;
typedef long long LL;
LL s[N];
int q[N];
int n , m;
int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ )
    {
        scanf("%lld\n" , &s[i]);
        s[i] += s[i - 1];
    }
    int hh = 0 , tt = 0;
    LL res = -1e18;
    for(int i = 1 ; i <= n  ; i ++ )
    {
        while(hh <= tt && q[hh] < i - m)        hh ++;
        res = max(res , s[i] - s[q[hh]]);
        while(hh <= tt && s[i] <= s[q[tt]])     tt --;
        q[++ tt] = i;
    }
    cout << res << endl;
    return 0;
}