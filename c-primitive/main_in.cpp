#include <signal.h>
#include <stdlib.h>

#define segfault raise(SIGSEGV);


int main(int argc, char **argv) {
// {{<snippets/chars>}}

    segfault
}
