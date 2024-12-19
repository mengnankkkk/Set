#include "Set.h"


void initSet(Set *set) {
    set->size = 0;
}


bool contains(Set *set, int e) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == e) {
            return true;
        }
    }
    return false;
}
bool add(Set *set, int e) {
    if (set->size >= MAX_SIZE) return false;  
    if (contains(set, e)) return false;  
    set->elements[set->size++] = e;
    return true;
}


bool addAll(Set *set, Set *other) {
    bool added = false;
    for (int i = 0; i < other->size; i++) {
        if (add(set, other->elements[i])) {
            added = true;
        }
    }
    return added;
}


void clear(Set *set) {
    set->size = 0;
}


bool isEmpty(Set *set) {
    return set->size == 0;
}


bool removeElement(Set *set, int e) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == e) {
            set->elements[i] = set->elements[set->size - 1];  // 将最后一个元素移到当前位置
            set->size--;
            return true;
        }
    }
    return false;
}


bool removeAll(Set *set, Set *other) {
    bool removed = false;
    for (int i = 0; i < other->size; i++) {
        if (removeElement(set, other->elements[i])) {
            removed = true;
        }
    }
    return removed;
}


bool retainAll(Set *set, Set *other) {
    bool changed = false;
    int newSize = 0;
    for (int i = 0; i < set->size; i++) {
        if (contains(other, set->elements[i])) {
            set->elements[newSize++] = set->elements[i];
        } else {
            changed = true;
        }
    }
    set->size = newSize;
    return changed;
}


int size(Set *set) {
    return set->size;
}


int* toArray(Set *set) {
    int* arr = (int*) malloc(set->size * sizeof(int));
    for (int i = 0; i < set->size; i++) {
        arr[i] = set->elements[i];
    }
    return arr;
}


void print(Set *set) {
    printf("{ ");
    for (int i = 0; i < set->size; i++) {
        printf("%d ", set->elements[i]);
    }
    printf("}\n");
}


Set unionSets(Set *set1, Set *set2) {
    Set result;
    initSet(&result);
    addAll(&result, set1);
    addAll(&result, set2);
    return result;
}


Set intersectionSets(Set *set1, Set *set2) {
    Set result;
    initSet(&result);
    for (int i = 0; i < set1->size; i++) {
        if (contains(set2, set1->elements[i])) {
            add(&result, set1->elements[i]);
        }
    }
    return result;
}


Set differenceSets(Set *set1, Set *set2) {
    Set result;
    initSet(&result);
    for (int i = 0; i < set1->size; i++) {
        if (!contains(set2, set1->elements[i])) {
            add(&result, set1->elements[i]);
        }
    }
    return result;
}


Set complementSets(Set *universalSet, Set *set) {
    Set result;
    initSet(&result);
    for (int i = 0; i < universalSet->size; i++) {
        if (!contains(set, universalSet->elements[i])) {
            add(&result, universalSet->elements[i]);
        }
    }
    return result;
}
