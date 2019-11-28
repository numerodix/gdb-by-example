#include <signal.h>

#define segfault raise(SIGSEGV);


int main(int argc, char **argv) {
    char initial = 'H';
    char first[] = "Hans";
    char last[] = {'Z', 'i', 'm', 'm', 'e', 'r', 0};

    char *pinitial = &initial;
    char *pfirst = &first[0];
    char *plast = &last[0];

    unsigned char hour = 11;
    unsigned short year = 1984;
    unsigned int population = 500000;
    unsigned long long fortune = 5LL << 60;

    unsigned char *phour = &hour;
    unsigned short *pyear = &year;
    unsigned int *ppopulation = &population;
    unsigned long long *pfortune = &fortune;

    unsigned char hours[] = {12, 13, 14};
    unsigned short years[] = {1984, 1991, 1976};
    unsigned int populations[] = {population, population * 2, population * 3};
    unsigned long long fortunes[] = {fortune, fortune >> 1, fortune >> 2};

    unsigned char *phours = &hours[0];
    unsigned short *pyears = &years[0];
    unsigned int *ppopulations = &populations[0];
    unsigned long long *pfortunes = &fortunes[0];

    segfault
}
