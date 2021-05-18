/*2. Projeto Buraco:

Objetivo: 

Criar em memória uma representação para cada uma das 52 cartas de um baralho
(x 2 baralhos) para serem utilizadas em um jogo de Buraco.

O programa deverá "distribuir" aleatoriamente as cartas (11 cartas para cada um dos 4 jogadores participantes). 
Encerra a proposta com a apresentação das "mãos" de cada jogador.

Notação para a identificação da carta:

N-99-B = Onde:

N  -> Naipe (1-Copas / 2-Paus / 3-Ouro / 4-Espada)
99 -> Número da carta (01-Ás / 13-Rei)
B  -> Baralho (1 ou 2)
Exemplo:

4-10-2  ->  10 de espada do baralho 2*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    int baralho[4][26];
    int naipes[4] = {26,26,26,26};
    int baralhoAtual, cartaAtual;
    bool cartaRep = false;
    
    srand(time(NULL));
    
    //zerando a matriz
    for(int i = 0; i < 4; i++) {
		for(int x = 0; x < 26; x++){
			baralho[i][x] = 0;	
		}
	}
    
    //distribuindo as cartas
    for(int i = 0; i < 4; i++) {
		for(int x = 0; x < 11; x++){
			
			do {
				cartaRep = false;
				baralhoAtual = rand() % (4+1-1)+1;
				
				if(naipes[baralhoAtual-1] == 0) {
					cartaRep = true;
				}else {
				
					cartaAtual = rand() % (26+1-1)+1;
					
					if(baralho[baralhoAtual-1][cartaAtual-1] != 0) {
						cartaRep = true;
					}else {
						baralho[baralhoAtual-1][cartaAtual-1] = i+1;
						naipes[baralhoAtual-1]--;
					}
				}

			}while(cartaRep);
			
		}
	}
	
	//mostrando as cartas
	for(int i = 0; i < 4; i++) {
		cout << "Jogador " << i+1 << endl;
		for(int y = 0; y < 4; y++){
			for(int x = 0; x < 26; x++){
				if(baralho[y][x] == i+1) {
					
					//cout << traduzCarta(y+1, x+1);
					if(x > 13) {
						if(x-12 >= 10){
							cout << y+1 << "-" << x-12 << "-2 | ";
						}else{
							cout << y+1 << "-" << "0" << x-12 << "-2 | ";
						}
					}else {
						if(x+1 >= 10){
							cout << y+1 << "-" << x+1 << "-1 | ";
						}else{
							cout << y+1 << "-" << "0" << x+1 << "-1 | ";
						}
					}
				}
			}
		}
		cout << endl;
		cout << endl;
	}
    	
    return 0;       
}