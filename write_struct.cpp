#ifdef OLD_HEADER_FILENAME
#include <iostream.h>
#else
#include <iostream>
#endif
using std::cout;
using std::endl;
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
const int   SIZE = 100;	// Create SimpleStruct of size 100
const int   RANK = 1;


// Function for printing the array
void print_array(struct SimpleStruct *array_index, int len)
	{

	for(int i = 0; i<len; i++)
		{
		std::cout << "Entry Number : " << i+1 << std::endl;
		std::cout << *array_index << std::endl;
		array_index++;
		}

	}

int main()
	{
	
	// Create an array of SIZE = 100
	struct SimpleStruct dummy[SIZE];
	// Fill the array with some predictable values
	for(int i = 0; i < SIZE; i++)
	{	

		dummy[i].x = i;
		dummy[i].y = i;
		dummy[i].z = i;
		dummy[i].p = {i+1, i+2, i+3, i+4}; 
	}
	
	// Print array of 100 values
	struct SimpleStruct * array_index;
	array_index = &dummy[0];
	print_array(array_index, SIZE);


  	// setup dataspace
      	hsize_t dim[] = {SIZE};   // Dataspace dimensions
      	DataSpace space( RANK, dim );

	// Array dimensions for the coordinate p in the struct
	hsize_t array_dim[] = {4}; 


	// create file 
	H5File* file = new H5File( FILE_NAME, H5F_ACC_TRUNC );


	// defining the datatype to pass HDF5
    	CompType mtype(sizeof(SimpleStruct));
    	mtype.insertMember(MEMBER1, HOFFSET(SimpleStruct, x), PredType::NATIVE_INT);
    	mtype.insertMember(MEMBER2, HOFFSET(SimpleStruct, y), PredType::NATIVE_INT);
    	mtype.insertMember(MEMBER3, HOFFSET(SimpleStruct, z), PredType::NATIVE_INT);
	mtype.insertMember(MEMBER4, HOFFSET(SimpleStruct, p), H5Tarray_create(H5T_NATIVE_INT, 1, array_dim));


   	// create dataset
      	DataSet* dataset;
      	dataset = new DataSet(file->createDataSet(DATASET_NAME, mtype, space));

	// write data	
	dataset->write( dummy, mtype );
      	
	// release resources
      	delete dataset;
      	delete file;
	return 0;


	}




