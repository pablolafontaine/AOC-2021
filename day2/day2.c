#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int part1(char* filename){
    FILE* f = fopen(filename, "r");
    char buff[256];
    int depth = 0, forward = 0;

    while(fgets(buff, 256, f)){
        char* command = strtok(buff, " ");
        int distance = atoi(strtok(NULL, " "));

        if(strcmp(command, "forward") == 0){
            forward += distance;
        }
        else if(strcmp(command, "down") == 0){
            depth += distance;
        }
        else if(strcmp(command, "up") == 0){
            depth -= distance;
        }
        
    }
    fclose(f);
    return depth*forward;
}

int part2(char* filename){
    FILE* f = fopen(filename, "r");
    char buff[256];
    int aim = 0, depth = 0, forward = 0;

    while(fgets(buff, 256, f)){
        char* command = strtok(buff, " ");
        int distance = atoi(strtok(NULL, " "));

        if(strcmp(command, "forward") == 0){
            forward += distance;
            depth += aim*distance;
        }
        else if(strcmp(command, "down") == 0){
            aim += distance;
        }
        else if(strcmp(command, "up") == 0){
            aim -= distance;
        }
        
    }
    fclose(f);
    return depth*forward;
}

int main(){
    char* f = "input2";
    printf("%d\n",part1(f));
    printf("%d\n",part2(f));
    return 0;

}
