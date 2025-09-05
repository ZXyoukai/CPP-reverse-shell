#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <sys/socket.h>

#define BUFFER_SIZE 819200

int main(int argc, char *argv[], char *envp[])
{
    (void)argc;
    (void)argv;
    char **environ = envp;
    struct sockaddr_in saddr;
    int opt = 1;
    int pipe_fd[2];
    int son_pid;
    int _server_fd;
    int _port = 8080;
    std::stringstream ss;
    std::string line;
    std::vector<std::string> lines;
    std::map<int, std::string> request;

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(_port);
    
    _server_fd = socket(saddr.sin_family, SOCK_STREAM, 0);
    if (_server_fd < 0)
        return -1;
    std::cout << "v1" << std::endl;

    setsockopt(_server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (bind(_server_fd, (struct sockaddr*)&saddr, sizeof(saddr)) < 0) {
        return -1;
    }

    listen(_server_fd, 10);
    std::cout << "v2" << std::endl;

    int client_fd = accept(_server_fd, NULL, NULL);
    if (client_fd < 0)
        return -1;
    std::cout << "Client connected" << std::endl;
    while (true)
    {
        std::cout << "Waiting for command..." << std::endl;
        char buffer[BUFFER_SIZE];
        ssize_t bytesRead = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
        if (bytesRead <= 0) {
            break;
        }
        buffer[bytesRead] = '\0';

        pipe(pipe_fd);
        son_pid = fork();
        if (son_pid < 0)
            return -1;
        else if (son_pid > 0) 
        {
            close(pipe_fd[1]);
            char outbuf[BUFFER_SIZE];
            ssize_t n;
            while ((n = read(pipe_fd[0], outbuf, sizeof(outbuf))) > 0) {
                send(client_fd, outbuf, n, 0);
            }
            close(pipe_fd[0]);
            waitpid(son_pid, NULL, 0);
        }
        else 
        {
            close(pipe_fd[0]);
            dup2(pipe_fd[1], STDOUT_FILENO);
            dup2(pipe_fd[1], STDERR_FILENO);
            close(pipe_fd[1]);
            
            std::string command = std::string(buffer);
            memset(buffer, 0, sizeof(buffer));
            if (!command.empty() && command.back() == '\n') {
                command.pop_back();
            }
            char *bash = const_cast<char*>("/bin/bash");
            char *c = const_cast<char*>("-c");
            char *const cmd[] = {bash, c, const_cast<char*>(command.c_str()), NULL};
            execvpe(bash, cmd, environ);
            perror("execvpe");
            exit(1);
        }

    }
}