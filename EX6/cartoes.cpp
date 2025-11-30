#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n)
    {
        vector<long long> cartoes(n);
        for (int i = 0; i < n; i++)
        {
            cin >> cartoes[i];
        }

        vector<long long> dpA(n), dpW(n);
        vector<long long> newA(n), newW(n);

        for (int i = 0; i < n; i++)
        {
            dpA[i] = cartoes[i];
            dpW[i] = 0;
        }

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;

                newA[i] = max(cartoes[i] + dpW[i + 1], cartoes[j] + dpW[i]);
                newW[i] = min(dpA[i + 1], dpA[i]);
            }

            for (int i = 0; i + len - 1 < n; i++)
            {
                dpA[i] = newA[i];
                dpW[i] = newW[i];
            }
        }

        cout << dpA[0] << "\n";
    }

    return 0;
}
