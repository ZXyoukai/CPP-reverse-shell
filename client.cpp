


#include <iostream>
#include <string>
#include <memory>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

 int PORT = 8080;
#define BUFFER_SIZE 819200
int main() {
    int sock = 0;
    sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    // std::cout << "Enter IP address: ";
    std::string ip = "0.0.0.0";
    // std::cin >> ip;
    if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return -1;
    }
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        return -1;
    }
    
    std::cout << "Connected! Type commands to execute on the target machine." << std::endl;
    std::cout << "Type 'exit' or 'quit' to disconnect." << std::endl;
    // std::cin.ignore();
    
    while (true)
    {
        std::string request;
        std::cout << "$ ";
        std::getline(std::cin, request);
        
        if (request == "exit" || request == "quit") {
            break;
        }
        if (request.empty()) {
            continue;
        }
        request += "\n";
        
        send(sock, request.c_str(), request.size(), 0);
        
        memset(buffer, 0, sizeof(buffer));
        size_t valread = recv(sock, buffer, BUFFER_SIZE - 1, 0);
        if (valread > 0) {
            buffer[valread] = '\0';
            std::cout << buffer;
        }
    }
    close(sock);
    return 0;
}
