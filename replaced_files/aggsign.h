#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tepla/ec.h>

#define hash_size 256
#define list_size 10
#define str_size 100

typedef char* String;
typedef Element Privkey;
typedef EC_POINT Pubkey;
typedef EC_POINT Sign;
typedef EC_POINT Hash;

// ***** my func ***** //
void my_point_print(const String s, const EC_POINT p);
void my_element_print(const String s, const Element e);
void set_mpz_from_element(mpz_t t, const Element e);

// ********** Algorithm 1 Setup **********//
typedef struct
{
    EC_PAIRING prg;  
    EC_POINT g2;
    Field f;
} Para;
Para para;
void ParaInit();
void ParaGenG2();
void ParaClear();
void Setup();

// ********** Algorithm 2 UserKeyGen **********//
typedef struct
{
    Privkey sk;
    Pubkey pk;
} Key;
void KeyInit(Key *key);
void KeyGen(Key *key);
void KeyClear(Key *key);
void UserKeyGen(Key *key);

// ********** Algorithm 3 SeqAggSign **********//
typedef struct{
    Pubkey pk;
    char m[100];
} List;

typedef struct{
    char prefix[20];
} TList;

typedef struct{
    int asn; 
} HashTarget;

void ListInit(List *list);
int ListLength(List *list);
void ListAdd(List *list, const Pubkey pk, const String m);
void ListDisplay(List *list);
void ListClear(List *list);
//void HashForSign(Hash c, const Sign sign, const String m);
//int SeqAggSign(Sign sign, const Key *key, const String m);

void HashForSign(Hash c, const Sign sign, List *list);
int SeqAggSign(Sign sign, List *list, const Key *key, const String m);

// ********** Algorithm 4 AggSign **********//
void AggSign(Sign sign1, List *list1, Sign sign2, List *list2);

// ********** Algorithm 5 Verify **********//
int Verify(const Sign sign, List *list);

// ********** Algorithm 6 PointGen **********//
void PointGen(List *list1, TList *list2, Element E);

// ********** Algorithm 7 PointVer **********//
int PointVer(const Sign sign, List *list1, TList *list2, Element E);

void best_route(const Sign sign, List *list1, TList *list2);
// ********** Algorithm 8 RemSign **********//
void RemSign(Sign sign1, List *list1, Sign sign2, List *list2);

// ********** Algorithm 9 Tracing **********//

