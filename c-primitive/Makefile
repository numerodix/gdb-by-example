all:
	cc -g3 -Werror -I ../common main.c -o main

	ulimit -c unlimited
	gdb \
		--command=_gdb.script \
		./main