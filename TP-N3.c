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
    float average;

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

// Função que realiza o calculo da média
float Calc(float *n1, float *n2)
{
    return (*n1 + *n2) / 2;
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
        { // verifica se existe duplicatas
            printf("\n O cpf já foi cadastrado anteriormente!\n");
            free(newNode);
            return;
        }
        else if (aux->cpf > newNode->cpf)
        { // insere ordenado, do menor ao maior, verifica se o nó aux atual é maior que o novo nó, se for ele é alocado antes de aux
            aux->prev = newNode;
            newNode->prev = previus;
            newNode->next = aux;
            previus->next = newNode;
            break;
        }
        previus = aux;   // ponteiro previus para ter a referencia a aux anterior que é sempre att
        aux = aux->next; // ponteiro aux sendo att no loop tbm
    }
    printf("\nDigite o nome do aluno inserido\n");
    scanf("%s", newNode->name);
    printf("\nDigite a primeira nota do aluno inserido\n");
    scanf("%f", &newNode->n1);
    printf("\nDigite a segunda nota do aluno inserido:\n");
    scanf("%f", &newNode->n2);
    newNode->average = Calc(&newNode->n1, &newNode->n2);
    if (head->next == NULL)
    { // se a lista está vazia insere no inicio
        head->next = newNode;
        newNode->prev = head;
    }
    else
    { // se entrou nesse else, ele será maior que todos os outros nós, sendo inserido no final
        previus->next = newNode;
        newNode->prev = previus;
        return;
    }
}
void Remove(node *head)
{
    long long int cpf = 0;
    if (head->next == NULL)
    {
        printf("\nLista está vazia, impossivel remover!\n");
        return;
    }
    if (head->next != NULL)
    {
        printf("\nDigite o número do cpf do aluno que deseja remover:\n");
        scanf("%lld", &cpf);
        node *aux = head->next;
        node *previus = head;
        while (aux != NULL)
        {
            if (aux->cpf == cpf)
            {
                previus->next = aux->next;
                if (aux->next != NULL)
                {
                    previus->next->prev = previus;
                }
                free(aux);
                printf("\nRemovido com sucesso!\n");
                return;
            }
            previus = aux;
            aux = aux->next;
        }
        printf("\nO número do cpf não foi encontrado\n");
    }
}
void Edit(node *head)
{
    long long int cpf = 0;
    if (head->next == NULL)
    {
        printf("\nLista vazia, impossivel editar!\n");
        return;
    }
    printf("\nDigite o cpf do aluno o qual deseja editar!\n");
    scanf("%lld", &cpf);
    node *aux = head->next;
    while (aux != NULL)
    {
        if (aux->cpf == cpf)
        {
            printf("\nDigite o novo valor do campo cpf\n");
            scanf("%lld", &aux->cpf);
            printf("\nDigite o novo valor do campo nome\n");
            scanf("%s", aux->name);
            printf("\nDigite o novo valor do campo nota 1\n");
            scanf("%f", &aux->n1);
            printf("\nDigite o novo valor do campo nota 2\n");
            scanf("%f", &aux->n2);
            aux->average = Calc(&aux->n1, &aux->n2);
        }
        aux = aux->next;
    }
}

void List(node *head)
{
    if (head->next == NULL)
    {
        printf("\nA lista está vazia, impossivel listar!\n");
        return;
    }
    else
    {
        node *aux = head->next;
        while (aux != NULL)
        {
            printf("\n------------------");
            printf("\nCPF--------------%lld", aux->cpf);
            printf("\nNOME-------------%s", aux->name);
            printf("\nNOTA 1-----------%f", aux->n1);
            printf("\nNOTA 2-----------%f", aux->n2);
            printf("\nMEDIA------------%f", aux->average);
            printf("\n------------------");
            aux = aux->next;
        }
    }
}

// Função que exibe o menu
int Menu(int *op, node *head)
{
    printf("\n\nDigite a opção desejada:");
    printf("\n------------------");
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
        Remove(head);
        break;
    case 3:
        Edit(head);
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