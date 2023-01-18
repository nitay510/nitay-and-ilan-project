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
#ABOUT THE CODE:-In this code there is a client and a server side.
   The user feeds the client a vector of distance type and size K and then the client sends this to the server.
   The server creates the KNN from the previous exercise and gives it the values it received from the client.
   In the running line of the server it is given a file with classified information,
   according to which the KNN knew how to classify each new vector.
   Given a certain vector, a distance function and a K value, the KNN will return the vector type.
   The server will pass this on to the client and the client will print the answer for us.
   The client continues to accept inputs from the user until the user enters -1.
   If the user enters an input that is incorrect, that is, not according to the format rules, the message "Invalid input" will be printed.
   If, while running the client, not enough arguments are received, the message will be printed:
   "you didn't put enough arguments!!:"
 -This code simulates a KNN algorithm when it receives a file of classified vectors,
 a distance function and a K value. And for each input the algorithm will check for the closest K vectors
 what is the most common type and accordingly the vector type will be returned.
 Proximity between the vector and the nearest K will be checked using the distance function.
 -all the checks are in the client and the student just check if he gets -1 and if not send all the info to the server
 the server than do all the check and if the input is invalid return "invalid input to the client" the client
 just recive text from user and send it to the server
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
-The part of the main happen as follows:
 First, we have a function external to main that will check for us if the string value received is indeed a double.
 After that we will receive for each variable each of the arguments of the running line.
 And we will check the validity of each of the arguments.
 A KNN object will be created whose K value will be the required value and its list of vectors will
 be prepared in the following order.
 The external function will assist us in receiving the values of the vectors so that we can
 differentiate between the classification which is of type string and the values of
 the vector which can be represented by double.
 Then we will make sure that the length of all the vectors is the same and does not contain a char value.
 A vector will be received from the user and a comparison will be made between it and
 all the values of the vectors classified in KNN according to the selected distance function
 Using the predict function, and so we will continue until no vector is recorded.
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
