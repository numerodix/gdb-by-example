#include <QString>

#include <segfault.h>


int main(int argc, char** argv) {
    QString name("Harry Gregson-Williams");

    segfault;
}
