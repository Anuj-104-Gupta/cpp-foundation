#include<iostream>
#include<vector>
#include<memory>
using namespace std;
struct Point{int x,y;};
class Shape{
public:
   virtual void draw() const=0;
   virtual ~Shape()=default;
};
class Shape_with_pos:public Shape{
protected:
   Point center;
public:
   Shape_with_pos(Point p):center{p}{}
   Point get_center() const {return center;}
};
class Circle:public Shape_with_pos {
private:
   int radius;
public:
   Circle(Point p,int r):Shape_with_pos{p},radius{r}{}
   void draw() const override{
       cout<<"Circle at"<<center.x<<", "<<center.y<<"with Radius"<<radius<<'\n';
   }
};
class Smiley:public Circle{
public:
   Smiley(Point p,int r):Circle{p,r}{}
   void wink() const{
       cout<<"Smiley is winking\n";
   }
   void draw() const override{
       cout<<"Smiley Face at("<<center.x<<", "<<center.y<<"):\n";
       cout<<" - Outer face:";
       Circle::draw();
       cout<<" - Eyes and mouth rendered.\n";
   }
};
int main(){
   vector<unique_ptr<Shape>> shapes;
   shapes.push_back(make_unique<Circle>(Point{10, 20}, 5));
   shapes.push_back(make_unique<Smiley>(Point{0, 0}, 15));
   for (const auto& shape:shapes){
       shape->draw();
       if (Smiley* sm=dynamic_cast<Smiley*>(shape.get())){
           sm->wink();
       }
       cout<<"-------------------\n";
   }
   return 0;
}
