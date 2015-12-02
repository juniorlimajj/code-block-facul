#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Fila {
		int capacidade;
		float *dados;
		int primeiro;
		int ultimo;
		int nItens;
<<<<<<< HEAD

=======
>>>>>>> 7b6fd411819b1d30d2033dc7926e937e65696fa4
	};

void criarFila( struct Fila *f, int c )
	{

	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;

	}

void inserir(struct Fila *f, int v)
	{
		if(f->ultimo==f->capacidade -1)
			f->ultimo = -1;
			f->ultimo++;
			f->dados[f->ultimo] = v; // incrementa ultimo e insere
			f->nItens++; // mais um item inserido
	}


int remover( struct Fila *f ) { // pega o item do comeco da fila

	int temp=f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro
		if(f->primeiro==f->capacidade)
			f->primeiro= 0;
			f->nItens--; // um item retirado
			return temp;
	}


int estaVazia( struct Fila *f ) { // retorna verdadeiro se a fila estA! vazia
	return (f->nItens==0);
}


int estaCheia( struct Fila *f ) { // retorna verdadeiro se a fila estA! cheia
	return (f->nItens==f->capacidade);
}


void mostrarFila(struct Fila *f)
{
	int cont, i;

		for ( cont=0, i=f->primeiro; cont<f->nItens; cont++)
		{

				printf("%.2f\t",f->dados[i++]);
				if (i== f->capacidade)
				i=0;
		}
		printf("\n\n");
}



int main(int argc, char *argv[]) {

	int opcao, capa;
	float valor;
	struct Fila umaFila;

		// cria a fila
		printf("\nCapacidade da fila? ");
		scanf("%d",&capa);
		criarFila(&umaFila, capa);


		// apresenta menu
		while( 1 )
		{
			printf("\n 1 - Inserir elemento\n 2 - Remover elemento\n 3 - Mostrar Fila\n 0 - Sair\n\n Opcao? ");
			scanf("%d", &opcao);

				switch(opcao){

					case 0: exit(0);

					case 1: // insere elemento
							if (estaCheia(&umaFila))
							{
									printf("\nFila Cheia!!!\n\n");
							}

							else
							{
									printf("\nValor do elemento a ser inserido? ");
									scanf("%f", &valor);
									inserir(&umaFila,valor);
							}
							break;

					case 2: // remove elemento
							if (estaVazia(&umaFila))
							{
									printf("\nFila vazia!!!\n\n");
							}
							else
							{
									valor = remover(&umaFila);
									printf("\n%1f removido com sucesso\n\n", valor) ;
							}
							break;

					case 3: // mostrar fila
							if (estaVazia(&umaFila))
							{
									printf("\nFila vazia!!!\n\n");
							}
							else
							{
									printf("\nConteudo da fila => ");
									mostrarFila(&umaFila);
							}
							break;


					default:
					printf("\nOpcao Invalida\n\n");

				}
		}


	return 0;
}
