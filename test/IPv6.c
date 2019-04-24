#include <unistd.h>
#include <stdio.h>
#include "net.h"

int
tIPv6(const char *param) {
	printf("当前IPv6网络%s\n", isIPv6Supported() ? "可用" : "禁用");
	return 0;
}

