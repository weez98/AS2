/**
*
* @Name : hash.h
*
**/
#ifndef __HASH__
#define __HASH__

    typedef struct {
        /**
        It should be PairValue after 'struct'
        The PairValue struct is used to represent a key-value pair in the hash map.
        Each PairValue instance stores a key string and its associated value count,
        and a pointer to the next PairValue instance in the linked list.
        **/
        #define KEY_STRING_MAX 255
		char KeyName[KEY_STRING_MAX];
		int  ValueCount;
        struct PairValue* Next;
	} PairValue;

	typedef struct {
        #define MAP_MAX 128
		PairValue* data[MAP_MAX];
	} HashMap;

    HashMap* HashInit();
    void HashAdd(HashMap *map, PairValue *value);
    void HashDelete(HashMap *map, const char* key);
    PairValue* HashFind(HashMap *map, const char* key);
    void HashDump(HashMap *map);
#endif
