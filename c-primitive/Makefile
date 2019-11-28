all:
	cc -g3 -Werror main.c -o main

	ulimit -c unlimited
	gdb \
		--command=_gdb.script \
		./main