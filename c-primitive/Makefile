all:
	cc -g3 -Werror main.cpp -o main

	ulimit -c unlimited
	gdb \
		--command=_gdb.script \
		./main