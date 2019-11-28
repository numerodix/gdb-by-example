#include <signal.h>

#define segfault raise(SIGSEGV);


int main(int argc, char **argv) {
// {{<snippets/chars>}}
 
// {{<snippets/unsigned-char>}}

// {{<snippets/unsigned-short>}}

// {{<snippets/unsigned-int>}}

    segfault
}
