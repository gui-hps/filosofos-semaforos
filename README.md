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

## 🛠️ Tecnologias utilizadas

- Linguagem: **C**
- Threads: **POSIX Threads (pthread)**
- Sincronização: **Semáforos POSIX**
- Biblioteca de semáforos: 
- Biblioteca de threads: 
- Biblioteca de tempo: 
- Sistema operacional recomendado: 

