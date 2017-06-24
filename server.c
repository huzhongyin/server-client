#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_addr.s_addr = 0;
    addr.sin_port = htons(8080);
    addr.sin_family = AF_INET;

    int ret = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret < 0)
    {
        perror("bind");
        return 0;
    }

    listen(fd, 10);

    while(1)
    {
        // this is new connect
        int conn = accept(fd, NULL, NULL);

        if(conn > 0)
        {
            printf("has new connect %d\n", conn);

            char buf[1024];
            recv(conn, buf, sizeof(buf), 0);

            printf("recv data is: %s\n", buf);

            send(conn, "hello ack", 10, 0);
        }
    }

    return 0;
}
