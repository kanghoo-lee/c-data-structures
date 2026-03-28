#include <stdio.h>
int main(void) {
    int i = 42;
    float f = 3.14f;
    char c = 'A';
    void *vp; /* 타입 없는 포인터 */
    vp = &i;
    printf("int : %d\n", *(int *)vp); /* 캐스팅 후 역참조 */
    vp = &f;
    printf("float : %.2f\n", *(float *)vp);
    vp = &c;
    printf("char : %c\n", *(char *)vp);

    /* void* 끼리 직접 역참조는 불가 */
    /* printf("%d", *vp); ← 컴파일 에러! */
    return 0;
}
