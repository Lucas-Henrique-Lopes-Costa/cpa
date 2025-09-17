/*

Professor Denis está curioso para saber se a classificação final de seus N alunos de programação competitiva segue a ordem de matrícula na universidade. Ele pediu a sua ajuda para, dada a classificação final, contar quantos pares (i, j) existem tais que i < j e m[i] > m[j], onde 1 ≤ i,j ≤ N e m[i] significa a matrícula do aluno que ficou em i-ésimo lugar.

Entrada
A entrada contém vários casos de teste.

A primeira linha de um caso de teste contém um único inteiro N, que representa o número de alunos, onde 1 ≤ N ≤ 105.

As próximas N linhas são a classificação final dos alunos. Cada linha contém uma cadeia de exatamente 10 caracteres.

Saída
Para cada caso de teste, imprima uma única linha com o número pedido na especificação.

Exemplo de Entrada

4
12/0001111
14/0001111
11/0001111
10/0001111

Exemplo de Saída

5

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * ALGORITMO: Contagem de Inversões em Array de Strings usando Merge Sort
 *
 * Problema: Contar quantos pares (i,j) existem onde i < j mas m[i] > m[j]
 * (matrícula na posição i é lexicograficamente maior que na posição j)
 *
 * Solução: Mesmo algoritmo de contagem de inversões do problema anterior,
 * mas adaptado para trabalhar com strings em vez de inteiros.
 *
 * Uma inversão indica que um aluno com matrícula "mais nova" (maior valor)
 * está classificado antes de um aluno com matrícula "mais antiga" (menor valor).
 *
 * Complexidade: O(n log n)
 */

/*
 * Função que mescla duas metades ordenadas de strings e conta inversões
 * Funciona igual ao merge sort tradicional, mas compara strings lexicograficamente
 */
long long mergeAndCount(vector<string> &arr, vector<string> &temp, int left, int mid, int right)
{
    int i = left;    // Índice para a metade esquerda
    int j = mid + 1; // Índice para a metade direita
    int k = left;    // Índice para o array temporário
    long long inv_count = 0;

    // Mescla as duas metades ordenadas contando inversões
    while (i <= mid && j <= right)
    {
        // Comparação lexicográfica de strings
        if (arr[i] <= arr[j])
        {
            // String da esquerda é menor ou igual - sem inversão
            temp[k++] = arr[i++];
        }
        else
        {
            // String da direita é menor - temos inversões!
            temp[k++] = arr[j++];

            // CHAVE: quando arr[i] > arr[j], todas as strings de i até mid
            // também são maiores que arr[j], pois a metade esquerda está ordenada
            // Logo, temos (mid - i + 1) inversões
            inv_count += (mid - i + 1);
        }
    }

    // Copia elementos restantes (já estão ordenados)
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // Copia de volta para o array original
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inv_count;
}

/*
 * Merge Sort recursivo modificado para contar inversões em strings
 * Divide o array em duas metades, conta inversões em cada metade,
 * depois conta inversões entre as metades durante o merge
 */
long long mergeSortAndCount(vector<string> &arr, vector<string> &temp, int left, int right)
{
    long long inv_count = 0;

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Conta inversões na metade esquerda
        inv_count += mergeSortAndCount(arr, temp, left, mid);

        // Conta inversões na metade direita
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        // Conta inversões entre as duas metades
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }

    return inv_count;
}

int main()
{
    int n;

    while (cin >> n)
    {
        vector<string> matriculas(n);

        // Lê as matrículas dos alunos na ordem de classificação
        for (int i = 0; i < n; i++)
        {
            cin >> matriculas[i];
        }

        // Array temporário para o merge sort
        vector<string> temp(n);

        // Conta o número total de inversões
        // Cada inversão representa um caso onde um calouro (matrícula maior)
        // está classificado antes de um veterano (matrícula menor)
        long long inversions = mergeSortAndCount(matriculas, temp, 0, n - 1);

        cout << inversions << endl;
    }

    return 0;
}