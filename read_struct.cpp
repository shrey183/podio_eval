#include "common.h"

int main(){


	// Set up file and dataset
	H5File* file = new H5File( FILE_NAME, H5F_ACC_RDONLY );

	std::shared_ptr<DataSet> dataset(new DataSet(file->openDataSet( DATASET_NAME )));

	// Create data type for SimpleStruct
    	CompType mtype(sizeof(SimpleStruct));
    	mtype.insertMember(MEMBER1, HOFFSET(SimpleStruct, x), PredType::NATIVE_INT);
    	mtype.insertMember(MEMBER2, HOFFSET(SimpleStruct, y), PredType::NATIVE_INT);
    	mtype.insertMember(MEMBER3, HOFFSET(SimpleStruct, z), PredType::NATIVE_INT);
	mtype.insertMember(MEMBER4, HOFFSET(SimpleStruct, p), H5Tarray_create(H5T_NATIVE_INT, RANK, array_dim));

      	dataset->read(dummy, mtype );

	// Print array of 100 values

	for(int i = 0; i<SIZE; i++)
		{
		std::cout << "Entry : " << i+1 << std::endl;
		std::cout << dummy[i] << std::endl;
		}

	
	delete file;
	return 0;
}


