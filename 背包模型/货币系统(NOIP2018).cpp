#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 25100 , M = 110;
int f[N];
int a[M];
int T;
int main()
{
    cin >> T;
    while(T -- )
    {
        int n;
        cin >> n;
        for(int i = 1 ; i <= n ; i ++ )         cin >> a[i];
        sort(a , a + n + 1);
        memset(f , 0 , sizeof f);
        f[0] = 1;
        int m = a[n];
        int res = 0;
        for(int i = 1 ; i <= n ; i ++ )
        {
                if(!f[a[i]])        res ++;            //如果凑不出a[i]，则a[i]本身就算是一个方案
                for(int j = a[i] ; j <= m ; j ++ )
                    f[j] += f[j - a[i]];
        }
       cout << res << endl;
    }
    return 0;
}