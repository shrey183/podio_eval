# Description:

## Part 1: Shell script
The file script_test.sh is the shell script that will checkout podio, compile it and run the unit tests. Run the script using `bash` in the directory of your choice. The prequisites for installing podio should be met before running the shell script. At the moment the support for automatically installing ROOT is not available, however, requirements for python and yaml are checked in the script. 

## Part 2,3,4: Understanding SimpleStruct and writing data to HDF5 file
The file `write_struct.cpp` contains the code that first creates an array of 100 elements and then fills it with predictable data. Next, this data is filled into a HDF5 file called `SimpleStruct_to_HDF5.h5`. To test this, first compile the file `write_struct.cpp` using `h5c++`. This takes care of certain header files such as `H5Cpp.h`. In order to setup `h5c++` first install the following libraries:

`sudo apt install libhdf5-serial-dev`  
`sudo apt install libhdf5-dev`  
`sudo apt install libhdf5-7`  
`sudo apt install libhdf5_cpp.a`  
`sudo apt install libhdf5_hl_cpp.a`  

Next, install hdf5 helpers:

`sudo apt install hdf5-helpers`  

and finally in order to view .h5 files using the command `h5dump` install `hdf5-tools`. 

`sudo apt install hdf5-tools`  

Now, return to the directory containing the file `write_struct.cpp` and compile it:

`h5c++ -o write_struct write_struct.cpp`  

This creates an executable which can be run 

`./write_struct`  

You will be able to view the values in the array as they are printed on the terminal. Finally, we can view the newly created HDF5 file by typing:

`h5dump SimpleStruct_to_HDF5.h5`  

## Part 5: Read from HDF5 file 
If I understood this part correctly, we want to read from the previously created file and store those values into an array. The file which does this is called `read_struct.cpp`. To test it, first compile it: 

`h5c++ -o read_struct read_struct.cpp`  

This creates an executable which can be run 

`./read_struct`  

You will be able to view the values in the array as they are printed on the terminal. This will verify that the values have been indeed read correctly from the HDF5 file. 

