#include <iostream>
#include <thread>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string>
// Includes Above

// Prototypes
void RocketsLaunchedFromSubStationMars();

// Global Variables
int m_TotalRocketsLaunchedFromMars = 0; // Keeps track of our Toal Rockets
static bool m_abortLaunchSwitch = false; // Our Abort Switch

int main()
{
int MissContLC = 0;
std::string Input;

	std::cout << "\n\n\t *** Mars Base Alpha *** \n\n"; // <- Introduction for our Simulation 
	std::cout << "\n *** Our base is located in the Gale Crater *** "; // <- Introduction for our Simulation 
	std::cout << "\n      *** COORDS : 5.4*S :: 137.8*E ***         "; // <- Introduction for our Simulation 
	std::cout << "\n Our base is used to launch Space X Rockets deeper"; // <- Introduction for our Simulation 
	std::cout << "\n into the universe, We get paid pretty well for it!"; // <- Introduction for our Simulation 

// Launching 10 Rockets from the Main Base || 3 Sec apart.
// Transfer LC from the Main to RPSC after the first launch.
// Create the ABort Button from MB to override the SC to stop any further launching.
// Keep the User Informed.

	std::cout << " \n\n\n Our current Mission thread ID is : " << std::this_thread::get_id() << std::endl; // Tells the user what the thread ID is
	std::cout << " \n\n\n " << std::endl;

	system("pause"); // Pauses the Simulation

	std::cout << "\n Gale Crater Main Base Launches : " << ++MissContLC << "\n"; // Adds one to the Mission Control Launch Count
	std::cout << "\n Gale Crater Total Launches : " << ++m_TotalRocketsLaunchedFromMars<< "\n"; // Adds to the Total Launches

	Sleep(3000); // Freezes the Program for 3 Seconds

	std::cout << "\n Mission Control has launched the first rocket from Gale Crater \n"; // Time to transfer to the Thread
	std::cout << "\n Time to turn over lauch control to our Space Cadet at our SubStation!\n\n ";

	system("pause"); // Pauses the Simulation

	std::thread RocketControlSubStationThread(RocketsLaunchedFromSubStationMars); // Starts the thread. keeping it running side by side.

	std::cout << "\n To stop any further launches from the SubStation, Please Type [Exit]\n\n";// To stop the SubStation, Enter Exit
	std::getline(std::cin, Input);

	if (Input == "Exit") // If we used the Exit, It ends the program instantly
	{
		m_abortLaunchSwitch = true;
		std::cout << "\n\n\n JR. SPACE RANGER === ABORT SWITCH HAS BEEN FLIPPED AT MAIN BASE === OVERIDE OCCURED \n\n\n";

		RocketControlSubStationThread.join(); // zips the threads back together


		std::cout << "Stats of Launch"; // shars the stats of the launch
		std::cout << "\nRockets Launched by MC : " << MissContLC; // main base launched
		std::cout << "\nRockets Launched by SS : " << m_TotalRocketsLaunchedFromMars - MissContLC; // Sub Station Launches
		std::cout << "\nTotal Launches from Base : " << m_TotalRocketsLaunchedFromMars << std::endl; // Total Rockets Launched
		std::cout << "\n\n\n"; // Newlines for neatness
		std::cout << "Ready to Exit Simulation!\n\n";
		system("pause");
		return 0; // Exits simulation
	}
	
	// if we dont use exit, it runs the rest of the program normally

	RocketControlSubStationThread.join(); // zips the threads back together


	std::cout << "Stats of Launch"; // shars the stats of the launch
	std::cout << "\nRockets Launched by MC : " << MissContLC; // main base launched
	std::cout << "\nRockets Launched by SS : " << m_TotalRocketsLaunchedFromMars - MissContLC; // Sub Station Launches
	std::cout << "\nTotal Launches from Base : " << m_TotalRocketsLaunchedFromMars << std::endl; // Total Rockets Launched
	std::cout << "\n\n\n"; // few newlines for neatness
	std::cout << "Ready to Exit Simulation!";
	system("pause");
	return 0; // Exits the simulation
}


void RocketsLaunchedFromSubStationMars()
{
	
		
		using namespace std::literals::chrono_literals; // using SLEEP to simulate Time passing for Processing
		
		int RocketControlSSLC = 0; //create our local rocket count and tracking VAR
		
		std::cout << "\n Mission Thread ID of our Sub Station : " << std::this_thread::get_id() << std::endl; //identify if we are on dif thread using Thread ID

		// Lets have our JR. SR launch some rockets
	
	
		while (m_abortLaunchSwitch != true) // While returning False, Continues running
		{
			std::cout << "####################" << std::endl;
			std::cout << "Gale Crater Sub Station Launches : " << ++RocketControlSSLC << std::endl;
			// The rocket base is the MCLF and the LPF
			std::cout << "Gale Crater Total Launches : " << ++m_TotalRocketsLaunchedFromMars << std::endl;
			std::cout << "####################" << std::endl;
			std::this_thread::sleep_for(3s); // Sleeps the thread for 3 seconds
			if (m_TotalRocketsLaunchedFromMars == 10) { m_abortLaunchSwitch = true; } // After Ten launches, it will automatacally end the While loop
		}
		std::cout << "All rockets have been launched :: Please Hit Enter to Continue\n\n"; // Once you hit enter, It will return to the rest of the simulation.
}