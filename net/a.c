#include <net.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

int
asdf(const char *domain, int type, void *ip) {
	printf("a %s\n", domain);
	if (domain == NULL || ip == NULL)
		return -1;
	if (type != AF_INET && type != AF_INET6)
		return -1;
	return 0;
}
