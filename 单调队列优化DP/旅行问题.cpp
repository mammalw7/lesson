#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10 , M = N << 1;
int q[M] , o[N] , d[N];
LL s[M];
bool ans[M];
int n;
int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i ++ )   scanf("%d%d" , &o[i] , &d[i]);    
    for(int i = 1 ; i <= n ; i ++ )   s[i] = s[i + n] = o[i] - d[i];
    for(int i = 1 ; i <= n << 1 ; i ++ )        s[i] += s[i - 1];
    int hh = 0 , tt = -1;
    
    // 顺时针，前缀和
    for(int i = 1 ; i <= n << 1 ; i ++ )
    {
        while(hh <= tt && q[hh] < i - n)        hh ++;
        while(hh <= tt && s[i] <= s[q[tt]])     tt --;
        q[++ tt] = i;
        if(i >= n && s[i - 1 - n] <= s[q[hh]])      ans[i - n] = true;
    }
    
    // 逆时针，后缀和
    hh = 0 , tt = -1;
    d[0] = d[n] ;
    for(int i = 1 ; i <= n ; i ++ )         s[i] = s[i + n] = o[i] - d[i - 1];
    for(int i = n << 1 ; i >= 0 ; i -- )        s[i] += s[i + 1];
    for(int i = 1 ; i <= n << 1 ; i ++ )
    {
        while(hh <= tt && q[hh] < i - n + 1)        hh ++;
        while(hh <= tt && s[i] <= s[q[tt]])         tt --;
        q[++ tt] = i;
        if(i >= n  && s[q[hh]] >= s[i + 1])         ans[i - n] = true;
    }
    for(int i = 1 ; i <= n ; i ++ )
    if(ans[i])          cout << "TAK" << endl;
    else                cout << "NIE" << endl;
    return 0;
}

