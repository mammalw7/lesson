#include <iostream>
using namespace std;
const int N = 110;
int K;
int a[N] , f[N];
int n;
int main()
{
    cin >> K;
    while (K -- )
    {
        cin >> n;
        for (int i = 1 ; i <= n ; i ++ )    cin >> a[i];
        //往左滑翔：最长上升子序列
        int res = 0;
        for (int i = 1 ; i <= n ; i ++ )
        {
            f[i] = 1;
            for (int j = 1 ; j < i ; j ++ )
                if(a[j] < a[i])
                    f[i] = max(f[i] , f[j] + 1);
            res = max(res , f[i]);
        }
        //往右滑翔：最长下降子序列
     
        for (int i = n ; i ; i -- )
        {
            f[i] = 1;
            for (int j = n ; j > i ; j -- )
                if(a[j] < a[i])
                    f[i] = max(f[i] , f[j] + 1);
            res = max (res , f[i]);
        }
        cout << res << endl;
    }
    return 0;
}
