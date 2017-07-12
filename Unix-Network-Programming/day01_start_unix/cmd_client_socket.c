// #include	"unp.h"
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
// #include <netdb.h>
// #include <netinet/in.h>
// #include <sys/types.h>

#define MAXLINE 255

int
main(int argc, char **argv)
{
	int					sockfd, n;
	char				recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr = { 0 };

	if (argc != 2)
  {
    printf("usage: a.out <IPaddress>");
    return -1;
  }

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("socket error");
    return -1;
  }

	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(12306);	/* daytime server */
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
  {
    printf("inet_pton error for %s", argv[1]);
    return -1;
  }

	if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
  {
    printf("connect error");
  }

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0)
  {
		recvline[n] = 0;	/* null terminate */
    printf("%s", recvline);
	}
	if (n < 0)
  {
    printf("read error");
  }

	return 0;
}
