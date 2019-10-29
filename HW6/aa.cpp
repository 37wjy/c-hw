#include <iostream>
#include <cmath>
using namespace std;

class mss
{
private:
    double x0,y0,x1,y1;
public:
    mss(double x0,double y0,double x1,double y1) {
        bool steep = abs(y1 - y0) > abs(x1 - x0);
    
        if (steep )
        {   swap(x0, y0);
            swap(x1, y1);}
        if (x0 > x1) 
            {swap(x0, x1);
            swap(y0, y1);}
        double dx = x1 - x0;
        double dy = y1 - y0;
        double gradient = dy / dx;
        if (dx == 0.0) 
            gradient = 1.0;


        // handle first endpoint
        double xend = (int)x0+0.5;
        double yend = y0 + gradient * (xend - x0);
        double xgap = 1.0-((x0+0.5)-(int)(x0+0.5));//rfpart(x0 + 0.5);
        double xpxl1 = xend; // this will be used in the main loop
        double ypxl1 = int(yend);
        if (steep) 
            {plot(ypxl1,   xpxl1, rfpart(yend) * xgap);
            plot(ypxl1+1, xpxl1,  fpart(yend) * xgap);}
        else
            {plot(xpxl1, ypxl1  , rfpart(yend) * xgap);
            plot(xpxl1, ypxl1+1,  fpart(yend) * xgap);}

        double intery = yend + gradient ;// first y-intersection for the main loop
        
        // handle second endpoint
        xend = round(x1);
        yend = y1 + gradient * (xend - x1);
        xgap = fpart(x1 + 0.5);
        double xpxl2 = xend ;//this will be used in the main loop
        double ypxl2 = int(yend);
        if (steep )
            {plot(ypxl2  , xpxl2, rfpart(yend) * xgap);
            plot(ypxl2+1, xpxl2,  fpart(yend) * xgap);}
        else
            {plot(xpxl2, ypxl2,  rfpart(yend) * xgap);
            plot(xpxl2, ypxl2+1, fpart(yend) * xgap);}
        
        // main loop
        if (steep) 
            for( int x =xpxl1 + 1 ;x<xpxl2 - 1;x++) 
            {
                    plot(int(intery)  , x, rfpart(intery));
                    plot(int(intery)+1, x,  fpart(intery));
                    intery = intery + gradient;
            }
        else
            for (int x =xpxl1 + 1;x< xpxl2 - 1;x++)
            {
                    plot(x, int(intery),  rfpart(intery));
                    plot(x, int(intery)+1, fpart(intery));
                    intery = intery + gradient;
            }
    };
    ~mss() {}

    double round(double x)
    {return int(x + 0.5);}

    double fpart(double x) 
    {return x - floor(x);}

    double rfpart(double x) 
    {return 1 - fpart(x);}
};