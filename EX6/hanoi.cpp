#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool ehQuadradoPerfeito(int n)
{
    int raiz = (int)sqrt((double)n);
    return raiz * raiz == n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> resposta(51);

    for (int n = 1; n <= 50; n++)
    {
        vector<int> topo;
        int bola = 1;
        bool infinito = false;

        int semNovaHaste = 0;
        const int LIMITE = 100000;
        const int LIMITE_SEM_NOVA = 1000;

        while (bola <= LIMITE)
        {
            bool colocou = false;

            for (int i = 0; i < (int)topo.size(); i++)
            {
                if (ehQuadradoPerfeito(topo[i] + bola))
                {
                    topo[i] = bola;
                    colocou = true;
                    semNovaHaste++;
                    break;
                }
            }

            if (!colocou)
            {
                if ((int)topo.size() < n)
                {
                    topo.push_back(bola);
                    semNovaHaste = 0;
                }
                else
                {
                    break;
                }
            }

            if (semNovaHaste >= LIMITE_SEM_NOVA && (int)topo.size() <= n)
            {
                infinito = true;
                break;
            }

            bola++;
        }

        if (infinito || bola > LIMITE)
        {
            resposta[n] = -1;
        }
        else
        {
            resposta[n] = bola - 1;
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << resposta[n] << "\n";
    }

    return 0;
}