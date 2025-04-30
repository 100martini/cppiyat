#include "Point.hpp"

Fixed area(Point const a, Point const b, Point const c) {
    Fixed area = ((a.getX() * (b.getY() - c.getY())) +
                 (b.getX() * (c.getY() - a.getY())) +
                 (c.getX() * (a.getY() - b.getY()))) / Fixed(2);
    
    if (area < Fixed(0))
        area = area * Fixed(-1);
    
    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = area(a, b, c);
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);
    
    if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
        return false;
        
    return (totalArea == area1 + area2 + area3);
}