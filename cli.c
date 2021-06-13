#include <stdio.h>
#include <winsock2.h>
//gcc cli.c -o cli -lws2_32 -finput-charset=UTF-8 -fexec-charset=CP932

//★socket()
//★connect()
//★read()/write()
//★close()

int main()
{
    printf("CLIENT\n");
    WSADATA wsaData;
    struct sockaddr_in si;
    int server_d;
    char buf[32];
    //winsock2の初期化
    WSAStartup(MAKEWORD(2, 0), &wsaData);
    //socketの作成
    server_d = socket(AF_INET, SOCK_STREAM, 0);
    //接続先指定用構造体の準備
    si.sin_family = AF_INET;
    si.sin_port = htons(8080);
    si.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    //Serverに接続
    connect(server_d, (struct sockaddr *)&si, sizeof(si));
    //Serverへ送信
    // char snum[200];
    // puts("送信データを入れてください...");
    // fgets(snum, sizeof(snum), stdin);
    // send(server_d, snum, strlen(snum), 0);
    //Serverからデータを受信
    // recv(server_d, snum, 200, 0);
    memset(buf, 0, sizeof(buf));
    int n = recv(server_d, buf, sizeof(buf), 0);
    printf("文字数　　：%s\n", buf);
    //winsock2の終了処理
    WSACleanup();
    return 0;
}