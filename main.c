#include <stdio.h>
#include <stdlib.h>

#include "level.h"

int main(int argc, char *argv[]) {
    printf("hello\n");

    FILE *file;
    fopen_s(&file, "map.ld", "rb");

    int num = 0;
    fread(&num, sizeof(int), 1, file);

    printf("num objs: %d\n", num);

    struct obj_t *objects = malloc(sizeof(struct obj_t) * num);
    
    fread(objects, sizeof(struct obj_t), num, file);

    for(int i = 0; i < num; i++) {
        printf("[%d] %d,%d\n", objects[i].type, objects[i].x, objects[i].y);
    }

    free(objects);
    return 0;
}