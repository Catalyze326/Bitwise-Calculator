#include <stdio.h>

void printBits(size_t const size, void const *const ptr) {
    unsigned char *b = (unsigned char *) ptr;
    unsigned char byte;
    int i, j;

    for (i = size - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

//unsigned int add(unsigned int a, unsigned b) {
//    unsigned int carry = (a & b) << 1;
//    unsigned int final = a | b;
//
//    printBits(a);
//    printBits(b);
//
//    unsigned int tmp;
//    printf("not carry = %u\ncarry = %u\n", final, carry);
//
//    while (carry) {
//        carry = carry & final;
//        tmp = carry | final;
//        carry = carry << 1;
//        final = tmp;
//
//        printBits(final);
//        printBits(carry);
//        printf("\n");
//    }
//    printBits(final);
//    return final;
//}
//unsigned int add(unsigned int a, unsigned b) {
//    unsigned int carry = (a & b) << 1;
//    unsigned int final = a | b;
//
//    printBits(a);
//    printBits(b);
//
//    unsigned int tmp;
//    printf("not carry = %u\ncarry = %u\n", final, carry);
//
//    while (carry) {
//        carry = carry & final;
//        tmp = carry | final;
//        carry = carry << 1;
//        final = tmp;
//
//        printBits(final);
//        printBits(carry);
//        printf("\n");
//    }
//    printBits(final);
//    return final;
//}


unsigned int bitwiseAdd(unsigned int a, unsigned int b) {
    unsigned int carry = (a & b) << 1;
    unsigned int nonCarry = (a ^ b);
    unsigned int tmp;

    while (carry) {
        tmp = carry ^ nonCarry;
        carry = (nonCarry & carry) << 1;
        nonCarry = tmp;
    }
    return nonCarry;
}


unsigned int bitwiseMultiply(unsigned int a, unsigned int b){

}


int main() {
    unsigned int a = 123;
    unsigned int b = 77;
    printf("\n%u", bitwiseAdd(a, b));
    printf("\n");
    return 0;
}