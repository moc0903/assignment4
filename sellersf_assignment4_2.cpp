//Rick Sellers; LecSec 1002; LabSec 1008; Assignment 04                                                                                                       
/* This program accepts integers representing points of line segments from an input file.  The program will compute and display the points entered for each data set, the length and midpoint of the line segment defined by each pair of points, the slope and equation of the line, and the slope and equation of the line perpindicular to the one represented by the points and passing through point 1.*/

/*The program expects input from a file using Linux redirection.  The file should contain 4 integers separated by whitespace, with a return or linefeed separating each set of points, and a linefeed at the end of the data file */

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

void display_points (int, int, int, int); //function to display the points entered 
double slope_float (int, int, int, int); //function to calculate the floating point value of the slope
void slope_frac (int, int, int, int); //function to determine the slope of the line as a fraction and reduce it to lowest terms
void length (int, int, int, int); //function to calculate the length of the line segment 
void midpoint (int, int, int, int);//function to display the coordinates of the midpoint of the line segment
void equation (double, double);//function to display the equation of the line
void perp_slope(int, int, int, int); //function to calculate the slope of the perpindicular line
void perp_equation (double, double);//function to display the equation of the perpindicular line

int main()
{
  int x1,y1,x2,y2;//variables for the two points of each set (x1, y1), (x2, y2)
  double b;//used to calculate the y-intercept 
  double m;//slope of the line segment
  int set, count;//
  cout<< "Rick Sellers; Lec Sec # 1002; Lab Sec # 1008; Assignment # 04"<<endl<<endl;

  cin >>x1;//get first coordinate
  while(cin)//loop to get ponts until end of data file
    {
      cin >> y1>> x2>> y2;  //gets remaing points in the set
      display_points(x1,y1,x2,y2); 
      length(x1,y1,x2,y2);
      midpoint(x1,y1,x2,y2);
      slope_frac(x1,y1,x2,y2);
      m = slope_float(x1,y1,x2,y2);  //calculates and stores a value for the slope using the slope_float function
      b = -m*x1 + y1;//calculates the y-intercept
      equation(m, b);
      perp_slope(x1, y1, x2, y2);
      m = -1/m;
      b = -m*x1 + y1;
      perp_equation(m,b);

      cin >>x1;//gets first coordinate of next set of points; returns to beginning of loop until end of file is reached
    }
  return 0;
}

// display_points function 

void display_points(int a, int b, int c, int d)
{
  cout<< "Point 1 is: ("<< a<< ","<< b<< ")"<< setw(15)<< right<< "Point 2 is: ("<< c<< ","<< d<< ")"<<endl;
}

//comment about length function
void length (int a, int b, int c, int d)
{
  int L = 0;
  int exes, whys;
  exes = c - a;
  whys = d - b;
  L = sqrt(pow(exes,2) + pow(whys,2));
  cout<< "Length of line segment: "<< L<<endl;
}


//comment about midpoint function
void midpoint (int a, int b, int c, int d)
{
  double Mx, My;
  Mx = (c+a)/2.0;
  My = (d+b)/2.0;
  cout<< "Midpoint of line segment: ("<< Mx<< ","<< My<< ")"<<endl;
}

//comment about slope fraction function
void slope_frac (int a, int b, int c, int d)
{
  int rise, run, slope;
  rise = d - b;
  run = c - a;
  //cout<< "rise modulo run is: "<< rise%run<<endl;
  /*if (rise%run == 0)
    {
      slope = rise/run;
      cout<< "Slope of line is: "<< slope<< endl;
    }
  */
  //  else 
  //  {
    for (int i=2;i<=rise && i<=run;i++)
      if (rise%run == 0)
	{
	  slope = rise/run;
	  cout<< "Slope of line is: "<< slope<<endl;
	}
      else if (rise%i == 0 && run%i == 0)
      {
	rise = rise/i;
	run = run/i;
      
	if (rise < 0 && run < 0)
	  cout << "Slope of line is: "<< -rise<< "/"<< -run<<endl;
	else if (rise < 0 && run > 0)
	  cout << "Slope of line is: "<< rise<< "/"<< run<< endl;
	else
	  cout<<  "Slope of line is: "<< -rise<< "/"<< -run<< endl;
      }     
    // }
}




// comment about slope float function
//
double slope_float(int a, int b, int c, int d)
{
  double m;
  m = (d - b)/(c - a);
  return m;
}

// comment about equation function
void equation (double m, double b)
{
  string b_coeff;
  if (b<0)
    b_coeff = " ";
  else
    b_coeff = " + ";

    if (m == 0)
      {
	cout<< "Equation of line: y = "<< b<<endl;
      }
    if (b == 0)
      {
	if (m == 1)
	  cout<< "Equation of line: y = "<< "x" << b_coeff<< b<<endl;
	else if (m == -1)
	  cout<< "Equation of line: y = "<< " -x" << b_coeff<< b<<endl;
	else  
	  cout<< "Equation of line: y = "<< m<< "x "<< b_coeff<< b<<endl;
      }
    else 
      {
     if (m == 1)
	  cout<< "Equation of line: y = "<< "x" << b_coeff<< b<<endl;
	else if (m == -1)
	  cout<< "Equation of line: y = "<< " -x" << b_coeff<< b<<endl;
	else  
	  cout<< "Equation of line: y = "<< m<< "x "<< b_coeff<< b<<endl;
      }
}

//comment for perp slope function
//
void perp_slope(int a, int b, int c, int d)
{
  int rise, run, slope;
  rise = d - b;
  run = c - a;
  if (run%rise == 0)
    {
      slope = run/rise;
      cout<< "Slope of perpindicular line is: "<< slope<< endl;
    }

  for (int i=2;i<=rise && i<=run;i++)
    if (rise%i == 0 && run%i == 0)
      {
	rise = rise/i;
	run = run/i;
	
	
	if (rise < 0 && run < 0)
	  cout << "Slope of perpindicular line is: "<< -run<< "/"<< -rise<<endl;
	if (rise < 0 && run > 0)
	  cout << "Slope of perpindicular line is: "<< -run<< "/"<< rise<< endl;
	if (rise > 0 && run < 0)
	  cout<<  "Slope of perpindicular line is: "<< run<< "/"<< -rise<< endl;
    
      }
}


//comment for perp_equation function
//
void perp_equation (double m, double b)
{
  string b_coeff;
  if (b<0)
    b_coeff = " ";
  else
    b_coeff = " + ";

   if (m == 0)
      {
	cout<< "Equation of perpindicular line: y = "<< b<<endl;
      }
    if (b == 0)
      {
	if (m == 1)
	  cout<< "Equation of perpindicular line: y = "<< "x" << b_coeff<< b<<endl;
	else if (m == -1)
	  cout<< "Equation of perpindicular line: y = "<< " -x" << b_coeff<< b<<endl;
	else  
	  cout<< "Equation of perpindicular line: y = "<< m<< "x "<< b_coeff<< b<<endl;
      }
    else 
      {
     if (m == 1)
	  cout<< "Equation of perpindicular line: y = "<< "x" << b_coeff<< b<<endl;
	else if (m == -1)
	  cout<< "Equation of perpindicular line: y = "<< " -x" << b_coeff<< b<<endl;
	else  
	  cout<< "Equation of perpindicular line: y = "<< m<< "x "<< b_coeff<< b<<endl;
      }
}
