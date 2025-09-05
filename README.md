# CPP Remote Shell

[![GitHub Issues](https://img.shields.io/github/issues/ZXyoukai/CPP-reverse-shell.svg)](https://github.com/ZXyoukai/CPP-reverse-shell/issues)

Bem-vindo ao **CPP Remote Shell**!  
Este projeto demonstra como implementar um sistema de execução remota de comandos em C++ utilizando sockets, composto por um cliente e um servidor (target).

⚠️ **Atenção:** Use este código apenas em ambientes controlados e para aprendizado. O uso indevido pode ser ilegal.

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