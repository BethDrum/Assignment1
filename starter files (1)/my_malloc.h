/**
 * FILE: MY_MALLOC.H
 *
 * Contains the definition of a function 'myMalloc' that you will be using for memory allocation instead of malloc() 
 *
 * NOTE: YOU DO NOT NEED TO MODIFY THIS FILE. IT CAN BE USED AS-IS.
 */

#ifndef __MY_MALLOC_HEADER__ // this is a 'guard' on the header file, to prevent it's contents from
#define __MY_MALLOC_HEADER__ // being redefined more than once during the build process

/** 
 * ### INCLUDES
 */
#include "stddef.h"   // defines the 'size_t' type used in the myMalloc function below (it is basically an 'int' data type)

/**
 * myMalloc(): a function to allocate memory.
 *
 * DO NOT REMOVE OR MODIFY THIS - PLEASE LEAVE AS IS
 * 
 * YOU DO NOT NEED TO IMPLEMENT THIS FUNCTION YOURSELF, IT WILL BE DONE FOR YOU
 *
 * You will use myMalloc() to allocate memory in your own code. 
 * The implementation of this function is provided to you and
 * has already been placed in the accompanying 'tester' files 
 * where it is ready to use. You simply need to call the
 * function in your code where required. When you compile your
 * own code with any of the tester files, everything will be linked 
 * together. 
 *
 * myMalloc works exactly the same way as malloc. For example, if 
 * you were using malloc to allocate an array of 10 integers, it
 * would be as follows:
 *
 * int *array = (int*)malloc(sizeof(int) * 10);
 * 
 * Using myMalloc will be exactly the same:
 *
 * int *array = (int*)myMalloc(sizeof(int) * 10);
 * 
 */
void *myMalloc(size_t size);

#endif
