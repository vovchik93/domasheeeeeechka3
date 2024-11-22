#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 7777
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    
    // Создаем сокет
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return 1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Преобразуем IPv4 и IPv6 адреса из текстового формата в двоичный формат
    if (inet_pton(AF_INET, "localhost", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return 1;
    }
    
    // Подключаемся к серверу
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return 1;
    }
    
    // Ввод числа от пользователя
    int number;
    printf("Enter a number (0-99): ");
    scanf("%d", &number);
    
    // Отправляем число на сервер
    snprintf(buffer, sizeof(buffer), "%d", number);
    send(sock, buffer, strlen(buffer), 0);
    
    // Получаем ответ от сервера
    read(sock, buffer, BUFFER_SIZE);
    printf("Server response: %s\n", buffer);
    
    close(sock);
    return 0;
}