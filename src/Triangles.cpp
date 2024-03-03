#include "../headers/Triangles.h"

Triangle::Triangle() {}

Triangle::Triangle(const int index1, const int index2, const int index3, const int indexNormal) : mIndex1(index1), mIndex2(index2), mIndex3(index3), mIndexNormal(indexNormal)
{
}
Triangle::~Triangle() {}
int Triangle::indexNormal() const
{
    return mIndexNormal;
}
int Triangle::index1() const
{
    return mIndex1;
}
int Triangle::index2() const
{
    return mIndex2;
}
int Triangle::index3() const
{
    return mIndex3;
}
void Triangle::setIndexNormal(int indexNormal)
{
    mIndexNormal = indexNormal;
}
void Triangle::setIndex1(int index1)
{
    mIndex1 = index1;
}
void Triangle::setIndex2(int index2)
{
    mIndex2 = index2;
}
void Triangle::setIndex3(int index3)
{
    mIndex3 = index3;
}
