#include <segfault.h>


typedef struct Pet {
    char *name;
} Pet;

typedef struct User {
    unsigned int id;
    char *name;
    float age;
    struct Pet *pets;
    unsigned int num_pets;
} User;

typedef struct Group {
    unsigned int id;
    struct User *users;
    unsigned int num_users;
} Group;


int main(int argc, char **argv) {
    Pet harold = { name: "harold" };
    Pet roger = { name: "roger" };
    Pet bill = { name: "bill" };
    Pet pets[] = {harold, roger, bill};

    User mike = {
        id: 1,
        name: "Michael",
        age: 13.57,
        pets: pets,
        num_pets: sizeof(pets) / sizeof(Pet),
    };
    User oliver = {
        id: 2,
        name: "Oliver",
        age: 87.3,
        pets: pets,
        num_pets: sizeof(pets) / sizeof(Pet),
    };

    User buds[] = {mike, oliver};
    Group buddies = {
        id: 1,
        users: buds,
        num_users: sizeof(buds) / sizeof(User),
    };

    User folks[] = {mike};
    Group parents = {
        id: 1,
        users: folks,
        num_users: sizeof(folks) / sizeof(User),
    };

    Group groups[] = {buddies, parents};
    Group *pgroups = &groups[0];

    segfault;
}
