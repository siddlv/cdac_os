#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdlib.h>

int main() {
	int sfd, ssfd, csz, pid;
	long unsigned int count = 0;
	char buff[5];
	struct sockaddr_in sa, ca;
	struct sigaction act;

	if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket creation failed");
		return -1;
	}

	sa.sin_family = AF_INET;
	sa.sin_port = htons(9000);
	inet_aton("127.0.0.1", &sa.sin_addr);
	if (bind(sfd, (const struct sockaddr *)&sa, sizeof(sa)) < 0) {
		perror("address bind failed");
		return -1;
	}

	if (listen(sfd, 20) < 0) {
		perror("cannot listen");
		return -1;
	}
	printf("Server listening on 127.0.0.1:9000...\n");

	memset(buff, '\0', sizeof(buff));
	csz = sizeof(ca);
	act.sa_handler = SIG_IGN;
	if (sigaction(SIGCHLD, &act, NULL) < 0) {
		perror("couldn't handle signal");
	}
	while (1) {
		if ((ssfd = accept(sfd, (struct sockaddr *)&ca, &csz)) < 0) {
			perror("unable to accept connection");
			return -1;
		}
		count++;
		pid = fork();
		if (pid == 0) {
			close(sfd);
			recv(ssfd, buff, sizeof(buff), 0);
			printf("%lu message from child %d : %s\n", count, getpid(), buff);
			close(ssfd);
			exit(0);
		}
		else if (pid < 0) {
			perror("child creation failed");
			return -1;
		}
		else {
			close(ssfd);
		}
		printf("%lu\n", count);
	}

	close(sfd);
	return 0;
}
