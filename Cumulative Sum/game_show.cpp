/*
Maratona de Programação da SBC 2020
Problema G - Game Show
link: maratona.sbc.org.br/hist/2020/primfase20/maratona20.pdf

solution by: Tamiris Tinelli
Date: 14/Nov/2020
*/

#include <iostream>
using namespace std;

int main(void){
    int c; //caixas
    int i;
    long long maior = 100;
    long long ac = 100; //acumulador
    cin >> c;
    for (i = 0; i < c; i++) {
        int x;
        cin >> x;
        ac += x;
        maior = max (maior, ac);
    }
    cout << maior;

    return 0;
}
