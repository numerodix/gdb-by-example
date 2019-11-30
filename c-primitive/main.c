#include <signal.h>

#define segfault raise(SIGSEGV);


int main(int argc, char **argv) {
    char initial = 'H';
    char *pinitial = &initial;
    char name[] = "Hans Zimmer";
    char *pname = &name[0];
 

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


    // a planet's surface temperature: -121 C
    char surface = -121;
    char *psurface = &surface;
    char surfaces[] = {-121, -97, -56};
    char *psurfaces = &surfaces[0];

    // credit card debt: 31,500 
    short balance = -31500;
    short *pbalance = &balance;
    short balances[] = {-31500, -29130, -15120};
    short *pbalances = &balances[0];

    // VC funded company earnings: -2,120,401,005
    int profit = -2120401005;
    int *pprofit = &profit;
    int profits[] = {profit, profit / 2, profit / 6};
    int *pprofits = &profits[0];

    // future world economy deficit: 8,220,802,194,093,872,013
    long long deficit = -8220802194093872013LL;
    long long *pdeficit = &deficit;
    long long deficits[] = {deficit, deficit / 2, deficit / 6};
    long long *pdeficits = &deficits[0];


    // mass of electron: 9.10e-31
    float electron = 9.10e-31;
    float *pelectron = &electron;
    // add proton
    float particles[] = {electron, 1.67e-27};
    float *pparticles = &particles[0];

    segfault
}
