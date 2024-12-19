#ifndef SET_H
#define SET_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000  

typedef struct {
    int elements[MAX_SIZE];  
    int size; 
} Set;


void initSet(Set *set);

bool add(Set *set, int e);


bool addAll(Set *set, Set *other);


void clear(Set *set);
bool contains(Set *set, int e);
bool isEmpty(Set *set);


bool removeElement(Set *set, int e);

bool removeAll(Set *set, Set *other);


bool retainAll(Set *set, Set *other);

int size(Set *set);

int* toArray(Set *set);

void print(Set *set);

Set unionSets(Set *set1, Set *set2);
Set intersectionSets(Set *set1, Set *set2);


Set differenceSets(Set *set1, Set *set2);


Set complementSets(Set *universalSet, Set *set);

#endif 
