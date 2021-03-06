/* ------------------------------ DECLARATIONS ------------------------------ */
#ifdef __GNUC__
#pragma GCC diagnostic error   "-Wimplicit-function-declaration"
#pragma GCC diagnostic error   "-Wimplicit-int"
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
#pragma GCC diagnostic ignored "-Wmissing-braces"
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wattributes"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#if defined(__clang__)
#pragma GCC diagnostic ignored "-Wunused"
#else
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"
#endif
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
#if __STDC_VERSION__ >= 201112L
#define nelua_static_assert _Static_assert
#else
#define nelua_static_assert(x, y)
#endif
nelua_static_assert(sizeof(void*) == 8, "Nelua and C disagree on architecture size");
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
typedef struct nlstringview nlstringview;
typedef uint8_t* nluint8_arr0_ptr;
struct nlstringview {
  nluint8_arr0_ptr data;
  uintptr_t size;
};
nelua_static_assert(sizeof(nlstringview) == 16, "Nelua and C disagree on type size");
typedef struct {nlstringview data[32];} nlstringview_arr32;
nelua_static_assert(sizeof(nlstringview_arr32) == 512, "Nelua and C disagree on type size");
static char __strlit1[5] = "zero";
static char __strlit2[3] = "ra";
static char __strlit3[3] = "sp";
static char __strlit4[3] = "gp";
static char __strlit5[3] = "tp";
static char __strlit6[3] = "t0";
static char __strlit7[3] = "t1";
static char __strlit8[3] = "t2";
static char __strlit9[3] = "s0";
static char __strlit10[3] = "s1";
static char __strlit11[3] = "a0";
static char __strlit12[3] = "a1";
static char __strlit13[3] = "a2";
static char __strlit14[3] = "a3";
static char __strlit15[3] = "a4";
static char __strlit16[3] = "a5";
static char __strlit17[3] = "a6";
static char __strlit18[3] = "a7";
static char __strlit19[3] = "s2";
static char __strlit20[3] = "s3";
static char __strlit21[3] = "s4";
static char __strlit22[3] = "s5";
static char __strlit23[3] = "s6";
static char __strlit24[3] = "s7";
static char __strlit25[3] = "s8";
static char __strlit26[3] = "s9";
static char __strlit27[4] = "s10";
static char __strlit28[4] = "s11";
static char __strlit29[3] = "t3";
static char __strlit30[3] = "t4";
static char __strlit31[3] = "t5";
static char __strlit32[3] = "t6";
static nlstringview_arr32 machine_REGNAMES = {{{(uint8_t*)__strlit1, 4}, {(uint8_t*)__strlit2, 2}, {(uint8_t*)__strlit3, 2}, {(uint8_t*)__strlit4, 2}, {(uint8_t*)__strlit5, 2}, {(uint8_t*)__strlit6, 2}, {(uint8_t*)__strlit7, 2}, {(uint8_t*)__strlit8, 2}, {(uint8_t*)__strlit9, 2}, {(uint8_t*)__strlit10, 2}, {(uint8_t*)__strlit11, 2}, {(uint8_t*)__strlit12, 2}, {(uint8_t*)__strlit13, 2}, {(uint8_t*)__strlit14, 2}, {(uint8_t*)__strlit15, 2}, {(uint8_t*)__strlit16, 2}, {(uint8_t*)__strlit17, 2}, {(uint8_t*)__strlit18, 2}, {(uint8_t*)__strlit19, 2}, {(uint8_t*)__strlit20, 2}, {(uint8_t*)__strlit21, 2}, {(uint8_t*)__strlit22, 2}, {(uint8_t*)__strlit23, 2}, {(uint8_t*)__strlit24, 2}, {(uint8_t*)__strlit25, 2}, {(uint8_t*)__strlit26, 2}, {(uint8_t*)__strlit27, 3}, {(uint8_t*)__strlit28, 3}, {(uint8_t*)__strlit29, 2}, {(uint8_t*)__strlit30, 2}, {(uint8_t*)__strlit31, 2}, {(uint8_t*)__strlit32, 2}}};
typedef struct machine_Machine machine_Machine;
typedef machine_Machine* machine_Machine_ptr;
struct machine_Machine {
  bool running;
  int64_t pc;
  uint64_t regs[32];
  uint8_t memory[134217728];
  int64_t exitcode;
};
nelua_static_assert(sizeof(machine_Machine) == 134218008, "Nelua and C disagree on type size");
static char __strlit33[3] = "rb";
#include <stdlib.h>
#define nelua_noreturn __attribute__((noreturn))
static nelua_noreturn void nelua_panic_stringview(nlstringview s);
static char __strlit34[20] = "failed to open file";
static void machine_Machine_loadfile(machine_Machine_ptr self, nlstringview filename);
typedef uint32_t* nluint32_ptr;
static inline uint32_t machine_Machine_fetch(machine_Machine_ptr self);
typedef struct nlniltype {} nlniltype;
static inline int8_t machine_Machine_read__1(machine_Machine_ptr self, nlniltype T, uint64_t addr);
typedef uint16_t* nluint16_ptr;
static inline int16_t machine_Machine_read__2(machine_Machine_ptr self, nlniltype T, uint64_t addr);
static inline int32_t machine_Machine_read__3(machine_Machine_ptr self, nlniltype T, uint64_t addr);
typedef uint64_t* nluint64_ptr;
static inline int64_t machine_Machine_read__4(machine_Machine_ptr self, nlniltype T, uint64_t addr);
static inline uint8_t machine_Machine_read__5(machine_Machine_ptr self, nlniltype T, uint64_t addr);
static inline uint16_t machine_Machine_read__6(machine_Machine_ptr self, nlniltype T, uint64_t addr);
static inline uint32_t machine_Machine_read__7(machine_Machine_ptr self, nlniltype T, uint64_t addr);
static inline void* machine_Machine_getptr(machine_Machine_ptr self, uint64_t addr);
static inline void machine_Machine_write__1(machine_Machine_ptr self, uint64_t addr, uint8_t val);
static inline void machine_Machine_write__2(machine_Machine_ptr self, uint64_t addr, uint16_t val);
static inline void machine_Machine_write__3(machine_Machine_ptr self, uint64_t addr, uint32_t val);
static inline void machine_Machine_write__4(machine_Machine_ptr self, uint64_t addr, uint64_t val);
static char __strlit35[18] = "x0 (%s) = 0x%08x\t";
static char __strlit36[18] = "x1 (%s) = 0x%08x\t";
static char __strlit37[18] = "x2 (%s) = 0x%08x\t";
static char __strlit38[19] = "x3 (%s) = 0x%08x\t\n";
static char __strlit39[18] = "x4 (%s) = 0x%08x\t";
static char __strlit40[18] = "x5 (%s) = 0x%08x\t";
static char __strlit41[18] = "x6 (%s) = 0x%08x\t";
static char __strlit42[19] = "x7 (%s) = 0x%08x\t\n";
static char __strlit43[18] = "x8 (%s) = 0x%08x\t";
static char __strlit44[18] = "x9 (%s) = 0x%08x\t";
static char __strlit45[19] = "x10 (%s) = 0x%08x\t";
static char __strlit46[20] = "x11 (%s) = 0x%08x\t\n";
static char __strlit47[19] = "x12 (%s) = 0x%08x\t";
static char __strlit48[19] = "x13 (%s) = 0x%08x\t";
static char __strlit49[19] = "x14 (%s) = 0x%08x\t";
static char __strlit50[20] = "x15 (%s) = 0x%08x\t\n";
static char __strlit51[19] = "x16 (%s) = 0x%08x\t";
static char __strlit52[19] = "x17 (%s) = 0x%08x\t";
static char __strlit53[19] = "x18 (%s) = 0x%08x\t";
static char __strlit54[20] = "x19 (%s) = 0x%08x\t\n";
static char __strlit55[19] = "x20 (%s) = 0x%08x\t";
static char __strlit56[19] = "x21 (%s) = 0x%08x\t";
static char __strlit57[19] = "x22 (%s) = 0x%08x\t";
static char __strlit58[20] = "x23 (%s) = 0x%08x\t\n";
static char __strlit59[19] = "x24 (%s) = 0x%08x\t";
static char __strlit60[19] = "x25 (%s) = 0x%08x\t";
static char __strlit61[19] = "x26 (%s) = 0x%08x\t";
static char __strlit62[20] = "x27 (%s) = 0x%08x\t\n";
static char __strlit63[19] = "x28 (%s) = 0x%08x\t";
static char __strlit64[19] = "x29 (%s) = 0x%08x\t";
static char __strlit65[19] = "x30 (%s) = 0x%08x\t";
static char __strlit66[20] = "x31 (%s) = 0x%08x\t\n";
static char __strlit67[13] = "pc = 0x%08x\n";
static void machine_Machine_dump_registers(machine_Machine_ptr self);
static char __strlit68[9] = "aborted!";
#include <inttypes.h>
static void __nelua_print1(char* a1);
static void __nelua_print2(int64_t a1);
static char __strlit69[20] = "illegal system call";
static uint64_t machine_Machine_handle_syscall(machine_Machine_ptr self, uint64_t code);
#define NLNIL (nlniltype){}
static char __strlit70[25] = "illegal load instruction";
#ifdef __GNUC__
#define nelua_likely(x) __builtin_expect(x, 1)
#define nelua_unlikely(x) __builtin_expect(x, 0)
#else
#define nelua_likely(x) (x)
#define nelua_unlikely(x) (x)
#endif
static char __strlit71[26] = "illegal store instruction";
static int64_t nelua_shl_int64(int64_t a, int64_t b);
static int64_t nelua_shr_int64(int64_t a, int64_t b);
static int64_t nelua_asr_int64(int64_t a, int64_t b);
static char __strlit72[33] = "illegal op-imm shift instruction";
static char __strlit73[27] = "illegal op-imm instruction";
static char __strlit74[36] = "illegal op-imm-32 shift instruction";
static char __strlit75[30] = "illegal op-imm-32 instruction";
static __int128 nelua_shr_int128(__int128 a, __int128 b);
static char __strlit76[23] = "illegal op instruction";
static char __strlit77[26] = "illegal op-32 instruction";
static char __strlit78[27] = "illegal branch instruction";
static char __strlit79[27] = "illegal system instruction";
static char __strlit80[20] = "illegal instruction";
static inline void machine_Machine_execute(machine_Machine_ptr self, uint32_t inst);
#define nelua_noinline __attribute__((noinline))
static nelua_noinline __attribute__((optimize("no-crossjumping,no-gcse"))) void machine_Machine_run(machine_Machine_ptr self);
typedef char** nlcstring_ptr;
static void __nelua_print3(nlstringview a1);
static void nelua_stdout_write_stringview(nlstringview s);
static char __strlit81[38] = "please supply a RV64I program to run!";
static char* riscvm_filename = NULL;
static machine_Machine riscvm_machine = {0};
static nlstringview nelua_cstring2stringview(char *s);
static int nelua_main(int nelua_argc, char** nelua_argv);
/* ------------------------------ DEFINITIONS ------------------------------- */
void nelua_panic_stringview(nlstringview s) {
  if(s.data && s.size > 0) {
    fprintf(stderr, "%s\n", (char*)s.data);
  }
  abort();
}
void machine_Machine_loadfile(machine_Machine_ptr self, nlstringview filename) {
  void* fp = fopen(((char*)(filename.data)), __strlit33);
  if(!fp) {
    nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit34, 19}));
  }
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  fread((void*)(&self->memory[4096]), (size_t)size, (size_t)1U, fp);
  fclose(fp);
  self->regs[2] = 134217728U;
  self->pc = 4096;
}
uint32_t machine_Machine_fetch(machine_Machine_ptr self) {
  return (*(nluint32_ptr)(&self->memory[self->pc]));
}
int8_t machine_Machine_read__1(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (int8_t)(*(&self->memory[addr]));
}
int16_t machine_Machine_read__2(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (int16_t)(*(nluint16_ptr)(&self->memory[addr]));
}
int32_t machine_Machine_read__3(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (int32_t)(*(nluint32_ptr)(&self->memory[addr]));
}
int64_t machine_Machine_read__4(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (int64_t)(*(nluint64_ptr)(&self->memory[addr]));
}
uint8_t machine_Machine_read__5(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (*(&self->memory[addr]));
}
uint16_t machine_Machine_read__6(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (*(nluint16_ptr)(&self->memory[addr]));
}
uint32_t machine_Machine_read__7(machine_Machine_ptr self, nlniltype T, uint64_t addr) {
  return (*(nluint32_ptr)(&self->memory[addr]));
}
void* machine_Machine_getptr(machine_Machine_ptr self, uint64_t addr) {
  return (void*)(&self->memory[addr]);
}
void machine_Machine_write__1(machine_Machine_ptr self, uint64_t addr, uint8_t val) {
  (*(&self->memory[addr])) = val;
}
void machine_Machine_write__2(machine_Machine_ptr self, uint64_t addr, uint16_t val) {
  (*(nluint16_ptr)(&self->memory[addr])) = val;
}
void machine_Machine_write__3(machine_Machine_ptr self, uint64_t addr, uint32_t val) {
  (*(nluint32_ptr)(&self->memory[addr])) = val;
}
void machine_Machine_write__4(machine_Machine_ptr self, uint64_t addr, uint64_t val) {
  (*(nluint64_ptr)(&self->memory[addr])) = val;
}
void machine_Machine_dump_registers(machine_Machine_ptr self) {
  printf(__strlit35, machine_REGNAMES.data[0], self->regs[0]);
  printf(__strlit36, machine_REGNAMES.data[1], self->regs[1]);
  printf(__strlit37, machine_REGNAMES.data[2], self->regs[2]);
  printf(__strlit38, machine_REGNAMES.data[3], self->regs[3]);
  printf(__strlit39, machine_REGNAMES.data[4], self->regs[4]);
  printf(__strlit40, machine_REGNAMES.data[5], self->regs[5]);
  printf(__strlit41, machine_REGNAMES.data[6], self->regs[6]);
  printf(__strlit42, machine_REGNAMES.data[7], self->regs[7]);
  printf(__strlit43, machine_REGNAMES.data[8], self->regs[8]);
  printf(__strlit44, machine_REGNAMES.data[9], self->regs[9]);
  printf(__strlit45, machine_REGNAMES.data[10], self->regs[10]);
  printf(__strlit46, machine_REGNAMES.data[11], self->regs[11]);
  printf(__strlit47, machine_REGNAMES.data[12], self->regs[12]);
  printf(__strlit48, machine_REGNAMES.data[13], self->regs[13]);
  printf(__strlit49, machine_REGNAMES.data[14], self->regs[14]);
  printf(__strlit50, machine_REGNAMES.data[15], self->regs[15]);
  printf(__strlit51, machine_REGNAMES.data[16], self->regs[16]);
  printf(__strlit52, machine_REGNAMES.data[17], self->regs[17]);
  printf(__strlit53, machine_REGNAMES.data[18], self->regs[18]);
  printf(__strlit54, machine_REGNAMES.data[19], self->regs[19]);
  printf(__strlit55, machine_REGNAMES.data[20], self->regs[20]);
  printf(__strlit56, machine_REGNAMES.data[21], self->regs[21]);
  printf(__strlit57, machine_REGNAMES.data[22], self->regs[22]);
  printf(__strlit58, machine_REGNAMES.data[23], self->regs[23]);
  printf(__strlit59, machine_REGNAMES.data[24], self->regs[24]);
  printf(__strlit60, machine_REGNAMES.data[25], self->regs[25]);
  printf(__strlit61, machine_REGNAMES.data[26], self->regs[26]);
  printf(__strlit62, machine_REGNAMES.data[27], self->regs[27]);
  printf(__strlit63, machine_REGNAMES.data[28], self->regs[28]);
  printf(__strlit64, machine_REGNAMES.data[29], self->regs[29]);
  printf(__strlit65, machine_REGNAMES.data[30], self->regs[30]);
  printf(__strlit66, machine_REGNAMES.data[31], self->regs[31]);
  printf(__strlit67, self->pc);
}
inline void __nelua_print1(char* a1) {
  printf("%s", a1);
  printf("\n");
}
inline void __nelua_print2(int64_t a1) {
  printf("%" PRIi64, a1);
  printf("\n");
}
uint64_t machine_Machine_handle_syscall(machine_Machine_ptr self, uint64_t code) {
  switch(code) {
    case 10000: {
      self->running = false;
      self->exitcode = (int64_t)self->regs[10];
      break;
    }
    case 10001: {
      nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit68, 8}));
      break;
    }
    case 10007: {
      void* dest = machine_Machine_getptr(self, self->regs[10]);
      uint64_t c = self->regs[11];
      uint64_t len = self->regs[12];
      void* res = memset(dest, (int)c, (size_t)len);
      return (uint64_t)res;
      break;
    }
    case 10101: {
      char* s = (char*)machine_Machine_getptr(self, self->regs[10]);
      __nelua_print1(s);
      break;
    }
    case 10102: {
      int64_t i = (int64_t)self->regs[10];
      __nelua_print2(i);
      break;
    }
    default: {
      nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit69, 19}));
      break;
    }
  }
  return 0U;
}
inline int64_t nelua_shl_int64(int64_t a, int64_t b) {
  if(nelua_likely(b >= 0 && b < 64)) return (uint64_t)a << b;
  else if(nelua_unlikely(b < 0 && b > -64)) return (uint64_t)a >> -b;
  else return 0;
}
inline int64_t nelua_shr_int64(int64_t a, int64_t b) {
  if(nelua_likely(b >= 0 && b < 64)) return (uint64_t)a >> b;
  else if(nelua_unlikely(b < 0 && b > -64)) return (uint64_t)a << -b;
  else return 0;
}
inline int64_t nelua_asr_int64(int64_t a, int64_t b) {
  if(nelua_likely(b >= 0 && b < 64)) return a >> b;
  else if(nelua_unlikely(b >= 64)) return a < 0 ? -1 : 0;
  else if(nelua_unlikely(b < 0 && b > -64)) return a << -b;
  else return 0;
}
inline __int128 nelua_shr_int128(__int128 a, __int128 b) {
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
      int64_t imm = (int64_t)(((int32_t)((inst >> 20) & 4095) << 20) >> 20);
      uint64_t addr = (self->regs[rs1] + (uint64_t)imm);
      int64_t val;
      switch(funct3) {
        case 0x0: {
          val = (int64_t)machine_Machine_read__1(self, NLNIL, addr);
          break;
        }
        case 0x1: {
          val = (int64_t)machine_Machine_read__2(self, NLNIL, addr);
          break;
        }
        case 0x2: {
          val = (int64_t)machine_Machine_read__3(self, NLNIL, addr);
          break;
        }
        case 0x3: {
          val = machine_Machine_read__4(self, NLNIL, addr);
          break;
        }
        case 0x4: {
          val = (int64_t)machine_Machine_read__5(self, NLNIL, addr);
          break;
        }
        case 0x5: {
          val = (int64_t)machine_Machine_read__6(self, NLNIL, addr);
          break;
        }
        case 0x6: {
          val = (int64_t)machine_Machine_read__7(self, NLNIL, addr);
          break;
        }
        default: {
          nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit70, 24}));
          break;
        }
      }
      if(nelua_likely((rd != 0U))) {
        self->regs[rd] = (uint64_t)val;
      }
      break;
    }
    case 0x23: {
      uint32_t funct3 = ((inst >> 12) & 7);
      int64_t imm = (int64_t)(((int32_t)(((inst >> 20) & 4064) | ((inst >> 7) & 31)) << 20) >> 20);
      uint64_t addr = (self->regs[rs1] + (uint64_t)imm);
      uint64_t val = self->regs[rs2];
      switch(funct3) {
        case 0x0: {
          machine_Machine_write__1(self, addr, (uint8_t)val);
          break;
        }
        case 0x1: {
          machine_Machine_write__2(self, addr, (uint16_t)val);
          break;
        }
        case 0x2: {
          machine_Machine_write__3(self, addr, (uint32_t)val);
          break;
        }
        case 0x3: {
          machine_Machine_write__4(self, addr, val);
          break;
        }
        default: {
          nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit71, 25}));
          break;
        }
      }
      break;
    }
    case 0x13: {
      uint32_t funct3 = ((inst >> 12) & 7);
      int64_t imm = (int64_t)(((int32_t)((inst >> 20) & 4095) << 20) >> 20);
      uint32_t shamt = ((inst >> 20) & 63);
      int64_t val = (int64_t)self->regs[rs1];
      switch(funct3) {
        case 0x0: {
          val = (val + imm);
          break;
        }
        case 0x1: {
          val = (nelua_shl_int64(val, shamt));
          break;
        }
        case 0x2: {
          if(val < imm) {
            val = 1;
          } else {
            val = 0;
          }
          break;
        }
        case 0x3: {
          if((uint64_t)val < (uint64_t)imm) {
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
              val = (nelua_shr_int64(val, shamt));
              break;
            }
            case 0x1: {
              val = (nelua_asr_int64(val, shamt));
              break;
            }
            default: {
              nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit72, 32}));
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
          nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit73, 26}));
          break;
        }
      }
      if(nelua_likely((rd != 0U))) {
        self->regs[rd] = (uint64_t)val;
      }
      break;
    }
    case 0x1b: {
      uint32_t funct3 = ((inst >> 12) & 7);
      int64_t imm = (int64_t)(((int32_t)((inst >> 20) & 4095) << 20) >> 20);
      int64_t val = (int64_t)self->regs[rs1];
      switch(funct3) {
        case 0x0: {
          val = (int64_t)(int32_t)(val + imm);
          break;
        }
        case 0x1: {
          val = (int64_t)(int32_t)(nelua_shl_int64(val, imm));
          break;
        }
        case 0x5: {
          uint32_t shamt = rs2;
          uint32_t funct7 = ((inst >> 25) & 127);
          switch((funct7 >> 5)) {
            case 0x0: {
              val = (int64_t)(int32_t)(nelua_shr_int64(val, shamt));
              break;
            }
            case 0x1: {
              val = (int64_t)(int32_t)(nelua_asr_int64(val, shamt));
              break;
            }
            default: {
              nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit74, 35}));
              break;
            }
          }
          break;
        }
        default: {
          nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit75, 29}));
          break;
        }
      }
      if(nelua_likely((rd != 0U))) {
        self->regs[rd] = (uint64_t)val;
      }
      break;
    }
    case 0x33: {
      uint32_t funct3 = ((inst >> 12) & 7);
      uint32_t funct7 = ((inst >> 25) & 127);
      int64_t val1 = (int64_t)self->regs[rs1];
      int64_t val2 = (int64_t)self->regs[rs2];
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
          val = (nelua_shl_int64(val1, (val2 & 0x1f)));
          break;
        }
        case 0x2: {
          if(val1 < val2) {
            val = 1;
          } else {
            val = 0;
          }
          break;
        }
        case 0x3: {
          if((uint64_t)val1 < (uint64_t)val2) {
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
          val = (nelua_shr_int64(val1, (val2 & 0x1f)));
          break;
        }
        case 0x105: {
          val = (nelua_asr_int64(val1, (val2 & 0x1f)));
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
          val = (int64_t)(uint64_t)(nelua_shr_int128(((__int128)val1 * (__int128)val2), 64));
          break;
        }
        case 0xa: {
          val = (int64_t)(uint64_t)(nelua_shr_int128(((__int128)val1 * (__int128)(uint64_t)val2), 64));
          break;
        }
        case 0xb: {
          val = (int64_t)(uint64_t)(nelua_shr_int128(((__int128)(uint64_t)val1 * (__int128)(uint64_t)val2), 64));
          break;
        }
        case 0xc: {
          int64_t dividend = val1;
          int64_t divisor = val2;
          if(nelua_unlikely(((dividend == -9223372036854775807-1) && (divisor == -1)))) {
            val = -9223372036854775807-1;
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
          if(nelua_unlikely((divisor == 0U))) {
            val = -1;
          } else {
            val = (int64_t)(dividend / divisor);
          }
          break;
        }
        case 0xe: {
          int64_t dividend = val1;
          int64_t divisor = val2;
          if(nelua_unlikely(((dividend == -9223372036854775807-1) && (divisor == -1)))) {
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
          if(nelua_unlikely((divisor == 0U))) {
            val = (int64_t)dividend;
          } else {
            val = (int64_t)(dividend % divisor);
          }
          break;
        }
        default: {
          nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit76, 22}));
          break;
        }
      }
      if(nelua_likely((rd != 0U))) {
        self->regs[rd] = (uint64_t)val;
      }
      break;
    }
    case 0x3b: {
      uint32_t funct3 = ((inst >> 12) & 7);
      uint32_t funct7 = ((inst >> 25) & 127);
      int64_t val1 = (int64_t)self->regs[rs1];
      int64_t val2 = (int64_t)self->regs[rs2];
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
          val = (int64_t)(int32_t)(nelua_shl_int64(val1, (val2 & 0x1f)));
          break;
        }
        case 0x5: {
          val = (int64_t)(int32_t)(nelua_shr_int64(val1, (val2 & 0x1f)));
          break;
        }
        case 0x105: {
          val = (int64_t)(int32_t)(nelua_asr_int64(val1, (val2 & 0x1f)));
          break;
        }
        case 0x8: {
          val = (int64_t)((int32_t)val1 * (int32_t)val2);
          break;
        }
        case 0xc: {
          int32_t dividend = (int32_t)val1;
          int32_t divisor = (int32_t)val2;
          if(nelua_unlikely(((dividend == -2147483647-1) && (divisor == -1)))) {
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
          if(nelua_unlikely((divisor == 0U))) {
            val = -1;
          } else {
            val = (int64_t)(int32_t)(dividend / divisor);
          }
          break;
        }
        case 0xe: {
          int32_t dividend = (int32_t)val1;
          int32_t divisor = (int32_t)val2;
          if(nelua_unlikely(((dividend == -2147483647-1) && (divisor == -1)))) {
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
          if(nelua_unlikely((divisor == 0U))) {
            val = (int64_t)(int32_t)dividend;
          } else {
            val = (int64_t)(int32_t)(dividend % divisor);
          }
          break;
        }
        default: {
          nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit77, 25}));
          break;
        }
      }
      if(nelua_likely((rd != 0U))) {
        self->regs[rd] = (uint64_t)val;
      }
      break;
    }
    case 0x37: {
      int64_t imm = (int64_t)(((int32_t)((inst << 0) & 4294963200) << 0) >> 0);
      if(nelua_likely((rd != 0U))) {
        self->regs[rd] = (uint64_t)imm;
      }
      break;
    }
    case 0x17: {
      int64_t imm = (int64_t)(((int32_t)((inst << 0) & 4294963200) << 0) >> 0);
      if(nelua_likely((rd != 0U))) {
        self->regs[rd] = (uint64_t)(self->pc + imm);
      }
      break;
    }
    case 0x6f: {
      int64_t imm = (int64_t)(((int32_t)(((((inst >> 11) & 1048576) | ((inst >> 20) & 2046)) | ((inst >> 9) & 2048)) | ((inst << 0) & 1044480)) << 11) >> 11);
      if(nelua_likely((rd != 0U))) {
        self->regs[rd] = (uint64_t)(self->pc + 4);
      }
      self->pc = (self->pc + imm);
      return;
      break;
    }
    case 0x67: {
      int64_t imm = (int64_t)(((int32_t)((inst >> 20) & 4095) << 20) >> 20);
      int64_t pc = (self->pc + 4);
      self->pc = ((self->regs[rs1] + imm) & -2);
      if(nelua_unlikely((rd != 0U))) {
        self->regs[rd] = (uint64_t)pc;
      }
      return;
      break;
    }
    case 0x63: {
      uint32_t funct3 = ((inst >> 12) & 7);
      int64_t imm = (int64_t)(((int32_t)(((((inst >> 19) & 4096) | ((inst >> 20) & 2016)) | ((inst >> 7) & 30)) | ((inst << 4) & 2048)) << 19) >> 19);
      uint64_t val1 = self->regs[rs1];
      uint64_t val2 = self->regs[rs2];
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
          nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit78, 26}));
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
          uint64_t code = self->regs[17];
          self->regs[10] = machine_Machine_handle_syscall(self, code);
          break;
        }
        case 0x1: {
          self->exitcode = -1;
          self->running = false;
          break;
        }
        default: {
          nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit79, 26}));
          break;
        }
      }
      break;
    }
    default: {
      nelua_panic_stringview(((nlstringview){(uint8_t*)__strlit80, 19}));
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
inline void nelua_stdout_write_stringview(nlstringview s) {
  if(s.data && s.size > 0) {
    fwrite((char*)s.data, s.size, 1, stdout);
  }
}
inline void __nelua_print3(nlstringview a1) {
  nelua_stdout_write_stringview(a1);
  printf("\n");
}
inline nlstringview nelua_cstring2stringview(char *s) {
  if(s == NULL) return (nlstringview){0};
  uintptr_t size = strlen(s);
  if(size == 0) return (nlstringview){0};
  return (nlstringview){(uint8_t*)s, size};
}
int nelua_main(int nelua_argc, char** nelua_argv) {
  if(nelua_argc != 2) {
    __nelua_print3(((nlstringview){(uint8_t*)__strlit81, 37}));
    exit(1);
  }
  riscvm_filename = (nelua_argv)[1];
  machine_Machine_loadfile(&riscvm_machine, nelua_cstring2stringview(riscvm_filename));
  machine_Machine_run(&riscvm_machine);
  exit((int)riscvm_machine.exitcode);
  return 0;
}
int main(int argc, char **argv) {
  return nelua_main(argc, argv);
}

