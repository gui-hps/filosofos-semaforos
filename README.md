# 🍝 Jantar dos Filósofos

Implementação do problema clássico do **Jantar dos Filósofos**, utilizando **Threads POSIX (pthread)** e **Semáforos POSIX**, desenvolvido como trabalho prático da disciplina de Sistemas Operacionais.

## 👥 Integrantes

- Guilherme de Holanda Pereira
- Rafael Rocha de Lima
- Viviane Guadalupe Barreto da Silveira

---

## 📚 Sobre o projeto

O projeto tem como objetivo demonstrar conceitos fundamentais de sincronização de processos e threads:

- Seção crítica;
- Condição de corrida;
- Deadlock;
- Starvation;
- Concorrência;
- Exclusão mútua;
- Sincronização utilizando semáforos.

Para isso, foi implementado o problema clássico do **Jantar dos Filósofos**.

A implementação utiliza cinco threads, sendo que cada thread representa um filósofo.

Cada filósofo possui dois garfos necessários para realizar a ação de comer.

---

## 🧠 Problema do Jantar dos Filósofos

O problema consiste em cinco filósofos sentados ao redor de uma mesa.

Entre cada dois filósofos existe um garfo.

Cada filósofo alterna entre dois estados principais:

1. Pensando;
2. Comendo.

Para comer, um filósofo precisa possuir simultaneamente os dois garfos ao seu lado.

O problema surge quando vários filósofos tentam utilizar os recursos ao mesmo tempo.

Sem uma estratégia de sincronização adequada, pode ocorrer um **deadlock**, no qual todos os filósofos ficam esperando indefinidamente por um garfo.

Também pode ocorrer **starvation**, quando um filósofo espera por muito tempo para conseguir utilizar os recursos necessários.

---

## ⚙️ Funcionamento da implementação

O programa cria cinco threads, cada uma representando um filósofo, e cinco semáforos individuais para controlar o acesso aos garfos.

Além desses semáforos, é utilizado um semáforo de controle, inicializado com o valor `4`, que limita a quantidade de filósofos que podem tentar adquirir garfos simultaneamente.

O funcionamento de cada filósofo segue estas etapas:

1. Pensar durante um intervalo de tempo;
2. Solicitar uma vaga no semáforo de controle;
3. Adquirir o garfo esquerdo;
4. Adquirir o garfo direito;
5. Liberar a vaga do semáforo de controle após obter os dois garfos;
6. Comer durante um intervalo de tempo;
7. Liberar os dois garfos;
8. Repetir o ciclo até completar 50 interações.

---

## 🧵 Conceitos demonstrados

* **Concorrência:** os cinco filósofos executam suas atividades por meio de threads independentes.
* **Exclusão mútua:** cada garfo possui um semáforo que controla seu acesso, impedindo que dois filósofos o utilizem simultaneamente.
* **Sincronização:** os semáforos coordenam a aquisição e a liberação dos recursos compartilhados.
* **Deadlock:** o semáforo de controle evita o deadlock clássico em que todos os filósofos seguram um garfo e aguardam o segundo.
* **Starvation:** a implementação não garante formalmente que todos os filósofos tenham acesso aos recursos de maneira justa.
* **Simulação de tempo:** a função `usleep()` introduz pausas para representar os períodos de pensamento e alimentação.

---

## 🛠️ Tecnologias utilizadas

- Linguagem: **C**
- Threads: **POSIX Threads (pthread)**
- Sincronização: **Semáforos POSIX**
- Biblioteca de semáforos: **semaphore.h**
- Biblioteca de threads: **pthread.h**
- Biblioteca de tempo: **unistd.h**
- Ambiente de desenvolvimento e testes: [OnlineGDB](https://www.onlinegdb.com/)
- Compatibilidade: **ambientes com suporte a C, POSIX Threads (`pthread`) e Semáforos POSIX**.
- Compilador: **GCC**
