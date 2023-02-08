/
 * @Name : hash.h
 *
 * Fix: Header comment added
/

#ifndef HASH
#define HASH

/
 * Fix: Moved struct PairValue definition to after its usage
/
typedef struct PairValue PairValue;
struct PairValue {
    #define KEY_STRING_MAX 255
    char KeyName[KEY_STRING_MAX];
    int  ValueCount;
    PairValue* Next;
};

typedef struct {
    #define MAP_MAX 128
    PairValue* data[MAP_MAX];
} HashMap;

/
 * Fix: Added argument types to HashInit prototype
/
HashMap* HashInit(void);

/
 * Fix: Added argument types to HashAdd prototype
/
void HashAdd(HashMap *map, PairValue *value);

/
 * Fix: Added argument types to HashDelete prototype
/
void HashDelete(HashMap *map, const char* key);

/
 * Fix: Added argument types to HashFind prototype
/
PairValue* HashFind(HashMap *map, const char* key);

/
 * Fix: Added argument types to HashDump prototype
/
void HashDump(HashMap *map);

#endif
