#include <iostream.h>
#define PI 3.14159



class Point
{
public:
  Point(float=0,float=0);
  void setPoint(float,float);
  float getX()const ;
  float getY()const ;
  friend ostream & operator<<(ostream &,const Point &);
protected:
  float x,y;
};
Point::Point(float a,float b):x(a),y(b){}
void Point::setPoint(float a,float b){x=a;y=b;}
float Point::getX()	const{return x;}
float Point::getY() const{return y;}
ostream & operator<<(ostream & output,const Point & b)
{
	output<<'['<<b.x<<','<<b.y<<']'<<'\n';
	return output;
}








class Circle:public Point
{
public:
  Circle(float x=0,float y=0,float r=0);
  void setRadius(float);
  float getRadius() const;
  float area () const;
  friend ostream &operator<<(ostream &,const Circle &);
 protected:
  float radius;
};

Circle::Circle(float a,float b,float r):Point(a,b),radius(r){}
void Circle::setRadius(float r){radius=r;}
float Circle::getRadius()const{return radius;}
float Circle::area() const{ return (float)PI*radius*radius;}
ostream & operator<<(ostream & output,const Circle & b)
{
	output<<"Center=["<<b.x<<','<<b.y<<"], r="<<b.radius<<", area="<<b.area();
	return output;
}








class Cylinder:public Circle
{
public:
  Cylinder (float x=0,float y=0,float r=0,float h=0);
  void setHeight(float);
  float getHeight() const;
  float area() const;
  float volume() const;
  friend ostream& operator<<(ostream&,const Cylinder&);
 protected:
  float height;
};

Cylinder::Cylinder(float x,float y,float r,float h):
		Circle(x,y,r),height(h){}
		void Cylinder::setHeight(float a){height=a;}
		float Cylinder::getHeight()const {return height;}
		float Cylinder::area() const {return (float)Circle::area()*2+2*PI*radius*height;}
		float Cylinder::volume() const {return Circle::area()*height;}

ostream & operator<<(ostream & output,const Cylinder & b)
{
	output<<"Center=["<<b.x<<','<<b.y<<"], r="<<b.radius<<", h="<<b.height<<'\n';
	output<<"area="<<b.area()<<", volume="<<b.volume()<<'\n';
	return output;
}








//小聪用于测试的函数

int main()
{
 Cylinder cy1(3.5,6.4,5.2,10);
 cy1.setHeight(15);
 cy1.setRadius(7.5);
 cy1.setPoint(5,5);
 cout<<"new cylinder:\n"<<cy1;
 Point &pRef=cy1;
 cout<<"pRef as a point:"<<pRef;
 Circle &cRef=cy1;
 cout<<"cRef as a Circle:"<<cRef;
 return 0;
}