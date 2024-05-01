/*
Maratona de Programação da SBC 2021
Problema E - Escalator
link: maratona.sbc.org.br/hist/2021/primeira-fase/maratona.pdf

solution by: Tamiris Tinelli
Date: 30/Oct/2021
*/

// obs: acredito que dá pra reduzir número de linhas do código fazendo uma função de embarque

#include <iostream>
#include <queue>

using namespace std;

int main () {

    int n;
    cin >> n;

    queue<int> dir1; //fila de quem quer a direção 0
    queue<int> dir2; //fila de quem quer a direção 1

    //leitura
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        //coloca na fila correspondente
        if (b == 0)
            dir1.push(a);
        else
            dir2.push(a);
    }

    
    //variavel que marca o sentido que a maquina esta andando
    // -1 -> parado, significa que pode iniciar qualquer sentido
    // 0 -> sentido do dir1
    // 1 -> sentido do dir2
    int mov = -1;
    
    //tempo
    int t = 0;

    while (dir1.empty() == false && dir2.empty() == false) {
        //enquanto as duas filas tiverem elementos

        if (mov == 0) {
            //ta movendo no sentido da fila 1
            
            if (dir1.front() < t) {
                //o primeiro cara da fila vai entrar
                t = max(dir1.front() + 10, t);
                //cout << "linha 47: o " << dir1.front() << " entrou e o tempo agora eh " << t << "\n";               
                dir1.pop();
            }
            else {
                //a maquina vai parar no tempo t
                mov = -1;
            }
        } 
        else if (mov == 1) {
            //ta movendo no sentido da fila 2
            
            if (dir2.front() < t) {
                //o primeiro cara da fila vai entrar
                t = max (dir2.front() + 10, t);
                //cout << "linha 61: o " << dir2.front() << " entrou e o tempo agora eh " << t << "\n";  
                dir2.pop();
            }
            else {
                //a maquina vai parar no tempo t
                mov = -1;
            }
        } 
        else {
            //esta parado, vai entrar o da fila com menor no inicio
            
            //eh a fila1?
            if (dir1.front() < dir2.front()) {
                //o cara entra
                t = max(dir1.front() + 10, t+10);
                mov = 0; //sentido da fila 1
                //cout << "linha 77: o " << dir1.front() << " entrou e o tempo agora eh " << t << "\n";  
                dir1.pop();
            }
            //eh a fila2?
            else {
                //o cara entra
                t = max(dir2.front() + 10, t+10);
                mov = 1; //sentido da fila 2
                //cout << "linha 85: o " << dir2.front() << " entrou e o tempo agora eh " << t << "\n";  
                dir2.pop();
            }
        }
    }

    // sobrou gente na fila 1
    while (dir1.empty() == false) {
        if (mov == 0) {
            //já está no sentido
            
            if (dir1.front() < t) {
                //o primeiro cara da fila vai entrar com estrutura andando
                t = max(dir1.front() + 10, t);
                //cout << "linha 99: o " << dir1.front() << " entrou e o tempo agora eh " << t << "\n";  
                dir1.pop();
            }
            else {
                //a maquina vai parar no tempo t
                mov = -1;
            }
        }
        else if (mov == 1) {
            //ta no outro sentido, tem que esperar parar
            mov = -1; //parou
        }
        else {
            //tá parado
            //o cara entra
            t = max(dir1.front() + 10, t+10);
            mov = 0; //sentido da fila 1
            //cout << "linha 116: o " << dir1.front() << " entrou e o tempo agora eh " << t << "\n";  
            dir1.pop();
        }
    }

    // sobrou gente na fila 2
    while (dir2.empty() == false) {
        if (mov == 1) {
            //já está no sentido
            
            if (dir2.front() < t) {
                //o primeiro cara da fila vai entrar com estrutura andando
                t = max(dir2.front() + 10, t);
                //cout << "linha 129: o " << dir2.front() << " entrou e o tempo agora eh " << t << "\n"; 
                dir2.pop();
            }
            else {
                //a maquina vai parar no tempo t
                mov = -1;
            }
        }
        else if (mov == 0) {
            //ta no outro sentido, tem que esperar parar
            mov = -1; //parou
        }
        else {
            //tá parado
            //o cara entra
            t = max(dir2.front() + 10, t+10);
            mov = 1; //sentido da fila 2
            //cout << "linha 145: o " << dir2.front() << " entrou e o tempo agora eh " << t << "\n";  
            dir2.pop();
        }
    }

    cout << t << "\n";
    
    return 0;
}

/*
-- casos de teste --

input:
3
5 0
8 0
13 0
output:
23

input:
3
5 0
7 1
9 0
output:
29

input:
3
5 0
10 1
16 0
output:
35
*/