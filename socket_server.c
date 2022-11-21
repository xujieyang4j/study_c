#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    // 创建套接字
    int serv_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    // 将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    // 每个字节都用0填充
    memset(&serv_addr, 0, sizeof(serv_addr));
    // 使用IPv4地址
    serv_addr.sin_family = AF_INET;
    // 具体的IP地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // 端口
    serv_addr.sin_port = htons(8080);
    bind(serv_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // 进入监听状态，等待用户发起请求
    listen(serv_socket, 20);

    // 接受客户端请求
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    int client_socket = accept(serv_socket, (struct sockaddr *)&client_addr, &client_addr_size);

    // 向客户端发送数据
    char str[] = "xujieyang";
    // write(client_socket, str, sizeof(str));
    send(client_socket, str, sizeof(str), 0);

    // 关闭套接字
    close(client_socket);
    close(serv_socket);

    return 0;
}
