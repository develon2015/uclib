#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

int
main(int argc, char *argv[]) {
	char *fn = NULL;
	char buf[10240] = { 0 };
	if (argc == 1) {
		setbuf(stdout, NULL);
		printf("要测试的函数名: ");
		read(STDIN_FILENO, buf, sizeof buf);
		buf[strlen(buf) - 1] = '\0'; // 删除换行
		fn = buf;
	} else
		fn = argv[1];
	char fn_copy[1024];
	strcpy(fn_copy, fn);
	sprintf(fn, "t%s", fn_copy);
	void (*fp)() = dlsym(NULL, fn);
	if (fp == NULL) {
		printf("%s\n", dlerror());
		return 1;
	}
	fp();
	return 0;
}
