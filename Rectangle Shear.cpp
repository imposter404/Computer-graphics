#include <iostream>
#include<math.h>
#include <graphics.h>

using namespace std;
class RectangleShear{
	public:
        int shx,shy;
		int row,col;
		int x0,y0,x1,y1,x2,y2,x3,y3;
		double matrix[3][4];
		double shMatrix[3][3];
		double finalmatrix[3][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},};
        void createMatrix();
        void createShMatrix();
        void drawRectangle(double mat[3][4]);
        void displayMatrix(double mat[3][4]);
        void mulMatrix();
};


void RectangleShear::createMatrix()
{
    matrix[0][0] = x0;
    matrix[1][0] = y0;
    matrix[0][1] = x1;
    matrix[1][1] = y1;
    matrix[0][2] = x2;
    matrix[1][2] = y2;
    matrix[0][3] = x3;
    matrix[1][3] = y3;
    matrix[2][0] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;
    matrix[2][3] = 1;
}

void RectangleShear::createShMatrix()
{
    shMatrix[0][0] = 1;
    shMatrix[1][0] = shy;
    shMatrix[0][1] = shx;
    shMatrix[1][1] = 1;
    shMatrix[0][2] = 0;
    shMatrix[1][2] = 0;
    shMatrix[2][0] = 0;
    shMatrix[2][1] = 0;
    shMatrix[2][2] = 1;
}




void RectangleShear::drawRectangle(double mat[3][4]){
	line(mat[0][0], mat[1][0], mat[0][1], mat[1][1]);
    line(mat[0][1], mat[1][1], mat[0][2], mat[1][2]);
    line(mat[0][2], mat[1][2], mat[0][3], mat[1][3]);
    line(mat[0][0], mat[1][0], mat[0][3], mat[1][3]);
}

void RectangleShear::displayMatrix(double mat[3][4]){
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
        {	
            cout << mat[i][j] << "   ";
		}
    	cout<< endl;
    }
}



void RectangleShear::mulMatrix(){
	cout<<"\n";
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<col;++j)
		{
			for(int k=0;k<row;++k)
			{
				finalmatrix[i][j]+=shMatrix[i][k] * matrix[k][j];
			}
		}
	}
}


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
