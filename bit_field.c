#include <stdint.h>

/* STM32 GPIO_MODER 레지스터 — 각 핀 2비트씩 */
typedef union {
    uint32_t word; /* 전체 32비트 접근 */
    struct {
        uint32_t MODER0 : 2; /* Pin 0 모드 */
        uint32_t MODER1 : 2; /* Pin 1 모드 */
        uint32_t MODER2 : 2;
        uint32_t MODER3 : 2;
        uint32_t MODER4 : 2;
        uint32_t MODER5 : 2;    /* PA5 = LED 핀 */
        uint32_t reserved : 20; /* 나머지 */
    } bits;
} GPIO_MODER_t;

/* 사용 예 */
volatile GPIO_MODER_t *GPIOA_MODER = (volatile GPIO_MODER_t *)0x40020000;
void set_pa5_output(void) {
    GPIOA_MODER->bits.MODER5 = 0b01; /* 01 = 출력 모드 */
    /* 비트 마스킹 없이 깔끔하게 접근! */
}
