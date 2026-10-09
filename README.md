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

## ▶️ Instruções para compilar e executar localmente

O projeto foi desenvolvido em **C** utilizando **POSIX Threads (`pthread`)** e **Semáforos POSIX**. Para executar o código localmente, é necessário utilizar um ambiente com suporte a essas tecnologias.

### 🪟 Windows — utilizando WSL

No Windows, recomenda-se utilizar o **WSL (Windows Subsystem for Linux)**.

#### 1. Instalar o WSL

Abra o **PowerShell como administrador** e execute:

```powershell
wsl --install
```

Após a instalação, reinicie o computador.

#### 2. Instalar o GCC

Abra o Ubuntu pelo menu Iniciar e execute:

```bash
sudo apt update
sudo apt install gcc
```

Verifique a instalação:

```bash
gcc --version
```

#### 3. Clonar o repositório

No terminal do Ubuntu/WSL:

```bash
git clone URL_DO_REPOSITORIO
```

Entre na pasta do projeto:

```bash
cd NOME_DO_REPOSITORIO
```

#### 4. Compilar o código

Caso o arquivo principal seja `jantar_filosofos.c`, execute:

```bash
gcc jantar_filosofos.c -o jantar_filosofos -pthread
```

O parâmetro `-pthread` é necessário para habilitar o suporte às **POSIX Threads**.

#### 5. Executar o programa

Após a compilação:

```bash
./jantar_filosofos
```

O programa será executado no terminal e apresentará as ações dos cinco filósofos durante as 50 interações.

---

### 🐧 Linux

Em distribuições Linux baseadas em Debian/Ubuntu, instale o GCC:

```bash
sudo apt update
sudo apt install gcc
```

Depois, clone o repositório:

```bash
git clone URL_DO_REPOSITORIO
```

Entre na pasta:

```bash
cd NOME_DO_REPOSITORIO
```

Compile:

```bash
gcc jantar_filosofos.c -o jantar_filosofos -pthread
```

Execute:

```bash
./jantar_filosofos
```

---

### 🌐 OnlineGDB

Também é possível executar o projeto utilizando o **OnlineGDB**.

1. Acesse o OnlineGDB.
2. Crie um novo projeto em **C**.
3. Cole o código do arquivo `jantar_filosofos.c`.
4. Clique em **Run**.
5. Verifique a execução no terminal.

> **Observação:** o programa utiliza recursos POSIX, como `pthread.h` e `semaphore.h`. Por isso, recomenda-se utilizar **Linux ou WSL** para garantir compatibilidade completa.

### ⚠️ Possíveis erros

Caso ocorra algum erro durante a compilação, verifique:

* Se o GCC está instalado;
* Se o arquivo possui extensão `.c`;
* Se as bibliotecas `pthread.h` e `semaphore.h` estão disponíveis;
* Se o comando de compilação contém `-pthread`;
* Se o ambiente possui suporte a **POSIX Threads** e **Semáforos POSIX**.

### 📌 Comando resumido

Para compilar e executar rapidamente:

```bash
gcc jantar_filosofos.c -o jantar_filosofos -pthread
./jantar_filosofos
```

