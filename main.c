#include "Set.h"

int main() {
    Set set1, set2;
    initSet(&set1);
    initSet(&set2);

    add(&set1, 1);
    add(&set1, 2);
    add(&set1, 3);

    add(&set2, 2);
    add(&set2, 3);
    add(&set2, 4);

    
    printf("Set1: ");
    print(&set1);
    printf("Set2: ");
    print(&set2);

    
    Set unionSet = unionSets(&set1, &set2);
    printf("Union: ");
    print(&unionSet);

    
    Set intersectionSet = intersectionSets(&set1, &set2);
    printf("Intersection: ");
    print(&intersectionSet);

    
    Set differenceSet = differenceSets(&set1, &set2);
    printf("Difference: ");
    print(&differenceSet);

    
    Set universalSet;
    initSet(&universalSet);
    add(&universalSet, 1);
    add(&universalSet, 2);
    add(&universalSet, 3);
    add(&universalSet, 4);
    add(&universalSet, 5);

    
    Set complementSet = complementSets(&universalSet, &set1);
    printf("Complement: ");
    print(&complementSet);

    return 0;
}
