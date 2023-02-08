/**
*
* @Name : hash.c
*
**/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

unsigned HashIndex(const char* key) {
    /**
    The expected fix for this issue is to change the loop condition in the HashIndex function to check if *c is not equal to \0,
    instead of c. This will ensure that the loop only continues while *c is not the null terminator, and that the loop will terminate when the end of the string is reached.

By making this change, the infinite loop and potential segmentation fault will be prevented, and the program will function correctly.
This will also help prevent potential denial of service attacks, and ensure that memory resources are used efficiently.
    **/
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
        /**
        The use of strcmp instead of strcpy in the HashFind function is expected to remove the problem because strcmp is a function specifically designed for comparing strings for equality.
        strcmp returns an integer indicating the result of the comparison, which can be used to determine whether the two strings are equal or not.

In contrast, strcpy is a function used to copy strings from one location to another, but it does not return a value indicating whether the strings are equal or not. As a result,
using strcpy in the HashFind function leads to incorrect behavior and can result in unexpected behavior and data integrity issues.

By using strcmp, the HashFind function can correctly compare the key and the KeyName field for equality and return the correct value associated with the key. This will help ensure the correct behavior of the HashFind function,
and improve the overall security of the code by ensuring that sensitive information stored in the hash map is not compromised.
        **/
            return val;
    }
    
    return NULL; 
}

void HashDelete(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    for(PairValue* val = map->data[idx], *prev = NULL; val != NULL; prev = val, val = val->Next) {
        if (strcmp(val->KeyName, key) == 0) {
            /**
        The use of strcmp instead of strcpy in the HashFind function is expected to remove the problem because strcmp is a function specifically designed for comparing strings for equality.
        strcmp returns an integer indicating the result of the comparison, which can be used to determine whether the two strings are equal or not.

In contrast, strcpy is a function used to copy strings from one location to another, but it does not return a value indicating whether the strings are equal or not. As a result,
using strcpy in the HashFind function leads to incorrect behavior and can result in unexpected behavior and data integrity issues.

By using strcmp, the HashFind function can correctly compare the key and the KeyName field for equality and return the correct value associated with the key. This will help ensure the correct behavior of the HashFind function,
and improve the overall security of the code by ensuring that sensitive information stored in the hash map is not compromised.
        **/
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
            /**
            The fix of passing the value of val->Value to printf instead of the key name, val->KeyName, ensures that the function HashDump will print the intended values stored in the hash map,
            rather than the key names. This allows the function to perform its intended purpose of printing the values stored in the hash map,
            ensuring that it works as intended.
            **/
            printf("%d", val->Value);
        }
    }
}
