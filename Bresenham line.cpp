#include <graphics.h>
#include <iostream>

class BresenhamLineDrawer {
private:
    int x0, y0, x1, y1;

public:
    BresenhamLineDrawer(int startX, int startY, int endX, int endY){
        x0=startX;
		y0=startY;
		x1=endX;
		y1=endY;
	}

    void drawLine() {
        int dx = x1 - x0;
        int dy = y1 - y0;
        int p = 2 * dy - dx;
        int x = x0;
        int y = y0;

        while (x <= x1) {
            putpixel(x, y, 7);
            if (p >= 0) {
                y = y + 1;
                p = p + 2 * dy - 2 * dx;
            } else {
                p = p + 2 * dy;
            }
            x = x + 1;
            delay(100);
        }
    }
};

int main() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, (char*)"");

    int x0, y0, x1, y1;

    std::cout << "Enter coordinates of first point: ";
    std::cin >> x0 >> y0;

    std::cout << "Enter coordinates of second point: ";
    std::cin >> x1 >> y1;

    BresenhamLineDrawer lineDrawer(x0, y0, x1, y1);
    lineDrawer.drawLine();

    getch();
    closegraph();
    return 0;
}
