# barrel-roll

## What is this
Barrel roll is a 150g combat robot that has a 2.706693 inch long bar spinner. There are two options for the microcontroller of the robot. Right now I have a pcb designed with a RP2040 in mind. I also have a version of the schematic/firmware with an esp32 as the microcontroller.

## Why I created this
I created barrel roll because the way I got into robotics/programming/stem in general is through watching various battlebots-like shows and videos on the internet. So for a long time, I wanted to create my own battle bot. Once I saw the Fallout event by Hack Club I decided that it would be an amazing opportunity to create something similar to what got me into this in the first place. My goal with barrel roll is to create a bar spinner battle bot that could compete in the 150g weight class.(not necessarily well)

## PCB
![image](ReadmeAssets/PCB.png)
![image](ReadmeAssets/PCBSchem.png)
Above are the images of the PCB version of the electrical components of the robot(To be honest right now it feels more like a glorified pinout board)

![image](ReadmeAssets/PCBDIP.png)
Above is a picture of the pcb using DIP sodering. The schematic is the same as the original SMD sodered PCB.

![image](ReadmeAssets/ESP32Schem.png)
The above is a picture of the schematic for anyone using the DOIT esp32 devkit v1. I made this one because it could cut down on the cost of the project as a whole.


## Assembly
Onshape link: https://cad.onshape.com/documents/4d0cf8c11fd66439fc3e30b0/w/a8064dfad10d7d33689fe150/e/b5006982824e862bc7271070?renderMode=0&uiState=69e65a2ccd9a40dd9e183c54
![image](ReadmeAssets/FinalAssembly.png)
A note about the assembly: I could not find 3d models of the bearings I wanted to use so I made a model with the same dimensions as the bearings. /n

### PCBs/Electronics
For this project I made several usable versions of the electronics. I did this to make sure that when it comes time for me to actually build this I can still build it even if I don't have some of the equipment that I need. The main distinction between all of the options are the different ways to soder on the microcontroller. For the no pcb method you could just use an esp32 instead of a xiao rp2040.

#### PCB SMD
IF you are using a PCB to create Barrel Roll then you need to get the Gerbers.zip from barrel-roll folder in the repo. After this you need to go to your preferred PCB manufacteror of your choice to have it manufactured.  [Gerbers.zip](barrel-roll-pcb/Gerbers.zip)
You could use [this](https://fabacademy.org/2024/labs/charlotte/students/richard-shan/lessons/week4/rp2040/) as a reference for SMD sodering the xiao RP2040.

#### PCB DIP
If you are using the DIP version of the pcb then you need to follow many of the same steps as using the SMD pcb method. However, since you are using DIP for the RP2040, sodering the PCB should be significantly simpler. [Gerbers.zip](barrel-roll-DIPPCB/Gerbers.zip)

#### No PCB
If you are not using a PCB your costs will be a little bit lower since you don't need to by the PCB. To find the wiring diagram you can look in the barrel-roll-nopcb folder of the repo. This is a kicad project that contains a wiring diagram if you have a DOIT ESP32 devkit 1(The esp32 from the electronics kits that commonly come from hackclub events).

#### Assembling the weapon system shell
In order to assemble the weapon system properly you want to make sure that you place the parts on the axle in the correct order. Axle stopper, Weapon with bearing, Axle stopper. Then you need to place the axle onto the two pieces on the Side shell.
![image](ReadmeAssets/FrontAssembly.png)
Here is a picture of the front assembly that you should try to replicate.


#### 3D printing
To assemble the barrel-roll you first need to print out the parts specified in the onshape document. All the parts in the FINAL folder must be printed There will be a note with the quantity and the infill amount. The fillament for all of these will be up to you. I will personally be using TPU. If you do not want to go into the Onshape, All of the final .step files will be in [models/FinalParts](models/FinalParts).\
\
 You need to print:
* 1 BodyFinalPart1.step
* 1 BodyFinalPart2.step
* 2 n20motorToWheel.step
* 2 shaftcap.step
* 1 WeaponMotorTimingWheel.step
* 1 WeaponV2.step



#### Assembling the shell
##### For context:
![image](ReadmeAssets/MainShell.png)
The above is the main shell
![image](ReadmeAssets/SideShell.png)
The above is the side shell
For the rest of it you should look at the onshape document.

To assemble the Main shell with the Side Shells you can use the bowtie connector along side the fastening rod to attach each part of the SIDE_SHELL without the use of metal connectors. However you may find that securing the weapon/shaft/shaft caps and belt may be easier than attaching SIDE_SHELL to MAIN_SHELL immediately. After you get the side shells attached to the main shell you need to place all of the remaining electronics into the shell. After this is done you can use the heatset inserts into the holes at the top of the Main shell. I would highly recomend taking a look into the onshape so you can see what I am descibing here.


## Usage
To use barrel roll you need to connect the radio recever to the radio sender.
After this you should be able to control the robot using your controller.



## BOM
There are three BOMs one for SMD, DIP and one if you are simply using a esp32.
The "master" BOM can be found here [BOM](ReadmeAssets/BOM.csv)(This will be the most convienient to use and will be the most updated in the coming months.)
### BOM for PCB
 [Here is the .csv for the BOM](ReadmeAssets/BarrelRollerBOM.csv)
### BOM if you are not using a PCB
 [Here is the .csv for the BOM](ReadmeAssets/BarrelRollerBOMnopcb.csv)
### BOM PCB-DIP
 [Here is the .csv for the BOM](ReadmeAssets/BarrelRollerBOMDIP.csv)


## Poster
![image](ReadmeAssets/BarrelRoller.png)
[Poster](Poster/Barrel%20Roller.pdf)
