/**
 * FILE: ADJ_LIST.C
 * 
 * THIS FILE CONTAINS EMPTY / DO-NOTHING IMPLEMENTATIONS
 * FOR THE ADJACENCY LIST DATA STRUCTURE 
 *
 * DO NOT RENAME THESE FUNCTIONS OR CHANGE THEIR RETURN
 * TYPES OR INPUT PARAMETERS.
 *
 * YOU NEED TO COMPLETE THE IMPLEMENTATION OF THESE
 * FUNCTIONS. 
 *
 * THESE FUNCTIONS RECEIVE INPUT PARAMETERS THAT WILL
 * PROVIDE THEM WITH THE INFORMATION THAT THEY REQUIRE. 
 *
 * THE FUNCTIONS RETURN VALUES TO REPRESENT SUCCESS, ERROR,
 * OR, IN SOME CASES, DATA THAT HAS TO BE RETURNED. THE CALLER 
 * OF THESE FUNCTIONS WILL EXPECT TO RECEIVE THESE RETURN VALUES 
 * IN ORDER TO VERIFY THE OUTCOME OF THE FUNCTION CALL. 
 *
 * IF THERE ARE ANY FUNCTIONS THAT YOU DON'T HAVE TIME TO 
 * IMPLEMENT, PLEASE LEAVE THE EMPTY / DO-NOTHING IMPLEMENTATION
 * FOR THEM IN THIS FILE, OTHERWISE YOUR PROGRAM WON'T COMPILE
 * WHEN IT IS FED INTO OUR TESTER PROGRAM.
 * 
 */

/** 
 * ### INCLUDES
 */
#include "my_malloc.h"  // gives access to memory allocation functions, including 'myMalloc'
#include "adj_matrix.h" // provides the definition of the 'Adjacency Matrix' struct which is required for one of the functions below
#include "adj_list.h"   // provides the definition of structs and functions for the adjacency list implementation
#include <stdio.h>      //used for on the go testing

/** #### FUNCTION IMPLEMENTATIONS ## */

/**
 * This function should add a new edge into the AdjacencyList provided, based on 
 * a starting vertex (src), destination vertex (dest), and weight of the edge. 
 * 
 * The function should return SUCCESS or an error code. 
 * 
 * Remember to use myMalloc() to allocate memory instead of malloc(). 
 */
int addEdgeToAdjacencyList(AdjacencyList *pList, int src, int dest, int weight) //NEEDS TESTING - DOES IT NEED TO ADD IT TO THE MATRIX OR ANYTHING???
{
    //check all incoming parameters are valid, proceed if so
    //ensure all given values are valid
    if (pList == NULL || src < 0 || src >= NUMBER_OF_VERTICES || dest < 0 || dest >= NUMBER_OF_VERTICES){
        return INVALID_INPUT_PARAMETER;
    }else{
        //create newNode instance of ListNode and ensure memory is allocated correctly
        ListNode *newNode = (ListNode*)myMalloc(sizeof(ListNode)); 
        if (newNode == NULL){
            return MEMORY_ALLOCATION_ERROR;
        }
        //set fields to according values
        newNode->destNode = dest;
        newNode->weight = weight;
        newNode->next = pList->adjacencyList[src];
        pList->adjacencyList[src] = newNode;
        //return success
        return SUCCESS;
    }
}

/**
 * This function should populate the contents of an AdjacencyMatrix based on an
 * AdjacencyList representation of a graph. The matrix will be empty initially to
 * reflect a graph with no edges on it. The matrix can be populated by determining the
 * edges that exist in the Adjacency List that is provided, and transfer / copy those 
 * same edges over into the adjacency matrix too. After the function is called, our tester
 * can determine if the correct edges have been added into the Adjacency Matrix based
 * on the information that was provided to you.  
 * 
 * The function should return SUCCESS or an error code. 
 */
int populateAdjacencyMatrixFromAdjacencyList(AdjacencyMatrix *pMatrix, AdjacencyList *pList)
{   
    //check incoming inputs
    if (pMatrix == NULL || pList == NULL){
        return INVALID_INPUT_PARAMETER;
    }

    //for all rows in the stored list
    for (int i=0; i<NUMBER_OF_VERTICES; i++){
        //create a new iteration of listNode for the current place in the list
        ListNode *curr = pList->adjacencyList[i];

        //if there is something stored in this space in the list:
        while (curr != NULL){
            //ensure the held weight is greater than 0 and destNode is within parameters set - if not, return error message
            if (curr->weight > 0 || curr->destNode < NUMBER_OF_VERTICES || curr->destNode > 0){
                //add it to the matrix
                pMatrix->matrix[i][curr->destNode] = curr->weight;
                //set current to the next availiable point in the list
                curr = curr->next;
            }else{
                return INVALID_INPUT_PARAMETER;
            }
        }
    }
    return SUCCESS;
}