
/*
Co-ordinate Conversion Calculator
Author John Lucey
Created on 23/10/17
Last Edited on 23/10/17
*/

//Pre-processor directives
#include <math.h>
#include <iostream>
using namespace std;

//Function Prototypes
void pol_2_car(double X, double Y, double *ptr_r, double *ptr_ang);
void car_2_pol(double r, double ang, double *ptr_X, double *ptr_Y);
char menu(void);
void pol2car(void);

//Main Function
int main()
{

    //Variable declared
    char input;
    double X = 0,Y = 0, r = 0, ang = 0;
    double *ptr_X, *ptr_Y;
    ptr_X = &X;
    ptr_Y = &Y;


    //Explains program to user
    cout << "Cartesian & Polar Form Conversion Calculator! \n\n" << endl;

    //Do while loop to ensure the user is looped until 'q' is selected
    do
    {
        //Menu options displayed to user & input prompted
        input = menu();

        //Switch case statement to invoke functions or exit loop
        switch (input)
        {
           case 'p': pol2car();
                    break;
          case 'c': cout<<" Enter values for Magnitude and Angle  = \n\n";
                    cin>>r>>ang;
                    car_2_pol(r, ang, ptr_X, ptr_Y);
                    cout<<" The X coordinate is = " << *ptr_X <<
                          " \n\n The Y Coordinate is = " << *ptr_Y <<endl;
                    break;
          case 'q': cout<<" Goodbye!!!!!!!!! "<<endl;
                    break;
          default : cout<<" Please try again"<<endl;

        }
    }
    //Do while loop condition
    while (input != 'q');
    //nil return of main function
    return 0;
}


//polar to cartesian calculation function
void pol_2_car(double X, double Y, double *ptr_r, double *ptr_ang)
{
      //variables declared
    *ptr_r = sqrt(pow(X,2)+ pow(Y,2));
    *ptr_ang = atan(Y/X);

    return ;
}


//Cartisian to polar calulation function
void car_2_pol(double r, double ang, double *ptr_X, double *ptr_Y)
{
  //variables declared
    *ptr_X = r * cos(ang);
    *ptr_Y = r * sin(ang);

    return ;
}


void pol2car(void)
{
    double X = 0,Y = 0, r = 0, ang = 0;
    double *ptr_ang, *ptr_r;

    ptr_ang = &ang;
    ptr_r = &r;

    cout << "Polar to Cartesian Conversion : \n\n"<<
            "Enter a Value For X & Y = \n\n";
    cin >> X >> Y;
    pol_2_car(X, Y, ptr_r, ptr_ang);
    cout<<  "The Magnitude =  " << *ptr_r <<
            "\n\n The Angle = " << *ptr_ang <<endl;
}


char menu(void)
{
    char userChoice;

    cout << "\n Choose from the following options: \n" <<
              "\n Press p to convert a number from polar to cartesian form\n" <<
              "\n Press c to convert a number from cartesian to polar form\n" <<
              "\n Press q to quit\n\n" << endl;
    cin >> userChoice;

    return userChoice;
}
