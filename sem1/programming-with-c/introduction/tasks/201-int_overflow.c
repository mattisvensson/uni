/* check_int_overflow.c Check when integer numbers are overflowing */
// TO DO 1: complete the overflow detecion for other types 
// TO DO 2: extend this to unsigned integers 
// TO DO 3: stop counting after first overflow 
// TO DO 4: estimate how many operations are performed per second. ~4mrds/s
// TO DO 5 (optional): Use this program as benchmark for your CPU performance and compare it with other students' computers,
// TO DO 6 (optional): Check the CPU load when running the programm. What do you observe? 

#include <stdio.h>
#include <stdbool.h>

int main() {
    char c = 0, old_c;
    short s = 0, old_s;
    int i = 0, old_i;
    long l = 0, old_l;

    unsigned char uc = 0, old_uc;
    unsigned short us = 0, old_us;
    unsigned int ui = 0, old_ui;
    unsigned long ul = 0, old_ul;

    bool is_overflow = false;

    // Loop for char
    while (!is_overflow) {
        old_c = c;
        c = c + 1;
        if (old_c > c) {
            printf("char overflow %d -> %d \n", old_c, c);
            is_overflow = true;
        }
    }

    is_overflow = false; // Reset overflow flag

    // Loop for short
    while (!is_overflow) {
        old_s = s;
        s = s + 1;
        if (old_s > s) {
            printf("short overflow %d -> %d \n", old_s, s);
            is_overflow = true;
        }
    }

    is_overflow = false; // Reset overflow flag

    // Loop for int
    while (!is_overflow) {
        old_i = i;
        i = i + 1;
        if (old_i > i) {
            printf("int overflow %d -> %d \n", old_i, i);
            is_overflow = true;
        }
    }

    is_overflow = false; // Reset overflow flag

    // Loop for long
    // while (!is_overflow) {
    //     old_l = l;
    //     l = l + 1;
    //     if (old_l > l) {
    //         printf("long overflow %ld -> %ld \n", old_l, l);
    //         is_overflow = true;
    //     }
    // }

    // is_overflow = false; // Reset overflow flag

    // Loop for unsigned char
    while (!is_overflow) {
        old_uc = uc;
        uc = uc + 1;
        if (old_uc > uc) {
            printf("unsigned char overflow %u -> %u \n", old_uc, uc);
            is_overflow = true;
        }
    }

    is_overflow = false; // Reset overflow flag

    // Loop for unsigned short
    while (!is_overflow) {
        old_us = us;
        us = us + 1;
        if (old_us > us) {
            printf("unsigned short overflow %u -> %u \n", old_us, us);
            is_overflow = true;
        }
    }

    is_overflow = false; // Reset overflow flag

    // Loop for unsigned int
    while (!is_overflow) {
        old_ui = ui;
        ui = ui + 1;
        if (old_ui > ui) {
            printf("unsigned int overflow %u -> %u \n", old_ui, ui);
            is_overflow = true;
        }
    }

    is_overflow = false; // Reset overflow flag

    // Loop for unsigned long
    // while (!is_overflow) {
    //     old_ul = ul;
    //     ul = ul + 1;
    //     if (old_ul > ul) {
    //         printf("unsigned long overflow %lu -> %lu \n", old_ul, ul);
    //         is_overflow = true;
    //     }
    // }

    return 0;
}
