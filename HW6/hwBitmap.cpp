 //in case you cannot see antialiasedLine()'s line, i change the position and color !!!!!!!!!!!!!!!!!!!!!
#include <iostream>
#include <string>
#include <cmath>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "imagelib/stb_image_write.h"

#define constexpr const

using namespace std;



class Bitmap
{
private:
	constexpr static uint32_t w = 800, h = 600;
	uint32_t pixels[h][w];

	void mss(double x0,double y0,double x1,double y1,uint32_t color) {
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
            {plot(ypxl1,   xpxl1, rfpart(yend) * xgap,color);
            plot(ypxl1+1, xpxl1,  fpart(yend) * xgap,color);}
        else
            {plot(xpxl1, ypxl1  , rfpart(yend) * xgap,color);
            plot(xpxl1, ypxl1+1,  fpart(yend) * xgap,color);}

        double intery = yend + gradient ;// first y-intersection for the main loop
        
        // handle second endpoint
        xend = round(x1);
        yend = y1 + gradient * (xend - x1);
        xgap = fpart(x1 + 0.5);
        double xpxl2 = xend ;//this will be used in the main loop
        double ypxl2 = int(yend);
        if (steep )
            {plot(ypxl2  , xpxl2, rfpart(yend) * xgap,color);
            plot(ypxl2+1, xpxl2,  fpart(yend) * xgap,color);}
        else
            {plot(xpxl2, ypxl2,  rfpart(yend) * xgap,color);
            plot(xpxl2, ypxl2+1, fpart(yend) * xgap,color);}
        
        // main loop
        if (steep) 
            for( int x =xpxl1 + 1 ;x<xpxl2 - 1;x++) 
            {
                    plot(int(intery)  , x, rfpart(intery),color);
                    plot(int(intery)+1, x,  fpart(intery),color);
                    intery = intery + gradient;
            }
        else
            for (int x =xpxl1 + 1;x< xpxl2 - 1;x++)
            {
                    plot(x, int(intery),  rfpart(intery),color);
                    plot(x, int(intery)+1, fpart(intery),color);
                    intery = intery + gradient;
            }
    };

    double round(double x)
    {return int(x + 0.5);}

    double fpart(double x) 
    {return x - floor(x);}

    double rfpart(double x) 
    {return 1 - fpart(x);}

	void plot(int x,int y,double opa,uint32_t color){
		int a=((int((color>>24&0xff)*opa))&0xff)<<24;
		pixels[y][x]=mix(((color<<8)>>8)+a,pixels[y][x]);
	}

public:
	Bitmap(uint32_t color) {
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				pixels[j][i]=color;
			}
		}
	}
	~Bitmap() {}

	void horizLine(int xl, int xr, int y, uint32_t color){
		line(xl,y,xr,y,color);
	}

	void vertLine(int yu,int yd,int x, uint32_t	color){
		line(x,yu,x,yd,color);
	}

	void drawRect(int x,int y, int width,int hight, uint32_t color){
		line(x,y,x,y+hight,color);
		line(x,y+hight,x+width,y+hight,color);
		line(x,y,x+width,y,color);
		line(x+width,y,x+width,y+hight,color);
	}

	void fillRect(int x,int y, int width,int hight, uint32_t color){
		for (int i = x; i < x+width; i++)
		{
			for (int j = y; j < y+hight; j++)
			{
				pixels[j][i]=color;
			}
		}
	}

	void line(int xl,int yl, int xr,int yr, uint32_t color,bool anti=false){
		float a=0;
		if(xl!=xr) a=(yr-yl)/(double)(xr-xl);
		
		if(abs(a)<1&&xl!=xr){
			if(xr<xl)swap(xr,xl);
			for (int i = xl; i <= xr; i++)
			{	
				//if(anti&&a){
				//}
				//else{
					pixels[(int)(yl+a*(i-xl))][i]=color;
				//	if((int)a!=0){pixels[(int)(yl+a*(i-xl))+1][i]=mix(color-0x80000000,pixels[(int)(yl+a*(i-xl))+1][i]);
				//	pixels[(int)(yl+a*(i-xl))-1][i]=mix(color-0x80000000,pixels[(int)(yl+a*(i-xl))-1][i]);}}
			}
		}
		else if(xl!=xr)
		{	
			//if(anti&&xl!=xr){
			//	uint32_t mtx[(int)abs(a)][2]; 
			//}
			if(yr<yl)swap(yl,yr);
			for (int i = yl; i <= yr; i++)
			{
				pixels[i][(int)(xl+(i-yl)/a)]=color;
			//	pixels[i+1][(int)(xl+(i-yl)/a)]=mix(color-0x80000000,pixels[i+1][(int)(xl+(i-yl)/a)]);
			//	pixels[i-1][(int)(xl+(i-yl)/a)]=mix(color-0x80000000,pixels[i-1][(int)(xl+(i-yl)/a)]);
			}
		}
		else{
			if(yr<yl)swap(yl,yr);
			for (int i = yl; i <= yr; i++)
			{
				pixels[i][xl]=color;
			}
		}
	}

	void ellipse(int xc, int yc, int dx, int dy){
		int x,y;
		int b=min(dx/2.0,dy/2.0);
		int a=max(dx/2.0,dy/2.0);
		double l=M_PI*2*b+4*abs(a-b);
		double step=4/l;
		for (double r = -M_PI; r < M_PI; r+=step)
		{	
			y=yc+dy*sin(r)/2;
			x=xc+dx*cos(r)/2;
			if(x>=0&&y>=0&&x<w&&y<h){
				pixels[y][x]=0xFF00FF00;
			}
		}
	}

	uint32_t mix(uint32_t c1,uint32_t c2){
		uint8_t A1=c1>>24;
		uint8_t R=((c1&0xff)*A1/255.0-(c2&0xff)*(1-A1/255.0));
		uint8_t G=(((c1>>8)&0xff)*A1/255.0-((c2>>8)&0xff)*(1-A1/255.0));
		uint8_t B=(((c1>>16)&0xff)*A1/255.0-((c2>>16)&0xff)*(1-A1/255.0));
		uint32_t c=0xff000000+R+(((uint32_t)G)<<8)+(((uint32_t)B)<<16);
		return c;
	}

	void antialiasedLine(int xl,int yl, int xr,int yr, uint32_t color){
		mss(xl,yl,xr,yr,color);
	}

	void save(const char filename[]) {
    	stbi_write_png(filename, w, h, 4, pixels, w*4);
  	}
};


int main() {
	// FIRST PART (ADD COLORS HERE)
	constexpr uint32_t BLACK = 0xFF000000; // black opaque
	constexpr uint32_t RED =   0xFF0000FF; // red opaque
	constexpr uint32_t GREEN = 0xFF00FF00;
	constexpr uint32_t BLUE =	0xFFFF0000;
	constexpr uint32_t YELLOW = GREEN|RED;
	constexpr uint32_t WHITE =	RED|GREEN|BLUE;


	// SECOND PART (DO NOT EDIT)
	int xcenter = 100;
	int ycenter = 100;
	int xdiameter = 200;
	int ydiameter = 100;
	0xffaabb;
	Bitmap b(BLACK); // Hardcoded size (600 x 400 pixels)
	
    b.horizLine(0, 500, 200, RED); // Red horizontal line, from x=0 to x=500, at y = 200
	b.vertLine(0, 399, 300, RED); // Red vertical line, from y=0 to y=399, at x = 300
	
	b.drawRect(200,200, 100,50, BLUE); // Blue rectangle, TOP-LEFT at x=200, y=200. width=100, height=50
	b.fillRect(201,201, 98,48, WHITE); // White rectangle, same rules as above, but filled with color
	
	b.line(400,0, 550,300, YELLOW); // Line drawn using https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
	
	b.ellipse(xcenter, ycenter, xdiameter, ydiameter); //Ellipse using specs from above
		
	// THIRD PART - OPTIONAL FUNCTION
	// 100pt bonus for properly implementing Wu's antialiasing
	//https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
	 //in case you cannot see antialiasedLine()'s line, i change the position and color !!!!!!!!!!!!!!!!!!!!!

	b.antialiasedLine(599,0, 550,300, 0xeeffddbb);  //in case you cannot see antialiasedLine()'s line, i change the position and color !!!!!!!!!!!!!!!!!!!!!

	b.save("bitmap.png");
	cout<<"\nin case you cannot see antialiasedLine()'s line, i change the position and color !!!!!!!!!!!!\n"<<endl;
}

