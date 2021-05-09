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
 * @file <data.h> 
 * @brief <This files describe headers of the source code data.c>
 *
 * <Header file for C-programming code data.c>
 *
 * @author <Stephane NGNEPIEPAYE WEMBE>
 * @date <08/05/2021>
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

/**
* @brief convert data from a standard integer type into an ASCII string
*
* @details 
*
* @param data number to convert
* @param ptr pointer to the converted character
* @param base the base we wish to convert to (base 2 or base 16) 
*
* @return length of the conveted data. Example my_itoa(ptr, 1234, 10) 
* should return an ASCII string length of 5 (including the null terminator).
*/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
* @brief convert data fron an ASCII represented string into an integer type
*
* @details 
*
* @param ptr pointer to the character to convert 
* @param digits number of digits in the character set in parameter  
* @param base the base we wish to convert to (base 2 or base 16) 
*
* @return The converted 32-bit signed integer
*/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
