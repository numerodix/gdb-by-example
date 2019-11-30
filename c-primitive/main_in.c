#include <signal.h>

#define segfault raise(SIGSEGV);


int main(int argc, char **argv) {
// {{<include:snippets/chars,indent:4>}}
 

// {{<include:snippets/unsigned-char,indent:4>}}

// {{<include:snippets/unsigned-short,indent:4>}}

// {{<include:snippets/unsigned-int,indent:4>}}

// {{<include:snippets/unsigned-long-long,indent:4>}}


// {{<include:snippets/signed-char,indent:4>}}

// {{<include:snippets/signed-short,indent:4>}}

// {{<include:snippets/signed-int,indent:4>}}

// {{<include:snippets/signed-long-long,indent:4>}}


    segfault
}
