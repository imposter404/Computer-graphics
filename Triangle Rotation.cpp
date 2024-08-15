#include <iostream>
#include<math.h>
//#include <cmath>
#include <graphics.h>

using namespace std;

int main(){
int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
cout << "Enter Triangle ABC Coordinates.....";
   cout << "\nEnter A: ";
cin >> t.x0 >> t.y0;
cout << "\nEnter B: ";
   cin >> t.x1 >> t.y1;
cout << "\nEnter C: ";
   cin >> t.x2 >> t.y2;
cout << "\nMatrix for Triangle ABC:\n";
 t.createMatrix();
    t.displayMatrix(t.matrix);
    t.drawTriangle(t.matrix);
t.createRMatrix();  
    t.mulMatrix();
cout<<"Rotated Triangle cooedinates \n";
    t.displayMatrix(t.finalmatrix);
	t.drawTriangle(t.finalmatrix);
getch();
    closegraph();
    return 0;
}