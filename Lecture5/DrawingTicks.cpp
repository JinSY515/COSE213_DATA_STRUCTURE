#include <iostream>

using namespace std;

void drawOneTick(int tickLength, int tickLabel);
void drawOneTick_start(int tickLength){
    drawOneTick(tickLength,-1);
}

void drawOneTick(int tickLength, int tickLabel){
    for(int i=0; i<tickLength; i++){
        printf("-");
    }
    if(tickLabel>=0) printf(" %d",tickLabel);
    printf("\n");
}

void drawTicks(int tickLength){
    if(tickLength>0){
        drawTicks(tickLength-1);
        drawOneTick_start(tickLength);
        drawTicks(tickLength-1);
    }
}

void drawRuler(int n, int length){
    drawOneTick(length,0);
    for(int i=1; i<=n; i++){
        drawTicks(length-1);
        drawOneTick(length,i);
    }
}

int main(void){
    drawRuler(3,5);
    return 0;
}