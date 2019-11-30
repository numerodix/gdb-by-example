#include <signal.h>

#define segfault raise(SIGSEGV);
