#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    int instancia = 1;

    while (cin >> n >> t && n != 0)
    {
        vector<int> duracao(n), pontuacao(n);

        for (int i = 0; i < n; i++)
        {
            cin >> duracao[i] >> pontuacao[i];
        }

        vector<int> dp(t + 1, 0);

        for (int tempo = 1; tempo <= t; tempo++)
        {
            for (int i = 0; i < n; i++)
            {
                if (duracao[i] <= tempo && duracao[i] > 0)
                {
                    dp[tempo] = max(dp[tempo], dp[tempo - duracao[i]] + pontuacao[i]);
                }
            }
        }

        cout << "Instancia " << instancia++ << "\n";
        cout << dp[t] << "\n\n";
    }

    return 0;
}
