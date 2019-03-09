#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <assert.h>

int
main(int argc, char *argv[]) {
	assert(argc == 3);
	char fn[1024] = { 0 };
	sprintf(fn, "t%s", argv[1]);
	void (*fp)(const char *) = dlsym(NULL, fn);
	if (fp == NULL) {
		printf("%s\n", dlerror());
		return 1;
	}
	fp(argv[2]);
	return 0;
}
