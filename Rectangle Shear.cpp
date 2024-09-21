#include <iostream>
#include <math.h>
#include <graphics.h>




int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    RectangleShear r;
    r.row=3;
    r.col=4;
    // r.x0=100;
    // r.y0=100;
    // r.x1=300;
    // r.y1=100;
    // r.x2=300;
    // r.y2=300;
    // r.x3=100;
    // r.y3=300;

    cout << "Enter Rectangle ABCD Coordinates.....";
    cout << "\n Enter A:";
    cin >> r.x0 >> r.y0;
    cout << "\n Enter B:";
    cin >> r.x1 >> r.y1;
    cout << "\n Enter C:";
    cin >> r.x2 >> r.y2;
    cout << "\n Enter D:";
    cin >> r.x3 >> r.y3;

    cout << "\nMatrix for Rectangle ABC:\n";
    r.createMatrix();
    r.displayMatrix(r.matrix);
    r.drawRectangle(r.matrix);

    cout<<"\nenter Sh_x =";
    cin>>r.shx;
    cout<<"\nenter Sh_y =";
    cin>>r.shy;
    r.createShMatrix();
    r.mulMatrix();
    cout<<"\nMatrix after Shear";
    r.displayMatrix(r.finalmatrix);
	r.drawRectangle(r.finalmatrix);
    
    getch();
    closegraph();
    return 0;
}


//tested 
// working ....
// :)

