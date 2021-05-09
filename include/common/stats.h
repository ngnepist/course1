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
 * @file <stats.h> 
 * @brief <This files describe headers of the source code stats.c>
 *
 * <Header file for C-programming code stats.c>
 *
 * @author <Stephane NGNEPIEPAYE WEMBE>
 * @date <16/04/2021>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


void print_statistics(unsigned char* arrayData, unsigned int arraySize);
/**
 * @brief <This function prints the statistics of an array.>
 *
 * <Printed values are minimum, maximum, mean, and median of the array>
 *
 * @param <arrayData> <Array of unsigned char data items>
 * @param <arraySize> <The size of the array>
 *
 * @return <Nothing>
 */

void print_array(unsigned char* arrayData, unsigned int arraySize);
/**
 * @brief <This function prints an array of data>
 *
 * <displays the index and the value of each element of the array>
 *
 * @param <arrayData> <array of unsigned char data items>
 * @param <arraySize> <The size of the array>
 *
 * @return <Nothing>
 */


unsigned char find_median(unsigned char* arrayData, unsigned int arraySize);
/**
 * @brief <This function finds the median of an array of data>
 *
 * <we sort values of the table. After having sorted,
 * if arraySize is even, we return the value of index n/2
 * elseif we return the average of values of index (n-1)/2 and (n+1)/2>
 *
 * @param <arrayData> <array of unsigned char data items>
 * @param <arraySize> <The size of the array>
 *
 * @return <The median of arrayData>
 */


unsigned char find_mean(unsigned char* arrayData, unsigned int arraySize);
/**
 * @brief <This function finds the mean of an array of data>
 *
 * <we calculate the mean of values in arrayData>
 *
 * @param <arrayData> <array of unsigned char data items>
 * @param <arraySize> <The size of the array>
 *
 * @return <The mean of arrayData>
 */


unsigned char find_maximum(unsigned char* arrayData, unsigned int arraySize);
/**
 * @brief <This function finds the maximum of an array of data>
 *
 * <we sort values of the table. After having sorted from large to small,
 * we take the first value>
 *
 * @param <arrayData> <array of unsigned char data items>
 * @param <arraySize> <The size of the array>
 *
 * @return <The maximmun of arrayData>
 */


unsigned char find_minimum(unsigned char* arrayData, unsigned int arraySize);
/**
 * @brief <This function finds the minimum of an array of data>
 *
 * <we sort values of the table. After having sorted from large to small,
 * we take the last value>
 *
 * @param <arrayData> <array of unsigned char data items>
 * @param <arraySize> <The size of the array>
 *
 * @return <The maximmun of arrayData>
 */


void sort_array(unsigned char* arrayData, unsigned int arraySize);
/**
 * @brief <This function sorts an array of data from large to small>
 *
 * <we sort values of the table from large to small>
 *
 * @param <arrayData> <array of unsigned char data items>
 * @param <arraySize> <The size of the array>
 *
 * @return <Nothing>
 */

#endif /* __STATS_H__ */
