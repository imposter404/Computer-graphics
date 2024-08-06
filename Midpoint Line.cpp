#include <graphics.h>
#include <iostream>
using namespace std;

class MidPointLineDrawer {
private:
    int x1, y1, x2, y2;

public:
    MidPointLineDrawer(int X1, int Y1, int X2, int Y2);
    void drawLine();
};

MidPointLineDrawer::MidPointLineDrawer(int X1, int Y1, int X2, int Y2)
{
    x1=X1;
    y1=Y2;
    x2=X2;
    y2=X2; 
}


void MidPointLineDrawer:: drawLine() {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int d, x, y;
        if (dy <= dx) {
            // initial value of decision parameter d
            d = dy - (dx / 2);
            x = x1, y = y1;
            while (x < x2) {
                x++;
                // E or East is chosen
                if (d < 0)
                    d = d + dy;
                // NE or North East is chosen
                else {
                    d += (dy - dx);
                    y++;
                }
                putpixel(x, y, WHITE);
            }
        } else {
            // initial value of decision parameter d
            d = dx - (dy / 2);
            x = x1, y = y1;
            while (y < y2) {
                y++;
                if (d < 0)
                    d = d + dx;
                else {
                    d += (dx - dy);
                    x++;
                }
                putpixel(x, y, WHITE);
            }
        }
    }




int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2;
    int xmax = getmaxx();
    int ymax = getmaxy();
    setbkcolor(BLACK);
    cleardevice();

    cout << "Xmax of screen = " << xmax << "\nYmax of screen = " << ymax << endl;
    cout << "Enter line end coordinates according to Xmax and Ymax of Screen!" << endl;
    cout << "Enter endpoints A(x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter endpoints B(x2, y2): ";
    cin >> x2 >> y2;

    MidPointLineDrawer lineDrawer(x1, y1, x2, y2);
    lineDrawer.drawLine();

    getch();
    closegraph();
    return 0;
}

//tested 
// working ....
// :)
