#include <stdint.h>
#include <stdio.h>

/* float의 비트 패턴을 uint32_t로 읽기 */
typedef union {
    float f;
    uint32_t u;
    uint8_t bytes[4];
} float_bits_t;

int main(void) {
    float_bits_t x;
    x.f = 3.14f;
    printf("float : %f\n", x.f);
    printf("uint32: 0x%08X\n", x.u);
    printf("bytes : %02X %02X %02X %02X\n", x.bytes[0], x.bytes[1], x.bytes[2],
           x.bytes[3]);
    return 0;
} /* UART로 float을 4바이트로 쪼개 전송할 때 이 패턴을 씁니다 */
