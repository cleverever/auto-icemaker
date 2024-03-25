# Background
The apartment I am leasing has a fridge which lacks a fully automatic ice maker. It must be manually switched on and off with a lever which means that if you forget to turn it on, there won't be enough ice or if you forget to turn it off, the ice bin may overflow and spill into the freezer. I figure I could save myself a lot of trouble by converting the ice maker from semi-automatic to fully-automatic and that it wouldn't be too difficult or costly.

# How It Works
1. Measure weight of ice in bin using a loadcell.
2. If weight is below a certain threshold, switch ice maker on. If weight is above a certain threshold switch ice maker off. State is unchanged between thresholds to prevent rapid switching.
3. Set servo angle to pull ice maker lever down or up to turn it on or off respectively.
4. Repeat at long intervals to reduce power usage.

# Libraries
This project makes use of [Bogdan Necula's HX711 library](https://github.com/bogde/HX711) and [Arduino's built-in servo library](https://github.com/arduino-libraries/Servo).

# Materials
## Power and computation
- Arduino Uno
- 9V battery + holder
- Breadboard

## Weight measurement
- HX711 load cell amplifier
- 10kg load cell
- 2x plastic sheet (9" X 8")
- 4x M4 screw
- 4x #8 spacer

## Ice maker switch
- 20kg servo + screws
- 14 gauge wire
- Velcro fastener
