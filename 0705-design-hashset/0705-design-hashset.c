#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool *hash;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* obj = malloc(sizeof(MyHashSet));

    obj->hash = calloc(1000001, sizeof(bool));

    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->hash[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->hash[key] = false;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->hash[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->hash);
    free(obj);
}