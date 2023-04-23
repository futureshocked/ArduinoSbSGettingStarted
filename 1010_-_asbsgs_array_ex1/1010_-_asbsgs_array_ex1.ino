/* 
 *  An example of how to create an use an array of integers
 *  We'll declare an array of 5 integers.
 *  We'll print the contents in the serial monitor.
 *  We'll do some calculations, store the results, and print the results in the serial monitor.
 *  
 */

int my_integers[5] = {1, 2, 3, 4, 5} ;  // We want this array to contain 5 integers, 
                                        // so we'll declare it with size 5.

void setup() {
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }

  Serial.println("Your array numbers:");
  for (int i = 0; i<5; i++)     // Experiment to see what happens if your index goes out of bounds
  { 
    Serial.print("Index ");
    Serial.print(i);
    Serial.print(" contains value ");
    Serial.println(my_integers[i]);
  }
  
  Serial.println();
  Serial.println("Let's do some calculations:");
  for (int i = 0; i<4; i++)     
  {     
    Serial.print(my_integers[i]);
    Serial.print(" + ");
    Serial.print(my_integers[i+1]);
    Serial.print(" = ");
    Serial.println(my_integers[i] + my_integers[i+1]);
  }

  Serial.println();
  Serial.println("Let's do some calculations, and store the results:");
  for (int i = 0; i<4; i++)     
  {     
    Serial.print(my_integers[i]);
    Serial.print(" + ");
    Serial.print(my_integers[i+1]);
    Serial.print(" = ");
    int sum = my_integers[i] + my_integers[i+1];
    my_integers[i] = sum;
    Serial.print(my_integers[i]);
    Serial.print(" -> Index ");
    Serial.print(i);
    Serial.print(" now contains value ");
    Serial.println(my_integers[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
