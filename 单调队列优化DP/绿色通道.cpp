#include <iostream>
using namespace std;
const int N = 5e4 + 10;
int f[N] , q[N] , w[N];
int n , m;

bool check(int limit)
{
    int hh = 0 , tt = 0;
    for(int i = 1 ; i <= n ; i ++ )
    {
        while(hh <= tt  && q[hh] < i - limit - 1)       hh ++ ;
        f[i] = f[q[hh]] + w[i];
        while(hh <= tt && f[i] <= f[q[tt]])         tt --;
        q[++ tt] = i;
    }
    
    for(int i = n - limit ; i <= n ; i ++ )
        if(f[i] <= m)   
            return true;
    return false;
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++ )         cin >> w[i];
    int l = 0 , r = n ; 
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid))              r = mid;
        else                        l = mid + 1;
    }
    
    cout << r << endl;
    return 0;
}
