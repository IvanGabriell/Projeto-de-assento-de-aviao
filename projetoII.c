#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{   
    int numero, sorteio = 0;
    float saldo, aposta = 0.75, premio = 2.5, fator_crescimento = 2.0;  // Aposta e fator de crescimento exponencial
    int jogadas = 0;
    int pity = 0;

    // Entrada do saldo inicial
    do {
        printf("\nDigite o quanto deseja apostar inicialmente (mínimo 5, máximo 800): ");
        scanf("%f", &saldo);
       
        if (saldo < 5 || saldo > 800) {
            printf("\nSaldo inválido! Por favor, insira um valor entre 5 e 800.");
        }
    } while (saldo < 5 || saldo > 800);

    srand(time(NULL));  // Inicializa o gerador de números aleatórios

    while (saldo > 0) { // Loop do jogo enquanto o saldo for positivo
        // Entrada do número escolhido pelo jogador
        do {
            printf("\nEscolha um número entre 0 e 9: ");
            scanf("%d", &numero);
            if (numero < 0 || numero > 9) {
                printf("\nNúmero inválido! Por favor, escolha um número entre 0 e 9.");
            }
        } while (numero < 0 || numero > 9);
        
        // Sorteia um número aleatório entre 0 e 9
        sorteio = rand() % 10;
        printf("\nSorteio = %d", sorteio);
        jogadas++;
        
        // Verifica se o jogador acertou
        if (numero == sorteio) {
            saldo += aposta * premio;  // Atualiza o saldo ao acertar
            printf("\nVocê acertou! Saldo atual: %.2f", saldo);
            break;  // Encerra o jogo ao acertar
        } else {
            saldo -= aposta;  // Atualiza o saldo ao errar
            printf("\nVocê errou! Saldo atual: %.2f", saldo);

            if (saldo <= 0) {
                printf("\nVocê ficou sem saldo. Fim de jogo!");
                break;  // Encerra o jogo se o saldo acabar
            }

            aposta *= fator_crescimento;  // Aumenta a aposta de forma exponencial
            printf("\nAposta atual após erro: %.2f", aposta);

            // Verifica se é a última rodada
            if (saldo <= aposta) {
                pity = 1;  // Indica que a última rodada deve ser aplicada
            }
        }

        // Se é a última rodada, aplica a chance 50/50
        if (pity) {
            int chance = rand() % 2;  // 0 ou 1 para 50/50
            if (chance == 0) {
                // O jogador perde
                saldo -= aposta;
                printf("\nVocê perdeu a última rodada! Saldo atual: %.2f", saldo);
                if (saldo <= 0) {
                    printf("\nVocê ficou sem saldo. Fim de jogo!");
                    break;  // Encerra o jogo se o saldo acabar
                }
            } else {
                // O jogador ganha
                saldo += aposta * premio;
                printf("\nVocê ganhou a última rodada! Saldo atual: %.2f", saldo);
                break;  // Encerra o jogo ao acertar na última rodada
            }
        }
    }

    // Exibe as informações finais
    printf("\nVocê jogou %d vezes", jogadas);

    return 0;
}