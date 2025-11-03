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
int runDijsktraAlgorithm(AdjacencyMatrix *pMatrix, DijkstraTable *pTable, int startNode) //it never stops. maybe change the while?? or add a run counter and stop once max runs found??
{
    //int distance[NUMBER_OF_VERTICES];
    //distance[currentNode] = 0;
    //bool visited[NUMBER_OF_VERTICES] = false;
    //bool visited[currentNode] = true;
    //.... pointer fix


    int currentNode = startNode;
    pTable->table[currentNode].distance = 0;
    pTable->table[currentNode].visited = true;
    bool firstRun = true;
    int currentDistance = 0;

    while (true){
        //for all nodes
        pTable->table[currentNode].visited = true;

        //update table distance
        for (int i = 0; i< NUMBER_OF_VERTICES; i++){
            int newDist = pTable->table[currentNode].distance + pMatrix->matrix[currentNode][i];
            //need more for calcualted distance
            if (newDist > 0 && pTable->table[i].visited == false){
                pTable->table[i].distance = newDist;
                pTable->table[i].predecessor = currentNode;
            }
        }


        //to find the shortest distance to a unvisited node
        //set next node variables to be empty
        int currentNode = -1;
        for (int i=0; i<NUMBER_OF_VERTICES; i++){
            //initialise variables
            int dist = -1;
            //navigate to next edge in the matrix
            //for (int j=0; j<NUMBER_OF_VERTICES; j++){
                //seperate the && to the ||??
            if (pTable->table[i].visited == false){
                if (currentNode == -1 || pTable->table[i].distance < pTable->table[currentNode].distance){
                    currentNode = i;
                }
            }
        }

        //check if there are any nodes left
        if(currentNode == -1){
        //return SUCCESS;
        break;
        }
        printf("ran");
    }
            //}else{
              //  firstRun = false;
            //}
            //return success if there are no nodes left


            /*
            for(int j=0; j<NUMBER_OF_VERTICES; j++){
                //check if node has been visited and find the shortest out of those not

                if (pTable->table[j].visited == false && pTable->table[j].distance < currentDistance){
                    currentNode = j;
                }
            }
        //go through adjency matrix to find non-sero edges for this node
        for (int i=0; i<NUMBER_OF_VERTICES; i++){
            //check if the node has a edge here or not and ensure edge hasnt been visited
            if (pMatrix->matrix[currentNode][i] > 0 && pTable->table[i].visited == false){//theres a or 1/0 in the guide here - check??
                //calcualte distance
                int totalDistance = pTable->table[currentNode].distance + pMatrix->matrix[currentNode][i];
                //if the distance is smaller, replace current stored
                if (pTable->table[i].distance > totalDistance){
                    pTable->table[i].distance = totalDistance;
                }
            }
        }
        }
        firstRun = false;
        //set node to visited
        pTable->table[currentNode].visited = true; 
        */
    }







    //navigate to the row of the start node
    //for size of a row
  //  for (int i=0; i<sizeof(NUMBER_OF_VERTICES); i++){
    //    currentW = pMatrix->matrix[startNode][0];
        //if startnode is less than previous then:
        //go through all places in that row to find the smallest number (thats not 0)
      //  if (pMatrix->matrix[startNode][i] != 0 && pMatrix->matrix[startNode][i] > currentW){
        //    currentW = pMatrix->matrix[startNode][i];
          //  place = i;
        //}
    //}
    //return place;
    //WHAT IF THERE IS 2 THE SAME DISTANCE
    //return that place in the table (?)



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
int getShortestPathFrom(DijkstraTable *pTable, int nodeFrom, int nodeTo, int pathFound[])
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    (void)pTable;
    (void)nodeFrom;
    (void)nodeTo;
    (void)pathFound;

    // returning NOT_IMPLEMENTED until your own implementation provided
    return NOT_IMPLEMENTED;
}