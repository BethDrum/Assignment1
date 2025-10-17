#include "adj_matrix.h"
#include "adj_list.h"
#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>

// advance declaration of some test functions which are referred to below
void testCreateAdjacencyMatrix();
void initialiseMatrix(AdjacencyMatrix*);
void displayMatrix(AdjacencyMatrix*);
void testAddEdge();
void testAddEdges();
void testLoadMatrixFromFile();
void testDoDepthFirstTraversal();
void testRunDijsktraAlgorithm();
void testGetShortestPathFrom();
void testAddEdgeToAdjacencyList();
void displayAdjacencyList(AdjacencyList*);
void freeAdjacencyList(AdjacencyList*);
void testPopulateAdjacencyMatrixFromAdjacencyList();

/**
 * The main function. Run some tests.
 */
int main()
{
    printf("### TESTER FOR CS21003 ASSIGNMENT 1 - C PROGRAMMING ASSIGNMENT #####\n\n");

    // NOTE: COMMENT OUT ANY TESTS BELOW THAT YOU ARE NOT READY TO USE, E.G., UNTIL YOU
    // HAVE IMPLEMENTED THE CODE FOR THE RELEVANT FUNCTIONS THAT THEY RELATE TO 

    // method to test the createAdjacencyMatrix() function
    printf("## FIRST TEST : createAdjacencyMatrix() ##\n");
    testCreateAdjacencyMatrix();

    // test the addEdge() function, to add a single edge to a graph
    printf("\n## NEXT TEST : addEdge() ##\n");
    testAddEdge();

    // test the addEdges() function, to add a collection of Edges to a graph
    printf("\n## NEXT TEST : addEdges() ##\n");
    testAddEdges();

    // test the loadMatrixFromFile() function
    printf("\n## NEXT TEST : loadMatrixFromFile() ##\n");
    testLoadMatrixFromFile();

    // test the doDepthFirstTraversal() function
    printf("\n## NEXT TEST : doDepthFirstTraversal() ##\n");
    testDoDepthFirstTraversal();

    // test the runDijsktraAlgorithm() function
    printf("\n## NEXT TEST : runDijsktraAlgorithm() ##\n");
    testRunDijsktraAlgorithm();

    // test the getShortestPathFrom() function
    printf("\n## NEXT TEST : getShortestPathFrom() ##\n");
    testGetShortestPathFrom();

    // test the addEdgeToAdjacencyList() function
    printf("\n## NEXT TEST : addEdgeToAdjacencyList() ##\n");
    testAddEdgeToAdjacencyList();

    // test the populateAdjacencyMatrixFromAdjacencyList() function
    printf("\n## NEXT TEST : populateAdjacencyMatrixFromAdjacencyList() ##\n");
    testPopulateAdjacencyMatrixFromAdjacencyList();
}


// run tests on the 'createAdjacencyMatrix' function
void testCreateAdjacencyMatrix()
{    
    // A variable to store a pointer to an adjacency matrix that will created for us
    AdjacencyMatrix *pNewMatrix; 

    /** Call the function to create an adjacency matrix. A default value for all edges
      in the graph is expected as an input. Here, a default value of '3' is used for testing
      purposes although it would usually be a value of 0.
      The method itself will be implemented by you in the file 'adj_matrix.c'.
      When you compile all of your .c files together, the implementations will be found.
      This function will return a pointer to the newly created matrix, or a value of NULL
      if an error occurred.*/
    pNewMatrix = createAdjacencyMatrix(3); 

    // if the function returned a valid pointer to a newly created matrix
    if (pNewMatrix != NULL) {
        // go ahead and use the matrix for whatever is required.
        printf("\nTesting 'createAdjacencyMatrix()'. Matrix created successfully.\n");

        // E.g., we can check to see if the matrix was filled up correctly with the 
        // default edge value of '1'
        int numberOfCorrectEdgesFound = 0;
        int numberOfCorrectEdgesExpected = NUMBER_OF_VERTICES * NUMBER_OF_VERTICES;
        for (int i=0; i<NUMBER_OF_VERTICES; i++)
        {
            for (int j=0; j<NUMBER_OF_VERTICES; j++)
            {
                if (pNewMatrix->matrix[i][j] == 3)
                {
                    numberOfCorrectEdgesFound++;
                }
            }
        }

        if (numberOfCorrectEdgesFound == numberOfCorrectEdgesExpected)
        {
            printf("\nChecking if edges values in matrix have been initialised correctly: YES. They are.\n");

            // display the content of the matrix for verification purposes
            displayMatrix(pNewMatrix);
        }
        else 
        {
            printf("\nChecking if edges values in matrix have been initialised correctly: NO. They are not.\n");
        }

        // free memory that was allocated for the matrix
        free(pNewMatrix);

    }
    else
    {
        // an error occurred when creating the matrix, or something else might have failed - check the code
        printf("\nTesting 'createAdjacencyMatrix()'. Failed to create matrix.\n");
    }
}

// run tests on the 'addEdge' function
void testAddEdge()
{
    // start with an empty adjacency matrix
    AdjacencyMatrix matrix;

    // initialise the matrix to empty values
    initialiseMatrix(&matrix);

    // we want to add an edge from node 2 to node 4 with a weight of 6
    // call method to add an edge to the matrix, providing it with a
    // pointer to (the memory address) of the matrix to use, and the edge values
    // the function will return a result which will be one of the SUCCESS or error codes
    int result = addEdge(&matrix, 2, 4, 6);

    // if method returned SUCCESS (where SUCCESS is one of the codes defined in 'core_definitions.h')
    if (result == SUCCESS)    
    {
        printf("\nTesting 'addEdge()'. Function reports SUCCESS.\n");

        // check if the edge was added successfully, it should be a matrix location [2][4]
        printf("\nChecking if edge was correctly added as expected: ");
        if (matrix.matrix[2][4] == 6)
        {
            printf("YES. Correct.\n");

            // display the content of the matrix for verification purposes
            displayMatrix(&matrix);
        }
        else
        {
            printf("NO. Incorrect.\n");
        }
    }
    else
    {
        printf("\nTesting 'addEdge()'. Function did NOT report SUCCESS.\n");
        // you can check what (error) code it may have returned instead
    }

    // CONSIDER THE FOLLOWING: WHAT IF YOU PROVIDE AN INVALID INPUT TO THE addEdge() FUNCTION?
    // AN INVALID POINTER TO A MATRIX: addEdge(NULL, 2, 4, 6);
    // AN INVALID EDGE VALUE? E.g., to a non-existent node on the graph which only has up to 
    // NUMBER_OF_VERTICES nodes in it?: addEdge(&matrix, 900, -232323, 4545);
}

// run tests on the 'addEdges' function
void testAddEdges()
{
    // start with an empty adjacency matrix (ideally, this should have all of its content initialised to a default value, but we can forego that here)
    AdjacencyMatrix matrix;

    // initialise the matrix to empty values
    initialiseMatrix(&matrix);

    // create an array of 3  edges (3 'Edge' structs) to represent Edges to add to the graph
    Edge edges[3] = {  { 2, 4, 7 }, // an edge from node 2 to node 4 with a weight of 7
                       { 1, 5, 2 }, // an edge from node 1 to node 5 with a weight of 2
                       { 3, 1, 4 }  // an edge from node 3 to node 1 with a weight of 4
                    };

    // call method to add the array of edges to the matrix, providing it with a
    // pointer to (the memory address) of the matrix to use, the array of edges, and the
    // number of edges in the array
    // the function will return a result which will be one of the SUCCESS or error codes
    int result = addEdges(&matrix, edges, 3);

    // if method returned SUCCESS
    if (result == SUCCESS)    
    {
        printf("\nTesting 'addEdges()'. Function reports SUCCESS.\n");

        // check if the edges were added successfully
        printf("\nChecking if three edges were correctly added as expected: ");
        if ((matrix.matrix[2][4] == 7) && (matrix.matrix[1][5] == 2) && (matrix.matrix[3][1] == 4))
        {
            printf("YES. Correct.\n");

            // display the content of the matrix for verification purposes
            displayMatrix(&matrix);
        }
        else
        {
            printf("No. Incorrect.\n");
        }
    }
    else
    {
        printf("\nTesting 'addEdges()'. Function did NOT report SUCCESS.\n");
        // you can check what (error) code it may have returned instead
    }

    /* ADDITIONAL TEST - WHAT IF ONE OF THE EDGES IN THE ARRAY IS INVALID, BUT OTHERS ARE OK?
       THE FUNCTION SHOULD PROCESS AS MANY EDGES AS IT CAN AND RETURN A RESULT OF 'PARTIAL_SUCCESS'.
       TRY THIS NOW */

    /* UNCOMMENT THIS CODE IF / WHEN YOU WANT TO USE IT 
    // create another, fresh, empty adjacency matrix to use
    AdjacencyMatrix matrix2;
    
    // create a second array of 3 edges where one of them refers to an invalid / non-existent node in the graph
    Edge edgesWithOneInvalid[3] = {  { 2, 4, 7 }, // an edge from node 2 to node 4 with a weight of 7
                                     { 67756757, 5, 2 }, // an edge from INVALID NODE 67756757 to node 5 with a weight of 2
                                     { 3, 1, 4 }  // an edge from node 3 to node 1 with a weight of 4
                                  };

    // call the addEdges function again with the fresh matrix and new array of edges
    result = addEdges(&matrix2, edgesWithOneInvalid, 3);

    // if method returned PARTIAL_SUCCESS
    if (result == PARTIAL_SUCCESS)    
    {
        // good this is what we expected
        printf("\nTesting 'addEdges()'. Function reports PARTIAL_SUCCESS as expected.\n");

        // check if the two valid edges were still added correctly to the graph
        if ((matrix.matrix[2][4] == 7) && (matrix.matrix[3][1] == 4))
        {
            printf("\nTesting 'addEdges()'. Two valid edges were still added to the graph as expected.\n");
        }
        else
        {
            printf("\nTesting 'addEdges()'. Two valid edges were NOT added to the graph as expected.\n");
        }
    }
    else
    {
        printf("\nTesting 'addEdges()'. Function does NOT report PARTIAL_SUCCESS as expected.\n");
    }
    */
}

// run tests on the 'loadMatrixFromFile' function
void testLoadMatrixFromFile()
{
    // start with an empty adjacency matrix 
    AdjacencyMatrix matrix;

    // call method to load a matrix from a file, providing it with a pointer to (the memory address) of 
    // the matrix to load the file content into and the name of the file to read from.
    // In this case, using the test file that is provided to you 'adjacency_matrix.txt'
    // the function will return a result which will be one of the SUCCESS or error codes
    int result = loadMatrixFromFile(&matrix, "adjacency_matrix.txt");

    // if method returned SUCCESS
    if (result == SUCCESS)    
    {
        printf("\nTesting 'loadMatrixFromFile()'. Function reports SUCCESS.\n");

        // the file 'adjacency_matrix.txt' contains the following edges:
        // src->dest {weight}
        // 0->1 {7}
        // 0->3 {2}
        // 1->0 {7}
        // 1->2 {4}
        // 1->3 {8}
        // 2->1 {4}
        // 2->3 {1}
        // 3->0 {2}
        // 3->1 {8}
        // 3->2 {1}

        // check if the edges were loaded successfully
        printf("\nChecking if content of matrix was loaded correctly from the file: ");
        if ((matrix.matrix[0][1] == 7) && (matrix.matrix[0][3] == 2) && (matrix.matrix[1][0] == 7) && (matrix.matrix[1][2] == 4) && (matrix.matrix[1][3] == 8)
                                       && (matrix.matrix[2][1] == 4) && (matrix.matrix[2][3] == 1) && (matrix.matrix[3][0] == 2) && (matrix.matrix[3][1] == 8)
                                       && (matrix.matrix[3][2] == 1))
        {
            printf("YES. Correct.\n");

            // display the content of the matrix for verification purposes
            displayMatrix(&matrix);
        }
        else
        {
            printf("NO. Incorrect.\n");
        }
    }
    else
    {
        printf("\nTesting 'loadMatrixFromFile()'. Function did NOT report SUCCESS.\n");
        // you can check what (error) code it may have returned instead
    }
}

// run tests on the 'doDepthFirstTraversal' function
void testDoDepthFirstTraversal()
{
    // start with an empty adjacency matrix
    AdjacencyMatrix matrix;

    // initialise the matrix to empty values
    initialiseMatrix(&matrix);

    // add edges to the matrix that will correspond to an example graph that we want to traverse
    // in this case, see the accompanying file 'depth-first-graph.png' which shows the graph being used here, 
    // which has 5 edges in total
    matrix.matrix[3][1] = 2; // an edge from node 3 to node 1 with a weight of 2
    matrix.matrix[1][2] = 5; // an edge from node 1 to node 2 with a weight of 5
    matrix.matrix[3][5] = 1; // an edge from node 3 to node 5 with a weight of 4
    matrix.matrix[3][7] = 3; // an edge from node 3 to node 7 with a weight of 3
    matrix.matrix[5][8] = 2; // an edge from node 5 to node 8 with a weight of 2

    // create an array that will store the output of the traversal, this will correspond to the 
    // number of nodes in the graph. Initialise ALL elements in the array to -1 because this is what
    // the function we are going to call excpects to start with
    int traversalOutput[NUMBER_OF_VERTICES];
    for (int i=0; i<NUMBER_OF_VERTICES; i++) 
        traversalOutput[i] = -1;

    // the starting node for the traversal is going to be node '3' on the graph.
    int startNode = 3;

    // a depth first traversal from node 3 should result in the following path: 3 1 2 5 8 7, meaning the expected
    // result in the traversalOutput[] would be: [3][1][2][5][8][7][-1][-1][-1][-1]

    // call method to do the depth-first traversal, providing it with a pointer to (the memory address) of 
    // the matrix to conduct the traversal on, the node to start the traversal from, and the traversalOutput[]
    // array which will be populated with the depth-first path that is found.
    // the function will return a result which will be one of the SUCCESS or error codes
    int result = doDepthFirstTraversal(&matrix, startNode, traversalOutput);
    
    // if function returned success
    if (result == SUCCESS)    
    {
        printf("\nTesting 'doDepthFirstTraversal()'. Function reports SUCCESS.\n");

        // check if the depth-first path is correct
        printf("\nChecking if the depth-first path is correct: ");
        if ((traversalOutput[0] == 3) && (traversalOutput[1] == 1) && (traversalOutput[2] == 2) && (traversalOutput[3] == 5) && (traversalOutput[4] == 8)
                                      && (traversalOutput[5] == 7) && (traversalOutput[6] == -1) && (traversalOutput[7] == -1) && (traversalOutput[8] == -1) 
                                      && (traversalOutput[9] == -1))
        {
            printf("YES. Correct.\n");

            // display the depth first traversal found
            printf("\nDisplaying depth-first path found for verification:\n");
            for (int i=0; i<NUMBER_OF_VERTICES; i++)
            {
                printf("[%d]", traversalOutput[i]);
            }
            printf("\n");
        }
        else
        {
            printf("NO. Incorrect.\n");
        }
    }
    else
    {
        printf("\nTesting 'doDepthFirstTraversal()'. Function did NOT report SUCCESS.\n");
        // you can check what (error) code it may have returned instead
    }

}

// run tests on the runDijsktraAlgorithm() function
void testRunDijsktraAlgorithm()
{ 
    // start with an empty adjacency matrix
    AdjacencyMatrix matrix;

    // initialise the matrix to empty values
    initialiseMatrix(&matrix);

    // add edges to the matrix that will correspond to an example graph that we want to traverse
    // in this case, see the accompanying file 'dijkstra-algorithm-graph.png' which shows the graph being used here, 
    // which has 4 nodes in the graph and 10 undirected edges between them in total
    matrix.matrix[0][1] = 7;
    matrix.matrix[0][3] = 2;
    matrix.matrix[1][0] = 7;
    matrix.matrix[1][2] = 4;
    matrix.matrix[1][3] = 8;
    matrix.matrix[2][1] = 4;
    matrix.matrix[2][3] = 1;
    matrix.matrix[3][0] = 2;
    matrix.matrix[3][1] = 8;
    matrix.matrix[3][2] = 1;

    // create an empty DijkstraTable. This will be used to store the result of running dijkstra's algorithm
    DijkstraTable dijkstraTable;

    // initialise the dijkstra table to default values prior to running the algorithm
    for (int i=0; i<NUMBER_OF_VERTICES; i++)
    {
        dijkstraTable.table[i].visited = false;
        dijkstraTable.table[i].distance = VERY_LARGE_NUMBER;
        dijkstraTable.table[i].predecessor = -1;
    }

    // call method to run dijkstra's algorithm traversal, providing it with a pointer to (the memory address) of 
    // the matrix to conduct the algorithm on, a pointer to the dijkstra table that should be populated with the
    // outcome of the algorithm, and the index of the node in the graph which represents the starting point of the 
    // algorithm - the algorithm will find the shortest path from the starting node to every other node in the graph.
    // the function will return a result which will be one of the SUCCESS or error codes
    int result = runDijsktraAlgorithm(&matrix, &dijkstraTable, 3);

    // if function returned success
    if (result == SUCCESS)    
    {
        printf("\nTesting 'runDijsktraAlgorithm()'. Function reports SUCCESS.\n");

        // if the algorithm worked correctly, the content of the Dijkstra Table should be as below
        // Node Visited Distance Predecessor
        //   0   true      2         3
        //   1   true      5         2
        //   2   true      1         3
        //   3   true      0        -1
        //
        // Explaining the above:
        // - Node 3 is the starting node from which we are trying to find the shortest paths 
        //   to every other node in the graph.
        // - The shortest distance from Node 3 to Node 0 is '2' which is going direct from Node 3 to Node 1
        // - The shortest distance from Node 3 to Node 1 is '5' which is going indirectly from Node 3 via Node 2 to Node 1
        // - The shortest distance from Node 3 to Node 2 is '1' which is going direct from Node 3 to Node 2
        // - The shortest distance from Node 3 to Node 3 is '0' and there is no predecessor required to get there

        // display the dijkstra table to show what it contains
        printf("\nDisplaying the dijkstra table that was received from the function:\n");
        printf("Node\tDist\tPred\n");
        for (int i=0; i<NUMBER_OF_VERTICES; i++)
        {
            printf("%d\t%d\t%d\n", i, dijkstraTable.table[i].distance, dijkstraTable.table[i].predecessor);
        }
        printf("\n");

        // check whether the table contains the expected results
        printf("Doing checks on the table:\n");
        printf("Row 0 of Dijkstra Table should be: Visited, Distance=2, Predecessor=3: ");
        if ((dijkstraTable.table[0].visited == true) && (dijkstraTable.table[0].distance == 2)
            && (dijkstraTable.table[0].predecessor == 3))
            printf("PASS\n"); 
        else
            printf("FAIL\n");
        printf("Row 1 of Dijkstra Table should be: Visited, Distance=5, Predecessor=2: ");
        if ((dijkstraTable.table[1].visited == true) && (dijkstraTable.table[1].distance == 5)
            && (dijkstraTable.table[1].predecessor == 2))
            printf("PASS\n"); 
        else
            printf("FAIL\n");
        printf("Row 2 of Dijkstra Table should be: Visited, Distance=1, Predecessor=3: ");
        if ((dijkstraTable.table[2].visited == true) && (dijkstraTable.table[2].distance == 1)
            && (dijkstraTable.table[2].predecessor == 3))
            printf("PASS\n"); 
        else
            printf("FAIL\n");
        printf("Row 3 of Dijkstra Table should be: Visited, Distance=0, Predecessor=-1: ");
        if ((dijkstraTable.table[3].visited == true) && (dijkstraTable.table[3].distance == 0)
            && (dijkstraTable.table[3].predecessor == -1))
            printf("PASS\n"); 
        else
            printf("FAIL\n");
    }
    else
    {
        printf("\nTesting 'runDijsktraAlgorithm()'. Function did NOT report SUCCESS.\n");
        // you can check what (error) code it may have returned instead
    }
}

// run tests on the getShortestPathFrom() function
void testGetShortestPathFrom()
{
    // create an empty DijkstraTable. This will be used to store the result of running dijkstra's algorithm
    DijkstraTable dijkstraTable;

    // initialise the dijkstra table to default values prior to running the algorithm
    for (int i=0; i<NUMBER_OF_VERTICES; i++)
    {
        dijkstraTable.table[i].visited = false;
        dijkstraTable.table[i].distance = VERY_LARGE_NUMBER;
        dijkstraTable.table[i].predecessor = -1;
    }

    // manually populate the dijkstra table to record the outcome of running the
    // algorithm on a graph. We will use the graph which is shown in the file
    // 'find-shortest-path-to-graph.png' which has 6 nodes and 8 directed edges in it
    // The result of running dijkstra's algorithm on this would have been as follows:
    // Node Visited Distance Predecessor
    //   0   true      0         -1
    //   1   true      10         0
    //   2   true      15         0
    //   3   true      22         1
    //   4   true      24         3
    //   5   true      23         3
    //
    // Explaining the above:
    // - Node 0 was the starting node from which we are trying to find the shortest paths 
    //   to every other node in the graph.
    // - The shortest distance from Node 0 to Node 0 is '0' and there is no predecessor required to get there
    // - The shortest distance from Node 0 to Node 1 is '10' which is going direct from Node 0 to Node 1
    // - The shortest distance from Node 0 to Node 2 is '15' which is going direct from Node 0 to Node 2
    // - The shortest distance from Node 0 to Node 3 is '22' which is going indirectly from Node 0 via Node 1 to Node 3
    // - The shortest distance from Node 0 to Node 4 is '24' which is going indirectly from Node 0 via Node 1 via Node 3 to Node 4
    // - The shortest distance from Node 0 to Node 5 is '23' which is going indirectly from Node 0 via Node 1 via Node 3 to Node 5

    // manually populate the dijkstra table to reflect the above
    dijkstraTable.table[0].visited = true;
    dijkstraTable.table[0].distance = 0;
    dijkstraTable.table[1].visited = true;
    dijkstraTable.table[1].distance = 10;
    dijkstraTable.table[1].predecessor = 0;
    dijkstraTable.table[2].visited = true;
    dijkstraTable.table[2].distance = 15;
    dijkstraTable.table[2].predecessor = 0;
    dijkstraTable.table[3].visited = true;
    dijkstraTable.table[3].distance = 22;
    dijkstraTable.table[3].predecessor = 1;
    dijkstraTable.table[4].visited = true;
    dijkstraTable.table[4].distance = 24;
    dijkstraTable.table[4].predecessor = 3;
    dijkstraTable.table[5].visited = true;
    dijkstraTable.table[5].distance = 23;
    dijkstraTable.table[5].predecessor = 3;

    // create an array that will store the path found. Initialise ALL elements in the array 
    // to -1 because this is what the function we are going to call excpects to start with
    int pathFound[NUMBER_OF_VERTICES];
    for (int i=0; i<NUMBER_OF_VERTICES; i++) 
        pathFound[i] = -1;

    // call method to find the path being sought based on the outcome of dijkstra's algorithm, providing it with a pointer 
    // to (the memory address) of the dijkstra table that contains the outcome of running dijkstra's algorithm, the start node
    // on the graph where the path begins, the destination node on the graph where the path leads to, and an array which will
    // be used to receive the path found IN REVERSE ORDER, e.g., from the destination back to the start. In this case, the start
    // node is 0 and the destination node is 4
    // the function will return a result which will be one of the SUCCESS or error codes
    int result = getShortestPathFrom(&dijkstraTable, 0, 4, pathFound);

    // if function returned success
    if (result == SUCCESS)    
    {
        printf("\nTesting 'getShortestPathFrom()'. Function reports SUCCESS.\n");

        // the shortest path from node 0 to node 4 would have been as follows: 0 -> 1 -> 3 -> 4
        // therefore, the content of the 'pathFound' array which records the path in REVERSE order
        // would be as follows, where '-1' represents array elements that weren't needed / written to
        //
        // pathFound = [4][3][1][0][-1][-1][-1][-1][-1][-1]
        
        // display the path found to see what it contains
        printf("\nDisplaying the shortest path that was received when calling the function:\n");
        for (int i=0; i<NUMBER_OF_VERTICES; i++)
        {
            printf("[%d]", pathFound[i]);
        }
        printf("\n");

        // check if the path found is correct
        printf("\nChecking if the path found is correct: ");
        if ((pathFound[0] == 4) && (pathFound[1] == 3) && (pathFound[2] == 1) && (pathFound[3] == 0))
        {
            printf("YES. Correct.\n");
        }
        else
        {
            printf("NO. Incorrect.\n");
        }
    }
    else
    {
        printf("\nTesting 'getShortestPathFrom()'. Function did NOT report SUCCESS.\n");
        // you can check what (error) code it may have returned instead
    }
}

// run tests on the addEdgeToAdjacencyList() function
void testAddEdgeToAdjacencyList()
{
    // create an Adjacency list struct
    AdjacencyList adjList;

    // initialise the content of the list to be empty
    // (it is an array of linked lists, each list will
    //  be empty, meaning the first / head item in each
    //  list will be NULL)
    for (int i=0; i<NUMBER_OF_VERTICES; i++)
        adjList.adjacencyList[i] = NULL;

    // call method to add an edge to the adjacency list, providing it with a pointer to (the memory address) of the adjacency list
    // to add the edge into, the start node where the edge commences, the destination node where the edge leads to, and the
    // weight of the edge.
    // let's try adding multiple edges:
    printf("\nTesting 'addEdgeToAdjacencyList()'.\n");
    printf("\nAdding edges to list...\n");
    addEdgeToAdjacencyList(&adjList, 2, 3, 8); // an edge from node 2 to node 3 with a weight of 8
    addEdgeToAdjacencyList(&adjList, 5, 1, 3); // an edge from node 5 to node 1 with a weight of 3
    addEdgeToAdjacencyList(&adjList, 2, 6, 5); // an edge from node 2 to node 6 with a weight of 5
    addEdgeToAdjacencyList(&adjList, 0, 2, 6); // an edge from node 0 to node 2 with a weight of 6

    // display list so we can see what's in it
    displayAdjacencyList(&adjList);

    printf("\nChecking if content of AdjacencyList is correct as expected: ");
    if ((adjList.adjacencyList[0] != NULL) && (adjList.adjacencyList[0]->destNode == 2) && (adjList.adjacencyList[0]->weight == 6) && (adjList.adjacencyList[0]->next == NULL)
        && (adjList.adjacencyList[1] == NULL)
        && (adjList.adjacencyList[2] != NULL) && (adjList.adjacencyList[2]->destNode == 6) && (adjList.adjacencyList[2]->weight == 5) && (adjList.adjacencyList[2]->next != NULL)
                                              && (adjList.adjacencyList[2]->next->destNode == 3) && (adjList.adjacencyList[2]->next->weight == 8) && (adjList.adjacencyList[2]->next->next == NULL)
        && (adjList.adjacencyList[3] == NULL)
        && (adjList.adjacencyList[4] == NULL)
        && (adjList.adjacencyList[5] != NULL) && (adjList.adjacencyList[5]->destNode == 1) && (adjList.adjacencyList[5]->weight == 3) && (adjList.adjacencyList[5]->next == NULL)
        && (adjList.adjacencyList[6] == NULL)
        && (adjList.adjacencyList[7] == NULL)
        && (adjList.adjacencyList[8] == NULL)
        && (adjList.adjacencyList[9] == NULL))
        printf("YES\n"); 
    else
        printf("NO\n");

    // free up the adjaceny list after use
    freeAdjacencyList(&adjList);
}

// run tests on the populateAdjacencyMatrixFromAdjacencyList() function
void testPopulateAdjacencyMatrixFromAdjacencyList()
{
    // NOTE: THESE TESTS WILL RELY ON YOUR 'addEdgeToAdjacencyList()' function having been
    // implemented and working already because we are going to use it here to create
    // an Adjacency List to work with

    printf("\nTesting 'populateAdjacencyMatrixFromAdjacencyList()'.\n");

    // create an Adjacency list struct
    AdjacencyList adjList;

    // initialise the content of the list to be empty
    // (it is an array of linked lists, each list will
    //  be empty, meaning the first / head item in each
    //  list will be NULL)
    for (int i=0; i<NUMBER_OF_VERTICES; i++)
        adjList.adjacencyList[i] = NULL;

    // calling your method to add edges to the adjacency list
    printf("\nAdding edges to list...\n");
    addEdgeToAdjacencyList(&adjList, 2, 3, 8); // an edge from node 2 to node 3 with a weight of 8
    addEdgeToAdjacencyList(&adjList, 5, 1, 3); // an edge from node 5 to node 1 with a weight of 3
    addEdgeToAdjacencyList(&adjList, 2, 6, 5); // an edge from node 2 to node 6 with a weight of 5
    addEdgeToAdjacencyList(&adjList, 0, 2, 6); // an edge from node 0 to node 2 with a weight of 6

    // display list so we can confirm what's in it
    displayAdjacencyList(&adjList);

    // start with an empty adjacency matrix
    AdjacencyMatrix matrix;

    // initialise the matrix to empty values
    initialiseMatrix(&matrix);

    // call method to populate the adjacency matrix, providing it with a pointer to (the memory address) 
    // of the adjacency list that contains a graph and a a pointer to the matrix to be populated on the
    // basis of that graph
    // the function will return a result which will be one of the SUCCESS or error codes
    int result = populateAdjacencyMatrixFromAdjacencyList(&matrix, &adjList);

    // if method returned SUCCESS (where SUCCESS is one of the codes defined in 'core_definitions.h')
    if (result == SUCCESS)    
    {
        printf("\nCalling 'populateAdjacencyMatrixFromAdjacencyList()'. Function reports SUCCESS.\n");

        // display the content of the matrix for verification purposes
        displayMatrix(&matrix);

        // check if the content of the matrix is as expected
        printf("\nChecking the content of the matrix to see if it is correct: ");
        if ((matrix.matrix[2][3] == 8) && (matrix.matrix[5][1] == 3) && (matrix.matrix[2][6] == 5) && (matrix.matrix[0][2] == 6))
        {
            printf("YES. Correct.\n");
        }
        else
        {
            printf("NO. Not correct\n");
        }
    }
    else
    {
        printf("\nCalling 'populateAdjacencyMatrixFromAdjacencyList()'. Function did NOT report SUCCESS.\n");
        // you can check what (error) code it may have returned instead
    }
}

// A helper function, to display the contents of an adjacency matrix for debugging purposes.
void displayMatrix(AdjacencyMatrix *pMatrix)
{
    printf("\nDisplaying content of Adjacency Matrix for verification:\n");
    for (int i=0; i<NUMBER_OF_VERTICES; i++)
    {
        for (int j=0; j<NUMBER_OF_VERTICES; j++)
        {
            printf("[%d] ", pMatrix->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// A helper function, to fill up the contents of an adjacency matrix to 0
void initialiseMatrix(AdjacencyMatrix *pMatrix)
{
    for (int i=0; i<NUMBER_OF_VERTICES; i++) { for (int j=0; j<NUMBER_OF_VERTICES; j++) { pMatrix->matrix[i][j] = 0; }}
}

// A helper function, to display the contents of an adjacency list for debugging purposes.
void displayAdjacencyList(AdjacencyList *pList)
{
    printf("Displaying AdjacencyList to confirm what's in it [node(weight)]:\n");
    ListNode *pNextNode;
    for (int i=0; i<NUMBER_OF_VERTICES; i++)
    {
        printf("[%d]", i);
        pNextNode = pList->adjacencyList[i];
        while (pNextNode != NULL)
        {
            printf(" -> [%d(%d)]", pNextNode->destNode, pNextNode->weight);
            pNextNode = pNextNode->next;
        }
        printf("\n");
    }
    printf("\n");
}

// Helper function to free the content of an Adjacency List
void freeAdjacencyList(AdjacencyList *pList)
{
    ListNode *pNextNode;
    for (int i=0; i<NUMBER_OF_VERTICES; i++)
    {
        pNextNode = pList->adjacencyList[i];
        while (pNextNode != NULL)
        {
            ListNode *nodeToDelete = pNextNode;
            pNextNode = pNextNode->next;
            free(nodeToDelete);
        }
    }   
}