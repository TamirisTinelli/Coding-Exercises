/*
Maratona de Programação da SBC 2021
Problema K - Kathmandu
link: maratona.sbc.org.br/hist/2021/primeira-fase/maratona.pdf

solution by: Tamiris Tinelli
Date: 30/Oct/2021
*/


#include <iostream>

using namespace std;

int main () {

    int t, d, m; //time, duration, meals

    cin >> t >> d >> m;

    int voo[m+5];

    voo[0] = 0; //tempo 0

    //leitura
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        voo[i] = x;
    }
    voo[m+1] = d; //tempo final

    int resp = 0; // 0 -> não; 1 -> sim
    for (int i = m + 1; i > 0; i--) {
        if (voo[i] - voo[i-1] >= t) {
            //da tempo de dormir
            resp = 1;
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
-- casos de teste --

input:
3 10 3
2
4
7
output:
Y

input:
4 10 3
2
4
7
output:
N

input:
5 5 0
output:
Y
*/