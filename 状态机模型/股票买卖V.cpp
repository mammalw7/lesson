#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

int n;
int w[N];
int f[N][3];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);

    f[0][0] = f[0][1] = -INF, f[0][2] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - w[i]);
        f[i][1] = f[i - 1][0] + w[i];
        f[i][2] = max(f[i - 1][2], f[i - 1][1]);
    }

    printf("%d\n", max(f[n][1], f[n][2]));

    return 0;
}

