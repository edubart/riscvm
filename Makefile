EXAMPLE=fib
FILE=examples/$(EXAMPLE)
NELUA=nelua
TOOLCHAIN=riscv64-elf
CC=$(TOOLCHAIN)-gcc
OBJDUMP=$(TOOLCHAIN)-objdump
OBJCOPY=$(TOOLCHAIN)-objcopy
CFLAGS=-march=rv64i -mabi=lp64 \
	-nostdlib \
	-Wl,-T,lib/link.ld \
	-I lib \
	-O2

example:
	$(CC) $(CFLAGS) -o $(FILE).out $(FILE).c lib/tinyc.c lib/start.s
# 	$(OBJDUMP) -M no-aliases -x -d $(FILE).out
	$(OBJCOPY) -O binary $(FILE).out $(FILE).bin
	$(NELUA) -qr riscvm.nelua $(FILE).bin

csrc:
	$(NELUA) --print-code riscvm.nelua > riscvm.c

clean:
	rm -f tests/*.out tests/*.bin
