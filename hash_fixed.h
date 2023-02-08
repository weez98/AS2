#ifndef HASH
#define HASH

// moved the definition of struct PairValue before using it in HashMap
typedef struct PairValue {
    #define KEY_STRING_MAX 255
    char KeyName[KEY_STRING_MAX];
    int  ValueCount;
    struct PairValue* Next;
} PairValue;

typedef struct {
    #define MAP_MAX 128
    // added initialization for data array
    PairValue* data[MAP_MAX];
} HashMap;

// added return type and argument types
HashMap* HashInit();
void HashAdd(HashMap *map, PairValue *value);
void HashDelete(HashMap *map, const char* key);
PairValue* HashFind(HashMap *map, const char* key);
void HashDump(HashMap *map);

#endif
