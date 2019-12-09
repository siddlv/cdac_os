#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int main() {
	int sfd, pid;
	long unsigned int i, n;
	char buff[] = "ping";
	struct sockaddr_in sa;
	struct sigaction act;

	sa.sin_family = AF_INET;
	sa.sin_port = htons(9000);
	inet_aton("127.0.0.1", &sa.sin_addr);

	printf("Enter no of clients:");
	scanf("%lu", &n);
	act.sa_handler = SIG_IGN;
	if (sigaction(SIGCHLD, &act, NULL) < 0) {
		perror("sigaction failed");
		return -1;
	}

	for (i = 0 ; i < n; i++) {
		pid = fork();
		if (pid == 0) {
			if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
				perror("socket creation failed");
				return -1;
			}

			if (connect(sfd, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
				perror("unable to accept connection");
				return -1;
			}

			send(sfd, buff, sizeof(buff), 0);

			close(sfd);
			exit(0);
		}
		else if (pid < 0) {
			perror("fork failed");
			return -1;
		}
	}
	return 0;
}
