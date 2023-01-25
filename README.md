# nitay-and-Ilan-second-milestone

AUTHOR: Nitay Shafrir and Ilan Talala.
#REQUIREMENTS:GNU C/C++ compiler.
#COMPILATION: On Linux work systems.

```
make
```

#RUNNING:
for the server:

```
./server.out <file directory> port_number
```

for the client:

```
./client.out ip_number port_number
```

After running the client.out there is input to type in:
enter input:

```
<vector> <TypeDistance> <K value>
```

In order to run the code, do it in the following order:

1. Compile the server and run it with a file of the "classified" data and a certain port.
2. Then you need to compile and run the client with a certain IP address and add the same port as the server.
3. Enter the input in the format described above.
   -port_number:
   A port is a number assigned to uniquely identify a connection endpoint and to direct data to a specific service.
   The port number of the client and the server must be identical!
   -ip_number:
   An IP address is a string of numbers separated by periods. IP addresses are expressed as a set of
   four numbers — an example address might be 192.158.1.38.
   -K value:
   A K value that is a positive int, for which the algorithm will look for
   the K vectors whose distance from the input value is the lowest,
   and then we will return the most common vector type among these K.
   -file_name: the name of the vectors file. (the path address should be between the K value and the TypeDistance)
   -TypeDistance:
   1.Euclidean- link:https://en.wikipedia.org/wiki/Euclidean_distance
   2.Manhattan- link:https://en.wikipedia.org/wiki/Taxicab_geometry
   3.Chebyshev- link:https://en.wikipedia.org/wiki/Chebyshev_distance
   4.Canberra- link:https://en.wikipedia.org/wiki/Canberra_distance
   5.Minkowski- link:https://en.wikipedia.org/wiki/Minkowski_distance
   *In Minkowski distance we chose random value for p (p=2)
   because the value of each p does not affect the algorithm and therefore does not matter to us.
   #ABOUT THE CODE:-The structure of the program is as follows:
   There is an interface called DefaultIO which recognizes 2 functions of "read" and "write".
   For the write function it receives a string and sends it to the client.
   For read the object that will implement DefaultIO will wait for input from the client and return it.
   After that there is an object called SocketIO which will implement DefaultIO and through sockets.
   There is another interface called Command which includes the functions "description"
   and "execute" and which will be implemented by the main functions of the program.
   There is an object named CLI whose fields are: DIO which will be of DefaultIO type, info which will be
   of HoldInfo type and functions which will be a map between the function number and the object of its type.
   The HoldInfo object contains all the information regarding the client's activity in the program, i.e.: are there
   files to sort, is the test file sorted, the K value, the distance metric, a database of the test files, KNN.
   The program starts after the client connects to the server and the server automatically creates a CLI instance
   and activates the start function.
   In this code there are a client and a server, and its purpose is to allow the
   use of the KNN algorithm as the user chooses. First, a menu with 5 options and option number
   8 to exit the program will be displayed.
   -Option number 1: will allow the user to enter a file of labeled vectors called "training files" and then "test"
   files.
   -Option number 2: will allow the user to enter a K value and a distance threshold according to which the test files
   will
   be sorted according to the training files. It should be noted that the default K value is 5 and the distance
   metric is "Euclidean distance". If the user presses enter, the parameters will remain unchanged, otherwise,
   the user can enter new values separated by a space, where K can accept a range of integer values and the distance
   calculator can accept the values of the 5 types of distance specified at the beginning of the README.
   If everything is fine - return to the main menu. If the user entered an invalid value - the error message will be
   returned.
   If one of the values is incorrect, an error message will be returned accordingly.

- Option number 3: Classify the test files according to training files and then print a message "classifying data
  complete"
  and return to the main menu if no files have been uploaded yet, a message "please upload data" will be printed.
- Option number 4: return the list of classifications numbered by lines and finally "Done" will be printed.
- Option number 5: In this function a local path must be entered in the Linux format with "/" and
  it must be noted that after the last "/" the user can enter the beginning of the name of the file that
  will be created, and then it will be completed with "outputFile".
  It should be noted that if the user entered the name of a local folder without "/" then a file will be created
  with the name of the folder and the extension "outputFile" when the file is located in the folder
  of the program (with the other cpp files).
  If nothing is written after the last "/" then the file will be called "output File".
  If this function is called more than once on the same path and chooses the same name,
  then it will add to the previous one the values that are in the old file.
  This function is done with a thread which is responsible for downloading the file while the program continues as usual.
  The entire program supports the use of several clients at the same time by using a thread for each client.
  -This code simulates a KNN algorithm when it receives a file of classified vectors,
  a distance function and a K value. And for each input the algorithm will check for the closest K vectors
  what is the most common type and accordingly the vector type will be returned.
  Proximity between the vector and the nearest K will be checked using the distance function.
  -all the checks are in the client and the student just check if he gets -1 and if not send all the info to
  the server than do all the check and if the input is invalid return "invalid input to the client" the client
  just receive text from user and send it to the server
  -The code is divided as follows:
  -there is a class called KNN and its fields are:
  1.multimap whose keys are vectors and the values in it are strings.
  2.The K value according to which the algorithm will search for the nearest K vectors.
  There is also a function called Predict and its job is to get a vector and a distance
  function and return the most common type among the nearest K.
  The function does this by checking the distance between the given vector and each of the vectors in the KNN map,
  and then it enters the value of the distance into a multimap called "distance"
  whose key is the distance and whose value is the type of vector that measured
  the distance between it and the given vector.
  After that there is a map named "counter" whose key values are the number of instances
  of its value type and its value is a string.
  At the beginning, all the key values of counter are reset, and then the multimap "distance" values are passed in a loop,
  and since multimap arranges its values in ascending order, and it is possible to store values with the same key
  then the loop passes through the first K values of "distance",
  and for each vector type A place will be allocated in the "counter" and the number of its occurrences will be counted.
  Finally, the type with the most occurrences will be returned.
  #ADAPTATION:
  -In order to optimize the code, there is a method called "basicCalVectors" which
  takes two vectors and an integer p and calculates the following value: the difference
  between a pair of values in i-th place to the p power.
  After calculating this value, the function sums all these values for each i present
  in both vectors, and returns the amount.
  The distances:
  -Euclidean
  -Manhattan
  -Minkowski
  are depend on how they are calculated in the "basicCalVectors", so we created
  it in advance.
  -Each distance function has its own unique class and each such class implements the "Distance" interface.
  Such an implementation brings to light the principle of polymorphism according to which we allow the KNN algorithm
  to receive a distance method of type "Distance" when each of the distance classes implements "Distance".
