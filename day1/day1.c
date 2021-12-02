#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int z;
} vect;

int vect_sum(vect v){
    return v.x + v.y + v.z;
}

int part1(char* filename){
    FILE* f = fopen(filename, "r");
    int result = 0;
    char buff[6];
    fgets(buff, sizeof(buff), f);
    int last_val = atoi(buff);

    while(fgets(buff, sizeof(buff), f)){
        int curr = atoi(buff);
        if(curr > last_val){
            result++;
        }
        last_val = curr;
    }
    fclose(f);
    
    return result;
}

int part2(char* filename){
    FILE* f = fopen(filename, "r");
    char buff[6];
    vect* values = (vect*)malloc(sizeof(vect)*2000);
    int count = 1;
    int result = 0;

    fgets(buff, sizeof(buff), f);
    values[0].x = atoi(buff);
    fgets(buff, sizeof(buff), f);
    values[0].y = atoi(buff);
    fgets(buff, sizeof(buff), f);
    values[0].z = atoi(buff);

    while(fgets(buff, sizeof(buff), f)){
            values[count].x = values[count-1].y;
            values[count].y = values[count-1].z;
            values[count].z = atoi(buff);
            if(vect_sum(values[count])  > vect_sum(values[count-1])){
                result++;
            }
            count++;

    }
    fclose(f);
    
    free(values);
    return result;
}

int main(){
    char* f = "input1";
    printf("%d\n", part1(f));
    printf("%d\n", part2(f));
    return 0;
}

