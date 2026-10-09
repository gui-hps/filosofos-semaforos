#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // Biblioteca para usar o Threads
#include <unistd.h>
#include <locale.h>
#include <semaphore.h> // Biblioteca para Semáforos

#define NUM_FILOSOFOS 5
#define NUM_INTERACOES 50

// Cores do terminal
#define AZUL "\033[34m"
#define AMARELO "\033[33m"
#define VERDE "\033[32m"
#define VERMELHO "\033[31m"
#define ROXO "\033[35m"
#define RESET "\033[0m"

// Cada garfo possui um semáforo
// 1 = garfo disponível
sem_t garfos[NUM_FILOSOFOS];

// Controla quantos filósofos podem tentar pegar garfos
sem_t controle;

// Controla a ordem de atendimento dos filósofos
pthread_mutex_t fila_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t fila_cond = PTHREAD_COND_INITIALIZER;

int proximo_ticket = 0;
int ticket_atual = 0;

// Função que cada filósofo vai executar
void *filosofo(void *arg){
     // Descobre qual é o número do filósofo
    int id = *(int *)arg;

    // Cada filósofo precisa de dois garfos
    int garfo_esquerdo = id;
    int garfo_direito = (id + 1) % NUM_FILOSOFOS;
	
    // Cada filósofo vai repetir isso 50 vezes
    int i;
    for(i=1;i<=NUM_INTERACOES;i++){
        // Primeiro, o filósofo fica pensando
        printf(AZUL "  [PENSANDO]  Filósofo %d está pensando...\n" RESET, id);
        // Espera meio segundo
        usleep(500000);
        
        // Recebe uma senha para entrar na fila
// 		pthread_mutex_lock(&fila_mutex);

// 		int meu_ticket = proximo_ticket++;
	
// 		while(meu_ticket != ticket_atual){
//     	pthread_cond_wait(&fila_cond, &fila_mutex);
// 	}

// 		pthread_mutex_unlock(&fila_mutex);

        // Agora ele vai tentar pegar os garfos
        printf(AMARELO "  [TENTANDO]  Filósofo %d está tentando pegar os garfos...\n" RESET, id);

        // Só 4 filósofos podem tentar pegar garfos ao mesmo tempo
        // Isso ajuda a evitar que todos fiquem travados
    // 	sem_wait(&controle);

		sem_wait(&garfos[garfo_esquerdo]);
		printf(AMARELO "  [GARFO]     Filósofo %d pegou o ESQUERDO [%d]\n" RESET,id, garfo_esquerdo);
		
		usleep(100000);
		
		sem_wait(&garfos[garfo_direito]);
		printf(AMARELO "  [GARFO]     Filósofo %d pegou o DIREITO  [%d]\n" RESET,id, garfo_direito);

        // Conseguiu os dois garfos
        // Então outro filósofo pode tentar pegar os seus
    // 	sem_post(&controle);
        
        // Libera a vez para o próximo filósofo
// 		pthread_mutex_lock(&fila_mutex);

// 		ticket_atual++;

// 		pthread_cond_broadcast(&fila_cond);

// 		pthread_mutex_unlock(&fila_mutex);

        // Agora sim, o filósofo pode comer
        printf(VERDE "  [COMENDO]   Filósofo %d está comendo  (%d/%d)\n" RESET,id, i, NUM_INTERACOES);
		// Fica 0,5 segundo comendo
        usleep(500000);

        // Terminou de comer
        // Então devolve os dois garfos
        sem_post(&garfos[garfo_esquerdo]);
        sem_post(&garfos[garfo_direito]);

        // Mostra que terminou de comer
        printf(VERMELHO "  [FINALIZOU]  Filósofo %d terminou de comer.\n\n" RESET, id);
		// Espera um pouco antes de começar novamente
        usleep(200000);
    }

    // Depois das 50 vezes, o filósofo termina
    printf(ROXO "  [FIM]       Filósofo %d terminou todas as interações!\n" RESET, id);

    return NULL;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    // Cria espaço para as 5 threads
    // Cada thread vai representar um filósofo
    pthread_t threads[NUM_FILOSOFOS];

    // ele vai guarda o número de cada filósofo
    int ids[NUM_FILOSOFOS];

	printf(ROXO "\n");
	printf(ROXO "+----------------------------------------------+\n");
	printf(ROXO "¦          JANTAR DOS FILÓSOFOS               ¦\n");
	printf(ROXO "¦        SIMULAÇÃO COM SEMÁFOROS              ¦\n");
	printf(ROXO "+----------------------------------------------+\n");
	printf(RESET "\n");

    // Cria um semáforo para cada garfo
    // O valor 1 significa que o garfo começa disponível
    int i;
    for(i=0;i<NUM_FILOSOFOS;i++){
        sem_init(&garfos[i], 0, 1);
    }

    // Permite que no máximo 4 filósofos
    // tentem pegar garfos ao mesmo tempo
    sem_init(&controle, 0, NUM_FILOSOFOS - 1);

    // Cria uma thread para cada filósofo
    for(i=0;i<NUM_FILOSOFOS;i++){
    	// Define o número do filósofo
        ids[i] = i;
// Cria a thread e inicia a função do filósofo
        pthread_create(
            &threads[i],
            NULL,
            filosofo,
            &ids[i]
        );
    }

    // Espera todos os filósofos terminarem
    for(i=0;i<NUM_FILOSOFOS;i++){
        pthread_join(threads[i], NULL);
    }

   // Depois que todos terminaram,
    // destrói os semáforos dos garfos
    for(i=0;i<NUM_FILOSOFOS;i++){
        sem_destroy(&garfos[i]);
    }

    // Destrói o semáforo de controle
    sem_destroy(&controle);
    
    // Destrói os controles da fila
	pthread_mutex_destroy(&fila_mutex);
	pthread_cond_destroy(&fila_cond);

	printf("\n");
	printf(ROXO "+----------------------------------------------+\n");
	printf(ROXO "¦              SIMULAÇÃO FINALIZADA           ¦\n");
	printf(ROXO "¦           TODOS TERMINARAM!                 ¦\n");
	printf(ROXO "+----------------------------------------------+\n");
	printf(RESET);

    return 0;
}