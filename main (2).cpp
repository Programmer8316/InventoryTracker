#include <iostream>
#include <iomanip>
using namespace std;

void getBearing(double heading, string &directionFace, double &angle, string &directionWalk)
{
    if(heading == 0)
    {
        directionFace = "North";
        directionWalk = "West";
        angle = 0.0;
    }
    
    else if(heading > 0 && heading < 90)
    {
        directionFace = "North";
        directionWalk = "East";
        angle = heading;
    }
    
    else if(heading == 90)
    {
        directionFace = "North";
        directionWalk = "East";
        angle = 90.0;
    }
    
    else if(heading > 90 && heading < 180)
    {
        directionFace = "South";
        directionWalk = "East";
        angle = 180 - heading;
    }
    
    else if(heading == 180)
    {
        directionFace = "South";
        directionWalk = "East";
        angle = 0.0;
    }
    
    else if(heading > 180 && heading < 270)
    {
        directionFace = "South";
        directionWalk = "West";
        angle = heading - 180;
    }
    
    else if(heading == 270)
    {
        directionFace = "North";
        directionWalk = "West";
        angle = 90.0;
    }
    
    else if(heading > 270 && heading < 360)
    {
        directionFace = "North";
        directionWalk = "West";
        angle = 360 - heading;
    }
    
    else
    {
        directionFace = "North";
        directionWalk = "West";
        angle = 0.0;
    }
}

void displayOutput(string directionFace, double angle, string directionWalk)
{
    cout << fixed << setprecision(1)
         << directionFace << " " << angle
         << " degrees " << directionWalk << endl;
}

int main()
{
    double heading, angle;
    string directionFace, directionWalk;
    bool isValid = false;
    
    while(!isValid)
    {
        cout << "Enter a compass heading [0-360 degrees]: ";
        cin >> heading;
        
        if(heading >= 0 && heading <= 360)
        {
            isValid = true;
        
            getBearing(heading, directionFace, angle, directionWalk);
            displayOutput(directionFace, angle, directionWalk);
        }
        
        else
        {
            cout << "\nError invalid heading entered." << endl;
        }
    }
    
    return 0;
}