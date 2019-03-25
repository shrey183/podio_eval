#ifndef COMMON_H
#define COMMON_H
#endif 

#include <iostream>
#include <string>
#include "H5Cpp.h"
#include "SimpleStruct.h"
using namespace H5;

const H5std_string FILE_NAME( "SimpleStruct_to_HDF5.h5" );
const H5std_string DATASET_NAME( "dummy" );
const H5std_string MEMBER1( "x" );
const H5std_string MEMBER2( "y" );
const H5std_string MEMBER3( "z" );
const H5std_string MEMBER4( "p" );
const int SIZE = 100;	// SIZE of the container holding elements of type SimpleStruct
const int RANK = 1;

// create a vector of Simple Struct type elements
struct SimpleStruct dummy[SIZE];

// setup dataspace
hsize_t dim[] = {SIZE};   // Dataspace dimensions
DataSpace space(RANK, dim);

// Array dimensions for the coordinate p in the struct
hsize_t array_dim[] = {4}; 
















