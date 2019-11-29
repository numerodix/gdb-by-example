#include <signal.h>

#define segfault raise(SIGSEGV);


int main(int argc, char **argv) {
    char initial = 'H';
    char first[] = "Hans";
    char last[] = {'Z', 'i', 'm', 'm', 'e', 'r', 0};

    char *pinitial = &initial;
    char *pfirst = &first[0];
    char *plast = &last[0];
    char initial = 'H';
    char *pinitial = &initial;
 
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

    // planet population: 4,043,309,055
    unsigned int planet = 4043309055;
    unsigned int *pplanet = &planet;
    unsigned int planets[] = {planet, planet / 2, planet / 6};
    unsigned int *pplanets = &planets[0];

    // universe population: 10,376,293,541,461,622,784
    unsigned long long universe = 10376293541461622784LLU;
    unsigned long long *puniverse = &universe;
    unsigned long long universes[] = {universe, universe / 2, universe / 6};
    unsigned long long *puniverses = &universes[0];

    segfault
}
