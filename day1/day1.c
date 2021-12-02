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
    vect last_vec;
    int result = 0;

    fgets(buff, sizeof(buff), f);
    last_vec.x = atoi(buff);
    fgets(buff, sizeof(buff), f);
    last_vec.y = atoi(buff);
    fgets(buff, sizeof(buff), f);
    last_vec.z = atoi(buff);

    while(fgets(buff, sizeof(buff), f)){
        vect curr_vec;
        curr_vec.x = last_vec.y;
        curr_vec.y = last_vec.z;
        curr_vec.z = atoi(buff);
        if(vect_sum(curr_vec)  > vect_sum(last_vec)){
            result++;
        }
       last_vec = curr_vec;

    }
    fclose(f);
    
    
    return result;
}

int main(){
    char* f = "input1";
    printf("%d\n", part1(f));
    printf("%d\n", part2(f));
    return 0;
}

