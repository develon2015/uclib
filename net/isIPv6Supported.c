#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int
isIPv6Supported() {
	int sfd = socket(AF_INET6, SOCK_STREAM, 0);
	if (sfd < 0) {
		perror("socket");
		return 0;
	}
	// 使用connect测试
	struct sockaddr_in6 localipv6 = { 0 };
	localipv6.sin6_family = AF_INET6;
	localipv6.sin6_port = htons(0);
	if (inet_pton(AF_INET6, "::1", (void *)&localipv6.sin6_addr) != 1) {
		perror("pton");
		return 0;
	}
	if (connect(sfd, (struct sockaddr *)&localipv6, sizeof localipv6) != 0) {
		printf("connect: %d %s\n", errno, strerror(errno));
		if (errno == ENETUNREACH)
			return 0;
	}
	return 1;
}

