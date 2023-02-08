#ifndef __HASH__

#define __HASH__



    typedef struct PairValue {

        #define KEY_STRING_MAX 255

                char KeyName[KEY_STRING_MAX];

                int  ValueCount;

        struct PairValue* Next;

        } PairValue;



        typedef struct {

                int size;

                int count;

                PairValue** data;

        } HashMap;



    HashMap* HashInit(int size);

    int HashAdd(HashMap *map, const char* key, int value);

    void HashDelete(HashMap *map, const char* key);

    PairValue* HashFind(HashMap *map, const char* key);

    void HashDump(HashMap *map);

    int HashFunction(const char* key, int size);

    void HashDestroy(HashMap *map);

#endif

