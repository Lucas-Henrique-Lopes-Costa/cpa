#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        long long D;
        int I, B;
        cin >> D >> I >> B;

        vector<int> precos(I);
        for (int i = 0; i < I; i++)
        {
            cin >> precos[i];
        }

        long long menorCusto = LLONG_MAX;

        for (int b = 0; b < B; b++)
        {
            int Qi;
            cin >> Qi;

            long long custoTotal = 0;
            for (int i = 0; i < Qi; i++)
            {
                int ingrediente, quantidade;
                cin >> ingrediente >> quantidade;
                custoTotal += (long long)precos[ingrediente] * quantidade;
            }

            if (custoTotal < menorCusto)
            {
                menorCusto = custoTotal;
            }
        }

        cout << D / menorCusto << endl;
    }

    return 0;
}