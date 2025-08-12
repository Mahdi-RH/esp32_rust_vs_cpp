#ifndef DEMO_H
#define DEMO_H

#ifdef __cplusplus
extern "C" {
#endif

// Concurrency demos
void demo_race_condition();
void demo_deadlock();

// Memory safety demos
void demo_use_before_init();
void demo_dangling_pointer();
void demo_raw_pointer();

#ifdef __cplusplus
}
#endif

#endif // DEMO_H
