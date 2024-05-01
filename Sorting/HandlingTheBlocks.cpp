/*
Maratona de Programação da SBC 2021
Problema H - Handling The Blocks
link: maratona.sbc.org.br/hist/2021/primeira-fase/maratona.pdf

solution by: Tamiris Tinelli
Date: 30/Oct/2021
*/

#include <iostream>
#include <vector>

using namespace std;

typedef struct block{
    int num;
    int color;
} block;

int comp (const void * a, const void * b) {

  block *blockA = (block *)a;
  block *blockB = (block *)b;

  return ( blockA->num - blockB->num );
}


int main () {

    int n, k;

    cin >> n >> k;

    //vai armazenar a configuração inicial dos blocos
    block b_ini[n+5];

    //vai armazenar a configuração dos blocos após a ordenação
    block b_fim[n+5];

    //leitura
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        
        b_ini[i].num = x;
        b_ini[i].color = y;

        b_fim[i].num = x;
        b_fim[i].color = y;
    }


    //ordenação
    // parametros do qsort:
    // - ponteiro para o inicio do array a ser ordenado
    // - numero de elementos do array
    // - tamanho de cada elemento do array
    // - função de comparação
    qsort (b_fim, n, sizeof(block), comp);

    /*
    //imprime para checar se ordenação funcionou
    for (int i = 0; i < n; i++) {
        
        int a1 = b_fim[i].num;
        int a2 = b_fim[i].color;

        cout << a1 << " " << a2 << "\n";
    }
    */

    // b_ini não foi ordenado
    // b_fim foi ordenado
    // comparamos a cor dos dois

    int resp = 1; // 1 -> sim; 0 -> não
    for (int i = 0; i < n; i++) {
        // vamos ver se achamos algo errado
        if (b_ini[i].color != b_fim[i].color) {
            resp = 0;
        }
    }

    if (resp == 1) {
        cout << "Y\n";
    }
    else {
        cout << "N\n";
    }

    return 0;
}

/*
-- caso de teste --
input:
4 2
3 1
4 2
1 1
2 2
output:
Y

input:
4 2
2 1
4 2
1 1
3 2
output:
N

input:
3 1
1 1
2 1
3 1
output:
Y
*/