#include <stdio.h>
#include <ctype.h>
#include <string.h> 

#define MAXIMO_FILAS 9
#define MAXIMO_ASSENTOS 6

int main() {
    char poltrona[MAXIMO_FILAS][MAXIMO_ASSENTOS]; 

    for (int i = 0; i < MAXIMO_FILAS; i++) {
        for (int j = 0; j < MAXIMO_ASSENTOS; j++) {
            poltrona[i][j] = ' ';
        }
    }

    char resposta;
    
    do {
        int num_pessoas;
        printf("Quantas pessoas você deseja reservar? (1, 2, 3 ou 4): ");
        scanf("%d", &num_pessoas);

        // Verifica se o número de pessoas está dentro do limite
        if (num_pessoas < 1 || num_pessoas > 4) {
            printf("Número de pessoas inválido. Tente novamente.\n");
            continue; // Volta ao início do loop
        }

        // Loop para cada pessoa do pacote
        for (int i = 0; i < num_pessoas; i++) {
            int fila;
            char assento;
            int assentoIndex;
            char cpf[12]; // 11 dígitos + '\0'

            // Exibir poltronas disponíveis
            printf("\nPoltronas disponíveis:\n");
            printf("\t A   B\t C   D\t E   F\n");
            for (int j = 0; j < MAXIMO_FILAS; j++) {
                printf("Fila %d:", j + 1);
                for (int k = 0; k < MAXIMO_ASSENTOS; k++) {
                    printf(" [%c]", poltrona[j][k]);
                }
                printf("\n");
            }

            while (1) {
                // Usuário escolhe a fila
                printf("\nEscolha sua fila (1-9): ");
                scanf("%d", &fila);
                fila--; // Converte para índice (0-8)

                // Usuário escolhe o assento (A-F)
                printf("Escolha o assento (A-F): ");
                scanf(" %c", &assento);
                assento = tolower(assento); // Converte para minúscula

                // Verifica se a coluna é A ou F (executivo)
                if (assento == 'a' || assento == 'f') {
                    char executiva;
                    printf("Essa coluna é permitida apenas para passageiros executivos. Você é um passageiro executivo? (S/N): ");
                    scanf(" %c", &executiva);
                    executiva = tolower(executiva);

                    if (executiva == 's') {
                        printf("Por favor, insira seu CPF (11 dígitos): ");
                        scanf("%s", cpf);

                        // Verificação simples do CPF
                        if (strlen(cpf) != 11) {
                            printf("CPF inválido! Deve ter 11 dígitos.\n");
                            continue; // Retorna ao início do loop se o CPF for inválido
                        }
                    } else {
                        printf("Apenas passageiros executivos podem ocupar esta coluna.\n");
                        continue; // Retorna ao início do loop se não for executivo
                    }
                }

                // Usar switch para definir o índice do assento
                switch (assento) {
                    case 'a':
                        assentoIndex = 0;
                        break;
                    case 'b':
                        assentoIndex = 1;
                        break;
                    case 'c':
                        assentoIndex = 2;
                        break;
                    case 'd':
                        assentoIndex = 3;
                        break;
                    case 'e':
                        assentoIndex = 4;
                        break;
                    case 'f':
                        assentoIndex = 5;
                        break;
                    default:
                        printf("Assento inválido. Escolha de A a F.\n");
                        continue; // Volta ao início do loop se a escolha for inválida
                }

                // Verifica se o assento já está ocupado
                if (poltrona[fila][assentoIndex] == 'X') {
                    printf("Esse assento já está reservado! Tente novamente.\n");
                } else {
                    // Marcar o assento escolhido com 'X'
                    poltrona[fila][assentoIndex] = 'X';
                    break; // Sai do loop se a reserva for bem-sucedida
                }
            }
        }

        // Pergunta se o usuário quer reservar mais passagens
        printf("\nDeseja reservar mais passagens? (S/N): ");
        scanf(" %c", &resposta);
        resposta = tolower(resposta); // Converte para minúscula
    } while (resposta == 's'); // Continua enquanto a resposta for 's' (sim)

    // Exibir poltronas atualizadas
    printf("\nPoltronas Atualizadas:\n");
    printf("\t A   B\t C   D\t E   F\n");
    for (int i = 0; i < MAXIMO_FILAS; i++) {
        printf("Fila %d:", i + 1);
        for (int j = 0; j < MAXIMO_ASSENTOS; j++) {
            printf(" [%c]", poltrona[i][j]);
        }
        printf("\n");
    }

    return 0;
}
