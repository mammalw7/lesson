#include <iostream>
#include <vector>
using namespace std;
const int N = 35;
int f[N][N];
int K , B;
void init()
{
    for(int i = 0 ; i < N ; i ++ )
        for(int j = 0 ; j <= i ; j ++ )
        {
            if(!j)      f[i][j] = 1;
            else        f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        }
}
int dp(int n)
{
    if(!n)     return 0;
    vector <int> nums;
    while(n)        nums.push_back(n % B) , n /= B;
    int res = 0 , last = 0;
    for(int i = nums.size() - 1 ; i >= 0 ; i -- )
    {
        int x = nums[i];
        if(x > 0)
        {
            res += f[i][K - last];       // 填0
            if(x > 1)
            {
                // 填 1
                if (K - last - 1 >= 0)    res += f[i][K - last - 1];
                break;     //右侧是表示就填an - 1,题目要求只填0和1，不符合题意，因此break
            }
            
            // x == 1
            else
            {
                last ++;
                if(last > K) break;
            }
        }
        if(!i && last == K )        res ++;         //最右侧也是一种合法方案
    }
    return res;
}

int main()
{
    init();
    int l , r;
    cin >> l >> r >> K >> B;
    cout << dp(r) - dp(l - 1) << endl;
    return 0;
}