# makefile
VPATH=test:net

MultiTarget: bin t
	@echo OK

t: test/*.c uclib.a
	$(CC) -o t $^ -Iinc -ldl -rdynamic

bin:
	mkdir bin

uclib.a: net/*.c
	$(CC) -c $^ -Iinc
	mv *.o bin
	ar rcs $@ bin/*.o

.PHONY:clean
clean:
	@-rm -rf bin
	@-rm t uclib.a
