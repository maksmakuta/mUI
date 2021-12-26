#ifndef TYPES_H
#define TYPES_H

/**
 * This header defines types.
 * Types in some places same as in Rust
 */

#include <string>   // c++ strings
#include <vector>   // c++ vectors
#include <sstream>  // c++ stringstreams
#include <iostream> // c++ input-output streams

#define null nullptr
#define pub  public
#define priv private
#define prot protected

#define nonNull(T)      T != null
#define nullable(T)     T == null

using namespace std;


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
typedef void        fun;

#endif
