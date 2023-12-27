#include <iostream>
using namespace std;
const int N = 3e5 + 10;
typedef long long LL;
LL f[N];
LL t[N] , c[N];
int q[N];
int n , s;
int main()
{
    cin >> n >> s;
    for(int i = 1 ; i <= n ; i ++ )
    {
        scanf("%lld%lld" , &t[i] , &c[i]);
        t[i] += t[i - 1];
        c[i] += c[i - 1];
    }
    
    int hh = 0 , tt = 0;
    q[0] = 0;
    for(int i = 1 ; i <= n ; i ++ )
    {
        while(hh < tt && f[q[hh + 1]] - f[q[hh]] <= (c[q[hh + 1]] - c[q[hh]]) * (t[i] + s))   hh ++;
        int j = q[hh];
        f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n];
        while(hh < tt && (f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt]]) >= (f[i] - f[q[tt]]) * (c[q[tt]] - c[q[tt - 1]]))    tt --;
        q[++ tt] = i;
    }
    
    cout << f[n] << endl;
    return 0;
}
