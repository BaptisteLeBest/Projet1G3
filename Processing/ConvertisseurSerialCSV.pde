//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;

String[] m1;

void setup() {
  udSerial = new Serial(this, Serial.list()[1], 9600);
  output = createWriter ("data.csv");
  frameRate(1);
}

  void draw() {
    if (udSerial.available() > 0) {
      String SenVal = udSerial.readString();
      
      m1 = match(SenVal, "(\\d.+);(\\d.+)");
      
      if(m1 != null && int(m1[1]) > 0) {
        print(SenVal);
        output.print(SenVal);
      }

    }
  }

  void keyPressed(){
    output.flush();
    output.close();
    exit(); 
  } 
