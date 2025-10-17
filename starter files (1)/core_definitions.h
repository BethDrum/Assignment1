/**
 * FILE: CORE_DEFINITIONS.H
 *
 * Contains declarations or definitions of constants, structs, or functions that are common to
 * other parts of the program so they can be included where required. 
 *
 * NOTE: YOU DO NOT NEED TO MODIFY THIS FILE. IT CAN BE USED AS-IS.
 */

#ifndef __CORE_DEFINITIONS_HEADER__ // this is a 'guard' on the header file, to prevent it's contents from
#define __CORE_DEFINITIONS_HEADER__ // being redefined more than once during the build process

/**
 * ### DEFINE CONSTANTS FOR ERROR CODES / SUCCESS CODES ###
 * 
 * PLEASE USE THESE AS THE RETURN VALUES FOR YOUR FUNCTIONS WHERE REQUIRED.
 * 
 * NOTE: it is the name of the constant you should use when returning values from your functions,
 * not its numerical value. E.g., in the case of a SUCCESS, you would return the following:
 * 
 * return SUCCESS;
 * 
 * And not the following:
 * 
 * return 100;
 *
 */
#define SUCCESS                	100   	// Value to be returned if a function is completed successfully

#define INVALID_INPUT_PARAMETER	101     // Value to be returned if you detect that one of the input parameters 
                                      	// into your function is invalid, e.g. it is NULL or an unexpected value

#define PARTIAL_SUCCESS         102     // Value to return if there has been only partial success in adding a collection
                                        // of edges to a graph, i.e., some were added, some were not.

#define MEMORY_ALLOCATION_ERROR 103     // Value to be returned if you are attempting to allocate memory in your program
                                        // using myMalloc(), and you detect that the memory allocation failed

#define NOT_IMPLEMENTED          104    // Value to be returned if you haven't implemented this function yet

#define FILE_IO_ERROR            105    // May be required for some File IO tasks. E.g. failure to open a file.


/** ### DEFINE OTHER CONSTANTS ### **/
#define NUMBER_OF_VERTICES      10      // the number of vertices on the graphs you will be working with

#define VERY_LARGE_NUMBER       9999999 // a large number, guaranteed to be larger than any path distance
                                        // found on a graph

#endif
