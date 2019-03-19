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
const int   SIZE = 100;
const int   RANK = 1;

// Function to print array
void print_array(struct SimpleStruct *array_index, int len)
	{

	for(int i = 0; i<len; i++)
		{
		std::cout << "Entry : " << i+1 << std::endl;
		std::cout << *array_index << std::endl;
		array_index++;
		}

	}


int main(){
	
	//Array dimensions for the array p in struct SimpleStruct
	hsize_t array_dim[] = {4}; 
	
	// Set up file and dataset
      	H5File* file = new H5File( FILE_NAME, H5F_ACC_RDONLY );
      	DataSet* dataset = new DataSet (file->openDataSet( DATASET_NAME ));

	// Create data type for SimpleStruct
    	CompType mtype(sizeof(SimpleStruct));
    	mtype.insertMember(MEMBER1, HOFFSET(SimpleStruct, x), PredType::NATIVE_INT);
    	mtype.insertMember(MEMBER2, HOFFSET(SimpleStruct, y), PredType::NATIVE_INT);
    	mtype.insertMember(MEMBER3, HOFFSET(SimpleStruct, z), PredType::NATIVE_INT);
	mtype.insertMember(MEMBER4, HOFFSET(SimpleStruct, p), H5Tarray_create(H5T_NATIVE_INT, RANK, array_dim));


	// Define array that will store the read values
	struct SimpleStruct dummy[SIZE]; 
      	dataset->read(dummy, mtype );

	// Print array of 100 values
	struct SimpleStruct* array_index;
	array_index = &dummy[0];
	print_array(array_index, SIZE);
      
	// Release resources
     	delete dataset; 
      	delete file;
	return 0;
}

