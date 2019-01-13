#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
	int cs;
	struct sockaddr_in sa;
	char buffer[1024];
	cs = socket(AF_INET, SOCK_STREAM, 0);	
	sa.sin_family = AF_INET;
	sa.sin_port = htons(4444);
	sa.sin_addr.s_addr = inet_addr("127.0.0.1");
	int status=connect(cs, (struct sockaddr*)&sa, sizeof(sa));
	if(status == -1)
	printf("error");
	else
	{
		while(1)
		{
		recv(cs, buffer, 1024, 0);
		printf("%s",buffer);
		scanf("%s",&buffer);
		send(cs, buffer, sizeof(buffer),0);
		}
	}
}