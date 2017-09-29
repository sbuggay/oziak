#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>

void loop() {
    double time_step = 16666666;
    double time_passed = 0;
    double time_delta = 0;
    int running = 1;

    struct timespec current, previous;

    clock_gettime(CLOCK_MONOTONIC, &previous);
    while(running) {
        clock_gettime(CLOCK_MONOTONIC, &current);
        time_delta = current.tv_nsec - previous.tv_nsec;
        time_passed += time_delta;

        
        while(time_passed > time_step) {
            printf("catching up...\n");

            time_passed -= time_step;

        }
          
        printf("delta: %f\n", time_delta);
        printf("total time: %f\n", time_passed);
        
        previous = current;
        // sleep(1);
    }
}