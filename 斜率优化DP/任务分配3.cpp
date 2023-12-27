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
        c[i] += c[i - 1];
        t[i] += t[i - 1];
    }
    int hh = 0 , tt = 0;
    q[0] = 0;
    for(int i = 1 ; i <= n ; i ++ )
    {
        int l = hh , r = tt;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(f[q[mid + 1]] - f[q[mid]] > (c[q[mid + 1]] - c[q[mid]]) * (s + t[i]))  r = mid;
            else        l = mid + 1;
        }
        
        int j = q[r];
        f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n];
        while(hh < tt && (__int128)(f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt]]) >= (__int128)(f[i] - f[q[tt]]) * (c[q[tt]] - c[q[tt - 1]]))     tt --;
        q[++ tt] = i;
        
    }
    
    cout << f[n] << endl;
    return 0;
}