# DataDisplay
Simple program to graph and log an input ASCII stream over COM port. Written in Visual Studios .NET framework ( C++/CLI). 

This will take an ascii string input in the following format: " [,D1,D2,D3,D4,]\r\n ".

For those versed in C and Arduino, insert the following lines into your code to output the correct string.

//At the top of program, outside of loop() and setup()
  char out_str[64]; //if you have more than 64 characters in your output stream, increase this number
  int data0 = 0;  // this can also be a float
  int data1 = 0;  // this can also be a float
  int data2 = 0;  // this can also be a float
  int data3 = 0;  // this can also be a float

//Do maths and put values into any of the dataX variables.

  sprintf(out_str, "[,%d,%d,%d,%d,]\r\n",data0,data1,data2,data3); 
  Serial.print(out_str);
  
  
