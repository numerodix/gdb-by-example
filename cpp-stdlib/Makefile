all:
	c++ -g3 -Werror -I ../common main.cpp -o main

	ulimit -c unlimited
	gdb \
		--command=_gdb.script \
		./main
