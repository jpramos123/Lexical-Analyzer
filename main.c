/*
João Paulo de Oliveira Ramos
RA: 22215022-9
Projeto 3 - Analisador Léxico
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void e0();
void e1();
void e2();
void e3();
void e4();
void e5();
void e6();
void lambda1();
void lambda2();
void lambda3();
void lambda4();
void lambda5();
void lambda6();
void lambda7();
void lambda8();
void lambda9();
void lambda10();
void concat(char [], char);
void copy(char[], char[]);
bool iguais(char[], char[]);

void aceita();
void rejeita();

char tabelaPalavra[9][6] = 
{
    "IF", "ELSE", "GOTO",
    "END", "THEN", "READ",
    "PRINT", "LET", "OF"
};

int i = 0; // Controla o indice do vetor de entrada
int j = 0; // Controla o indice do vetor tempS 
int k = -1; // Controla o indice da linha da matriz 
char vec[60];
int tempN;
char tempC;
char tempS[11];
char mat[50][11];

int main(){

printf("Digite o texto: \n");

gets(vec);

e0();

}
 
void e0(){
    
     if(vec[i] == '\0'){
        printf("\n");
        printf("\nTabela de variaveis\n\n");
        for(int printa = 0; printa <= k; printa++){
            printf("%d...%s\n", printa, mat[printa]);
        }
        printf("\nTabela de palavras\n\n");
        for(int printa = 0; printa < 9; printa++){
            printf("%d...%s\n", printa, tabelaPalavra[printa]);
        }
        return;
    }
    else
        if(vec[i] >= 'A' && vec[i] <= 'Z' || vec[i] >= 'a' && vec[i] <= 'z'){
            lambda1();
            i++;
            e1();
        }
        else
            if(vec[i] >= '0' && vec[i] <= '9'){
                lambda4();
                i++;
                e2();
            }else
                if(vec[i] == ' '){
                    i++;
                    e0();
                }
            else{
                if(vec[i] == ':'){
                    i++;
                    e3();
                }
                else{
                    if(vec[i] == '%'){
                        i++;
                        e5();
                    }
                    else{
                        lambda9();
                        i++;
                        e6();
                    }
                }
            }
}

void e1(){

        if(vec[i] >= 'A' && vec[i] <= 'Z' || vec[i] >= 'a' && vec[i] <= 'z' || vec[i] >= '0' && vec[i] <= '9'){
            lambda2();
            i++;
            e1();
            
        }
        else{
            lambda3();
            e0();
        }
}

void e2(){
    
    if(vec[i] >= '0' && vec[i] <= '9'){
        lambda5();
        i++;
        e2();
    }
    else{
        lambda6();
        e0();
    }
}

void e3(){
    if(vec[i] == '='){
        i++;
        e4();
    }
    else{
        lambda8();
        e0();
    }
}

void e4(){

        lambda7();
        e0();
}

void e5(){
    if(vec[i] == '\0'){
        e0();
    }
    else{
        i++;
        e5();
    }
}

void e6(){
    lambda10();
    e0();
}

void lambda1(){

    tempS[j] = vec[i];
    j++;
    tempS[j] = '\0';
}

void lambda2(){

    tempS[j] = vec[i];
    j++;
    tempS[j] = '\0';
}

void lambda3(){

    j = 0;
    concat(tempS, '\0');
    
    int a;
    int b;
    for(int i = 0; i <= 9; i++){
        if(iguais(tempS, tabelaPalavra[i])){
            printf("P(%d) ", i);
            tempS[j] = '\0';
            return;
        }
    }
    for(a = 0; a <= k; a++){
        if(iguais(tempS, mat[a])){
            printf("V(%d) ", a);
            tempS[j] = '\0';
            return;
        }
    }
    
    k++;
    copy(mat[k], tempS);
    tempS[0] = '\0';
    printf("V(%d) ", k);

}

void lambda4(){

    tempN = vec[i] - '0';
}

void lambda5(){

    tempN = tempN*10 + (vec[i] - '0');
}

void lambda6(){

    printf("N(%d) ", tempN);

}

void lambda7(){

    printf(":=");
}
  
void lambda8(){
    printf(":");
}

void lambda9(){
    tempC = vec[i];
}
void lambda10(){
    printf("%c", tempC);
}

bool iguais(char a[], char b[]){
	int c;
	for(c = 0; a[c] != 0; c++){
		if(a[c] != b[c])
			return false;
	}
	if(a[c] != b[c])
		return false;
	else
		return true;	
}

void concat(char a[], char b){
	int i, j;
	for(i = 0; a[i] != '\0'; i++);

	a[i] = b;

	a[i+1] = '\0';
}

void copy(char destino[], char origem[]){
	int i = 0;
	while(origem[i] != 0){
		destino[i] = origem[i];
		i++;
	}
	destino[i] = '\0';
}