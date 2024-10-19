#include <stdio.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

typedef struct	minhas_cartas
{
	int 	populacao;
	float 	area;
	float 	pib;
	int 	pontos_turis;
	float 	pib_per_capita;
	float 	densi_pop;
	char 	estado;
	int 	cidade;
	float 	super_poder;

} Carta;

void print_scan(char *frase, char set, void *dado){
	printf("%s",frase);
	switch(set){
		case 'd':
			scanf("%d", (int*)dado);
			break ;
		case 'f':
			scanf("%f", (float *)dado);
			break ;
		case 'c':
			scanf("%c", (char *)dado);
			break ;
		default:
			printf ("erro no codigo");
	}
}

void info(Carta *carta){
	printf("Código: %c0%d\n", carta->estado, carta->cidade); 
	printf("População: %d\n", carta->populacao);
	printf("Area: %f\n", carta->area);
	printf("PIB: %f\n", carta->pib);
	printf("Pontos Turisticos: %d\n", carta->pontos_turis);
	printf("Densidade Populacional: %f\n", carta->densi_pop);
	printf("PIB per Capita: %f\n", carta->pib_per_capita);
	printf("Super Poder: %f\n", carta->super_poder);
}

Carta * lendo_dados(int nc){
	Carta *carta = malloc(sizeof(Carta) * 1);

	printf("\nVoce esta inserindo a carta de numero %d\n", nc);

	do{
		print_scan("\nInforme o Estado (A-H): ", 'c', &carta->estado);
	}while (!(carta->estado >= 'A' && carta->estado <= 'H'));
	
	do{
		print_scan("\nInforme a cidade (1-4): ",'d', &carta->cidade);
	}while (!(carta->cidade >= 1 && carta->cidade <= 4));
	
	print_scan("\nInforme a População em numeros: ",'d', &carta->populacao);
	
	print_scan("\nInforme a Área em numeros: ",'f', &carta->area);
	
	print_scan("\nInforme o PIB em numeros: ",'f', &carta->pib);

	print_scan("\nInforme o numero de Pontos turisticos: ",'d', &carta->pontos_turis);

	carta->densi_pop = (float)carta->populacao / carta->area;
	carta->pib_per_capita = carta->pib / (float)carta->populacao;

	carta->super_poder = carta->area + carta->densi_pop + carta->pib + carta->pib_per_capita + (float)carta->populacao + (float)carta->pontos_turis;
	return carta;
}

int start_menu(){
	int num = 0;
	printf("Olá, bem vindo ao super trunfo du kaioba\nInforme abaixo quantas cartas voce deseja inserir :D\nCada país será dividido em oito estados, identificados pelas letras de A a H. Cada estado terá quatro cidades, numeradas de 1 a 4. A combinação da letra do estado e o número da cidade define o código da carta (por exemplo, A01, A02, B01, B02).\n\tIai menó quantas cartas ? -> ");
	scanf("%d", &num);

	printf("Uhhhhhh %d cartas bora pro jogo cria\n", num);
	return num;
}

Carta * comparacao(Carta *carta1, Carta *carta2){
	printf("\n\n\t\tCarta %c0%d \t vs \t Carta %c0%d\n", carta1->estado, carta1->cidade, carta2->estado, carta2->cidade);

	printf("População:\t\t%d \t x \t%d \t-> Vencedor %d\n", carta1->populacao, carta2->populacao,  carta1->populacao > carta2->populacao ? carta1->populacao : carta2->populacao);
	printf("Area: \t\t%f \t x \t%f \t-> Vencedor %f\n", carta1->area, carta2->area,  carta1->area > carta2->area ? carta1->area : carta2->area);
	printf("PIB: \t\t%f \t x \t%f \t-> Vencedor %f\n", carta1->pib, carta2->pib,  carta1->pib > carta2->pib ? carta1->pib : carta2->pib);
	printf("Pontos Turisticos:\t%d \t x \t%d \t-> Vencedor %d\n", carta1->pontos_turis, carta2->pontos_turis,  carta1->pontos_turis > carta2->pontos_turis ? carta1->pontos_turis : carta2->pontos_turis);
	printf("Densidade Pop.:\t%f \t x \t%f \t-> Vencedor %f\n", carta1->densi_pop, carta2->densi_pop,  carta1->densi_pop < carta2->densi_pop ? carta1->densi_pop : carta2->densi_pop);
	printf("PIB per Capita:\t%f \t x \t%f \t->Vencedor %f\n", carta1->pib_per_capita, carta2->pib_per_capita,  carta1->pib_per_capita > carta2->pib_per_capita ? carta1->pib_per_capita : carta2->pib_per_capita);
	printf("Super Poder:\t%f \t x \t%f \t->Vencedor %f\n", carta1->super_poder, carta2->super_poder,  carta1->super_poder > carta2->super_poder ? carta1->super_poder : carta2->super_poder);

	return carta1->super_poder > carta2->super_poder ? carta1 : carta2;
}

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    int nc = start_menu();
    Carta **cartas = malloc(nc);

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    for(int i = 0; i < nc; i++){
	    cartas[i] = lendo_dados(i + 1);
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
	    info(cartas[i]);
    }

    // Nivel mestre :D

    Carta *winner = cartas[0];
    if(nc > 2){
    for(int i = 1; i < nc; i++){
	    winner = comparacao(cartas[i], winner);
    }
    }
    else if (nc > 1) 
	    winner = comparacao(winner, cartas[1]);
    printf("\n\nCarta Vencedora -> ");
    info(winner);
    return 0;
}
