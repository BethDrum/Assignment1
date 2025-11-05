/**
 * FILE: ADJ_MATRIX.C
 * 
 * THIS FILE  CONTAINS EMPTY / DO-NOTHING IMPLEMENTATIONS
 * FOR THE FUNCTIONS REQUIRED FOR THE ADJACENCY MATRIX STRUCT. 
 *
 * DO NOT RENAME THESE FUNCTIONS OR CHANGE THEIR RETURN
 * TYPES OR INPUT PARAMETERS.
 *
 * YOU NEED TO COMPLETE THE IMPLEMENTATION OF THESE
 * FUNCTIONS. 
 *
 * THESE FUNCTIONS RECEIVE INPUT PARAMETERS THAT WILL
 * PROVIDE THEM WITH THE INFORMATION THEY REQUIRE. 
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
#include "my_malloc.h"          // gives access to memory allocation functions, including 'myMalloc'
#include <stdio.h>              // required for access to file input-output functions in C
#include "adj_matrix.h"         // required, to include the Adjacency Matrix data structures and function declarations
                                // that are being implemented in this file
#include <stdbool.h>            // required, to include the definition of the 
#include <string.h>             // allows for strtok later on
#include <stdlib.h>             // allows for atoi later on


/** #### FUNCTION IMPLEMENTATIONS ## */

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
AdjacencyMatrix* createAdjacencyMatrix(int defaultEdgeValue)
{

    //create the adjacency matrix - size of pre defined number of vertices
    AdjacencyMatrix *qMatrix = NULL;

    qMatrix = (AdjacencyMatrix*)myMalloc(sizeof(AdjacencyMatrix));
    //check dynamic memory allocation for errors
    if (qMatrix == NULL){
        return MEMORY_ALLOCATION_ERROR;
    }

    //initialise with default edge given
    for (int i=0; i<NUMBER_OF_VERTICES; i++){
        for (int j=0; j<NUMBER_OF_VERTICES; j++){
            qMatrix->matrix[i][j] = defaultEdgeValue;
        }
    }

    //return pointer to created Adjency Matrix
    return qMatrix;
}

/**
 * Add a new edge into an Adjacency Matrix using the details given
 * e.g., source node (src), destination node (dest), and weight
 * of the edge.
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int addEdge(AdjacencyMatrix *pMatrix, int src, int dest, int weight)
{
    //check inputs
    if (pMatrix == NULL || src < 0 || src >= NUMBER_OF_VERTICES || dest < 0 || dest >= NUMBER_OF_VERTICES || weight < 0){
        return INVALID_INPUT_PARAMETER;
    }else{
        //set the corresponding place in the adjancy matrix to = the weight 
        pMatrix->matrix[src][dest] = weight;
        return SUCCESS;
    }
}

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
int addEdges(AdjacencyMatrix *pMatrix, Edge edges[], int edgeNum)
{ 
    //check inputs
    if (pMatrix == NULL || edges == NULL || edgeNum < 0){
        return INVALID_INPUT_PARAMETER;
    }

    //initialise values
    int correct = 0;

    //for the number of the given edges
    for (int i = 0; i<edgeNum; i++){
        //check if the current edge is within bounds for dest, src are smaller than the given number of vertices. Also check that both of those & weight are all >=0 
        if ((edges[i].dest >= 0 && edges[i].dest < NUMBER_OF_VERTICES && edges[i].src >= 0 && edges[i].src < NUMBER_OF_VERTICES && edges[i].weight >=0)){
            //add edge to the array using addEdge
            int result = addEdge(pMatrix, edges[i].src, edges[i].dest, edges[i].weight);
            if (result == SUCCESS){
                //if adding the edge returns a success code, add 1 to the correct count
                correct++;
            }
        }
    }

    //according to the number added successfully, return a corresponding success/error code
        if (correct == edgeNum){
            return SUCCESS;
        }else if (correct == 0){
            return INVALID_INPUT_PARAMETER;
        }else{
            return PARTIAL_SUCCESS;
        }
}

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
 * The function should return SUCCESS or a relevant error code.
 * 
 */
int loadMatrixFromFile(AdjacencyMatrix *pMatrix, char filename[]){
    //check all incoming variables
    if (pMatrix == NULL || filename == NULL || filename[0] == '\0'){
        return INVALID_INPUT_PARAMETER;
    }
    
    //set up variables
    FILE *fp;
    char s[22];
    char ch = ' ';
    int sucess = 0;
    int row = 0;
    
    //open the file
    fp = fopen(filename, "r");
    //if the file has opened correctly;
    if (fp !=NULL){
        //while the line read in is not NULL;
        while (fgets(s, 22, fp) != NULL){
            //split by the space
            char *token = strtok(s, " ");
            //for the length of the vertice
            for (int j=0; j<(NUMBER_OF_VERTICES*2)-1; j++){
                //assign that space in the matrix to the read in value
                pMatrix->matrix[row][j]= atoi(token);
                //if the token does not return NULL, add to sucess tracker
                if (token != NULL){
                    sucess++;
                }
                //gather new token for next iteration
                token = strtok(NULL, " ");
            }
            //add to the row
            row++;
        }
    }else{
        //close the file and return error if failure to read in file
        fclose(fp);
        return FILE_IO_ERROR;
    }

    //close the file
    fclose(fp);

    //check if the file was read in successfully using sucess check gathered throughout
    if (sucess == NUMBER_OF_VERTICES * NUMBER_OF_VERTICES){
        return SUCCESS;
    }else{
        return FILE_IO_ERROR;
    }
}


int doDepthFirstTraversal(AdjacencyMatrix *pMatrix, int startingNode, int traversalOutput[]){ 
    //check all incoming variables
    if (pMatrix == NULL || startingNode < 0 || startingNode > NUMBER_OF_VERTICES || traversalOutput == NULL){
        return INVALID_INPUT_PARAMETER;
    }
    
    //set all variables
    int currentNode = startingNode;
    bool visited[NUMBER_OF_VERTICES];
    int stack[NUMBER_OF_VERTICES];
    int top = -1;
    int outTrack = 1;
    traversalOutput[0] = currentNode;

    //initialise stack & visited to 0/false for all positions in their array
    for (int k=0; k<NUMBER_OF_VERTICES; k++){
        stack[k] = 0;
        visited[k] = false;
    }
    //set current node visited to true as this is our starting point
    visited[currentNode] = true;

    //go to next unvisited node
    for (int i=0; i<NUMBER_OF_VERTICES; i++){
        for (int j=0; j<NUMBER_OF_VERTICES; j++){
            //ensure the current edge is present and has not been visited
            if (pMatrix->matrix[currentNode][j] > 0 && visited[j] == false){
                //'push' the current node onto the stack
                top ++;
                stack[top] = currentNode;
                
                //move to the next node using j and set visited to true
                currentNode = j;
                visited[j] = true;

                //record the traversal
                traversalOutput[outTrack] = currentNode;

                //restart j loop
                j = -1;
            }
        }

        //while more left in the 'stack'
        if (top >= 0){
            //s'pop' from the stack to backtrack if needed before continuing 
            currentNode = stack[top];
            top--;
        }else{
            //the stack is empty so it can now exit
            break;
        }
    }
    return SUCCESS;
}