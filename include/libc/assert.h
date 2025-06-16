#ifndef ASSERT_H
#define ASSERT_H

// Runtime assertions

// TODO

// Static/compile-time assertions

// GCC implemented _Static_assert in gcc 4.6
// https://gcc.gnu.org/wiki/C11Status
#if (__STDC_VERSION__ >= 201112L) || (__GNUC__ >= 5) || __clang__
# define static_assert(cond, msg) _Static_assert(cond, msg)
#else
# ifndef GLUE
#  define GLUE(a, b) a##b
# endif
# ifndef GLUE2
#  define GLUE2(a, b) GLUE(a, b)
# endif

# define static_assert(cond, msg) typedef char GLUE2(static_assertion_failed, __LINE__)[(cond) ? 1 : -1]
#endif

#endif
