#include <iostream>
using namespace std;

bool podeDividir(int pesos[], int n, int k, int mid)
{
    int soma = 0;
    int caminhoes = 1;
    for (int i = 0; i < n; i++)
    {
        if (pesos[i] > mid)
            return false;
        if (soma + pesos[i] <= mid)
        {
            soma += pesos[i];
        }
        else
        {
            caminhoes++;
            soma = pesos[i];
            if (caminhoes > k)
                return false;
        }
    }
    return true;
}

void resolverCaso(int nPaineis, int caminhoes, int frete, int pesos[])
{
    int soma = 0;
    int maxPainel = 0;
    for (int i = 0; i < nPaineis; i++)
    {
        soma += pesos[i];
        if (pesos[i] > maxPainel)
            maxPainel = pesos[i];
    }

    int esq = maxPainel;
    int dir = soma;
    int resposta = soma;

    while (esq <= dir)
    {
        int mid = (esq + dir) / 2;
        if (podeDividir(pesos, nPaineis, caminhoes, mid))
        {
            resposta = mid;
            dir = mid - 1;
        }
        else
        {
            esq = mid + 1;
        }
    }

    int custo = resposta * caminhoes * frete;
    cout << resposta << " $" << custo << endl;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int nPaineis, caminhoes, frete;
        cin >> nPaineis >> caminhoes >> frete;
        int pesos[105];
        for (int i = 0; i < nPaineis; i++)
        {
            cin >> pesos[i];
        }
        resolverCaso(nPaineis, caminhoes, frete, pesos);
    }
    return 0;
}