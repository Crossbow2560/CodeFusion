// int heartbeat = 0;
// int bpm = 0;
// int threshold = 350;
// int timer = 0;
// int trigger = 10;
// int trigger_timer = 0;
int reading = 0;
int beats = 0; // Value of bpm
int threshold_bpm = 520; //Tweak this value for diiferent people
int time = 0;  // Value of the time between 1st and "measurement_amt" value
int measurement_freq = 50; // Tweak this value to increase or decrease the value of the measurement time
int time_delay = 500; // Tweak this value to increase or ddecrease the value of the time delay after one beat is sensed
int measurement_amt = 10; // Tweak this value to increase or decrease the value of measurement
int measurement_cur = 0;
float bpm = 0;
int threshold_pot = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  reading = analogRead(0);
  // threshold_pot = analogRead(1);
  // threshold_bpm = threshold_pot;
  if(reading >= threshold_bpm && measurement_cur <= measurement_amt){
    Serial.println("Heartbeat Detected!");
    beats += 1;
    measurement_cur += 1;
    delay(time_delay);
    time += time_delay;
  }
  else if(measurement_cur > measurement_amt){
    Serial.println("MAX");
    Serial.println(time);
    bpm = (time/(1000))*6;
    Serial.println(bpm);
    measurement_cur = 0;
    time = 0;
  }
  else{
    delay(measurement_freq);
    time += measurement_freq;
  }
}

  // heartbeat = analogRead(0);
  // if(heartbeat >= threshold){
  //   Serial.println("Detected Heartbeat");
  //   if(timer == 0){
  //      ;
  //   }
  //   else{
  //     Serial.println("Inside else statement 1");
  //     trigger += 1;
  //     timer += 50;
  //   }
  // }
  // if(trigger_timer >= 10){
  //   Serial.println("Inside if statement 1");
  //   // Serial.println(timer);
  //   trigger = 0;
  //   timer = 0;
  // delay(400);
  // timer += 400;
  // }
  // delay(50);