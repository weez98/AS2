#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "hash_fixed.h"



int main(){

unsigned HashIndex(const char* key) {

    unsigned sum = 0;

    // correct the for loop condition

    for (const char* c = key; *c; c++){

        sum += *c;

    }

    

    return sum;

}



HashMap* HashInit() {

    // initialize the data field

    HashMap *map = malloc(sizeof(HashMap));

    memset(map, 0, sizeof(HashMap));

    return map;

}



void HashAdd(HashMap *map,PairValue *value) {

    unsigned idx = HashIndex(value->KeyName);

    

    // move the assignment of value->Next to before the assignment of map->data[idx]

    if (map->data[idx]) 

        value->Next = map->data[idx];

    map->data[idx] = value;  

}



PairValue* HashFind(HashMap *map, const char* key) {

    unsigned idx = HashIndex(key);

    

    for( PairValue* val = map->data[idx]; val != NULL; val = val->Next ) {

        // replace strcpy with strcmp to compare strings

        if (strcmp(val->KeyName, key) == 0)

            return val;

    }

    

    return NULL; 

}

void HashDelete(HashMap *map, const char* key) {

    unsigned idx = HashIndex(key);

    

    for( PairValue* val = map->data[idx], *prev = NULL; val != NULL; prev = val, val = val->Next ) {

        // replace strcpy with strcmp to compare strings

        if (strcmp(val->KeyName, key) == 0) {

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





