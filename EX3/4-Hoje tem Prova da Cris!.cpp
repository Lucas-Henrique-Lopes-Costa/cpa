/*

A Profa. Cristina é muito exigente. Sua fama de maquiavélica já é conhecida fora da universidade e ela até gosta disso... Mas, parece que agora ela exagerou... Na última prova de sua disciplina, a professora exigiu que os alunos formassem fila indiana para entrar na sala de aula. Eles formaram. Quando eles iam entrar, ela gritou: "Mas, vocês não estão em ordem lexicográfica crescente!!!???"

Os alunos revoltados formaram uma comissão e foram conversar com a professora dizendo que aquilo já era demais. Para não parecerem intransigentes eles disseram que permitiriam no máximo um número k de trocas de posição entre pessoas consecutivas na fila. A professora gostou da idéia, e colocou como um problema extra da prova.

Dada uma sequência de nomes e um inteiro k, devolver a menor sequência (em ordem lexicográfica) que pode ser obtida a partir da original com no máximo k trocas de elementos vizinhos. Sua tarefa é resolver este exercício para os alunos da Profa. Cristina a fim de que eles consigam entrar na sala e começar a prova.

Entrada
A entrada é composta de diversas instâncias. Cada instância começa com dois inteiros n e k, onde 1 ≤ n ≤ 100 e 0 ≤ k ≤ n, indicando a quantidade nomes e a quantidade máxima de trocas, respectivamente. A próxima linha contém uma sequência de n nomes. Cada nome possui tamanho máximo de 20 caracteres, e letras de 'a' a 'z'.

O programa deve parar de processar a entrada quando n = k = 0.

Saída
Para cada instância, você deverá imprimir um identificador "Instancia c", onde c é o número da instância atual. Na linha seguinte você deve imprimir a lista de nomes resultante do processo. Após cada nome, seu programa deve imprimir um espaço em branco, inclusive após o último nome (por exemplo, na saída do primeiro caso de teste abaixo: wanderleybthadeubchegadob, onde b representa um espaço em branco. Após cada instância, seu programa deve imprimir uma linha em branco, inclusive após a última.

Exemplo de Entrada

3 0
wanderley thadeu chegado
3 1
wanderley thadeu chegado
3 2
wanderley thadeu chegado
3 3
wanderley thadeu chegado
0 0

Exemplo de Saída

Instancia 1
wanderley thadeu chegado

Instancia 2
thadeu wanderley chegado

Instancia 3
chegado wanderley thadeu

Instancia 4
chegado thadeu wanderley

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
 * ALGORITMO: Ordenação Gulosa com Número Limitado de Trocas
 *
 * Problema: Dado um array de strings e um número máximo k de trocas entre
 * elementos adjacentes, encontrar a menor sequência lexicograficamente possível.
 *
 * Estratégia Gulosa:
 * Para cada posição do array (da esquerda para a direita):
 * 1. Encontra o menor elemento lexicograficamente que pode ser movido
 *    para esta posição com as trocas restantes
 * 2. Move esse elemento para a posição atual usando bubble sort
 * 3. Atualiza o número de trocas restantes
 *
 * Complexidade: O(n²) onde n é o número de elementos
 * A estratégia gulosa funciona porque priorizamos colocar os menores
 * elementos nas posições mais à esquerda primeiro.
 */

int main()
{
    int n, k;
    int instance = 1;

    while (cin >> n >> k && (n != 0 || k != 0))
    {
        vector<string> names(n);

        // Lê os nomes
        for (int i = 0; i < n; i++)
        {
            cin >> names[i];
        }

        int swaps_used = 0; // Contador de trocas utilizadas

        // ALGORITMO GULOSO: para cada posição, coloca o menor elemento possível
        for (int pos = 0; pos < n && swaps_used < k; pos++)
        {
            // Encontra o menor nome que pode ser movido para a posição atual
            // Limitado pelo número de trocas restantes: só pode ir até
            // pos + (k - swaps_used) posições à frente
            int best_idx = pos;
            for (int i = pos + 1; i < n && i <= pos + (k - swaps_used); i++)
            {
                // Compara lexicograficamente e atualiza se encontrar um menor
                if (names[i] < names[best_idx])
                {
                    best_idx = i;
                }
            }

            // Move o menor nome encontrado para a posição atual
            // Usa bubble sort: faz trocas adjacentes até chegar na posição
            while (best_idx > pos && swaps_used < k)
            {
                // Troca elementos adjacentes
                swap(names[best_idx], names[best_idx - 1]);
                best_idx--;   // Atualiza posição do elemento
                swaps_used++; // Contabiliza a troca
            }
        }

        // Imprime o resultado
        cout << "Instancia " << instance << endl;
        for (int i = 0; i < n; i++)
        {
            cout << names[i] << " ";
        }
        cout << endl
             << endl;

        instance++;
    }

    return 0;
}
