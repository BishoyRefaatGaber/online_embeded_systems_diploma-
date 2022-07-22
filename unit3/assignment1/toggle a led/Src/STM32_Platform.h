
#ifndef STM32_PLATFORM_H_
#define STM32_PLATFORM_H_
/*non-volatile unsigned*/
typedef unsigned char            uint_8;
typedef unsigned short int       uint_16;
typedef unsigned int             uint_32;
typedef unsigned long long int   uint_64;
typedef float           ufloat_32;
typedef double          udouble_64;
typedef long double     uldouble_80;


/*non-volatile signed*/

typedef char            sint_8;
typedef short int       sint_16;
typedef int             sint_32;
typedef long long int   sint_64;
typedef float           sfloat_32;
typedef double          sdouble_64;
typedef long double     sldouble_80;


/*volatile unsigned*/
typedef volatile unsigned char            vuint_8;
typedef volatile unsigned short int       vuint_16;
typedef volatile unsigned int             vuint_32;
typedef volatile unsigned long long int   vuint_64;
typedef volatile float           vufloat_32;
typedef volatile double          vudouble_64;
typedef volatile long double     vuldouble_80;


/*volatile signed*/

typedef volatile char            vsint_8;
typedef volatile short int       vsint_16;
typedef volatile int             vsint_32;
typedef volatile long long int   vsint_64;
typedef volatile float           vsfloat_32;
typedef volatile double          vsdouble_64;
typedef volatile long double     vsldouble_80;


#endif
