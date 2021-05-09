/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c>
 * @brief <This code perfoms statistical analysis on a dataset >
 *
 * <The code analyze an array of unsigned char data items and report analytics on
 * the maximum, minimum, mean, and median of the data set. In addition, the code
 * reorder this data set from large to small. All results are
 * rounded down to the nearest integer. After analysis and sorting is done,
 * the code prints that data to the screen>
 *
 * @author <Stephane NGNEPIEPAYE WEMBE>
 * @date <16/04/2021>
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  printf("Unsorted array\n");
  print_array(test, SIZE);
  print_statistics(test, SIZE);
}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char* arrayData, unsigned int arraySize){
    sort_array(arrayData, arraySize);
    printf("Statistics\n");
    unsigned char maxValue = find_maximum(arrayData, arraySize);
    unsigned char minValue = find_minimum(arrayData, arraySize);
    unsigned char medianValue = find_median(arrayData, arraySize);
    unsigned char meanValue = find_mean(arrayData, arraySize);
    printf("maximun value = %u \n",(unsigned int) maxValue);
    printf("minimun value = %u \n",(unsigned int) minValue);
    printf("median value = %u \n",(unsigned int) medianValue);
    printf("mean value = %u \n\n",(unsigned int) meanValue);
    printf("sorted array \n");
    print_array(arrayData,arraySize);

}


void print_array(unsigned char* arrayData, unsigned int arraySize){
    unsigned int i = 0;
    #ifdef VERBOSE
    for (i=0 ; i<arraySize ; i++){
        PRINTF("element %d : %u \n",i,(unsigned int)(arrayData[i]));
    }
    #endif
}


unsigned char find_median(unsigned char* arrayData, unsigned int arraySize){
    sort_array(arrayData, arraySize);
    if (arraySize%2 == 0)
        return arrayData[(unsigned int)(arraySize/2)];
    else
        return (unsigned char)((arrayData[(unsigned int)((arraySize-1)/2)]+arrayData[(unsigned int)((arraySize+1)/2)])/2);
}


unsigned char find_mean(unsigned char* arrayData, unsigned int arraySize){
    unsigned int  i=0;
    unsigned char sum=0;
    for (i=0 ; i<arraySize ; i++)
    {
              sum = (unsigned char)((unsigned int)sum + (unsigned int)arrayData[i]);
    }
printf("sum : %u \n",(unsigned int)(sum));
     return (unsigned char)((int)(sum/arraySize));
}


unsigned char find_maximum(unsigned char* arrayData, unsigned int arraySize){
    sort_array(arrayData, arraySize);
    return arrayData[0];
}


unsigned char find_minimum(unsigned char* arrayData, unsigned int arraySize){
    sort_array(arrayData,arraySize);
    return arrayData[arraySize-1];
}


void sort_array(unsigned char* arrayData, unsigned int arraySize){

    unsigned int i=0,j=0;
    unsigned char c=0;
    /* bubble sorting*/
    for(j=1;j<=arraySize;j++){ // To do the operation ArraySize Time
        for(i=0;i<arraySize-1;i++){
            if ( arrayData[i] < arrayData[i+1] ) {
                    c = arrayData[i];
                    arrayData[i] = arrayData[i+1];
                    arrayData[i+1] = c;
            }
        }
    }
}


