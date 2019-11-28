#include <signal.h>

#define segfault raise(SIGSEGV);


int main(int argc, char **argv) {
    char initial = 'H';
    char first[] = "Hans";
    char last[] = {'Z', 'i', 'm', 'm', 'e', 'r', 0};

    char *pinitial = &initial;
    char *pfirst = &first[0];
    char *plast = &last[0];
 
    // village population: 243
    unsigned char village = 243;
    unsigned char *pvillage = &village;
    unsigned char villages[] = {243, 113, 54};
    unsigned char *pvillages = &villages[0];

    // town population: 61,000
    unsigned short town = 61000;
    unsigned short *ptown = &town;
    unsigned short towns[] = {61000, 33109, 41001};
    unsigned short *ptowns = &towns[0];


    segfault
}
