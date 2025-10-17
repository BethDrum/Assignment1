/**
 * FILE: DIJKSTRA.H
 *
 * Contains definitions of data structures and functions relevant to Dijkstra's algorithm
 *
 * NOTE: YOU DO NOT NEED TO MODIFY THIS FILE. IT CAN BE USED AS-IS.
 * THE CODE THAT YOU IMPLEMENT WILL BE IN THE DIJKSTRA.C FILE.
 */

#ifndef __DIJKSTRA_HEADER__ // this is a 'guard' on the header file, to prevent it's contents from
#define __DIJKSTRA_HEADER__ // being redefined more than once during the build process

/** 
 * ### INCLUDES
 */
#include "core_definitions.h"   // for access to common values, constants, etc.
#include <stdbool.h>            // required, defines the 'bool' data type in C

struct AdjacencyMatrix;         // advance declaration of the adjaceny matrix struct which is used in one of the functions below
                                // we are just reassuring C that the struct exists
                                // the full #include / definition of the struct will be resolved during compilation later

/** ### DATA STRUCTURES ### */

/* typedef for one of the rows / entries in a Dijkstra Table.
 * For a corresponding node in a graph, each table entry will record whether 
 * that node has been visited, the shortest cumulative distance found
 * so far to that node from a given starting point on the graph, and any 
 * predecessor node that led us this node on its shortest path
 */
/* DO NOT MODIFY */
typedef struct dijkstra_table_entry {
    bool visited;
    int distance;
    int predecessor;
} DijkstraTableEntry; 

/* typedef for the actual Dijkstra Table itself
 * It contains an array of Dijkstra Table entries as one of its fields.
 * There is an entry for each node on the graph where the entry at
 * array position 0 corresponds to node 0 on the graph, array position 1
 * corresponds to node 1 on the graph, and so on.
 */
/* DO NOT MODIFY */
typedef struct dijkstra_table {
    DijkstraTableEntry table[NUMBER_OF_VERTICES];
} DijkstraTable;


/** ### FUNCTION DECLARATIONS ### */
/*  DO NOT MODIFY FUNCTION NAMES, RETURN TYPES, OR INPUT PARAMETERS.
 *  YOU WILL IMPLEMENT THESE FUNCTIONS IN THE SEPARATE DIJKSTRA.C FILE.
 */

/**
 * This function should perform the Dijkstra algorithm. It expects to receive a 
 * ready-made graph to work with in the form of an AdjacencyMatrix. It 
 * also expects to receive an empty DijkstraTable which will be pre-initialised and 
 * ready to use. It also expects to receive the starting node on the graph to commence 
 * the algorithm from. 
 * 
 * This function should implement the algorithm, running it on the graph 
 * provided and updating the DijkstraTable with the outcome. After the function 
 * is called, the DijkstraTable will be inspected to determine whether the 
 * algorithm has been completed successfully. 
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int runDijsktraAlgorithm(AdjacencyMatrix *pMatrix, DijkstraTable *pTable, int startNode);

/**
 * This function should determine the shortest path that exists on a graph 
 * from a given starting node (nodeFrom) to a given end node (nodeTo). 
 * The function expects to receive a pre-populated DijkstraTable which already 
 * contains the outcome of running the Dijkstra algorithm on a graph. It will 
 * also be provided with an array (pathFound) into which the shortest path should 
 * be recorded. The path should be recorded in reverse order; showing, from the 
 * end node, the predecessors that lead us there from the start node. 
 * For example, if the shortest path on graph from node 2 to node 8 was found 
 * to be 2 -> 4 -> 5 -> 8. The content that would be recorded in the ‘pathFound’ 
 * variable would be as follows: [8][5][4][2]. I.e., it shows the relevant nodes 
 * in the path, in reverse order. This includes the start and end node too. After the 
 * function is called, the 'pathFound' will be inspected to determine whether the 
 * algorithm has been completed successfully. 
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int getShortestPathFrom(DijkstraTable *pTable, int nodeFrom, int nodeTo, int pathFound[]);

#endif
