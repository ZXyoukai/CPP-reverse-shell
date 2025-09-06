# CPP Remote Shell

[![GitHub Issues](https://img.shields.io/github/issues/ZXyoukai/CPP-reverse-shell.svg)](https://github.com/ZXyoukai/CPP-reverse-shell/issues)

Bem-vindo ao **CPP Remote Shell**!  
Este projeto demonstra como implementar um sistema de execução remota de comandos em C++ utilizando sockets, composto por um cliente e um servidor (target).

⚠️ **Atenção:** Use este código apenas em ambientes controlados e para aprendizado. O uso indevido pode ser ilegal.

---

## 🎯 Sobre este Projeto - Uma Jornada de Aprendizado em Cybersecurity

Este é um **projeto fascinante** que representa um marco importante no aprendizado de conceitos avançados de **cybersegurança** e **programação de sistemas**! 🚀

### 🔥 Por que este projeto é especial?

Este projeto nasceu da aplicação prática de conceitos fundamentais aprendidos durante o desenvolvimento do **webserver na 42luanda**. Enquanto no webserver trabalhamos com comunicação HTTP, sockets TCP/IP e arquiteturas cliente-servidor, este projeto leva esses conceitos a um nível mais avançado, explorando o fascinante mundo da **cybersegurança**.

### 🛡️ O que é um Reverse Shell?

Um **reverse shell** é uma técnica poderosa em cybersegurança onde:

- **Shell tradicional:** O cliente conecta-se ao servidor para executar comandos
- **Reverse shell:** O servidor conecta-se DE VOLTA ao cliente, invertendo o fluxo normal

**Por que isso é importante?**
- Bypassa firewalls que bloqueiam conexões de entrada
- Permite acesso remoto mesmo quando o alvo está atrás de NAT
- É uma técnica fundamental em penetration testing e incident response
- Demonstra conceitos avançados de network programming

### 🎓 Conexão com os Conceitos da 42luanda

Este projeto aplica diretamente o que aprendemos no webserver:

| Conceito do Webserver | Aplicação no Reverse Shell |
|----------------------|----------------------------|
| **Sockets TCP/IP** | Comunicação entre client e target |
| **Arquitetura Cliente-Servidor** | Implementação invertida para bypass |
| **Gestão de processos** | Fork/exec para execução de comandos |
| **Manipulação de I/O** | Redirecionamento de stdin/stdout/stderr |
| **Programação de rede** | Gestão de conexões e buffers |

### 💡 Conceitos Técnicos Implementados

**1. Socket Programming Avançado:**
```cpp
// Criação de socket e bind (como no webserver)
_server_fd = socket(AF_INET, SOCK_STREAM, 0);
bind(_server_fd, (struct sockaddr*)&saddr, sizeof(saddr));
```

**2. Process Manipulation:**
```cpp
// Fork para executar comandos de forma isolada
son_pid = fork();
if (son_pid == 0) {
    execvpe(bash, cmd, environ); // Execução do comando
}
```

**3. I/O Redirection:**
```cpp
// Redirecionamento de stdout/stderr para o socket
dup2(pipe_fd[1], STDOUT_FILENO);
dup2(pipe_fd[1], STDERR_FILENO);
```

### 🎯 Para os Colegas que Ainda Não Chegaram Até Aqui

Se você ainda está nos primeiros projetos da 42luanda, não se preocupe! Este projeto será naturalmente compreensível quando você:

1. **Completar o webserver** - Você entenderá sockets, TCP/IP e client-server
2. **Dominar process management** - Fork, exec, pipes ficarão claros
3. **Aprender system calls** - A mágica dos system calls Linux
4. **Explorar security concepts** - O mundo da cybersegurança se abrirá

### 🔍 Por que Estudar Este Código?

- **Aprofunda conhecimentos de rede** adquiridos no webserver
- **Introduz conceitos de cybersecurity** de forma prática
- **Demonstra técnicas de system programming** avançadas
- **Prepara para carreiras em security/DevSecOps**
- **Mostra aplicação real** de conceitos teóricos

Este projeto é uma **ponte natural** entre o desenvolvimento web e a cybersegurança, mostrando como os fundamentos que aprendemos na 42luanda se aplicam em áreas mais especializadas! 🌟

---

## 🚀 Como funciona?

Este projeto implementa um sistema cliente-servidor para execução remota de comandos:  
**Arquitetura:**
- **Target (Servidor):** Escuta na porta 8080 e aguarda conexões
- **Client (Cliente):** Conecta-se ao target e envia comandos para execução

**Fluxo de execução:**
1. O target é executado e fica escutando na porta 8080
2. O client conecta-se ao target
3. O usuário digita comandos no client que são enviados ao target
4. O target executa os comandos usando `/bin/bash` e retorna a saída

---

## 🛠️ Como usar

### 1. Clone o repositório
```bash
git clone https://github.com/ZXyoukai/CPP-reverse-shell.git
cd CPP-reverse-shell
```

### 2. Compile o projeto
```bash
make
```
Isso criará dois executáveis: `client` e `target`

### 3. Execute o target (servidor)
```bash
./target
```
O target ficará escutando na porta 8080

### 4. Execute o client (em outro terminal)
```bash
./client
```
O client se conectará automaticamente ao target em `127.0.0.1:8080`

### 5. Digite comandos no client
Você pode digitar qualquer comando que será executado no target:
```
$ ls -la
$ pwd  
$ whoami
```
Digite `exit` ou `quit` para encerrar a conexão.

## 📋 Estrutura do Projeto

```
CPP-reverse-shell/
├── client.cpp    # Cliente que se conecta ao target
├── target.cpp    # Servidor que executa comandos
├── makefile      # Arquivo para compilação
└── README.md     # Este arquivo
```

---

## 🤝 Contribua!

Quer melhorar este projeto?  
- Faça um fork
- Crie uma branch: `git checkout -b minha-feature`
- Envie um PR!

---

## 🔍 Referências

- [Socket Programming in C++](https://www.geeksforgeeks.org/socket-programming-cc/)
- [Linux System Calls](https://man7.org/linux/man-pages/man2/socket.2.html)

---

> _Dúvidas ou sugestões? Abra uma [issue](https://github.com/ZXyoukai/CPP-reverse-shell/issues)!_