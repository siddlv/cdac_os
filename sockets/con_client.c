#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>

int main() {
	int sfd;
	char buff[] = "ping";
	struct sockaddr_in sa;

	if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket creation failed");
		return -1;
	}

	sa.sin_family = AF_INET;
	sa.sin_port = htons(9000);
	inet_aton("127.0.0.1", &sa.sin_addr);

	if (connect(sfd, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
		perror("unable to accept connection");
		return -1;
	}

	send(sfd, buff, sizeof(buff), 0);

	close(sfd);
	return 0;
}
