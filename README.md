Hardware Platfor : STM32F407G - DISC-1 Board
Editor and Comiler - VS Code with GCC complier, used Open OCD on mac terminal for debugging.

Objective: To build the whole GCC tool chain from scratch that includes
**Startup File** - startup file that is able to define vector table, exception handlers, reset handler with atleast basic functionalities.
**Linker File** - Linker file that defines range of stack, heap, flash and RAM. Defines the placement of different types of program sections in different memory areas.
**Make File** - Make file that is able to build, clean, load and make a library of source code.

Debugging was done using **open OCD(On Chip Debugger) and GDB** with MAC terminal. Steps for debugging setup are defined below:
1. Flash the image using **"make load"** (optional)
2. Start **openocd - openocd -f interface/stlink.cfg -f target/stm32f4x.cfg**
3. Open a new terminal and run **"arm-none-eabi-gdb build/my_app.elf"** - launches GDB debugger and loads elf file
4. In GDB terminal run "**target remote localhost:3333"**, it connects GDB to openOCD
5. load
6. break main
7. Continue
8. for reset and continue - monitor reset init
9. for reset and halt - monitor reset halt
    **Other useful command**
   1. step - next instruction
   2. next - step over
   3. finish - finish the function
   4. info reg - CPU registers
   5. print variable
   6. set variable
   7. delete - all breakpoints
   8. info b - show all breakpoints
   10. bt - backtrace
  
   **Other GNU Toolchain utilities**
   1. arm-none-eabi-objdump -d build/my_app.elf - disassemble
   2. arm-none-eabi-objdump -S build/my_app.elf - source + assembly
   3. arm-none-eabi-objdump -h build/my_app.elf - show headers
   4. arm-none-eabi-objdump -d -j .text build/my_app.elf - filter only .txt disassembly
   5. arm-none-eabi-nm build/my_app.elf - symbol list
   6. arm-none-eabi-nm -n build/my_app.elf - sorted symbol list
   7. arm-none-eabi-size build/my_app.elf
   8. arm-none-eabi-size -Ax build/my_app.elf
   9. arm-none-eabi-readelf -S build/my_app.elf - header from elf
   10. arm-none-eabi-readelf -s build/my_app.elf - symbol table from elf
   11. arm-none-eabi-readelf -h build/my_app.elf - entry point
   12. arm-none-eabi-readelf -a build/my_app.elf - full elf dump
   13. arm-none-eabi-objcopy -O binary build/my_app.elf Output/my_app.bin - elf to bin
   14. arm-none-eabi-objcopy -O ihex build/my_app.elf Output/my_app.hex - elf to hex

