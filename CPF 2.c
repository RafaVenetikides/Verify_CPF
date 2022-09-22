#include <stdio.h>

int verificaDigito(int soma);

int main(){
    char *ptr;
    char cpf[15];
    int numcpf[11];
    int i, j, ver, *numptr, soma, ver2, soma2;
    
    ver = 10;
    j = 0;
    soma = 0;
    ver2 = 11;
    
    printf("digite seu cpf: ");
    scanf("%s", cpf);

    numptr = &numcpf[0];
    for (i = 0; i<14 ; i++){
        if (i != 3 && i != 7 && i != 11){
            *(numptr + j)= cpf[i] - '0';
            j++;
        }
    }

    i = 0;
    do{
        soma += *(numptr + i) * ver;
        ver--;
        i++;
    }while (ver>=2);

    if (verificaDigito(soma) != numcpf[9]){
        printf("CPF inválido!");
    }
    else{
        soma = 0;
        ver = 11;
        i = 0;
        do{
            soma += *(numptr + i) * ver;
            ver--;
            i++;
        }while (ver>=2);

        if (verificaDigito(soma) != numcpf[10]){
            printf("CPF inválido!");
        }
        else{
            printf("Cpf válido!");
        }
    }

    return 0;
}

int verificaDigito(int soma){
    if (soma % 11 < 2){
        return 0;
    }
    else{
        return 11 - (soma % 11);
    }
}