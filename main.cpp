#include <iostream>
#include "headers/STL_Reader.h"
#include "headers/STL_Writer.h"


int main()
{
    STL_Reader fileReader;
    Triangulations triangulation = fileReader.stlReader("resources\\cube.stl");

    STL_Writer filewriter;
    filewriter.stlWrite( triangulation);
}