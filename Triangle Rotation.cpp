#include <iostream>
#include<math.h>
//#include <cmath>
#include <graphics.h>

using namespace std;

void triangle::createMatrix()
{
    matrix[0][0] = x0;
    matrix[1][0] = y0;
    matrix[0][1] = x1;
    matrix[1][1] = y1;
    matrix[0][2] = x2;
    matrix[1][2] = y2;
    matrix[2][0] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;
}

void triangle::createRMatrix()
{
    Rmatrix[0][0] = cos(theta);
    Rmatrix[1][0] = sin(theta);
    Rmatrix[0][1] = -sin(theta);
    Rmatrix[1][1] = cos(theta);
    Rmatrix[0][2] = 0;
    Rmatrix[1][2] = 0;
    Rmatrix[2][0] = 0;
    Rmatrix[2][1] = 0;
    Rmatrix[2][2] = 1;
}


void triangle::drawTriangle(double mat[3][3]){
	line(mat[0][0], mat[1][0], mat[0][1], mat[1][1]);
    line(mat[0][0], mat[1][0], mat[0][2], mat[1][2]);
    line(mat[0][1], mat[1][1],  mat[0][2], mat[1][2]);
}




void triangle::mulMatrix(){
	cout<<"\n";
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<col;++j)
		{
			for(int k=0;k<col;++k)
			{
				finalmatrix[i][j]+=Rmatrix[i][k] * matrix[k][j];
			}
		}
	}
}




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