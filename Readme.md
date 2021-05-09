#1 To check the project you can run the output file course1.out.
$ ./course1.out

#2- if this don't work delate this following file :
	* course1.map 
	* course1.out 
	* src/*.d : all .d file in the repository src/
	* src/*.o : all .o file in the repository src/
And at the path : course1/ rebuild the project with :
	$ make build
And retried the #1

#3- To activated the VERBOSE flags for the function print_array in the file stats.c : 
	* Open the file course1/Makefile
	* At the line number 45 uncommented the -DVERBOSE flag 
	* And uncommented the '\' character at the end of the line 44
And do #2  
