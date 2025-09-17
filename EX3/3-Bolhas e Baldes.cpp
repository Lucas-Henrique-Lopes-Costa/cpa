/*

Andrea, Carlos e Marcelo são muito amigos e passam todos os finais de semana à beira da piscina. Enquanto Andrea se bronzeia ao sol, os dois ficam jogando Bolhas. Andrea, uma cientista da computação muito esperta, já disse a eles que não entende por que passam tanto tempo jogando um jogo tão primário.

Usando o computador portátil dela, os dois geram um inteiro aleatório N e uma seqüência de inteiros, também aleatória, que é uma permutação de 1, 2, . . . ,N.

O jogo então começa, cada jogador faz um movimento, e a jogada passa para o outro jogador. Marcelo é sempre o primeiro a começar a jogar. Um movimento de um jogador consiste na escolha de um par de elementos consecutivos da seqüência que estejam fora de ordem e em inverter a ordem dos dois elementos. Por exemplo, dada a seqüência 1, 5, 3, 4, 2, o jogador pode inverter as posições de 5 e 3 ou de 4 e 2, mas não pode inverter as posições de 3 e 4, nem de 5 e 2. Continuando com o exemplo, se o jogador decide inverter as posições de 5 e 3 então a nova seqüência será 1, 3, 5, 4, 2.

Mais cedo ou mais tarde, a seqüência ficará ordenada. Perde o jogador impossibilitado de fazer um movimento. Andrea, com algum desdém, sempre diz que seria mais simples jogar cara ou coroa, com o mesmo efeito. Sua missão, caso decida aceitá-la, é determinar quem ganha o jogo, dada a seqüência inicial.

Entrada
A entrada contém vários casos de teste. Os dados de cada caso de teste estão numa única linha, e são inteiros separados por um espaço em branco. Cada linha contém um inteiroN (2 ≤ N ≤ 105), seguido da seqüência inicial P = (X1, X2, ...,XN) de N inteiros distintos dois a dois, onde1 ≤ Xi ≤ N para 1 ≤ i ≤ N.

O final da entrada é indicado por uma linha que contém apenas o número zero.

Saída
Para cada caso de teste da entrada seu programa deve imprimir uma única linha, com o nome do vencedor, igual a Carlos ou Marcelo., sem espaços em branco.

Exemplo de Entrada

51 5 3 42
551 3 42
512345
6352146
554321
6654321

Exemplo de Saída

Marcelo
Carlos
Carlos
Carlos
Carlos
Marcelo

*/

#include <iostream>
#include <vector>
using namespace std;

/*
 * ALGORITMO: Contagem de Inversões usando Merge Sort Modificado
 *
 * Uma inversão é um par (i,j) onde i < j mas arr[i] > arr[j].
 * Este algoritmo conta eficientemente o número total de inversões em O(n log n).
 *
 * O jogo "Bolhas e Baldes" se baseia na teoria dos jogos:
 * - Se o número de inversões for ímpar, o primeiro jogador (Marcelo) ganha
 * - Se for par, o segundo jogador (Carlos) ganha
 *
 * Cada movimento no jogo remove exatamente uma inversão, então o número
 * de movimentos possíveis é igual ao número de inversões.
 */

/*
 * Função que mescla duas metades ordenadas e conta inversões entre elas
 * Parâmetros:
 * - arr: array principal
 * - temp: array temporário para merge
 * - left, mid, right: delimitadores das duas metades
 *
 * Retorna: número de inversões encontradas durante o merge
 */
long long mergeAndCount(vector<int> &arr, int temp[], int left, int mid, int right)
{
    int i, j, k;
    long long inv_count = 0;

    // Índices para as duas metades e para o array temporário
    i = left; // Início da metade esquerda
    j = mid;  // Início da metade direita
    k = left; // Posição no array temporário

    // Merge das duas metades ordenadas
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            // Elemento da esquerda é menor ou igual - sem inversão
            temp[k++] = arr[i++];
        }
        else
        {
            // Elemento da direita é menor - temos inversões!
            temp[k++] = arr[j++];

            // CHAVE DO ALGORITMO: quando arr[i] > arr[j],
            // todos os elementos de i até mid-1 também são > arr[j]
            // Logo, temos (mid - i) inversões
            inv_count += (mid - i);
        }
    }

    // Copia elementos restantes (já ordenados)
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copia de volta para o array original
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

/*
 * Merge Sort modificado que conta inversões
 * Usa divisão e conquista: divide o array em duas metades,
 * conta inversões em cada metade recursivamente,
 * depois conta inversões entre as metades durante o merge
 */
long long mergeSortAndCount(vector<int> &arr, int temp[], int left, int right)
{
    long long inv_count = 0;

    if (left < right)
    {
        int mid = (left + right) / 2;

        // Conta inversões na metade esquerda
        inv_count += mergeSortAndCount(arr, temp, left, mid);

        // Conta inversões na metade direita
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        // Conta inversões entre as duas metades
        inv_count += mergeAndCount(arr, temp, left, mid + 1, right);
    }

    return inv_count;
}

int main()
{
    int n;

    while (cin >> n && n != 0)
    {
        vector<int> sequence(n);

        // Lê a sequência
        for (int i = 0; i < n; i++)
        {
            cin >> sequence[i];
        }

        // Array temporário para o merge sort
        int *temp = new int[n];

        // Conta o número total de inversões na sequência
        long long inversions = mergeSortAndCount(sequence, temp, 0, n - 1);

        delete[] temp;

        // LÓGICA DO JOGO:
        // Cada jogada remove exatamente uma inversão
        // Marcelo joga primeiro, então:
        // - Se número de inversões for ímpar, Marcelo faz a última jogada e ganha
        // - Se for par, Carlos faz a última jogada e ganha
        if (inversions % 2 == 1)
        {
            cout << "Marcelo" << endl;
        }
        else
        {
            cout << "Carlos" << endl;
        }
    }

    return 0;
}
