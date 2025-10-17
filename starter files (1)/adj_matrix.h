/**
 * FILE: ADJ_MATRIX.H
 *
 * Contains definitions of data structures and function declarations for an adjacency matrix
 * representation of a graph data structure
 *
 * NOTE: YOU DO NOT NEED TO MODIFY THIS FILE. IT CAN BE USED AS-IS. THE CODE THAT YOU IMPLEMENT 
 * WILL BE IN A SEPARATE FILE ADJ_MATRIX.C.
 */

#ifndef __ADJ_MATRIX_HEADER__ // this is a 'guard' on the header file, to prevent it's contents from
#define __ADJ_MATRIX_HEADER__ // being redefined more than once during the build process

/** 
 * ### INCLUDES
 */
#include "core_definitions.h"   // for access to common values, constants, etc.


/** ### DATA STRUCTURES ### */

/* typedef for an Adjacency Matrix. Contains a 2-D array
 * as one of its fields, which represents the matrix itself 
 * The number of vertices will correspond to the number of
 * nodes in the graph that you will be using.
 */
/* DO NOT MODIFY */
typedef struct adjacency_matrix {
	int matrix[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES];
} AdjacencyMatrix;

/* typedef for an Edge, to record details of an Edge on
 * a graph, e.g., start node (src), destination node (dest)
 * and the weight on the edge
 */
/* DO NOT MODIFY */
typedef struct edge {
	int src;
	int dest;
	int weight;
} Edge;

/** ### FUNCTION DECLARATIONS ### */
/*  DO NOT MODIFY FUNCTION NAMES, RETURN TYPES, OR INPUT PARAMETERS.
 *  YOU WILL IMPLEMENT THESE FUNCTIONS IN THE SEPARATE ADJ_MATRIX.C FILE.
 */

/**
 * Create a new, empty Adjacency Matrix, returning a pointer to the newly 
 * allocated matrix OR a value of NULL in the event of error. Ensure that 
 * the matrix is initialised to the defaultEdgeValue provided.
 * 
 * Remember to use myMalloc() to allocate memory instead of malloc(). 
 * In the event of memory allocation errors, return a value of NULL
 * for this function instead of the usual MEMORY_ALLOCATION_ERROR
 *
 */
AdjacencyMatrix* createAdjacencyMatrix(int defaultEdgeValue);

/**
 * Add a new edge into an Adjacency Matrix using the details given
 * e.g., source node (src), destination node (dest), and weight
 * of the edge.
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int addEdge(AdjacencyMatrix *pMatrix, int src, int dest, int weight);

/**
 * This function should add a collection of new edges into an 
 * AdjacencyMatrix using the input values given. In this case,
 * an array of Edges is provided, each one containing details of
 * a single Edge in the graph (src node, dest node, and weight).
 * 
 * You need to consider validation of the edges as you work your
 * way through them. The function should return SUCCESS if all
 * edges were processed successfully. It should return PARTIAL_SUCCESS
 * if only some of the edges were processed successfully. It should
 * return INVALID_INPUT_PARAMETER if all edges in the array were
 * found to be invalid. Your function should attempt to process all
 * edges before returning the result, ignoring any that are invalid,
 * but ensuring any valid edges are added to the graph successfully.
 * 
 */
int addEdges(AdjacencyMatrix *pMatrix, Edge edges[], int edgeNum);

/**
 * This function will receive the name of a file on disk which contains the 
 * data for a graph which has been stored in the form of an adjacency matrix. 
 * The function should read the content from the file and use it to populate 
 * the AdjacencyMatrix provided. The file will be formatted thus:
 * 
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 
 * I.e., assuming a graph with 10 vertices, this will require a 10 x 10 matrix.
 * 
 * Each line in the file represents the next row in matrix, indexed from 0 to 9.
 * 
 * Each line will record the weight of the relevant edge in the graph. This will
 * be a value of zero (no edge) or a value of greater than zero (signifying that
 * an edge does exist, and the weight of that edge).
 * 
 * You can assume that the file content will be valid and in the correct format 
 * too, so you do not need to check for this when reading in from the file. 
 * Other validations may be required in the function however.
 * 
 * The function should return SUCCESS or a relevant error code.
 * 
 */
int loadMatrixFromFile(AdjacencyMatrix *pMatrix, char filename[]);


/**
 * This function should conduct a depth-first traversal of a graph and record the traversal 
 * sequence into the array provided (traversalOutput). The function expects to receive the 
 * following inputs:
 * - A pointer to an Adjacency Matrix representing the graph to be traversed.
 * - The index of the starting node in the graph where the traversal should commence.
 * - An array which will be used to store the output of the traversal, i.e., the order in 
 *   which the traversal visited the nodes in the graph. The first item of the array will 
 *   record the starting node of the traversal (as per the input value 'startingNode' which is
 *   provided). Subsequent items in the array will reflect the nodes of the depth-first path 
 *   that are found beyond that, up to and including the final node that is visited
 * 
 * The function should return SUCCESS or a relevant error code.
 *
 */
int doDepthFirstTraversal(AdjacencyMatrix *pMatrix, int startingNode, int traversalOutput[]);

#endif
