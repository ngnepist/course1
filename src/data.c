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
* @file <data.c>
* @brief <This code perfoms  basic data manipulation>
*
* <The code convert an integer to ASCII string and vis versa>
*
* @author <Stephane NGNEPIEPAYE WEMBE>
* @date <08/05/2021>
*
*/

#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

// Convert 1 digit
static int value(int ch) {
  if (isdigit(ch)) {
    return ch - '0';
  }
  if (isxdigit(ch)) {
    ch = tolower(ch);
    const char *xdigits = "abcdef";
    return strchr(xdigits, ch) - xdigits  + 10;
  }
  return INT_MAX; // non-digit
}


/***********************************************************
 Function Definitions
***********************************************************/

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  int32_t sum = 0;
  bool signed_digit = false;
  while (isspace(*ptr)) ptr++;  // skip leading white space at the beginning
  if (*ptr == '+')  ptr++;      // Allow optional leading `+`
  if (*ptr == '-')              // Allow optional leading `-'
  {
      signed_digit = true;
      ptr++;
  }
  bool digit_found = false;
  

  while (*ptr) {
    unsigned digit = value(*ptr++);
    if (digit >= base) {
      return INT_MIN; // TBD signal unexpected digit
    }
    if (sum >= INT_MAX/base && (sum > INT_MAX/base || digit > INT_MAX%base)) {
      // Overflow
      return INT_MIN; // TBD signal OF
    }
    sum *= base;
    sum += digit;
    digit_found = true;
  }

  if (signed_digit) sum = - sum;
  if (*ptr) {
    sum = INT_MIN; // TBD signal unexpected junk at the end
  }
  if (!digit_found) {
    sum = INT_MIN; // TBD signal no digits
  }
  return sum;
}


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  uint8_t len; 
  char tmp[16];
  char *tp = tmp;
  int32_t i;
  uint32_t v;

  uint8_t sign = (base == 10 && data < 0);  
  if (sign)
    v = -data;
  else
    v = (unsigned)data;
 
  while (v || tp == tmp)
  {
    i = v % base;
    v /= base; 
    if (i < 10)
      *tp++ = i+'0';
    else
      *tp++ = i + 'a' - 10;
  }

  len = tp - tmp;

  if (sign) 
  {
    *ptr++ = '-';
    len++;
  }

  while (tp > tmp)
    *ptr++ = *--tp;

  *ptr = '\0';

  return len;
}

