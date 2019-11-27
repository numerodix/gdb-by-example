#include <signal.h>
#include <stdlib.h>

#define segfault raise(SIGSEGV);


int main(int argc, char **argv) {
    char initial = 'H';
    char first[] = "Hans";
    char last[] = {'Z', 'i', 'm', 'm', 'e', 'r', 0};

    char *pinitial = &initial;
    char *pfirst = &first[0];
    char *plast = &last[0];

    segfault
}
