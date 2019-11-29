#include <signal.h>

#define segfault raise(SIGSEGV);


int main(int argc, char **argv) {
// {{<include:snippets/chars>}}
 
// {{<include:snippets/unsigned-char>}}

// {{<include:snippets/unsigned-short>}}

// {{<include:snippets/unsigned-int>}}

// {{<include:snippets/unsigned-long-long>}}

    segfault
}
