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

    struct Student *prev;
    struct Student *next;
};
typedef struct Student node;

// Função que aloca dinamicamente o novo nó e o retorna
node *Allocation()
{
    node *head = (node *)malloc(sizeof(node));
    if (!head)
    {
        printf("A alocação de memória falhou!");
    }
    head->prev = NULL;
    head->next = NULL;
    return head;
}

void Insert(node *head)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("A alocação de memória falhou!");
    }
    newNode->prev = NULL;
    newNode->next = NULL;
    printf("\nDigite o cpf do aluno a ser inserido\n");
    scanf("%lld", &newNode->cpf);
    node *aux = head->next;
    node *previus = head;
    while (aux != NULL)
    {
        if (aux->cpf == newNode->cpf)
        {
            printf("\n O cpf já foi cadastrado anteriormente!\n");
            return;
        }
        else if (aux->cpf > newNode->cpf)
        {
            aux->prev = newNode;
            newNode->prev = previus;
            newNode->next = aux;
            previus->next = newNode;
            break;
        }
        previus = aux;
        aux = aux->next;
    }
    printf("\nDigite o nome do aluno inserido\n");
    scanf("%s", newNode->name);
    printf("\nDigite a primeira nota do aluno inserido\n");
    scanf("%f", &newNode->n1);
    printf("\nDigite a segunda nota do aluno inserido:\n");
    scanf("%f", &newNode->n2);
    if (head->next == NULL)
    {
        head->next = newNode;
        newNode->prev = head;
    }
}
/*void Remove(node *head){
    printf("Remove...\n");
}

void Edit(node *head){
    printf("Editando...\n");
}
*/
void List(node *head)
{
    node *aux = head->next;
    if (head->next == NULL)
    {
        printf("\nA lista está vazia!\n");
    }
    else
    {
        
    }
}

// Função que exibe o menu
int Menu(int *op, node *head)
{
    printf("\nDigite a opção desejada:");
    printf("\n-----------------------------");
    printf("\n0 - PARA SAIR");
    printf("\n1 - PARA INSERIR");
    printf("\n2 - PARA REMOVER");
    printf("\n3 - PARA EDITAR");
    printf("\n4 - PARA LISTAR\n");
    scanf("%d", op);
    switch (*op)
    {
    case 0:
        printf("\nSaindo...\n");
        return *op;
        break;
    case 1:
        Insert(head);
        break;
    case 2:
        // Remove(head);
        break;
    case 3:
        // Edit(head);
        break;
    case 4:
        List(head);
        break;
    default:
        printf("\nOpção Ínvalida, por favor digite uma opção válida!\n");
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op = 0;
    node *head = Allocation();
    do
    {
        Menu(&op, head);
    } while (op != 0);
    return 0;
}