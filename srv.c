#include <stdio.h>
#include <winsock2.h>

//★socket()
//★bind()
//★listen()
//★accept()
//★read()
//★write()
//★close()

int main()
{
    printf("SERVER\n");
    WSADATA wsaData;
    struct sockaddr_in addr;
    struct sockaddr_in client;
    int len;
    int listener_d;
    int sock;
    //winsock2の初期化
    WSAStartup(MAKEWORD(2, 0), &wsaData);
    //socketの作成
    listener_d = socket(AF_INET, SOCK_STREAM, 0);
    //socketの設定
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.S_un.S_addr = INADDR_ANY;
    bind(listener_d, (struct sockaddr *)&addr, sizeof(addr));
    //TCP CLIENTからの接続要求を待っている状態にする。
    listen(listener_d, 5);
    puts("接続を待機しています...");
    //TCP CLIENTからの要求を受け付ける。
    len = sizeof(client);
    sock = accept(listener_d, (struct sockaddr *)&client, &len);
    if (sock == INVALID_SOCKET)
    {
        printf("socket failed\n");
        return 1;
    }
    else
    {
        puts("接続しました");
        char *msg = "Hello! Welcome my Program!!\n";
        //5文字送信
        send(sock, msg, strlen(msg), 0);
        puts("接続を終了します。");
    }
    //Error処理
    //TCPセッションの終了
    closesocket(sock);
    // winsock2の終了処理
    WSACleanup();

    return 0;
}