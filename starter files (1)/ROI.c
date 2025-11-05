#include "adj_matrix.h"
#include "adj_list.h"
#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>

void *implementROI(int enteredStIn, int destinationIn, int enteredStOut, int destinationOut){
    //set temp values for different airoplanes?

    //FOR OUTBOUND
    //create empty matrixes for out (1) and incoming (2)
    AdjacencyMatrix matrix1;
    int startOut = -1;
    AdjacencyMatrix matrix2;
    int startIn = -1;

    // initialise the matrix to empty values
    initialiseMatrix(&matrix1);
    initialiseMatrix(&matrix2);

    // initialise for given graph on the task instructions
    //0 = Dundee
    //1 = Edinburgh
    //2 = London
    //3 = madrid
    //4 = paris

    matrix1.matrix[0][1] = 30; //dundee -> edinburgh
    matrix1.matrix[1][2] = 75; //edinburgh -> london
    matrix1.matrix[0][2] = 85; //dundee -> london
    matrix1.matrix[2][3] = 115; //london -> madrid
    matrix1.matrix[1][4] = 115; //edinburgh -> paris
    matrix1.matrix[4][3] = 115; //paris -> madrid
    startOut = enteredStOut;

    //for initialising inbound when needed
    matrix2.matrix[3][2] = 105; //madrid -> london
    matrix2.matrix[2][1] = 75; //london -> edinburgh
    matrix2.matrix[4][2] = 120; //paris -> london
    matrix2.matrix[4][1] = 110; //paris -> edinburgh
    matrix2.matrix[1][0] = 45; //edinburgh -> dundee
    startIn = enteredStIn;

    // create an empty DijkstraTable for both out (1) and in (2)
    DijkstraTable dijkstraTable1;
    DijkstraTable dijkstraTable2;

    // initialise the dijkstra table to default values for both
    for (int i=0; i<NUMBER_OF_VERTICES; i++)
    {
        dijkstraTable1.table[i].visited = false;
        dijkstraTable1.table[i].distance = VERY_LARGE_NUMBER;
        dijkstraTable1.table[i].predecessor = -1;

        dijkstraTable2.table[i].visited = false;
        dijkstraTable2.table[i].distance = VERY_LARGE_NUMBER;
        dijkstraTable2.table[i].predecessor = -1;
    }
    
    //do djirkstras on data from start to end and vis versa for both matrixes
    int result1 = runDijsktraAlgorithm(&matrix1, &dijkstraTable1, enteredStOut);
    int result2 = runDijsktraAlgorithm(&matrix2, &dijkstraTable2, enteredStIn);

    /*
    printf("\nDisplaying the dijkstra table that was received from the function:\n");
    printf("Node\tDist\tPred\n");
    for (int i=0; i<NUMBER_OF_VERTICES; i++)
    {
        printf("%d\t%d\t%d\n", i, dijkstraTable.table[i].distance, dijkstraTable.table[i].predecessor);
    }
    printf("\n");*/

    int distOut = 0;
    int distIn = 0;
    // if function returned success
    if (result1 == SUCCESS && result2 == SUCCESS){
        //print distance found for both
        printf("%d \n", dijkstraTable1.table[destinationOut].distance);
        printf("%d \n", dijkstraTable2.table[destinationIn].distance);

        //compare both directions and display according output
        if (dijkstraTable1.table[destinationOut].distance < dijkstraTable2.table[destinationIn].distance){
            printf("The company will embark on the outbound trip, as the distance of the outbound trip is %d minutes less \n", dijkstraTable2.table[destinationIn].distance - dijkstraTable1.table[destinationOut].distance);
        }else if (dijkstraTable1.table[destinationOut].distance > dijkstraTable2.table[destinationIn].distance){
            printf("The company will embark on the inbound trip, as the distance of the inbound trip is: %d, minutes less", dijkstraTable2.table[destinationOut].distance - dijkstraTable1.table[destinationIn].distance);
        }else{
            printf("The company will embark on both as they take the same amount of time, %d minutes.\n", dijkstraTable1.table[destinationOut].distance);
        }
    }else{
        printf("Error recieved");
    }
}