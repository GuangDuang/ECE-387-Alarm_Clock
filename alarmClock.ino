unsigned long time;
int s = 0;
int m = 0;
int h = 0;
int mSet = -1;
int hSet = -1;
int mAlarm = -1;
int hAlarm = -1;
boolean enableAlarm = false;
String income;
String setElement;
void setup() {
  Serial.begin(9600);
  pinMode(2 , INPUT);
}
void loop() {
  Serial.print("Time: ");
  Serial.print(h);
  Serial.print(":");
  Serial.print(m);
  Serial.print(":");
  Serial.print(s);
  Serial.println(" ");
  s++;
  //time = millis();
  if (Serial.available() > 0) {
    int index = 0;
    income = Serial.readString();
    index = income.indexOf(" ");
    setElement = income.substring(0, index);
    income = income.substring(index + 1);
    index = income.indexOf(" ");
    hSet = income.substring(0, index).toInt();
    mSet = income.substring(index + 1).toInt();
    if (setElement.equals("time")) {
      h = hSet;
      m = mSet;
      s = 0;
    }
    if (setElement.equals("alarm")) {
      hAlarm = hSet;
      mAlarm = mSet;
      enableAlarm = true;
    }
  }
  if (s == 60) {
    s = 0;
    m = m + 1;
  }
  if (m == 60)
  {
    m = 0;
    h = h + 1;
  }
  if (h == 24)
  {
    h = 0;
  }
  if (enableAlarm){
    if(h == hAlarm && m == mAlarm){
      tone(3, 300);
    }
    if (digitalRead(2)==1){
      noTone(3);
      enableAlarm = false;
    }
    
  }
  //Serial.println(time); 
  delay(999);
  delayMicroseconds(450);
          
}
