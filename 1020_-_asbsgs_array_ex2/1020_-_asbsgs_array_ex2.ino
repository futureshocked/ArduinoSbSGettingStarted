/* 
 *  An example of how to create an use an array of chars
 *  We'll declare an array of 5 chars.
 *  We'll print the contents in the serial monitor.
 *  
 *  The table of ASCII character from https://en.wikipedia.org/wiki/ASCII
 *  is useful.
 *  
 */

//char my_char[5] = {'a', 'b', 'c', 'd', 'e'} ;  // We want this array to contain 5 char, 
                                               // so we'll declare it with size 5.
                                               // Try the exact same experiment with byte

//char my_char[5] = "abcde";  // Alternative definition 1     

//String my_char = "abcde";   // Alternative definition 2, using a String

void setup() {
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }

  Serial.println("Your array char:");
  for (int i = 0; i<5; i++)     // Experiment to see what happens if your index goes out of bounds
  { 
    Serial.print("Index ");
    Serial.print(i);
    Serial.print(" contains char '");
    Serial.print(my_char[i]);
    Serial.print("', ASCII decimal ");
    Serial.println(my_char[i], DEC);
  }
  
  Serial.println();
  Serial.println("Let's do some calculations:");
  for (int i = 0; i<4; i++)     
  {     
    Serial.print(my_char[i]);
    Serial.print(" + ");
    Serial.print(my_char[i+1]);
    Serial.print(" = ");
    Serial.println(my_char[i] + my_char[i+1]);
  }

  Serial.println();
  Serial.println("Let's do some calculations, and store the results:");
  for (int i = 0; i<4; i++)     
  {     
    Serial.print(my_char[i]);
    Serial.print(" + ");
    Serial.print(my_char[i+1]);
    Serial.print(" = ");
    char sum = my_char[i] + my_char[i+1];  // Beware, I am using a char here, which is 
                                           // a single byte. This means that if this
                                           // calculation yields more than 256, it will 
                                           // truncate without an error.
    my_char[i] = sum;
    Serial.print(my_char[i], DEC);
    Serial.print(" -> Index ");
    Serial.print(i);
    Serial.print(" now contains value ");
    Serial.println(my_char[i], DEC);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
