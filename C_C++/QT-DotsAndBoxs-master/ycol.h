#ifndef YCOL_H
#define YCOL_H
#include <gogal.h>

class ycol
{
private:
    int y;
    int col;
    int type;
public:
    ycol(int y,int type);
    int toCol();
    int toY();
};

#endif // YCOL_H
