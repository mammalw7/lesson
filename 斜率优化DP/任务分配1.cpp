#include <iostream>
#include <cstring>
using namespace std;
const int N = 5050;
typedef long long LL;
LL f[N];
int sumt[N] , sumc[N];
int n;
int main()
{
    cin >> n;
    int s;
    cin >> s;
    for(int i = 1 ; i <= n ; i ++ )
    {
        cin >> sumt[i] >> sumc[i];
        sumt[i] += sumt[i - 1];
        sumc[i] += sumc[i - 1];
    }

    memset(f , 0x3f , sizeof f);
    f[0] = 0;
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 0 ; j < i ; j ++ )
            f[i] = min(f[i] , f[j] + (LL)sumt[i] * (sumc[i] - sumc[j]) + (LL)s * (sumc[n] - sumc[j]));

    cout << f[n] << endl;        

    return 0;
}