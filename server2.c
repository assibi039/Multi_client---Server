#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h> 
void *king( void *);
int main()
{
		int ss,c,*ns;
		struct sockaddr_in sa,cl;
		ss = socket(AF_INET, SOCK_STREAM, 0);	
		sa.sin_family = AF_INET;
		sa.sin_port = htons(4444);
		sa.sin_addr.s_addr = inet_addr("127.0.0.1");
		bind(ss, (struct sockaddr*) &sa, sizeof(sa));
		listen(ss,5);
		int cs;
		while( (cs = accept(ss, (struct sockaddr *)&cl, (socklen_t*)&c)) )
    {
      	 pthread_t tc;
        ns = malloc(1);
        *ns = cs;
		pthread_create( &tc,NULL,king,(void*) ns);
	}
}
void *king( void *ss)
{
		char buffer[1024]="hello";
		int read_size;
		int cs=*(int*)ss;
		while(1)
		{
			send(cs, buffer, sizeof(buffer),0);
			recv(cs, buffer, 1024, 0);
			printf("%s",buffer);
			scanf("%s",&buffer);
		}	
}



