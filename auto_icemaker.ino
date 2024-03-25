#include <HX711.h>
#include <Servo.h>

const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;
const int SERVO_PIN = 5;

const bool INVERT_WEIGHT = true;
const long ON_THRESHOLD = 300000;
const long OFF_THRESHOLD = 100000;
const int SERVO_ON_POS = 140;
const int SERVO_OFF_POS = 90;

const int LOOP_DELAY = 1000;
const int SAFETY_COUNT = 5;
const int SAMPLES = 5;

HX711 loadcell;
Servo servo;

bool on;
int counter;
int misses;

void setup()
{
  Serial.begin(57600);
  loadcell.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  servo.attach(SERVO_PIN);

  on = false;
  counter = 0;
  misses = 0;
}

void loop()
{
  if(loadcell.is_ready())
  {
    long value = loadcell.get_units(10);
    Serial.print("Weight value: ");
    Serial.println(value);
    misses = 0;
    if(INVERT_WEIGHT ^ (value < ON_THRESHOLD))
    {
      if(counter < SAMPLES)
      {
        counter++;
      }
      else
      {
        ice_on();
      }
    }
    else if(INVERT_WEIGHT ^ (value > OFF_THRESHOLD))
    {
      if(counter > 0)
      {
        counter--;
      }
      else
      {
        ice_off();
      }
    }
  } 
  else
  {
    Serial.println("HX711 not found.");
    if(misses < SAFETY_COUNT)
    {
      misses++;
    }
    else
    {
      ice_off();
    }
  }
  delay(LOOP_DELAY);
}

void ice_on()
{
  if(!on)
  {
    Serial.println("Turning icemaker on.");
    servo.write(SERVO_ON_POS);
    on = true; 
  }
}

void ice_off()
{
  if(on)
  {
    Serial.println("Turning icemaker off.");
    servo.write(SERVO_OFF_POS);
    on = false;
  }
}