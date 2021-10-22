#ifndef MUI_TYPES_H
#define MUI_TYPES_H

#include <string> // c++ strings

/**
 * This header defines types.
 * Types in some places same as in Rust
 */

typedef float   f32;
typedef double  f64;

typedef char    i8 ;
typedef short   i16;
typedef int     i32;
typedef long    i64;

typedef unsigned char    u8 ;
typedef unsigned short   u16;
typedef unsigned int     u32;
typedef unsigned long    u64;

typedef std::string str;

// for function only
typedef void fun;

#define null nullptr

#endif