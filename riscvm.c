/* ------------------------------ DIRECTIVES -------------------------------- */
#ifdef __GNUC__
  #ifndef __cplusplus
    #pragma GCC diagnostic error   "-Wimplicit-function-declaration"
    #pragma GCC diagnostic error   "-Wimplicit-int"
    #pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
  #else
    #pragma GCC diagnostic ignored "-Wwrite-strings"
    #pragma GCC diagnostic ignored "-Wnarrowing"
  #endif
  #pragma GCC diagnostic ignored "-Wmissing-braces"
  #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
  #pragma GCC diagnostic ignored "-Wtype-limits"
  #pragma GCC diagnostic ignored "-Wunused-parameter"
  #ifdef __clang__
    #pragma GCC diagnostic ignored "-Wunused"
    #pragma GCC diagnostic ignored "-Wparentheses-equality"
  #else
    #pragma GCC diagnostic ignored "-Wunused-value"
    #pragma GCC diagnostic ignored "-Wunused-variable"
    #pragma GCC diagnostic ignored "-Wunused-function"
    #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
    #ifndef __cplusplus
      #pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"
    #endif
  #endif
#endif
#if __STDC_VERSION__ >= 201112L
  #define nelua_static_assert _Static_assert
#elif __cplusplus >= 201103L
  #define nelua_static_assert static_assert
#else
  #define nelua_static_assert(x, y)
#endif
nelua_static_assert(sizeof(void*) == 8, "Nelua and C disagree on pointer size");
#if !defined(_FILE_OFFSET_BITS) && __SIZEOF_LONG__ >= 8
  #define _FILE_OFFSET_BITS 64
#endif
#if !defined(_POSIX_C_SOURCE) && !defined(_XOPEN_SOURCE) && !defined(_GNU_SOURCE) && !defined(_DEFAULT_SOURCE)
  #if defined(__gnu_linux__)
    #define _GNU_SOURCE
  #else
    #define _XOPEN_SOURCE 600
  #endif
#endif
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#if __STDC_VERSION__ >= 201112L
  #define nelua_alignof _Alignof
#elif __cplusplus >= 201103L
  #define nelua_alignof alignof
#elif defined(__GNUC__)
  #define nelua_alignof __alignof__
#elif defined(_MSC_VER)
  #define nelua_alignof __alignof
#else
  #define nelua_alignof(x)
#endif
#ifdef __GNUC__
  #define nelua_inline __attribute__((always_inline)) inline
#elif __STDC_VERSION__ >= 199901L
  #define nelua_inline inline
#else
  #define nelua_inline
#endif
#include <stddef.h>
#include <stdlib.h>
#if __STDC_VERSION__ >= 201112L
  #define nelua_noreturn _Noreturn
#elif defined(__GNUC__)
  #define nelua_noreturn __attribute__((noreturn))
#elif defined(_MSC_VER)
  #define nelua_noreturn __declspec(noreturn)
#else
  #define nelua_noreturn
#endif
#include <inttypes.h>
#define NLNIL (nlniltype){}
#ifdef __GNUC__
  #define nelua_likely(x) __builtin_expect(x, 1)
  #define nelua_unlikely(x) __builtin_expect(x, 0)
#else
  #define nelua_likely(x) (x)
  #define nelua_unlikely(x) (x)
#endif
#ifdef __GNUC__
  #define nelua_noinline __attribute__((noinline))
#elif defined(_MSC_VER)
  #define nelua_noinline __declspec(noinline)
#else
  #define nelua_noinline
#endif
/* ------------------------------ DECLARATIONS ------------------------------ */
typedef struct machine_Machine machine_Machine;
typedef machine_Machine* machine_Machine_ptr;
struct machine_Machine {
  bool running;
  int64_t pc;
  uint64_t regs[32];
  uint8_t memory[134217728];
  int64_t exitcode;
}; nelua_static_assert(sizeof(machine_Machine) == 134218008 && nelua_alignof(machine_Machine) == 8, "Nelua and C disagree on type size or align");
typedef struct nlstring nlstring;
typedef uint8_t* nluint8_arr0_ptr;
struct nlstring {
  nluint8_arr0_ptr data;
  uintptr_t size;
}; nelua_static_assert(sizeof(nlstring) == 16 && nelua_alignof(nlstring) == 8, "Nelua and C disagree on type size or align");
static void machine_Machine_loadfile(machine_Machine_ptr self, nlstring filename);
typedef FILE* FILE_ptr;
static nelua_inline char* nelua_string2cstring(nlstring s);
static nelua_noreturn void nelua_abort();
static nelua_noreturn void nelua_panic_string(nlstring s);
typedef struct nluint8_arr134217728 {uint8_t v[134217728];} nluint8_arr134217728; nelua_static_assert(sizeof(nluint8_arr134217728) == 134217728 && nelua_alignof(nluint8_arr134217728) == 1, "Nelua and C disagree on type size or align");
typedef struct nluint64_arr32 {uint64_t v[32];} nluint64_arr32; nelua_static_assert(sizeof(nluint64_arr32) == 256 && nelua_alignof(nluint64_arr32) == 8, "Nelua and C disagree on type size or align");
static nelua_inline uint32_t machine_Machine_fetch(machine_Machine_ptr self);
typedef uint32_t* nluint32_ptr;
typedef struct nlniltype {} nlniltype;
static nelua_inline int8_t machine_Machine_read_1(machine_Machine_ptr self, nlniltype T, uint64_t addr);
static nelua_inline int16_t machine_Machine_read_2(machine_Machine_ptr self, nlniltype T, uint64_t addr);
typedef uint16_t* nluint16_ptr;
static nelua_inline int32_t machine_Machine_read_3(machine_Machine_ptr self, nlniltype T, uint64_t addr);
static nelua_inline int64_t machine_Machine_read_4(machine_Machine_ptr self, nlniltype T, uint64_t addr);
typedef uint64_t* nluint64_ptr;
static nelua_inline uint8_t machine_Machine_read_5(machine_Machine_ptr self, nlniltype T, uint64_t addr);
static nelua_inline uint16_t machine_Machine_read_6(machine_Machine_ptr self, nlniltype T, uint64_t addr);
static nelua_inline uint32_t machine_Machine_read_7(machine_Machine_ptr self, nlniltype T, uint64_t addr);
static nelua_inline void* machine_Machine_getptr(machine_Machine_ptr self, uint64_t addr);
static nelua_inline void machine_Machine_write_1(machine_Machine_ptr self, uint64_t addr, uint8_t val);
static nelua_inline void machine_Machine_write_2(machine_Machine_ptr self, uint64_t addr, uint16_t val);
static nelua_inline void machine_Machine_write_3(machine_Machine_ptr self, uint64_t addr, uint32_t val);
static nelua_inline void machine_Machine_write_4(machine_Machine_ptr self, uint64_t addr, uint64_t val);
static uint64_t machine_Machine_handle_syscall(machine_Machine_ptr self, uint64_t code);
static void nelua_print_1(char* a1);
static void nelua_print_2(int64_t a1);
static nelua_inline void machine_Machine_execute(machine_Machine_ptr self, uint32_t inst);
static nelua_inline int64_t nelua_shl_nlint64(int64_t a, int64_t b);
static nelua_inline int64_t nelua_shr_nlint64(int64_t a, int64_t b);
static nelua_inline int64_t nelua_asr_nlint64(int64_t a, int64_t b);
static nelua_inline __int128 nelua_shr_nlint128(__int128 a, __int128 b);
static nelua_noinline void machine_Machine_run(machine_Machine_ptr self);
static void nelua_print_3(nlstring a1);
static char* riscvm_filename;
static machine_Machine riscvm_machine;
static nelua_inline nlstring nelua_cstring2string(const char* s);
static int nelua_main(int nelua_argc, char** nelua_argv);
/* ------------------------------ DEFINITIONS ------------------------------- */
char* nelua_string2cstring(nlstring s){
  return (s.size == 0) ? (char*)"" : (char*)s.data;
}
void nelua_abort(){
  fflush(stderr);
  abort();
}
void nelua_panic_string(nlstring s){
  if(s.size > 0) {
    fwrite(s.data, 1, s.size, stderr);
    fputc('\n', stderr);
  }
  nelua_abort();
}
void machine_Machine_loadfile(machine_Machine_ptr self, nlstring filename) {
  FILE_ptr fp = fopen(nelua_string2cstring(filename), "rb");
  if((!(fp != NULL))) {
    nelua_panic_string(((nlstring){(uint8_t*)"failed to open file", 19}));
  }
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  fread((void*)(&(*(nluint8_arr134217728*)self->memory).v[4096]), (size_t)size, 1U, fp);
  fclose(fp);
  (*(nluint64_arr32*)self->regs).v[2] = 134217728U;
  self->pc = 4096;
}
uint32_t machine_Machine_fetch(machine_Machine_ptr self) {
  return (*(nluint32_ptr)(&(*(nluint8_arr134217728*)self->memory).v[self->pc]));
}
int8_t machine_Machine_read_1(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (int8_t)(*(&(*(nluint8_arr134217728*)self->memory).v[addr]));
}
int16_t machine_Machine_read_2(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (int16_t)(*(nluint16_ptr)(&(*(nluint8_arr134217728*)self->memory).v[addr]));
}
int32_t machine_Machine_read_3(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (int32_t)(*(nluint32_ptr)(&(*(nluint8_arr134217728*)self->memory).v[addr]));
}
int64_t machine_Machine_read_4(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (int64_t)(*(nluint64_ptr)(&(*(nluint8_arr134217728*)self->memory).v[addr]));
}
uint8_t machine_Machine_read_5(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (*(&(*(nluint8_arr134217728*)self->memory).v[addr]));
}
uint16_t machine_Machine_read_6(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (*(nluint16_ptr)(&(*(nluint8_arr134217728*)self->memory).v[addr]));
}
uint32_t machine_Machine_read_7(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (*(nluint32_ptr)(&(*(nluint8_arr134217728*)self->memory).v[addr]));
}
void* machine_Machine_getptr(machine_Machine_ptr self, uint64_t addr) {
  return (void*)(&(*(nluint8_arr134217728*)self->memory).v[addr]);
}
void machine_Machine_write_1(machine_Machine_ptr self, uint64_t addr, uint8_t val) {
  (*(&(*(nluint8_arr134217728*)self->memory).v[addr])) = val;
}
void machine_Machine_write_2(machine_Machine_ptr self, uint64_t addr, uint16_t val) {
  (*(nluint16_ptr)(&(*(nluint8_arr134217728*)self->memory).v[addr])) = val;
}
void machine_Machine_write_3(machine_Machine_ptr self, uint64_t addr, uint32_t val) {
  (*(nluint32_ptr)(&(*(nluint8_arr134217728*)self->memory).v[addr])) = val;
}
void machine_Machine_write_4(machine_Machine_ptr self, uint64_t addr, uint64_t val) {
  (*(nluint64_ptr)(&(*(nluint8_arr134217728*)self->memory).v[addr])) = val;
}
void nelua_print_1(char* a1) {
  fputs(a1, stdout);
  fputc('\n', stdout);
  fflush(stdout);
}
void nelua_print_2(int64_t a1) {
  fprintf(stdout, "%" PRIi64, a1);
  fputc('\n', stdout);
  fflush(stdout);
}
uint64_t machine_Machine_handle_syscall(machine_Machine_ptr self, uint64_t code) {
  switch(code) {
    case 10000: {
      self->running = false;
      self->exitcode = (int64_t)(*(nluint64_arr32*)self->regs).v[10];
      break;
    }
    case 10001: {
      nelua_panic_string(((nlstring){(uint8_t*)"aborted!", 8}));
      break;
    }
    case 10007: {
      void* dest = machine_Machine_getptr(self, (*(nluint64_arr32*)self->regs).v[10]);
      uint64_t c = (*(nluint64_arr32*)self->regs).v[11];
      uint64_t len = (*(nluint64_arr32*)self->regs).v[12];
      void* res = memset(dest, (int)c, (size_t)len);
      return (uint64_t)res;
      break;
    }
    case 10101: {
      char* s = (char*)machine_Machine_getptr(self, (*(nluint64_arr32*)self->regs).v[10]);
      nelua_print_1(s);
      break;
    }
    case 10102: {
      int64_t i = (int64_t)(*(nluint64_arr32*)self->regs).v[10];
      nelua_print_2(i);
      break;
    }
    default: {
      nelua_panic_string(((nlstring){(uint8_t*)"illegal system call", 19}));
      break;
    }
  }
  return 0U;
}
int64_t nelua_shl_nlint64(int64_t a, int64_t b){
  if(nelua_likely(b >= 0 && b < 64)) return (uint64_t)a << b;
  else if(nelua_unlikely(b < 0 && b > -64)) return (uint64_t)a >> -b;
  else return 0;
}
int64_t nelua_shr_nlint64(int64_t a, int64_t b){
  if(nelua_likely(b >= 0 && b < 64)) return (uint64_t)a >> b;
  else if(nelua_unlikely(b < 0 && b > -64)) return (uint64_t)a << -b;
  else return 0;
}
int64_t nelua_asr_nlint64(int64_t a, int64_t b){
  if(nelua_likely(b >= 0 && b < 64)) return a >> b;
  else if(nelua_unlikely(b >= 64)) return a < 0 ? -1 : 0;
  else if(nelua_unlikely(b < 0 && b > -64)) return a << -b;
  else return 0;
}
__int128 nelua_shr_nlint128(__int128 a, __int128 b){
  if(nelua_likely(b >= 0 && b < 128)) return (unsigned __int128)a >> b;
  else if(nelua_unlikely(b < 0 && b > -128)) return (unsigned __int128)a << -b;
  else return 0;
}
void machine_Machine_execute(machine_Machine_ptr self, uint32_t inst) {
  uint32_t opcode = ((inst >> 0) & 127);
  uint32_t rd = ((inst >> 7) & 31);
  uint32_t rs1 = ((inst >> 15) & 31);
  uint32_t rs2 = ((inst >> 20) & 31);
  switch(opcode) {
    case 0x3: {
      uint32_t funct3 = ((inst >> 12) & 7);
      int64_t imm = (int64_t)(((int32_t)((uint32_t)(int32_t)((inst >> 20) & 4095) << 20)) >> 20);
      uint64_t addr = ((*(nluint64_arr32*)self->regs).v[rs1] + (uint64_t)imm);
      int64_t val;
      switch(funct3) {
        case 0x0: {
          val = (int64_t)machine_Machine_read_1(self, NLNIL, addr);
          break;
        }
        case 0x1: {
          val = (int64_t)machine_Machine_read_2(self, NLNIL, addr);
          break;
        }
        case 0x2: {
          val = (int64_t)machine_Machine_read_3(self, NLNIL, addr);
          break;
        }
        case 0x3: {
          val = machine_Machine_read_4(self, NLNIL, addr);
          break;
        }
        case 0x4: {
          val = (int64_t)machine_Machine_read_5(self, NLNIL, addr);
          break;
        }
        case 0x5: {
          val = (int64_t)machine_Machine_read_6(self, NLNIL, addr);
          break;
        }
        case 0x6: {
          val = (int64_t)machine_Machine_read_7(self, NLNIL, addr);
          break;
        }
        default: {
          nelua_panic_string(((nlstring){(uint8_t*)"illegal load instruction", 24}));
          break;
        }
      }
      if(nelua_likely((rd != 0))) {
        (*(nluint64_arr32*)self->regs).v[rd] = (uint64_t)val;
      }
      break;
    }
    case 0x23: {
      uint32_t funct3 = ((inst >> 12) & 7);
      int64_t imm = (int64_t)(((int32_t)((uint32_t)(int32_t)(((inst >> 20) & 4064) | ((inst >> 7) & 31)) << 20)) >> 20);
      uint64_t addr = ((*(nluint64_arr32*)self->regs).v[rs1] + (uint64_t)imm);
      uint64_t val = (*(nluint64_arr32*)self->regs).v[rs2];
      switch(funct3) {
        case 0x0: {
          machine_Machine_write_1(self, addr, (uint8_t)val);
          break;
        }
        case 0x1: {
          machine_Machine_write_2(self, addr, (uint16_t)val);
          break;
        }
        case 0x2: {
          machine_Machine_write_3(self, addr, (uint32_t)val);
          break;
        }
        case 0x3: {
          machine_Machine_write_4(self, addr, val);
          break;
        }
        default: {
          nelua_panic_string(((nlstring){(uint8_t*)"illegal store instruction", 25}));
          break;
        }
      }
      break;
    }
    case 0x13: {
      uint32_t funct3 = ((inst >> 12) & 7);
      int64_t imm = (int64_t)(((int32_t)((uint32_t)(int32_t)((inst >> 20) & 4095) << 20)) >> 20);
      uint32_t shamt = ((inst >> 20) & 63);
      int64_t val = (int64_t)(*(nluint64_arr32*)self->regs).v[rs1];
      switch(funct3) {
        case 0x0: {
          val = (val + imm);
          break;
        }
        case 0x1: {
          val = nelua_shl_nlint64(val, shamt);
          break;
        }
        case 0x2: {
          if((val < imm)) {
            val = 1;
          } else {
            val = 0;
          }
          break;
        }
        case 0x3: {
          if(((uint64_t)val < (uint64_t)imm)) {
            val = 1;
          } else {
            val = 0;
          }
          break;
        }
        case 0x4: {
          val = (val ^ imm);
          break;
        }
        case 0x5: {
          uint32_t funct6 = ((inst >> 26) & 63);
          switch((funct6 >> 4)) {
            case 0x0: {
              val = nelua_shr_nlint64(val, shamt);
              break;
            }
            case 0x1: {
              val = nelua_asr_nlint64(val, shamt);
              break;
            }
            default: {
              nelua_panic_string(((nlstring){(uint8_t*)"illegal op-imm shift instruction", 32}));
              break;
            }
          }
          break;
        }
        case 0x6: {
          val = (val | imm);
          break;
        }
        case 0x7: {
          val = (val & imm);
          break;
        }
        default: {
          nelua_panic_string(((nlstring){(uint8_t*)"illegal op-imm instruction", 26}));
          break;
        }
      }
      if(nelua_likely((rd != 0))) {
        (*(nluint64_arr32*)self->regs).v[rd] = (uint64_t)val;
      }
      break;
    }
    case 0x1b: {
      uint32_t funct3 = ((inst >> 12) & 7);
      int64_t imm = (int64_t)(((int32_t)((uint32_t)(int32_t)((inst >> 20) & 4095) << 20)) >> 20);
      int64_t val = (int64_t)(*(nluint64_arr32*)self->regs).v[rs1];
      switch(funct3) {
        case 0x0: {
          val = (int64_t)(int32_t)(val + imm);
          break;
        }
        case 0x1: {
          val = (int64_t)(int32_t)nelua_shl_nlint64(val, imm);
          break;
        }
        case 0x5: {
          uint32_t shamt = rs2;
          uint32_t funct7 = ((inst >> 25) & 127);
          switch((funct7 >> 5)) {
            case 0x0: {
              val = (int64_t)(int32_t)nelua_shr_nlint64(val, shamt);
              break;
            }
            case 0x1: {
              val = (int64_t)(int32_t)nelua_asr_nlint64(val, shamt);
              break;
            }
            default: {
              nelua_panic_string(((nlstring){(uint8_t*)"illegal op-imm-32 shift instruction", 35}));
              break;
            }
          }
          break;
        }
        default: {
          nelua_panic_string(((nlstring){(uint8_t*)"illegal op-imm-32 instruction", 29}));
          break;
        }
      }
      if(nelua_likely((rd != 0))) {
        (*(nluint64_arr32*)self->regs).v[rd] = (uint64_t)val;
      }
      break;
    }
    case 0x33: {
      uint32_t funct3 = ((inst >> 12) & 7);
      uint32_t funct7 = ((inst >> 25) & 127);
      int64_t val1 = (int64_t)(*(nluint64_arr32*)self->regs).v[rs1];
      int64_t val2 = (int64_t)(*(nluint64_arr32*)self->regs).v[rs2];
      int64_t val;
      switch(((funct7 << 3) | funct3)) {
        case 0x0: {
          val = (val1 + val2);
          break;
        }
        case 0x100: {
          val = (val1 - val2);
          break;
        }
        case 0x1: {
          val = nelua_shl_nlint64(val1, (val2 & 0x1f));
          break;
        }
        case 0x2: {
          if((val1 < val2)) {
            val = 1;
          } else {
            val = 0;
          }
          break;
        }
        case 0x3: {
          if(((uint64_t)val1 < (uint64_t)val2)) {
            val = 1;
          } else {
            val = 0;
          }
          break;
        }
        case 0x4: {
          val = (val1 ^ val2);
          break;
        }
        case 0x5: {
          val = nelua_shr_nlint64(val1, (val2 & 0x1f));
          break;
        }
        case 0x105: {
          val = nelua_asr_nlint64(val1, (val2 & 0x1f));
          break;
        }
        case 0x6: {
          val = (val1 | val2);
          break;
        }
        case 0x7: {
          val = (val1 & val2);
          break;
        }
        case 0x8: {
          val = (val1 * val2);
          break;
        }
        case 0x9: {
          val = (int64_t)(uint64_t)nelua_shr_nlint128(((__int128)val1 * (__int128)val2), 64);
          break;
        }
        case 0xa: {
          val = (int64_t)(uint64_t)nelua_shr_nlint128(((__int128)val1 * (__int128)(uint64_t)val2), 64);
          break;
        }
        case 0xb: {
          val = (int64_t)(uint64_t)nelua_shr_nlint128(((__int128)(uint64_t)val1 * (__int128)(uint64_t)val2), 64);
          break;
        }
        case 0xc: {
          int64_t dividend = val1;
          int64_t divisor = val2;
          if(nelua_unlikely(((dividend == (-9223372036854775807LL-1)) && (divisor == -1)))) {
            val = (-9223372036854775807LL-1);
          } else if(nelua_unlikely((divisor == 0))) {
            val = -1;
          } else {
            val = (dividend / divisor);
          }
          break;
        }
        case 0xd: {
          uint64_t dividend = (uint64_t)val1;
          uint64_t divisor = (uint64_t)val2;
          if(nelua_unlikely((divisor == 0))) {
            val = -1;
          } else {
            val = (int64_t)(dividend / divisor);
          }
          break;
        }
        case 0xe: {
          int64_t dividend = val1;
          int64_t divisor = val2;
          if(nelua_unlikely(((dividend == (-9223372036854775807LL-1)) && (divisor == -1)))) {
            val = 0;
          } else if(nelua_unlikely((divisor == 0))) {
            val = dividend;
          } else {
            val = (dividend % divisor);
          }
          break;
        }
        case 0xf: {
          uint64_t dividend = (uint64_t)val1;
          uint64_t divisor = (uint64_t)val2;
          if(nelua_unlikely((divisor == 0))) {
            val = (int64_t)dividend;
          } else {
            val = (int64_t)(dividend % divisor);
          }
          break;
        }
        default: {
          nelua_panic_string(((nlstring){(uint8_t*)"illegal op instruction", 22}));
          break;
        }
      }
      if(nelua_likely((rd != 0))) {
        (*(nluint64_arr32*)self->regs).v[rd] = (uint64_t)val;
      }
      break;
    }
    case 0x3b: {
      uint32_t funct3 = ((inst >> 12) & 7);
      uint32_t funct7 = ((inst >> 25) & 127);
      int64_t val1 = (int64_t)(*(nluint64_arr32*)self->regs).v[rs1];
      int64_t val2 = (int64_t)(*(nluint64_arr32*)self->regs).v[rs2];
      int64_t val;
      switch(((funct7 << 3) | funct3)) {
        case 0x0: {
          val = (int64_t)(int32_t)(val1 + val2);
          break;
        }
        case 0x100: {
          val = (int64_t)(int32_t)(val1 - val2);
          break;
        }
        case 0x1: {
          val = (int64_t)(int32_t)nelua_shl_nlint64(val1, (val2 & 0x1f));
          break;
        }
        case 0x5: {
          val = (int64_t)(int32_t)nelua_shr_nlint64(val1, (val2 & 0x1f));
          break;
        }
        case 0x105: {
          val = (int64_t)(int32_t)nelua_asr_nlint64(val1, (val2 & 0x1f));
          break;
        }
        case 0x8: {
          val = (int64_t)((int32_t)val1 * (int32_t)val2);
          break;
        }
        case 0xc: {
          int32_t dividend = (int32_t)val1;
          int32_t divisor = (int32_t)val2;
          if(nelua_unlikely(((dividend == (-2147483647-1)) && (divisor == -1)))) {
            val = -2147483648;
          } else if(nelua_unlikely((divisor == 0))) {
            val = -1;
          } else {
            val = (int64_t)(dividend / divisor);
          }
          break;
        }
        case 0xd: {
          uint32_t dividend = (uint32_t)val1;
          uint32_t divisor = (uint32_t)val2;
          if(nelua_unlikely((divisor == 0))) {
            val = -1;
          } else {
            val = (int64_t)(int32_t)(dividend / divisor);
          }
          break;
        }
        case 0xe: {
          int32_t dividend = (int32_t)val1;
          int32_t divisor = (int32_t)val2;
          if(nelua_unlikely(((dividend == (-2147483647-1)) && (divisor == -1)))) {
            val = 0;
          } else if(nelua_unlikely((divisor == 0))) {
            val = (int64_t)dividend;
          } else {
            val = (int64_t)(dividend % divisor);
          }
          break;
        }
        case 0xf: {
          uint32_t dividend = (uint32_t)val1;
          uint32_t divisor = (uint32_t)val2;
          if(nelua_unlikely((divisor == 0))) {
            val = (int64_t)(int32_t)dividend;
          } else {
            val = (int64_t)(int32_t)(dividend % divisor);
          }
          break;
        }
        default: {
          nelua_panic_string(((nlstring){(uint8_t*)"illegal op-32 instruction", 25}));
          break;
        }
      }
      if(nelua_likely((rd != 0))) {
        (*(nluint64_arr32*)self->regs).v[rd] = (uint64_t)val;
      }
      break;
    }
    case 0x37: {
      int64_t imm = (int64_t)(((int32_t)((uint32_t)(int32_t)((inst << 0) & 4294963200LL) << 0)) >> 0);
      if(nelua_likely((rd != 0))) {
        (*(nluint64_arr32*)self->regs).v[rd] = (uint64_t)imm;
      }
      break;
    }
    case 0x17: {
      int64_t imm = (int64_t)(((int32_t)((uint32_t)(int32_t)((inst << 0) & 4294963200LL) << 0)) >> 0);
      if(nelua_likely((rd != 0))) {
        (*(nluint64_arr32*)self->regs).v[rd] = (uint64_t)(self->pc + imm);
      }
      break;
    }
    case 0x6f: {
      int64_t imm = (int64_t)(((int32_t)((uint32_t)(int32_t)(((((inst >> 11) & 1048576) | ((inst >> 20) & 2046)) | ((inst >> 9) & 2048)) | ((inst << 0) & 1044480)) << 11)) >> 11);
      if(nelua_likely((rd != 0))) {
        (*(nluint64_arr32*)self->regs).v[rd] = (uint64_t)(self->pc + 4);
      }
      self->pc = (self->pc + imm);
      return;
      break;
    }
    case 0x67: {
      int64_t imm = (int64_t)(((int32_t)((uint32_t)(int32_t)((inst >> 20) & 4095) << 20)) >> 20);
      int64_t pc = (self->pc + 4);
      self->pc = ((int64_t)((*(nluint64_arr32*)self->regs).v[rs1] + imm) & -2);
      if(nelua_unlikely((rd != 0))) {
        (*(nluint64_arr32*)self->regs).v[rd] = (uint64_t)pc;
      }
      return;
      break;
    }
    case 0x63: {
      uint32_t funct3 = ((inst >> 12) & 7);
      int64_t imm = (int64_t)(((int32_t)((uint32_t)(int32_t)(((((inst >> 19) & 4096) | ((inst >> 20) & 2016)) | ((inst >> 7) & 30)) | ((inst << 4) & 2048)) << 19)) >> 19);
      uint64_t val1 = (*(nluint64_arr32*)self->regs).v[rs1];
      uint64_t val2 = (*(nluint64_arr32*)self->regs).v[rs2];
      bool cond;
      switch(funct3) {
        case 0x0: {
          cond = (val1 == val2);
          break;
        }
        case 0x1: {
          cond = (val1 != val2);
          break;
        }
        case 0x4: {
          cond = ((int64_t)val1 < (int64_t)val2);
          break;
        }
        case 0x5: {
          cond = ((int64_t)val1 >= (int64_t)val2);
          break;
        }
        case 0x6: {
          cond = (val1 < val2);
          break;
        }
        case 0x7: {
          cond = (val1 >= val2);
          break;
        }
        default: {
          nelua_panic_string(((nlstring){(uint8_t*)"illegal branch instruction", 26}));
          break;
        }
      }
      if(cond) {
        self->pc = (self->pc + imm);
        return;
      }
      break;
    }
    case 0xf: {
      break;
    }
    case 0x73: {
      uint32_t funct11 = ((inst >> 20) & 4095);
      switch(funct11) {
        case 0x0: {
          uint64_t code = (*(nluint64_arr32*)self->regs).v[17];
          (*(nluint64_arr32*)self->regs).v[10] = machine_Machine_handle_syscall(self, code);
          break;
        }
        case 0x1: {
          self->exitcode = -1;
          self->running = false;
          break;
        }
        default: {
          nelua_panic_string(((nlstring){(uint8_t*)"illegal system instruction", 26}));
          break;
        }
      }
      break;
    }
    default: {
      nelua_panic_string(((nlstring){(uint8_t*)"illegal instruction", 19}));
      break;
    }
  }
  self->pc = (self->pc + 4);
}
void machine_Machine_run(machine_Machine_ptr self) {
  self->running = true;
  while(nelua_likely(self->running)) {
    uint32_t inst = machine_Machine_fetch(self);
    machine_Machine_execute(self, inst);
  }
}
void nelua_print_3(nlstring a1) {
  if(a1.size > 0) {
    fwrite(a1.data, 1, a1.size, stdout);
  }
  fputc('\n', stdout);
  fflush(stdout);
}
nlstring nelua_cstring2string(const char* s){
  if(s == NULL) return (nlstring){0};
  uintptr_t size = strlen(s);
  if(size == 0) return (nlstring){0};
  return (nlstring){(uint8_t*)s, size};
}
int nelua_main(int nelua_argc, char** nelua_argv) {
  if((nelua_argc != 2)) {
    nelua_print_3(((nlstring){(uint8_t*)"please supply a RV64I program to run!", 37}));
    exit(1);
  }
  riscvm_filename = nelua_argv[1];
  machine_Machine_loadfile((&riscvm_machine), nelua_cstring2string(riscvm_filename));
  machine_Machine_run((&riscvm_machine));
  exit((int)riscvm_machine.exitcode);
  return 0;
}
int main(int argc, char** argv) {
  return nelua_main(argc, argv);
}

