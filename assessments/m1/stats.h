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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */


// A function that prints the statistics of an array including minimum, maximum, mean, and median.
void print_statistics(unsigned char * arr, int len);

// Given an array of data and a length, prints the array to the screen
void print_array(unsigned char * arr, int len);

// Given an array of data and a length, returns the median value
int find_median(unsigned char * arr, int len);

// Given an array of data and a length, returns the mean
int find_mean(unsigned char * arr, int len);

// Given an array of data and a length, returns the maximum
int find_maximum(unsigned char * arr, int len);

// Given an array of data and a length, returns the minimum
int find_minimum(unsigned char * arr, int len);

// Given an array of data and a length, sorts the array from largest to smallest. 
// (The zeroth Element should be the largest value, and the last element (n-1) 
// should be the smallest value. )
void sort_array(unsigned char * arr, int len);


#endif /* __STATS_H__ */
