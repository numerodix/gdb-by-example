#include <signal.h>

#define segfault raise(SIGSEGV);


int main(int argc, char **argv) {
    char initial = 'H';
    char first[] = "Hans";
    char last[] = {'Z', 'i', 'm', 'm', 'e', 'r', 0};

    char *pinitial = &initial;
    char *pfirst = &first[0];
    char *plast = &last[0];

    unsigned char village = 240;
    unsigned short town = 63 * 1000;
    unsigned int city = 12 * 1000 * 1000;
    unsigned long long universe = 5LL << 60;

    segfault
}
