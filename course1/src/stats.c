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



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char * arr, int len) {
    sort_array(arr, len);

    print_array(arr, len);
}

void print_array(unsigned char * arr, int len) {
#ifdef VERBOSE
    PRINTF("array: [");
    for(int i = 0; i < len; i++) {
        if (i < len - 1) {
            PRINTF("%d, ", arr[i]);
        }
        else {
            PRINTF("%d", arr[i]);
        }
    }
    PRINTF("]\n");
#endif
}

int find_median(unsigned char * arr, int len) {
    if (len % 2 == 0) {
        unsigned char v1 = arr[len/2];
        unsigned char v2 = arr[len/2 + 1];
        return (v1 + v2) / 2;
    }
    else {
        return arr[len/2 + 1];
    }
}

int find_mean(unsigned char * arr, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }

    return sum / len;
}

int find_maximum(unsigned char * arr, int len) {
    return arr[len-1];
}

int find_minimum(unsigned char * arr, int len) {
    return arr[0];
}

void sort_array(unsigned char * arr, int len) {
    for (int i = 1; i < len; i++) { 
        unsigned char key = arr[i]; 
        int j = i - 1; 

        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 

        arr[j + 1] = key; 
    } 
}

