#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

enum {
  SYSCALL_EXIT      = 10000,
  SYSCALL_ABORT     = 10001,

  // SYSCALL_MALLOC    = 10002,
  // SYSCALL_CALLOC    = 10003,
  // SYSCALL_REALLOC   = 10004,
  // SYSCALL_FREE      = 10005,

  // SYSCALL_MEMCPY    = 10006,
  SYSCALL_MEMSET    = 10007,
  // SYSCALL_MEMMOVE   = 10008,
  // SYSCALL_MEMCMP    = 10009,

  SYSCALL_PRINTS    = 10101,
  SYSCALL_PRINTI    = 10102,
};

static inline long syscall0(long n) {
  register long a0 asm("a0") = 0;
  register long syscall_id asm("a7") = n;
  asm volatile ("scall" : "+r"(a0) : "r"(syscall_id));
  return a0;
}

static inline long syscall1(long n, long arg0) {
  register long a0 asm("a0") = arg0;
  register long syscall_id asm("a7") = n;
  asm volatile ("scall" : "+r"(a0) : "r"(syscall_id));
  return a0;
}

static inline long syscall3(long n, long arg0, long arg1, long arg2) {
  register long a0 asm("a0") = arg0;
  register long a1 asm("a1") = arg1;
  register long a2 asm("a2") = arg2;
  register long syscall_id asm("a7") = n;
  asm volatile ("scall" : "+r"(a0) : "r"(a1), "r"(a2), "r"(syscall_id));
  return a0;
}

static inline void sys_exit(long status) { syscall1(SYSCALL_EXIT, status); }
static inline void sys_abort() { syscall0(SYSCALL_ABORT);}

static inline void sys_prints(const char* s) { syscall1(SYSCALL_PRINTS, (long)(s)); }
static inline void sys_printi(long i) { syscall1(SYSCALL_PRINTI, i); }

static inline void* sys_memset(void* vdest, int ch, size_t size) { syscall3(SYSCALL_MEMSET, (long)vdest, ch, (long)size); }

#define sys_assert(expr) { \
    if(!(expr)) { \
        sys_prints("assertion failed: (" #expr ")"); \
        sys_abort(); \
    }}
