#include "stdio.h"
#include "math.h"

int min(int a, int b){
    if(b> a){
        return a;
    }else{
        return b;
    }
}
int jumpSearch(int array[], int toFind, int size){
    int step = sqrt(size);

    int prev = 0;

    while (array[min(step,size) -1] < toFind){
        prev = step;
        step += sqrt(size);
        if(prev >= size){
            return -1;
        }
    }
    if(array[min(step,size) - 1] == toFind){
        return min(step, size)-1;
    }

    while (array[prev] < toFind){
        int secondSize = step;
        int secondStep = sqrt(secondSize);
        int secondPrev = prev;

        while(array[min(secondStep, secondSize)-1] < toFind){
            secondPrev = secondStep;
            secondStep += sqrt(secondSize);
            if(secondPrev >= secondSize){
                return -1;
            }
        }

        if(array[min(secondStep, secondSize)-1] == toFind){
            return min(secondStep,secondSize)-1;
        }

        while(array[secondPrev] < toFind){
            secondPrev++;
            if(secondPrev >= secondSize){
                return -1;
            }
        }

        if(array[secondPrev] == toFind){
            return secondPrev;
        }
    }

    if(array[prev] == toFind){
        return prev;
    }

    return -1;

}

int main() {

    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

    int size = sizeof (array)/sizeof (array[0]);

    int toFind = 14;

    int result = jumpSearch(array, toFind, size);

    if(result >= 0) {
        printf("index %d: data %d\n", result, array[result]);
    }else {
        printf("Data not found");
    }



    return 0;
}