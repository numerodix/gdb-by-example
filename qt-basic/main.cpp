#include <QString>

#include <segfault.h>


int main(int argc, char** argv) {
    QChar initial('H');
    QString name("Harry Gregson-Williams");

    segfault;
}
