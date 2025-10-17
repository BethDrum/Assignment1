/**
 * FILE: MY_MALLOC.C
 * 
 * THIS FILE CONTAINS THE IMPLEMENTATION FOR THE 'myMalloc' function
 * that you will use to allocate memory for your program instead of
 * the standard 'malloc'.
 * 
 * THIS IMPLEMENTATION SHOULD BE USED AS-IS. 
 * 
 * YOU DON'T NEED TO MODIFY IT.
 *
 * YOU SHOULDN'T ADD ANY OTHER CODE TO THIS FILE.
 * 
 * JUST MAKE SURE THAT YOU INCLUDE THIS FILE WHEN YOU COMPILE 
 * YOUR PROGRAM SO THAT IT'S IMPLEMENTATION CAN BE INCLUDED 
 * IN YOUR EXECUTABLE
 * 
 */

/** 
 * ### INCLUDES
 */
#include <stdlib.h>     // gives access to 'malloc' which is used by the myMalloc function
#include "my_malloc.h"  // provides the prototype / declaration of the myMalloc function being implemented here

/** #### FUNCTION IMPLEMENTATIONS ## */

/**
 * Implementation of the 'myMalloc' function. Required so that any
 * references to myMalloc within *YOUR* code will be resolved. 
 * Please leave this function here. You don't need to copy or 
 * place it anywhere else.
 */
int mallocFail = 0;
void* myMalloc(size_t size) {
    if (mallocFail) { return NULL; }
    else { return malloc(size); }
}