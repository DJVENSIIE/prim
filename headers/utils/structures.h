/*!
 * \file structures.h
 * \author Ramzy ZEBRIR
 * \version 0.1
 * \date 26/03/2021
 * \see effect.h
 *
 * Contains structures
 */
#ifndef PRIM_STRUCTURES_H
#define PRIM_STRUCTURES_H

//todo: Ramzy comment all

#include "../data/effect.h" // effect.h : information about effect
#include "../data/error.h" // todo: ...

/*!
 * \typedef ElementType
 * \enum ElementType_S
 * \brief todo : do a comment
 */
typedef enum ElementType_S {
    NUMBER,
    TEXT,
    OBJECT
} ElementType;

/*!
* \typedef Element
* \union Element_S effect.h "headers/data/structures.h"
* \brief Represent a list
*/
//todo: Ramzy documentation and move to element.h
typedef struct Element_S {
    union {
        int number;
        char* text;
        void* object;
    } content;
    ElementType type; //!< in witch field we got our value
} Element;

typedef struct Couple_S{
    Element keys;
    Element values;
} Couple;

/*!
 * \typedef Dictionary
 * \struct Dictionary_S structures.h "headers/data/structures.h"
 * \brief Struct which contains a dictionary of ElementType
 */
//todo: documentation
typedef struct Dictionary_S {
    int length;
    int numberOfElement;
    Couple* entries;
} Dictionary;

typedef struct List_S {
    Element* current;
    struct List_S* next;
} List;

// create list
List* list_create(Element first);
List* list_createEmpty( );
Element* list_getByIndex(List* list, int index);
int list_getSize(List* list);
// at the end
ErrorCode list_addElement(List* l, Element e);
ErrorCode list_addCoupleIntText(List* l, int number, char* text);
ErrorCode list_addCoupleNumber(List* l, int n1, int n2);
// advance list => next and return current
Element list_next(List** current);
// get Element
Element list_get(List* list);
// remove Element by Index
ErrorCode list_removeByIndex(List** list,int index);
// destroy all (next included)
ErrorCode list_destroy(List* list);
// destroy only this list
ErrorCode list_destroyFirst(List* list);
/*!
 * \fn Dictionary* createDictionary()
 * @brief Create a Dictionary of ElementType and Element
 * create an array of structures_tab
 *
 *
 * @return Array of the structures_tab
 */
// todo : do the documentation
Dictionary* dictionary_create(int length);
ErrorCode dictionary_destroy(Dictionary* d);
Element* dictionary_getElement(Dictionary* d, Element key);
ErrorCode dictionary_addElement(Dictionary* d, Element key, Element value);
Couple* dictionary_getCoupleByIndex( Dictionary *d, int index);
ErrorCode dictionary_addCoupleText(Dictionary *d,char* key, char* value);
ErrorCode dictionary_addCoupleNumberText(Dictionary* d,int key, char* value);
Element* dictionary_getElementText(Dictionary *d, char* key);
ErrorCode dictionary_addCoupleNumber( Dictionary* d, int key, int value );
Element* dictionary_getElementNumber(Dictionary *d, int key);

int dictionary_elementToNumber(Element e);
char* dictionary_elementToText( Element e);
void* dictionary_elementToObject( Element e);
Element dictionary_elementFromNumber(int number);
Element dictionary_elementFromText( char* text);
Element dictionary_elementFromObject (void* object);

/*!
 * \fn destroyStructuresTab
 * @brief Destroy the array structures_tab
 *
 * At the end of the game we need to clean all of the map
 * this function will destroy the array
 *
 * @param[in] array of structures_tab
 * @return a void
 */

#endif //PRIM_STRUCTURES_H