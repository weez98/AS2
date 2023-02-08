
/
*
* @Name : hash.h
*
/
#ifndef HASH
#define HASH

    typedef struct {
        #define KEY_STRING_MAX 255
    char KeyName[KEY_STRING_MAX];
    int  ValueCount;
        // error: struct PairValue not defined yet
        struct PairValue* Next;
  } PairValue;

  typedef struct {
        #define MAP_MAX 128
        // error: data array not initialized
    PairValue* data[MAP_MAX];
  } HashMap;

    // error: missing return type and argument types
    HashMap* HashInit();
    void HashAdd(HashMap *map, PairValue *value);
    void HashDelete(HashMap *map, const char* key);
    PairValue* HashFind(HashMap *map, const char* key);
    void HashDump(HashMap *map);
#endif
