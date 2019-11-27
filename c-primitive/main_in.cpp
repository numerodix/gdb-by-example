#include <signal.h>
#include <stdlib.h>

#define segfault raise(SIGSEGV);


int main(int argc, char **argv) {
// {{<chars.snippet>}}

    segfault
}
