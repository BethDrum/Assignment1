/**
 * FILE: ADJ_LIST.H
 *
 * Contains definitions of data structures and functions related to the
 * implementation of an Adjacency List data structure
 *
 * NOTE: YOU DO NOT NEED TO MODIFY THIS FILE. IT CAN BE USED AS-IS.
 * THE CODE THAT YOU IMPLEMENT WILL BE IN THE ADJ_LIST.C FILE.
 */

#ifndef __ADJ_LIST_HEADER__ // this is a 'guard' on the header file, to prevent it's contents from
#define __ADJ_LIST_HEADER__ // being redefined more than once during the build process

/** 
 * ### INCLUDES
 */
#include "core_definitions.h"   // for access to common values, constants, etc.

struct AdjacencyMatrix;         // advance declaration of the adjaceny matrix struct which is used in one of the functions below
                                // we are just reassuring C that the struct exists
                                // the full #include / definition of the struct will be resolved during compilation later


/** ### DATA STRUCTURES ### */

/* typedef for a list node in an Adjacency List.
 * For node X on a graph, it records details of any directly
 * adjacent destination on the graph which has an edge emanating towards
 * it from node X, such as the ID / index of the destination node and the
 * weight of the edge that leads to it from node X.
 *
 * Each list node may refer / point to another list node after it.
 * This represents the case, for example, where node X has several
 * directly adjacency destinations emanating from it, and these have
 * to be listed, one after another in a connected fashion. 
 */
/* DO NOT MODIFY */
typedef struct listnode {
	int destNode;
	int weight;
	struct listnode *next;
} ListNode;

/* typedef for the Adjacency List itself
 * It contains an array of pointers to list nodes. Effectively, a series
 * of mini-linked lists, each one corresponding to a node on the graph,
 * and each one recording any of the adjacent destinations from each
 * node on the graph. If there are no edges emanating from a given node
 * on the graph, the relevant list entry will be empty / NULL. Otherwise,
 * one or more ListNodes may be present, representing the different edges
 * emanating from a given node.
 */
/* DO NOT MODIFY */
typedef struct adjacency_list {
	ListNode* adjacencyList[NUMBER_OF_VERTICES];
} AdjacencyList;


/** ### FUNCTION DECLARATIONS ### */
/*  DO NOT MODIFY FUNCTION NAMES, RETURN TYPES, OR INPUT PARAMETERS.
 *  YOU WILL IMPLEMENT THESE FUNCTIONS IN THE SEPARATE ADJ_LIST.C.C FILE.
 */

/**
 * This function should add a new edge into the AdjacencyList provided, based on 
 * a starting vertex (src), destination vertex (dest), and weight of the edge. 
 * 
 * The function should return SUCCESS or an error code. 
 * 
 * Remember to use myMalloc() to allocate memory instead of malloc(). 
 */
int addEdgeToAdjacencyList(AdjacencyList *pList, int src, int dest, int weight);

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
 * 
 */
int populateAdjacencyMatrixFromAdjacencyList(AdjacencyMatrix *pMatrix, AdjacencyList *pList);


#endif
