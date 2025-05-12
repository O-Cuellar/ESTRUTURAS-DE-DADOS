/* IMPLEMENTAR UMA LISTA DUPLAMENTE ENCADEADA PARA GERENCIAR UM SISTEMA DE NOTAS DE ALUNOS
QUE PERMITA, INSERÇÃO, REMOÇÃO, EDIÇÃO E LISTAGEM DE FORMA DINÂMICA
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Student
{
    long long int cpf;
    char name[50];
    float n1;
    float n2;
    float averege;

    struct Student* prev;
    struct Student* next;
};
typedef struct Student node;

//Função que aloca dinamicamente o novo nó e o retorna
node* Allocation(){
    node *head = (node*)malloc(sizeof(node));
    if(!head){
        printf("A alocação de memória falhou!");
    }
    head -> prev = NULL;
    head -> next = NULL;
    return head;
}

//Função que exibe o menu
int Menu(int *op){
    printf("\nDigite a opção desejada:\n");
    scanf("%d", op);
    switch (*op)
    {
    case 0:
        printf("\nSaindo...\n");
        return *op;
        break;
    case 1:
        printf("INSERINDO...");
        break;
    case 2:
        printf("REMOVENDO...");
        break;    
    default:
        break;
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int op = 0;
    Allocation();
    do
    {
        Menu(&op);
    } while (op != 0);
    
    return 0;
}