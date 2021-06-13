#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int main()
{
    printf("■CLIENT\n");
    /* IP アドレス、ポート番号、ソケット */
    char ip[80];
    unsigned short port = 8080;
    int dstSocket;
    /* sockaddr_in 構造体 */
    struct sockaddr_in dstAddr;
    /* 各種パラメータ */
    int status;
    int numsnt;
    char *toSendText = "Hello World!";
    /* Windows 独自の設定 */
    WSADATA data;
    WSAStartup(MAKEWORD(2, 0), &data);
    /* 相手先アドレスの入力 */
    printf("Connect to ? : (name or IP address) ");
    scanf("%s", ip);
    /* sockaddr_in 構造体のセット */
    memset(&dstAddr, 0, sizeof(dstAddr));
    dstAddr.sin_port = htons(port);
    dstAddr.sin_family = AF_INET;
    dstAddr.sin_addr.s_addr = inet_addr(ip);
    /* ソケット生成 */
    dstSocket = socket(AF_INET, SOCK_STREAM, 0);
    /* 接続 */
    printf("Trying to connect to %s: \n", ip);
    connect(dstSocket, (struct sockaddr *)&dstAddr, sizeof(dstAddr));
    /* パケット送出 */
    for (int i = 0; i < 5; i++)
    {
        printf("sending...\n");
        send(dstSocket, toSendText, strlen(toSendText) + 1, 0);
        Sleep(1000);
    }
    /* Windows 独自の設定 */
    closesocket(dstSocket);
    WSACleanup();
}