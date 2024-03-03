#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include "../headers/STL_Writer.h"

STL_Writer::STL_Writer() {}
STL_Writer::~STL_Writer() {}

Triangulations& STL_Writer::stlWrite(Triangulations& triangulation) {
    std::vector<Point3D>& points = triangulation.uniquePoints();
    std::vector<Triangle>& triangles = triangulation.triangles();
    
    // Set to store unique normal indices
    std::set<int> uniqueNormalIndices;
    
    // Find unique normal indices
    for (const Triangle& triangle : triangles) {
        uniqueNormalIndices.insert(triangle.indexNormal());
    }
    
    // Map to store output file streams based on normal index
    std::map<int, std::ofstream> outputFiles;
    
    // Open output files for each unique normal index
    for (int normalIndex : uniqueNormalIndices) {
        std::string filename = "output/plane" + std::to_string(normalIndex + 1) + ".txt";
        outputFiles[normalIndex].open(filename);
    }

    // Write points to respective output files based on normal index
    for (const Triangle& triangle : triangles) {
        int normalIndex = triangle.indexNormal();
        std::ofstream& outputFile = outputFiles[normalIndex];
        
        outputFile << points[triangle.index1()].X() << " " << points[triangle.index1()].Y() << " " << points[triangle.index1()].Z() << std::endl;
        outputFile << points[triangle.index2()].X() << " " << points[triangle.index2()].Y() << " " << points[triangle.index2()].Z() << std::endl;
        outputFile << points[triangle.index3()].X() << " " << points[triangle.index3()].Y() << " " << points[triangle.index3()].Z() << std::endl;
    }

    // Close all output files
    for (auto& file : outputFiles) {
        file.second.close();
    }

    std::cout << "Points written into Text Files" << std::endl;
    return triangulation;
}
