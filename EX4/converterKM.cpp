/*
Converter Quilômetros para Milhas
Contest Local, Universidade de Ulm DE Alemanha

Timelimit: 1
Este ano, Bruce Force passa suas férias em Flagstaff, Arizona, onde ele quer treinar para a próxima meia maratona (uma corrida de mais de 21 km). Em seu primeiro treino, ele correu até a casa de seu amigo Greedy Gonzales, que fica a 21 milhas de distância de Flagstaff.

Chegando lá, ele já muito cansado, percebe que 21 milhas são muito mais de 21 km. Greedy Gonzales diz que 21 km é igual a 13 milhas. 21, 13? Bruce percebe imediatamente que deve haver uma relação mais profunda! Ambos, 13 e 21 são números de Fibonacci!

Números Fibonacci podem ser definidos da seguinte forma:

F1 = 1

F2 = 2

Fn+1 = Fn+Fn-1 para n > 1

Bruce está aprendendo sobre o sistema numérico Fibonacci em sua universidade. Cada inteiro positivo X pode ser escrito como a soma de diferentes números Fibonacci, isso significa que dado um numero k e b1, b2, ..., bk tal que x = ∑i=1..k bi * Fi, onde bk = 1 e bi (1 ≤ i < k) é 0 ou 1. Em resumo, podemos escrever a representação como: b (x) = (bk, bk-1, ..., b1). Para tornar a representação única, é necessário que bi * bi-1 = 0 para todo i > 1.

Por exemplo 21 pode ser representado por (1,0,0,0,0,0,0) e 13 como (1,0,0,0,0,0) no sistema Fibonacci. Bruce percebe que se pode converter uma x distância em quilômetros em uma distância y correspondente a milhas da seguinte forma: Primeiro, anote x em seu Fibonacci representação do sistema b(x). Em segundo lugar, mudar os bits de b (x) uma posição para a direita (o último bit é excluído) e obter b(y). Em terceiro lugar, calcular y de b(y) através da avaliação da soma dada acima.

Por exemplo, o número 42 escrito no sistema de Fibonacci é (1,0,0,1,0,0,0,0). Na etapa dois iríamos mudar os bits uma posição para a direita e termos (1,0,0,1,0,0,0). No terceiro passo, calcular 0*1 + 0*2 + 0*3 + 1*5 + 0*8 + 0*13 + 1*21 = 26.

Agora é a sua vez de escrever um programa para Bruce que converte quilômetros em milhas de acordo com o algoritmo de Bruce.

Entrada
A primeira linha de entrada contém t, o número de distâncias que Bruce quer converter de quilômetros em milhas (0 < t <25000). Cada uma das t linhas contem um inteiro, correspondente a distância x (2 < x < 25000) em quilômetros.

Saída
Para cada x distância em quilômetros imprima a distância em milhas y calculadas de acordo com o algoritmo de Bruce.

Exemplo de Entrada	Exemplo de Saída
5

42

100

180

300

360

26

62

111

185

222
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> fib;
    fib.push_back(1);
    fib.push_back(2);

    while (fib.back() < 25000)
    {
        int n = fib.size();
        fib.push_back(fib[n - 1] + fib[n - 2]);
    }

    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        vector<int> bits(fib.size(), 0);

        int restante = x;
        for (int i = fib.size() - 1; i >= 0 && restante > 0; i--)
        {
            if (fib[i] <= restante)
            {
                bits[i] = 1;
                restante -= fib[i];
            }
        }

        int y = 0;
        for (int i = 1; i < (int)bits.size(); i++)
        {
            if (bits[i] == 1)
            {
                y += fib[i - 1];
            }
        }

        cout << y << "\n";
    }

    return 0;
}
