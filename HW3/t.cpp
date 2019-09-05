#include <iostream>
using namespace std;
 
class Box
{
   double length;      // 长度
   double breadth;     // 宽度
   double height;      // 高度
public:
 
   double getVolume(void)
   {
      return length * breadth * height;
   }
   void setLength( double len )
   {
       length = len;
   }
 
   void setBreadth( double bre )
   {
       breadth = bre;
   }
 
   void setHeight( double hei )
   {
       height = hei;
   }
   
   friend Box operator+(const Box& a, const Box& b);

   Box operator-() const
   {
      Box box;
      box.length=-length;
      box.breadth=-breadth;
      box.height=-height;
      return box;
   }


};

Box operator+(const Box& a, const Box& b)
{
    Box box;
    box.length = a.length + b.length;
    box.breadth = a.breadth + b.breadth;
    box.height = a.height + b.height;
    // cout << box.length << "--" << box.breadth << "--" << box.height << endl; 
    return box;
}

// 程序的主函数
int main( )
{
   Box Box1;                // 声明 Box1，类型为 Box
   Box Box2;                // 声明 Box2，类型为 Box
   Box Box3;                // 声明 Box3，类型为 Box
   double volume = 0.0;     // 把体积存储在该变量中
 
   // Box1 详述
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
 
   // Box2 详述
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);
 
   const Box Box4=Box2;
   const Box Box5=Box1;

   // Box1 的体积
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   // Box2 的体积
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;
   Box2=-Box2;

   // 把两个对象相加，得到 Box3
   Box3 = Box4 + Box5;
 
   Box3=-Box4;
   // Box3 的体积
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;
 
   return 0;
}