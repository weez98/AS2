/
*
* @Name : hash.c
*
/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_fixed.h"

int main(){
unsigned HashIndex(const char* key) {
    unsigned sum = 0;
    for (const char* c = key; *c; c++){ // corrected the type of c to const char*
        sum += *c;
    }
    
    return sum;
}

HashMap* HashInit() {
    HashMap* map = malloc(sizeof(HashMap)); // created a variable to hold the returned pointer
    if (!map) {
        // handle error: malloc failed
    }
    memset(map, 0, sizeof(HashMap)); // zero out the memory
    return map;
}

void HashAdd(HashMap *map,PairValue *value) {
    unsigned idx = HashIndex(value->KeyName);
    
    value->Next = map->data[idx]; // set the next to the current data at the index
    map->data[idx] = value;  
}

PairValue* HashFind(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    for( PairValue* val = map->data[idx]; val != NULL; val = val->Next ) {
        if (!strcmp(val->KeyName, key)) // used strcmp to compare strings instead of strcpy
            return val;
    }
    
    return NULL; 
}

void HashDelete(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    PairValue* prev = NULL;
    for( PairValue* val = map->data[idx]; val != NULL; prev = val, val = val->Next ) {
        if (!strcmp(val->KeyName, key)) {
            if (prev)
                prev->Next = val->Next;
            else
                map->data[idx] = val->Next;
        }
    }
}

void HashDump(HashMap *map) {
    for( unsigned i = 0; i < MAP_MAX; i++ ) {
        for( PairValue* val = map->data[i]; val != NULL; val = val->Next ) {
            printf("%s\n", val->KeyName); // added format specifier for printf
        }
    }
}
}
