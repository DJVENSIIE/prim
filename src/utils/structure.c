/*!
 * \file structures.c
 * \author Ramzy ZEBRIR
 * \version 0.1
 * \date 06/04/2021
 * \see structures.h
 *
 * Contains structures
 */
#include <string.h>
#include <stdio.h>
#include "../../headers/utils/structures.h"

List* list_create( Element first )
{
    List* l = (List*) malloc(sizeof(List));
    l->current = first;
    l->next = NULL;
    return l;
}

// at the end
ErrorCode list_addElement( List* l, Element e )
{
    List* c = l;
    if ( l->next == NULL ) {
        l->next = list_create(e);
    } else {
        while ( c->next != NULL ) {
            c = c->next;
        }
        c->next = list_create(e);
    }
    return NO_ERROR;
}

// advance list => next and return current
Element list_next( List** current )
{
    Element e = (*current)->current;
    *current = (*current)->next;
    return e;
}

// get Element
Element list_get( List* list )
{
    return list->current;
}

// destroy
ErrorCode list_destroy( List* list )
{
    //todo: no a real free (check list->next)
    if ( list != NULL )
        free(list);
    return NO_ERROR;
}

Dictionary* dictionary_create( int length )
{
    Dictionary* dict = (Dictionary*) malloc(sizeof(Dictionary));
    dict->length = length;
    dict->numberOfElement = 0;
    dict->entries = (Couple*) malloc(length * sizeof(Couple));
    return dict;
}

ErrorCode dictionary_destroy( Dictionary* d )
{
    if ( d != NULL ) {
        free(d->entries);
        free(d);
    }
    return NO_ERROR;
}

Element* dictionary_getElement( Dictionary* d, Element key )
{
    for ( int i = 0; i < d->numberOfElement; i++ ) {
        Couple current = d->entries[i]; //!< current value check
        // type is different, we can't compare
        if ( key.type != current.keys.type )
            continue; //next
        if ( current.keys.type == NUMBER && key.type == NUMBER ) {
            if ( current.keys.content.number == key.content.number )
                return &(d->entries[i].values);
        } else if ( current.keys.type == OBJECT && key.type == OBJECT ) {
            if ( current.keys.content.object == key.content.object )
                return &(d->entries[i].values);
        } else if ( current.keys.type == TEXT && key.type == TEXT ) {
            if ( current.keys.content.text == key.content.text )
                return &(d->entries[i].values);
        }
    }
    return NULL;
}

ErrorCode dictionary_addElement( Dictionary* d, Element key, Element value )
{
    if ( d == NULL )
        return ERROR; //todo: create and use ERROR_DICTIONARY_NULL

    // verify that the key don't exist before insert
    for ( int i = 0; i < d->numberOfElement; i++ ) {
        Couple current = d->entries[i]; //!< current value check
        // type is different, we can't compare
        if ( key.type != current.keys.type )
            continue; //next
        // check equals
        switch ( key.type ) {
            case NUMBER:
                if ( current.keys.content.number == key.content.number ) {
                    // set value and go back
                    d->entries[i].values = value;
                    return NO_ERROR;
                }
                break;
            case TEXT:
                if ( strcmp(current.keys.content.text, key.content.text) == 0 ) {
                    // set value and go back
                    d->entries[i].values = value;
                    return NO_ERROR;
                }
                break;
            case OBJECT:
                if ( current.keys.content.object == key.content.object ) {
                    // set value and go back
                    d->entries[i].values = value;
                    return NO_ERROR;
                }
                break;
        }
    }

    // else
    // realloc if needed
    if ( d->length == d->numberOfElement ) {
        d->length += 5;
        d->entries = (Couple*) realloc(d->entries, d->length * sizeof(Couple*));
    }

    // set
    d->entries[d->numberOfElement].keys = key;
    d->entries[d->numberOfElement].values = value;
    d->numberOfElement++; //increase

    return NO_ERROR;
}

Couple* dictionary_getCoupleByIndex( Dictionary* d, int index )
{
    if ( index <= d->numberOfElement )
        return &(d->entries[index]);
    return NULL;
}

// convenience methods

ErrorCode dictionary_addCoupleText( Dictionary* d, char* key, char* value )
{
    Element e_key;
    Element e_value;

    e_key.type = TEXT;
    e_key.content.text = key;

    e_value.type = TEXT;
    e_value.content.text = value;
    return dictionary_addElement(d, e_key, e_value);
}

ErrorCode dictionary_addCoupleInt( Dictionary* d, int key, int value )
{
    Element e_key;// rename name of variable
    Element e_value;

    e_key.type = NUMBER;
    e_key.content.number = key;

    e_value.type = NUMBER;
    e_value.content.number = value;
    return dictionary_addElement(d, e_key, e_value);
}

ErrorCode dictionary_addCoupleIntText( Dictionary* d, int key, char* value )
{
    Element e_key;// rename name of variable
    Element e_value;

    e_key.type = NUMBER;
    e_key.content.number = key;

    e_value.type = TEXT;
    e_value.content.text = value;
    return dictionary_addElement(d, e_key, e_value);
}

Element* dictionary_getElementText( Dictionary* d, char* key )
{
    // create element
    Element e_key;
    e_key.type = TEXT;
    e_key.content.text = key;
    return dictionary_getElement(d, e_key);
}

Element* dictionary_getElementInt( Dictionary* d, int key )
{
    // create element
    return dictionary_getElement(d, dictionary_elementFromInt(key));
}

int dictionary_elementToInt( Element e )
{
    if ( e.type == NUMBER ) {
        return e.content.number;
    }
    return -1;
}

char* dictionary_elementToText( Element e )
{
    if ( e.type == TEXT ) {
        return e.content.text;
    }
    return "";
}

Element dictionary_elementFromInt( int number )
{
    Element e;
    e.type = NUMBER;
    e.content.number = number;
    return e;
}

Element dictionary_elementFromText( char* text )
{
    Element e;
    e.type = TEXT;
    e.content.text = text;
    return e;
}

int main( void )
{
    Dictionary* d = dictionary_create(10);
    dictionary_addCoupleIntText(d, 10, "aza");
    dictionary_addCoupleInt(d, 3, 3);
    dictionary_addCoupleInt(d, 5, 5);
    dictionary_addCoupleText(d, "toto", "choco");

    dictionary_addElement(d, dictionary_elementFromInt(5), dictionary_elementFromInt(7));
    dictionary_addElement(d, dictionary_elementFromInt(10), dictionary_elementFromText("ok"));

    printf("%s\n", dictionary_elementToText(*dictionary_getElementInt(d, 10)));
    printf("%s\n", dictionary_elementToText(*dictionary_getElementText(d, "toto")));
    printf("%d\n", dictionary_elementToInt(*dictionary_getElementInt(d, 3)));
    printf("%d\n", dictionary_elementToInt(*dictionary_getElementInt(d, 5)));
    dictionary_destroy(d);
}