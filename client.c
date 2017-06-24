
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_addr.s_addr = inet_addr("55.0.0.104");
    addr.sin_port = htons(8080);
    addr.sin_family = AF_INET;

    int ret = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret < 0)
    {
        perror("connect");
        return 0;
    }

    send(fd, "hello", 6, 0);

    char buf[1024];
    recv(fd, buf, sizeof(buf), 0);

    close(fd);


    return 0;
}
