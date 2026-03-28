#include <stdio.h>
/* 시스템 상태 정의 */
typedef enum {
    STATE_IDLE = 0,
    STATE_RUNNING,
    STATE_ERROR,
    STATE_COUNT /* 상태 개수 — 배열 크기에 사용 */
} system_state_t;
typedef void (*state_handler_t)(void); /* 각 상태에서 실행할 함수들 */
void state_idle(void) { printf("[IDLE] Waiting...\n"); }
void state_running(void) { printf("[RUN] Reading sensor...\n"); }
void state_error(void) {
    printf("[ERR] Handling error...\n");
} /* 상태 → 함수 매핑 테이블 */
static const state_handler_t state_table[STATE_COUNT] = {
    [STATE_IDLE] = state_idle,
    [STATE_RUNNING] = state_running,
    [STATE_ERROR] = state_error};
int main(void) {
    system_state_t current = STATE_IDLE; /* 상태 머신 실행 */
    state_table[current]();              /* IDLE 실행 */
    current = STATE_RUNNING;
    state_table[current](); /* RUNNING 실행 */
    current = STATE_ERROR;
    state_table[current](); /* ERROR 실행 */
    return 0;
}
