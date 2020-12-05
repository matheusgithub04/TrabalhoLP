#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "cabec.h"
#define QTDALUNOS 2

int i, j, c, op, *resultado;
int main(){
    setlocale(LC_ALL, "");
    op = 0;

    while(op != 3){
        printf("1 - Criptografia.\n2 - Vestibular.\n3 - Sair.\n");
        scanf("%d", &op);
        switch(op){
            case 1:;
                char palavra[201], aux[201], asci[256];
                printf("Criptografia.\nDigite: ");
                fflush(stdin);
                gets(palavra);
                int tam = strlen(palavra), ctt = 0;
                //recebendo os elementos da tabela ascii
                for(i = 0; i < 256; i++){
                    asci[i] = i;
                }
                //primeira etapa
                for(j = 0; j < tam; j++){
                    for(i = 0; i < 256; i++){
                        if(isalpha(palavra[j])){
                            if(asci[i] == palavra[j]){
                                palavra[j] = asci[i+3];
                                break;
                            }
                        }
                    }
                }
                //segunda etapa
                for(i = tam-1; i >= 0; i--){
                    aux[ctt] = palavra[i];
                    ctt++;
                }
                for(i = 0; i < tam; i++){
                    palavra[i] = aux[i];
                }
                //terceira etapa
                for(i = tam/2; i <= tam; i++){
                    for(j = 0; j < 256; j++){
                        if(asci[j] == palavra[i]){
                            palavra[i] = asci[j-1];
                        }
                    }
                }
                printf("Resultado criptografado: ");
                for(i = 0; i < tam; i++){
                    printf("%c", palavra[i]);
                }
                printf("\n");
                break;
            case 2:;
                inicializar();
                char prova[2][56];
                char inscricao[6];
                int questao = 0;
                for(i = 0; i < QTDALUNOS; i++){
                    for(j = 0; j < 55; j++){
                        if(j==0){
                            printf("Informe os 5 números de inscrição:\n");
                            fflush(stdin);
                            gets(inscricao);
                            for(c=0; c<5; c++){
                                prova[i][c] = inscricao[c];
                            }
                            j = 4;
                        }else{
                            questao++;
                            printf("Questão %d:\n", questao);
                            printf("(a)\t(b)\t(c)\t(d)\t(e)\n");
                            fflush(stdin);
                            scanf("%c", &prova[i][j]);
                        }
                    }
                    questao = 0;
                }

                int *classific;
                classific = correcao(prova);

                for(i = 0; i < QTDALUNOS; i++){
                    printf("O aluno de inscrição ");
                    for(j=0; j<5;j++){
                        printf("%c", prova[i][j]);
                    }
                    printf(", acertou %d\n", classific[i]);
                }
                finalizar();
                break;
            case 3:;
                printf("Você saiu do programa.\n");
                break;
            default:
                printf("Opção não existe.\n");
        }
    }
    return 0;
}

int *correcao(char respostas[][56]){
    char gabarito[51] = {'a','b','c','d','e','a','b','c','d','e','a','b','c','d','e','a','b','c','d','e','a','b','c','d','e','a','b','c','d','e','a','b','c','d','e','a','b','c','d','e','a','b','c','d','e','a','b','c','d','e','\0'};
    int ctt = 0, k = 0;
    for(i = 0; i < QTDALUNOS; i++){
        for(j = 5; j < 55; j++){
            if(respostas[i][j] == gabarito[k]) {
                ctt++;
            }
            k++;
        }
        resultado[i] = ctt;
        ctt = 0;
        k = 0;
    }
    return (resultado);
}

void inicializar(){
    resultado = malloc(QTDALUNOS * sizeof(int));
    if(!resultado){
        printf("Erro de alocacao!");
        exit(-1);
    }
}

void finalizar(){
    free(resultado);
}

