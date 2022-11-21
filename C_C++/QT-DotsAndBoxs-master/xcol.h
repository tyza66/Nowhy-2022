#ifndef XCOL_H
#define XCOL_H
#include <gogal.h>
class Xcol
{
private:
    int x;
    int col;
    int type;
public:
    Xcol(int content,int type);
    int toCol();
    int toX();

};

#endif // XCOL_H
