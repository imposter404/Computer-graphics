#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

#define R(x) (int(x + 0.5))

class DDALineDrawer {
    private:
        int x1, y1, x2, y2;
        void putPixelWithDelay(int x, int y, int color, int delayTime) {
            putpixel(R(x), R(y), color);
            delay(delayTime);
        }
    public:
        DDALineDrawer(int xStart, int yStart, int xEnd, int yEnd);
        void drawLine(int color, int delayTime);
        
};



DDALineDrawer::DDALineDrawer(int xStart, int yStart, int xEnd, int yEnd){
    x1=xStart;
    y1=yStart;
    x2=xEnd;
    y2=yEnd; 
}


void DDALineDrawer:: drawLine(int color, int delayTime) {
    int dx, dy, steps;
    float xinr, yinr;
    float x, y;
    dx = (x2 - x1);
    dy = (y2 - y1);
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xinr = dx / (float)steps;
    yinr = dy / (float)steps;
    x = x1;
    y = y1;
    for (int i = 0; i < steps; ++i) {
        putPixelWithDelay(x, y, color, delayTime);
        x = x + xinr;
        y = y + yinr;
    }
}



int main() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, (char*)"");
    int x1, y1, x2, y2;
    int xmax = getmaxx();
    int ymax = getmaxy();
    setbkcolor(BLACK);
    cleardevice();

    cout << "X_max of screen = " << xmax << "\nY_max of screen = " << ymax << endl;
    cout << "Enter line end coordinates according to X_max and Y_max of Screen! " << endl;
    cout << "Enter endpoints A(x1,y1): ";
    cin >> x1 >> y1;
    cout << "Enter endpoints B(x2,y2): ";
    cin >> x2 >> y2;

    DDALineDrawer lineDrawer(x1, y1, x2, y2);
    lineDrawer.drawLine(YELLOW, 20);

    getch();
    closegraph();
    return 0;
}


//tested 
//working 
// :)
