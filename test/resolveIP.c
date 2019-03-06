#include <net.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void
tresolveIP() {
	const char *domain = "javac.ga";
	printf("测试 %s 函数...\n", __func__);
	struct in6_addr addr;
	char buf[1024];
	resolveIP(domain, AF_INET, &addr);
	printf("%s -> %s\n", domain, inet_ntop(AF_INET, &addr, buf, sizeof addr));
	resolveIP(domain, AF_INET6, &addr);
	printf("%s -> %s\n", domain, inet_ntop(AF_INET6, &addr, buf, sizeof buf));
}
