#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_fixed.h"

#define MAP_MAX 256

int main(){
unsigned HashIndex(const char* key) {
    unsigned sum = 0;
    for (const char* c = key; *c != '\0'; c++) {
        sum += *c;
    }
    
    return sum;
}

HashMap* HashInit() {
    return malloc(sizeof(HashMap));
}

void HashAdd(HashMap *map, PairValue *value) {
    unsigned idx = HashIndex(value->KeyName);
    
    if (map->data[idx]) 
        value->Next = map->data[idx]->Next;
    map->data[idx] = value;     
}

PairValue* HashFind(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    for(PairValue* val = map->data[idx]; val != NULL; val = val->Next) {
        if (strcmp(val->KeyName, key) == 0)
            return val;
    }
    
    return NULL; 
}

void HashDelete(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    for(PairValue* val = map->data[idx], *prev = NULL; val != NULL; prev = val, val = val->Next) {
        if (strcmp(val->KeyName, key) == 0) {
            if (prev)
                prev->Next = val->Next;
            else
                map->data[idx] = val->Next;
        }
    }
}

void HashDump(HashMap *map) {
    for(unsigned i = 0; i < MAP_MAX; i++) {
        for(PairValue* val = map->data[i]; val != NULL; val = val->Next) {
            printf("%s\n", val->KeyName);
        }
    }
}
}
