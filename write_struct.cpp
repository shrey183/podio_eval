#include "common.h"
int main()
	{
	// Fill the array with some predictable values
	for(int i = 0; i < SIZE; i++)
	{	

		dummy[i].x = i;
		dummy[i].y = i;
		dummy[i].z = i;
		dummy[i].p = {i+1, i+2, i+3, i+4}; 
	}
	
	// create file 
	H5File* file = new H5File(FILE_NAME, H5F_ACC_TRUNC);

	// Create data type for SimpleStruct 
	CompType mtype(sizeof(SimpleStruct));
	mtype.insertMember(MEMBER1, HOFFSET(SimpleStruct, x), PredType::NATIVE_INT);
	mtype.insertMember(MEMBER2, HOFFSET(SimpleStruct, y), PredType::NATIVE_INT);
	mtype.insertMember(MEMBER3, HOFFSET(SimpleStruct, z), PredType::NATIVE_INT);
	mtype.insertMember(MEMBER4, HOFFSET(SimpleStruct, p), H5Tarray_create(H5T_NATIVE_INT, 1, array_dim));

   	// create dataset
      	DataSet* dataset = new DataSet(file->createDataSet(DATASET_NAME, mtype, space));

	// write data
	dataset->write(dummy, mtype);
      	
	// release resources
      	delete dataset;
      	delete file;
	return 0;

	}



