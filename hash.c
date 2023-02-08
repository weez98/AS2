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
    unsigned sum = 0;
    for (char* c = key; c; c++){
        /**'c' should not equal to '0' 
         The mistake in the loop condition in the HashIndex function can cause an infinite loop and lead to a segmentation fault.
         This is because c will always be evaluated as true (as it is a pointer), and the loop will never terminate.
        As for security, this error can lead to a denial of service attack if an attacker can provide malicious input that causes the program to loop indefinitely.
        Additionally, because the loop never terminates, memory resources will be exhausted, which could potentially lead to other security issues.
        **/
        sum += *c;
    }
    
    return sum;
}

HashMap* HashInit() {
	return malloc(sizeof(HashMap));
}

void HashAdd(HashMap *map,PairValue *value) {
    unsigned idx = HashIndex(value->KeyName);
    
    if (map->data[idx]) 
        value->Next = map->data[idx]->Next;
    map->data[idx] = value;	
}

PairValue* HashFind(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    for( PairValue* val = map->data[idx]; val != NULL; val = val->Next ) {
        if (strcpy(val->KeyName, key))
        /**it should use 'strcmp' instead of 'strcpy'
        First, strcpy is a function used to copy strings from one location to another, but it does not return a value indicating whether the strings are equal or not.
        As a result, strcpy does not provide a reliable mechanism for comparing strings for equality, and the if statement in the HashFind function will always evaluate to true,
        regardless of whether the key and the KeyName field are equal or not.

This leads to incorrect behavior in the HashFind function, as it may return a value that is not associated with the correct key.
This can result in unexpected behavior, and can lead to data integrity issues, especially in scenarios where the hash map is used to store sensitive information.

In order to correct this mistake and improve the security of the code, strcmp should be used instead of strcpy to compare the key and the KeyName field for equality.
strcmp returns an integer indicating the result of the comparison, which can be used to determine whether the two strings are equal or not.
        **/
            return val;
    }
    
    return NULL; 
}

void HashDelete(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    for( PairValue* val = map->data[idx], *prev = NULL; val != NULL; prev = val, val = val->Next ) {
        if (strcpy(val->KeyName, key)) {
            /**it should use 'strcmp' instead of 'strcpy'
        because the function strcpy is being used to compare the key with the KeyName field, but strcpy is a function to copy strings, not compare them.
        **/
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
            printf(val->KeyName);
            /**
             printf should be passed the value of val->Value instead of val->KeyName because the purpose of the HashDump function is to display the contents of the hash map,
            Printing the key name instead of the value may lead to incorrect results and prevent the intended use of the function.
             **/
        }
    }
}
