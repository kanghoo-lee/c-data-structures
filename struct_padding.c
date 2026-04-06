#include <stddef.h>
#include <stdio.h>

/* ❌ 패딩 낭비 구조체 — 12바이트 */
struct Bad {
    char a; /* 1 byte + 3 패딩 */
    int b;  /* 4 bytes */
    char c; /* 1 byte + 3 패딩 */
}; /* 총 12 bytes */

/* ✅ 패딩 최소화 구조체 — 8바이트 */
struct Good {
    char a; /* 1 byte */
    char c; /* 1 byte + 2 패딩 */
    int b;  /* 4 bytes */
}; /* 총 8 bytes */

int main(void) {
    printf("Bad: %zu\n", sizeof(struct Bad));   /* 12 */
    printf("Good: %zu\n", sizeof(struct Good)); /* 8 */

    /* offsetof로 실제 패딩 위치 확인 */
    printf("Bad.b offset: %zu\n", offsetof(struct Bad, b)); /* 4 */
}
