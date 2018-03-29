#ifndef PLANE_HPP_
#define PLANE_HPP_

enum Plane_status {null, arriving, departing};

class Plane {
public:
   Plane();
   Plane(int flt, int time, Plane_status status);
   void refuse() const;
   void land(int time) const;
   void fly(int time) const;
   int started() const;

private:
   int flt_num;
   int clock_start;
   Plane_status state;
};
#endif
