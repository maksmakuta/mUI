#ifndef TYPEUTILS_H
#define TYPEUTILS_H

#define null nullptr

typedef void            fun;
typedef int             i32;
typedef long            i64;
typedef unsigned int    u32;
typedef unsigned long   u64;
typedef float           f32;
typedef double          f64;

#define nonNull(x) (x != null)
#define nullable(x) (x == null)

#endif // TYPEUTILS_H
