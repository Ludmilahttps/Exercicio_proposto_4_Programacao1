/**
 * @author Ludmila Silveira (ludmila.ss@grad.ufsc.br)
 * @brief Rotinas para localizar, e calcular o valor total do estoque;
 * Exercício proposto 4 de Linguagem de Programação 1;
 * Engenharia de Computação - UFSC
 *
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIM 			4
#define TRUE			1
#define FALSE 		0

typedef char string[50];
typedef unsigned char boolean;

// Dados de um produto para venda
typedef struct dados_no {
	string descricao;
	int quantidade;
	float valor;
	struct dados_no *prox;
} dados_no_t;

int menu();
dados_no_t *cadastrar_item();
void mostra_todos_os_itens_em_estoque(dados_no_t *lista);
void apaga_todos_os_itens_do_estoque(dados_no_t **lista);
boolean lista_esta_vazia(dados_no_t *lista);
void insere_item_pelo_fim(dados_no_t **lista, dados_no_t *item);
void remove_enter(string s);

int main()
{
  int opcao;
  // Lista inicia vazia
  dados_no_t *lista = NULL, *novo;
	
	do {
		opcao = menu();

		switch (opcao) {

			case 1: novo = cadastrar_item();
							insere_item_pelo_fim(&lista, novo);		
							break;
			
			case 2: mostra_todos_os_itens_em_estoque(lista);
							break;
							
	 		case 3: apaga_todos_os_itens_do_estoque(&lista);
	 						break;
	 	}
		
	} while (opcao != FIM);
		
	return 0;
}

int menu()
{
  int opcao;
	
	printf("1.Inserir novo item no estoque\n");
	printf("2.Mostrar todos os itens do estoque\n");
	printf("3.Apagar todos os itens do estoque\n");
	printf("4.Sair do programa\n");
	printf("?: ");
	scanf("%d", &opcao);
	
	return opcao;	
}

dados_no_t *cadastrar_item()
{
  dados_no_t *no = (dados_no_t*)malloc(sizeof(dados_no_t));
  
  getchar();
  printf("Descricao do item.....: ");
  fgets(no->descricao, 50, stdin);
  remove_enter(no->descricao);
  printf("Quantidade do item....: ");
  scanf("%d", &no->quantidade);
  printf("Valor unitario........: ");
  scanf("%f", &no->valor);
  
  no->prox = NULL;
  
  return no;
}

void mostra_todos_os_itens_em_estoque(dados_no_t *lista)
{
	dados_no_t *aux = lista;
	
	while (aux != NULL) {
	  printf("Descricao do item.....: %s\n", aux->descricao);
	  printf("Quantidade do item....: %d\n", aux->quantidade);
	  printf("Valor unitario........: %.2f\n", aux->valor);
	  printf("***********************************************\n\n");
	  
		aux = aux->prox;
	}
	
}

void apaga_todos_os_itens_do_estoque(dados_no_t **lista)
{
	dados_no_t *aux;
	
	while (*lista != NULL) {
		aux = *lista;
		*lista = (*lista)->prox;
		printf("Apagando o item %s\n", aux->descricao);		
		free(aux);
	}	
}

boolean lista_esta_vazia(dados_no_t *lista)
{
	if (lista == NULL) return TRUE;
	return FALSE;
}

void insere_item_pelo_fim(dados_no_t **lista, dados_no_t *item)
{
	dados_no_t *aux;
	if (lista_esta_vazia(*lista) == TRUE) {
		*lista = item;
	}
	else {
		aux = *lista;
		while (aux->prox != NULL) aux = aux->prox;
		aux->prox = item;
	}
}

void remove_enter(string s)
{
	int tamanho = strlen(s);
	s[tamanho-1] = '\0';
}