# advanced-embedded-systems
# Early Flood Detection

#### Description:

This project targets implementing a system which observes natural factors to detect a potential
flood early for caution. This helps minimize the damage caused by the flood ranging from
property damage to loss of lives.

#### Engineering requirements:

The system is required to detect a flood through achieving the following:

- The system should keep water level under observation by reading the value of the water
    level sensor every 15 minutes.
- The system should send the recorded data to the database every 15 min.
- Once the water level rises above a predetermined point, the system should send a signal
    to trigger an alarm.
- The system should be power optimal.

#### Engineering specs:

The system consists of two nodes: a main processing node and a one or many gateway nodes
and a database to log data into. An alarming nonfiction is sent to the gateway node from the

#### processing node once the flood alarm is signaled.

- The sensor is connected to ESP32, which processes and saves data in the database and
    sends an alarming notification to the gateway node.
- The system has a WIFI feature, which is useful to access the system and its data over IoT
    (its collected data can be accessed from anywhere easily using IoT).
       - We would use the deep sleep mode to conserve the power.
       - Convert to light sleep mode when the RTC registers is filled with data to move
          them to the main memory when needed (since the RTC data registers can with
          hold 8KB)
       - convert to the modem sleep mode to turn on the WiFi in 2 cases:
          - To alert the user and to log the data every 24 hours on a website
          - To check the leakage that occurred throughout the day.


### Overall hardware block diagram:

### Overall Data-Flow block diagram:


**Hardware Specifications**

```
● 1x esp
● Water Level Sensor
● Resistors
● Capacitors
● Transistors
● Cables and Connectors
● Diodes
● Breadboard
● Transformer/Adapter
```
**Software Specifications**

```
● C Compiler
● Programming Language: C
```
### Power consumption:

### ESP32 power modes


## E = Edeep-sleep + Elight-sleep + Emodem-sleep= 8.63*10^- 3 mAh

## Using a 2.3 v / 500 mAh battery, the duration is 2392 days, which is more

## than enough.

```
State Power
(mA)
```
```
Duration
(sec)
```
```
Consumption (mAh)
```
```
Deep-sleep = 0.01* 3587* 7.744x10^- 10
```
```
Light-sleep - to
main memory = 0.8 *12 *1.85x10^- 5
```
```
Modem-sleep -
transmission = 31* 1 *8.61x10^- 3
```

