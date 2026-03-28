#include <stdio.h>
int a = 10, b = 20;
/* ❌ 이렇게 하면 함수 밖의 포인터가 바뀌지 않음 */
void bad_switch(int *p) { p = &b; /* 지역 복사본만 바뀜 */ }

/* ✅ 이중 포인터를 써야 함수 밖 포인터가 바뀜 */
void good_switch(int **pp) { *pp = &b; /* 원본 포인터 변경 */ }

int main(void) {
    int *p = &a;
    printf("before: *p = %d\n", *p); // 10
    bad_switch(p);
    printf("after bad: *p = %d\n", *p); // 10 (안 바뀜)
    good_switch(&p);
    printf("after good: *p = %d\n", *p); // 20 (바뀜!)
    return 0;
}
