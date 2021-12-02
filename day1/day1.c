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

vect vect_push(vect v, int item){
    vect temp;
    temp.x = v.y;
    temp.y = v.z;
    temp.z = item;
    return temp;
}

int part1(char* filename){
    FILE* f = fopen(filename, "r");
    int result = 0;
    char buff[6];
    fgets(buff, sizeof(buff), f);
    int last_val = atoi(buff);

    while(fgets(buff, sizeof(buff), f)){
        int curr = atoi(buff);
        result += (curr > last_val);
        last_val = curr;
    }
    fclose(f);
    
    return result;
}

int part2(char* filename){
    FILE* f = fopen(filename, "r");
    char buff[6];
    vect last_vec;
    int i = 0;
    int result = 0;

    while(fgets(buff, sizeof(buff), f)){
        i++;
        vect curr_vec = vect_push(last_vec, atoi(buff));
        if(i > 3){
            result += (vect_sum(curr_vec)  > vect_sum(last_vec));
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

