#ifndef COLCLASS_H
#define COLCLASS_H
#include <xcol.h>
#include <ycol.h>
class colClass
{
private:
    int col;
public:
    colClass(int col);
    int getX();
    int getY();

};

#endif // COLCLASS_H
