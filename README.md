# CPP Reverse Shell

[![MIT License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![GitHub Issues](https://img.shields.io/github/issues/ZXyoukai/CPP-reverse-shell.svg)](https://github.com/ZXyoukai/CPP-reverse-shell/issues)

Bem-vindo ao **CPP Reverse Shell**!  
Este projeto demonstra como implementar uma reverse shell em C++ para fins educacionais e de pesquisa.

⚠️ **Atenção:** Use este código apenas em ambientes controlados e para aprendizado. O uso indevido pode ser ilegal.

---

## 🚀 Como funciona?

Este projeto implementa uma **bind shell** em C++, onde o alvo executa um servidor que aguarda conexões.  
**Exemplo de fluxo:**
1. O alvo executa o binário `target` (que cria um servidor na porta 8080)
2. O atacante executa o binário `client` para conectar-se ao alvo
3. O atacante recebe acesso remoto ao terminal do alvo através do cliente

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
> Isso gerará os executáveis `client` e `target`  
> Use `make clean` para remover os arquivos compilados

### 3. Execute o servidor no alvo (máquina que será controlada)
```bash
./target
```
> O servidor irá aguardar conexões na porta 8080

### 4. Conecte-se do cliente (máquina do atacante)
```bash
./client
```
> Configure o IP do alvo no código (`client.cpp` linha 27) antes de compilar
> Atualmente está configurado para "0.0.0.0" - altere para o IP do alvo

---

## 🏗️ Arquitetura

O projeto consiste em dois componentes principais:

- **`target.cpp`**: Servidor que roda na máquina alvo
  - Cria um socket servidor na porta 8080
  - Aguarda conexões de clientes
  - Executa comandos recebidos via `/bin/bash -c`
  - Retorna a saída dos comandos para o cliente

- **`client.cpp`**: Cliente que se conecta ao alvo
  - Conecta-se ao servidor target na porta 8080
  - Permite enviar comandos interativos
  - Exibe as respostas dos comandos executados
  - Digite 'exit' ou 'quit' para desconectar

---

## 🤝 Contribua!

Quer melhorar este projeto?  
- Faça um fork
- Crie uma branch: `git checkout -b minha-feature`
- Envie um PR!

---

## 🔍 Referências

- [Reverse Shell Cheatsheet](https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Methodology%20and%20Resources/Reverse%20Shell%20Cheatsheet.md)
- [Documentação C++ Sockets](https://www.cplusplus.com/reference/cstdio/)

---

## 📜 Licença

Distribuído sob a licença MIT. Veja o arquivo `LICENSE` para mais informações.

---

> _Dúvidas ou sugestões? Abra uma [issue](https://github.com/ZXyoukai/CPP-reverse-shell/issues)!_