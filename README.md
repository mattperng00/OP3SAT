# OP3SAT
Team CSpark
Matthew Perng, Billy Petruska, Johnny Poeschel, Ifeanyi Orizu Jr
ECE:4880 Principles of Electrical and Computer Engineering Design
13 December 2020
Project Proposal
 
Executive Summary
In order to help solve the missing baryon problem, the Halosat was launched in 2018 to search for baryon gas that halos around our galaxy. Baryonic matter consists of atoms that emit and transmit electromagnetic radiation and is believed to be found in warm and hot intergalactic gas. During the Microwave Background time period, the universe was uniformly filled with 3000 K hot gas. Analyzing today’s baryon quantity, only three percent of the total mass and energy of the universe was found. Therefore, the observed amount of baryonic matter does not match the theoretical predictions. The satellite is equipped with x-ray detectors in order to discover if hot bayron gas haloes around our galaxy. The Halostat is still orbiting Earth today and it will eventually burn up. For spring semester 2021, Team CSpark has taken the project of implementing a new Control and Data Handling System (CDHS) for OP3Sat, the successor to Halosat. Using the FreeRTOS open source operating system and an ARM microcontroller, the team will attempt to create an efficient embedded system that receives and processes commands, detects x-rays, and transmits science and housekeeping data back to a ground station on Earth. 
 
I.	Problem Statement
The goal of this project is to implement a Control and Data Handling System (CDHS) suitable for use on science instruments intended for flight on small satellites. To implement this system we are importing FreeRTOS into the SAMD20. We will use FreeRTOS mechanisms to implement concurrency, process and memory management, and task scheduling to ensure that the system is reliable, responsive, and robust. 

	The SAMD20 is a single core processor, yet the CDHS will be expected to implement a variety of functions, such as serial link communication, detecting and recording asynchronous events, and managing the instrument cooling system. This means that we will need to divide the CDHS into independent tasks, and develop a scheduling scheme that ensures that each task gets time on the CPU, while also prioritizing higher priority jobs. Furthermore, these tasks will also need to pass information between each other. To do this we will use queues. 
The CDHS will be controlled via a user interface implemented in the Ball Aerospace COSMOS system for command and control of embedded systems. The computer running COSMOS serves as both the spacecraft and ground station, transmitting messages to the instrument and also storing data received from it.
 
II.	Design Objectives 
1.	Design a system that sends and receives packets to and from the spacecraft, decodes them, and detects and recovers from errors in the transmission.
1.	We will be implementing serial communication that sends and receives via UART. A timer interrupt will be triggered when the external x-ray/instruments are sending data to the SAMD20. The data then will be stored in one of out the five heaps in FreeRTOS. Then the data will be sent back to ground when commanded.
2.	Design a system that utilizes memory in an efficient manner and does not exceed its physical memory capacity. 
3.	Design a system that has guaranteed maximum response and processing times.
1.	This will be handled by implementing a scheduling algorithm that is based on priority.
4.	Design a system which implements efficient queues, which will facilitate the passing of data between processes with zero copy.

III.	Major System Requirements and Constraints
•	Major System Requirements
The CDHS shall: 
1.	Receive and interpret commands and Time of Day (ToD) messages transmitted from the spacecraft via a serial communications line.
2.	 Format and transmit telemetry packets contain housekeeping and science data to the spacecraft via a serial communications line.
3.	Receive “science events” and then store the events so that they can be formatted into telemetry packets that can be transmitted to the spacecraft. There must be sufficient information in the telemetry stream to reconstruct the absolute time of each science event using information from the ToD messages. 
4.	Record housekeeping information so that it can be formatted into telemetry packets that can be transmitted to the spacecraft. There must be sufficient information in the telemetry stream to reconstruct the absolute time at which the housekeeping information was measured. 
5.	Automatically reset using a watchdog timer in case of a processing fault. 
•	Secondary System Requirements (Nice to Have)
1.	Set control voltages and digital signals via commands from the spacecraft.
2.	Provide a mechanism to run device control processes with process parameters that can be adjusted via commands from the spacecraft.
3.	Build the CDHS with sufficient generality to allow flexibility in how each of these requirements is implemented for different science instruments. The definitions of the packet formats, science events, housekeeping information, etc., may vary between different science instruments.
4.	Implement an user interface application (Java FX) that will handle commands sent to the SAMD20 and display a log of activity using an embedded database (SQLite)  as well as simulate the connection to the satellite.
 
•	Major System Constraints
1.	Must simulate instrument readings such as x-ray pulses, due to lack of instrument hardware. 
2.	The system must not exceed its physical memory capacity (i.e the stacks and heaps must not overflow).
3.	The system must guarantee that commands/tasks will begin processing within a certain time period after the trigger has been received.
4.	The system must guarantee that commands/tasks will finish within a certain time period after processing has started.
5.	C Programming Language
6.	FreeRTOS operating system
7.	Cortex-M0+ 32 bit processor
8.	ARMv6-M instruction set architecture
9.	Serial Peripheral Interface
•	Standards
Document Number	Title
CCSDS 133.0-P-1.1	Space Packet Protocol
ITU-T V.41	Code-Independent Error-Control System
CCSDS CRC-16	Frame Error Control Field
Table 1: System Standards
•	Societal Factors
This project will not have an effect on public health because it will not be used by the public and will be out of reach as it will be launched into space. This may be beneficial to science culture to further our understanding of the universe. The device we are designing has an environmental impact as it uses a PCB board which is harmful manufacturing. Our device will also burn up upon reentry so it will not be recycled. The device doesn’t have any economic impact as it will not be sold, and is inexpensive for our client. Our project will have a miniscule to no effect a global level as it is being used for one small satellite. 

IV.	Design Concept
•	Research and Investigation
Initially we planned on using the IGLOO2 RISC-V Creative Development Board as the base of our system. However, due to our inexperience with FPGAs, we decided to use the ATSAMD20-XPRO ARM development board instead.  The client will allow us to see software used on a previous project if we choose, and has also put in contact with an expert if we would like to discuss concepts or concerns.
•	Selection of Design Concept
Figure 1: Software Block Diagram
The plan we are going to follow is modular design. We are going to look at the overall logic of the system and break it into simple processes that will be time-shared on the CPU by the FreeRTOS kernel.  This concept we think will allow our functions to be concise and should be the most time effective because we can split up the tasks for each group member.
Figure 2: Hardware Block Diagram
The hardware used for this project will require a PID loop to control the temperature of instruments aboard our design. The TEC will require a smoothing filter because the microcontroller will output a PWM wave and the sharp edges will affect the X-ray instrument. We will simulate the X-ray instrument through the use of a push button.
 
V.	Deliverables and Milestones
•	Project Deliverables
1.	Initial command processing demonstration
2.	Final design software files
3.	Complete logic design documentation
4.	Fully Functioning Control and Data Handling System
•	Schedule and Timeline
1.	Meeting every two weeks with the sponsors to discuss project architecture and progress during the fall semester.
			Figure 3: Project Timeline
VI.	Risk Management
•	Primary Risks to Project Success
The primary risks for this project include being unable to implement the necessary software specifications to integrate the software with the hardware, as well as communication between the two. Another risk is the corruption of the memory of the atsamd20-xpro.
•	Risk Management Plan
We plan on talking to our client to get more insight on the project if we are making no progress because they have past experiences which could be beneficial to get past any difficulties that we might face. We also managed the risk of the ATSAMD20-XPRO breaking by purchasing 3 additional sets.
•	Contingency Plan for COVID pandemic
We plan to meet in person with the exception of meeting Ifeanyi over zoom. We have everything we need to work on this from home, as well as a github for code collaboration.  If the pandemic gets worse, then we will continue to work together over zoom.
VII.	Budget
 
Item #	Description	Source	Quantity	Individual
Cost	Total Cost
1	ATSAMD20-XPRO 	Microchip
Technology	3	$71.60	$214.80
2	ADC	TBD	1	~$5	$219.80
3	DAC	TBD	1	~$5	$223.80
Table 2: Project Budget

VIII.	Team Considerations
•	Knowledge and Skills
The knowledge required to complete this project successfully are knowledge of embedded systems, electronic circuits, and coding.  The skills required are design, research, and troubleshooting.  Our team is capable of completing the objectives because of previous coursework which includes, embedded systems, circuits knowledge, and coding classes. Those classes have helped us to refine our skills which will be necessary in being successful.  The circuits classes and coding have aided our design and troubleshooting skills by completing labs and projects.  Embedded systems class has taught us how to do the necessary research in order to understand specs of microcontrollers and component choice.  
•	Team Organization and Function
We determined the most efficient method of team organization is by splitting roles by strengths. Billy has extensive experience with building circuits. Therefore, he will be in charge of troubleshooting and designing the circuit and will assist with hardware integration.  Ifeanyi will manage the overall functionality of the software logic and write tests since he has good organization skills.  Matt will implement the functions that Ifeanyi has designed since he has experience with hardware coding.  Johnny will assist Matt with the implementation, and he will code the simulations in order to test the system’s logic.
•	Interaction with Sponsor
We plan to meet with our sponsor every other week for progress updates and design . This time will also be used to address any questions or concerns if any are to arise. 

