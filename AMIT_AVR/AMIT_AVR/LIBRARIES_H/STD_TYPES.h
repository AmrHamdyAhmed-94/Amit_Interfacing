#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char uint8_t;                  /*Define Type of 1  Unsigned Byte*/
typedef signed char sint8_t;                    /*Define Type of 1  signed Byte*/
typedef unsigned int uint16_t;            /*Define Type of 2  Unsigned Byte*/
typedef signed short int sint16_t;              /*Define Type of 2  signed Byte*/
typedef unsigned long int uint32_t ;            /*Define Type of 4  Unsigned Byte*/
typedef signed long int sint32_t ;              /*Define Type of 4  signed Byte*/
typedef unsigned long long int uint64_t ;       /*Define Type of 8  Unsigned Byte*/
typedef signed long long int sint64_t ;         /*Define Type of 8  signed Byte*/
typedef float float32_t ;                        /*Define Type of 4  Float Byte */
typedef double double64_t ;                       /*Define Type of 8  Double Byte*/

#define NULL  0                            /*Define Null*/

#define NULL_CHAR  '\0'                            /*Define Null*/

#define NULL_POINTER (void *)NULL          /*Define Null Pointer */

#define NULL_CHR NULL                      /*Define Type of 1  Unsigned Byte*/

#define FALSE 		0U
#define TRUE 		1U

#define DISABLE 	0U
#define ENABLE  	1U

#define ERROR   	0U
#define NO_ERROR 	1U

#define START_LOOP 0U

#undef F_CPU
#define F_CPU 8000000UL


#endif /* STD_TYPES_H_ */
