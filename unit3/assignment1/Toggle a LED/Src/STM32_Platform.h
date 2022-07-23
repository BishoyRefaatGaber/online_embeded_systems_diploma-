/*
 * STM32_Platform.h
 *
 *  Created on: Jul 22, 2022
 *      Author: refaa
 */

#ifndef STM32_PLATFORM_H_
#define STM32_PLATFORM_H_


#ifndef STM32_PLATFORM_H_
#define STM32_PLATFORM_H_
/*non-volatile unsigned*/
typedef unsigned char            uint_8;
typedef unsigned short int       uint_16;
typedef unsigned int             uint_32;
typedef unsigned long long int   uint_64;


/*non-volatile real*/
<<<<<<< HEAD
typedef float                    float_32;
typedef double                   double_64;
typedef long double              ldouble_80;
=======
typedef float           ufloat_32;
typedef double          udouble_64;
typedef long double     uldouble_80;
>>>>>>> 6a532e6e4d70faee8308c59a8cd7c6f38ad95a04


/*non-volatile signed*/

typedef char            sint_8;
typedef short int       sint_16;
typedef int             sint_32;
typedef long long int   sint_64;
<<<<<<< HEAD
=======

>>>>>>> 6a532e6e4d70faee8308c59a8cd7c6f38ad95a04


/*volatile unsigned*/
typedef volatile unsigned char            vuint_8;
typedef volatile unsigned short int       vuint_16;
typedef volatile unsigned int             vuint_32;
typedef volatile unsigned long long int   vuint_64;


<<<<<<< HEAD
/*volatile real*/
typedef volatile float                    vfloat_32;
typedef volatile double                   vdouble_64;
typedef volatile long double              vldouble_80;
=======

/* volatile real */
typedef volatile float           vufloat_32;
typedef volatile double          vudouble_64;
typedef volatile long double     vuldouble_80;
>>>>>>> 6a532e6e4d70faee8308c59a8cd7c6f38ad95a04


/*volatile signed*/

typedef volatile char            vsint_8;
typedef volatile short int       vsint_16;
typedef volatile int             vsint_32;
typedef volatile long long int   vsint_64;



#endif


#endif /* STM32_PLATFORM_H_ */
