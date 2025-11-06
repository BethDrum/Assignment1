/**
 * FILE: DIJKSTRA.C
 * 
 * THIS FILE  CONTAINS EMPTY / DO-NOTHING IMPLEMENTATIONS
 * FOR THE FUNCTIONS REQUIRED OF DIJKSTRA'S ALGORITHM 
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
#include <stddef.h>
#include "adj_matrix.h" // provides the definition of the 'Adjacency Matrix' struct which is required for one of the functions below
#include "dijkstra.h"   // provides the definition of structs and functions for the Dijkstra implementation
#include <stdio.h>        //used for testing

/** #### FUNCTION IMPLEMENTATIONS ## */

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
int runDijsktraAlgorithm(AdjacencyMatrix *pMatrix, DijkstraTable *pTable, int startNode){
    //check incoming variables
    if (pMatrix == NULL || pTable == NULL || startNode < 0 || startNode > NUMBER_OF_VERTICES){
        return INVALID_INPUT_PARAMETER;
    }
    
    //set initial variables
    int currentNode = startNode;
    pTable->table[currentNode].distance = 0;
    pTable->table[currentNode].visited = true;
    int newDist = 0;

    //first, add the shortest distance to the table for that node 
    //for all nodes
    for (int k=0; k<NUMBER_OF_VERTICES; k++){
        for (int i = 0; i< NUMBER_OF_VERTICES; i++){
            //error check to ensure the current weight is greater than 0
            if (pMatrix->matrix[currentNode][i] > 0){
                //calculate new distance to store
                newDist = pTable->table[currentNode].distance + pMatrix->matrix[currentNode][i];
                
                //ensure the distance is less than whats currently stored
                if (newDist < pTable->table[i].distance){
                    //assign new variables to dijsktra table
                    pTable->table[i].distance = newDist;
                    pTable->table[i].predecessor = currentNode;
                }
            }
        }

        //to get the next node to go to
        for (int j=0; j<NUMBER_OF_VERTICES; j++){
            //initialise variable
            int dist = -1;
            //check if the current edge has been visited
            if (pTable->table[j].visited == false){
                //set current node as visited in the dijskttra table and set currentNode to j
                pTable->table[currentNode].visited = true;    
                currentNode = j;
                //exit the loop
                break;
            }
        }
    }
    //return success to the main program
    return SUCCESS;
}

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
int getShortestPathFrom(DijkstraTable *pTable, int nodeFrom, int nodeTo, int pathFound[]){
    //check incoming parameters
    if (pTable == NULL || nodeFrom <= 0 || nodeFrom > NUMBER_OF_VERTICES || nodeTo <= 0 || nodeTo > NUMBER_OF_VERTICES || pathFound == NULL){
        return INVALID_INPUT_PARAMETER;
    }

    //initialise variables
    int startNode = nodeFrom;
    int endNode = nodeTo;
    int track = 0;
    pathFound[track] = endNode;
    track++;

    //for all nodes from end to start (also known as, backwards)
    for (int j = endNode-1; j>startNode; j--){
        //add path to given array
        pathFound[track] = pTable->table[j+1].predecessor;
        //add 1 to tracker - this ensures the pathFound array is added to correctly. 
        track++;
    }    
    //return success message
    return SUCCESS;
}