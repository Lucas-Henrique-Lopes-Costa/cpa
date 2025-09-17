/*

George é dono de um circo e traz seu circo de cidade em cidade. Ele sabe o quanto de receita ele pode obter em qualquer dia de uma série de dias em uma cidade. Ele também sabe o custo constante diário para manter o seu circo. George quer trazer seu circo à cidade para a série de dias que resulta em maior lucro.

Por exemplo, se em uma determinada cidade o custo for de $ 20 por dia em um exemplo com 6 dias, sendo que as receitas previstas por dia são {$ 18, $ 35, $ 6, $ 80, $ 15, $ 21}, George pode obter o máximo de lucro trazendo o seu circo para esta cidade do dia 2 ao dia 4. Desta forma ele pode lucrar (35 + 80 + 6) - (3 * 20) = $ 61.

Nota: A série de dias que George traz seu circo para a cidade pode ser entre 0 e o número máximo de dias, inclusive. Obviamente, se George traz seu circo para a cidade por 0 dias, ele obtém $ 0 de lucro.

Entrada
A entrada contém muitos casos de teste. A primeira linha de cada caso de teste contém um inteiro N (1 ≤ N ≤ 50) que representa o número de dias que George pode trazer o seu circo para a cidade. A segunda linha do caso de teste contém um número inteiro custoPorDia (0 ≤ custoPorDia < 1000) que representa o custo em manter o circo na cidade. Segue N linhas (uma por cada dia), contendo cada um um inteiro receita (0 ≤ receita < 1000) representa a receita que o circo obtem em cada dia. O final da entrada é indicado por EOF (fim de arquivo).

Saída
Para cada caso de teste imprima o máximo de dinheiro que George pode ganhar trazendo o seu circo para a cidade de acordo com o exemplo abaixo.

Exemplo de Entrada

6
20
18
35
6
80
15
21
4
40
30
20
10
38

Exemplo de Saída

61
0

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * ALGORITMO DE KADANE: Maximum Subarray Problem
 *
 * Problema: George quer maximizar o lucro do seu circo escolhendo uma
 * sequência contígua de dias para operar na cidade.
 *
 * Transformação do problema:
 * - Para cada dia, calcula-se o lucro líquido = receita - custo_por_dia
 * - O problema se torna: encontrar o subarray contíguo de maior soma
 * - Se a maior soma for negativa, é melhor não operar (lucro = 0)
 *
 * Algoritmo de Kadane:
 * - Percorre o array mantendo a soma máxima terminando na posição atual
 * - A cada posição, decide se "continua" o subarray ou "reinicia"
 * - Mantém o registro da maior soma encontrada até agora
 *
 * Complexidade: O(n) tempo, O(1) espaço - extremamente eficiente!
 *
 * Intuição: Se a soma acumulada se torna negativa, é melhor descartar
 * os dias anteriores e começar um novo período a partir do dia atual.
 */

int main()
{
    int n;

    while (cin >> n)
    {
        int custoPorDia;
        cin >> custoPorDia;

        vector<int> receitas(n);
        vector<int> lucroLiquido(n);

        // Lê as receitas e calcula o lucro líquido por dia
        // lucro_liquido[i] = receita[i] - custo_por_dia
        for (int i = 0; i < n; i++)
        {
            cin >> receitas[i];
            lucroLiquido[i] = receitas[i] - custoPorDia;
        }

        // ALGORITMO DE KADANE para Maximum Subarray Sum
        int maxLucro = 0;   // Pode escolher 0 dias (não operar)
        int lucroAtual = 0; // Soma do subarray terminando na posição atual

        for (int i = 0; i < n; i++)
        {
            // Decisão chave: continuar o subarray atual ou começar novo?
            // Se lucroAtual + lucroLiquido[i] < lucroLiquido[i],
            // é melhor começar um novo subarray a partir do dia i
            lucroAtual = max(lucroLiquido[i], lucroAtual + lucroLiquido[i]);

            // Atualiza o lucro máximo encontrado até agora
            maxLucro = max(maxLucro, lucroAtual);

            // Versão equivalente mais explícita:
            // lucroAtual += lucroLiquido[i];
            // if (lucroAtual < 0) lucroAtual = 0;  // Reinicia se ficar negativo
            // maxLucro = max(maxLucro, lucroAtual);
        }

        cout << maxLucro << endl;
    }

    return 0;
}
