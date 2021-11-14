//Micah Turpin
//micturpi@uat.edu
//Assignment - CIA Codebreaker
//I don't even know if half of this is going to work. I made this while hyped up on so much caffeine and lack of sleep, I'm surprised anything is even readable. I ran it multiple times to try to work out any bugs and check all program cases, but if something breaks, I'm sorry. I hope you actually read this :)

#include <iostream> //imports the iostream library
#include <cstring> //imports the cstring library
#include <vector> //imports the vector library
#include <ctime> //imports the ctime library
#include <algorithm> //imports the algorithm library

using namespace std; //ensures that the standard namespace for keywords is being used in this program

vector<string> words; //creates string vector called 'words'. Will be important later in this program
string userName; //creates variable that will end up holding the agent's name


void intro() { //prints out an introduction to the CIA Codebreaker program
	cout << "----Welcome To CIA CODEBREAKER----\n\n";
	cout << "Best of luck. . .\n";
}

void username() { //takes the user input and stores it in a variable called 'username' for future use
	cout << "Enter your name here, Agent:   ";
	cin >> userName;
	cout << endl;
}

void overview() { //gives the player an overview of the program they will be going through
	cout << "*Overview:*\n";
	cout << "The current automated programs that the CIA uses to decode enemy transmissions have always worked well. . .until recently.\n";
	cout << "Recently the enemy is using single-scrambled low-tech keywords to signal other enemies to start attacks, which our current code decryption programs have not been successful against.\n";
	cout << "Here at the CIA, we are developing a new codebreaking team, which will rely on human expertise to detect these low-tech scrambled keywords.\n";
}

void directions() { //gives the player the directions for the program they will be going through
	cout << "*Directions:*\n";
	cout << "The first step would be to identify when the simulation is starting so, you know when to start.\n";
	cout << "The next step would be trying to get the 3 words that have been randomly assigned to you.\n";
	cout << "You will know how many guesses you have left if you end up guessing incorrectly.\n";
	cout << "The point of the simulation is to guess the 3 words that were given to you to solve.\n";
	cout << "If you guess the first word correctly, you will be congratulated and you will move on to the next.\n";
	cout << "You will know if you pass or fail the course. You will have the chance to take it again.\n";
	cout << "--These are the end of the directions--";
}

void keywords() { //creates the keywords that the user will be guessing
	words.push_back("undercover"); //adds the word 'undercover' to the string vector 'words'
	words.push_back("agency"); //^^ --> 'agency'
	words.push_back("airport"); //^^ --> 'airport'
	words.push_back("station"); //^^ --> 'station'
	words.push_back("corporate"); //^^ --> 'corporate'
	words.push_back("mechanic"); //^^ --> 'mechanic'
	words.push_back("boil"); //^^ --> 'boil'
	words.push_back("beetle"); //^^ --> 'beetle'
	words.push_back("obscurity"); //^^ --> 'obscurity'
	words.push_back("adjacent"); //^^ --> 'parallel'
}

void mainGuessing() { //function that contains all of the statements that run the main portion of the guessing part of the program
	srand(static_cast<unsigned int>(time(0))); //generates a pseudo-generated random number
	random_shuffle(words.begin(), words.end()); //shuffles the words in the 'words' string vector in a random order

	char again = 'y'; //creates a variable that will be checked for later to see if the user wants to restart the program
	const int maxIncorrect = 8; //creates a variable that will be referenced as the maximum number of tries that the agent gets
	int wrong = 0; //creates a variable that keeps count of how many incorrect guesses have been made
	string currentWord; //creates a variable that contains the current word that was randomly selected earlier
	string currentStance; //creates a variable that keeps track of the current position in the randomly selected word
	string lettersUsed = ""; //creates a variable that keeps track of what letters have been used
	int simulations = 1; //creates a variable that keeps track of how many simulations have been played

	do { //dew it
		for (int roundNumber = 0; roundNumber < 3; roundNumber++) { //runs the below code statements three times
			currentWord = words[roundNumber]; //chooses the word correlating to the round number from the randomly shuffled 'word' string vector from earlier
			currentStance = string(currentWord.size(), '-'); //prints out a string with all of the letters replaced with dashes, so the user can't see any of the letters

			while ((wrong < maxIncorrect) && (currentStance != currentWord)) { //where all the guud stuff happens (user is actually interacting in this loop)
				cout << userName << ", You have " << (maxIncorrect - wrong) << "  guesses left! \n"; //tells the user how many guesses they have left
				cout << "You have used the following letters: \n" << lettersUsed << endl; //shows the user a list of what letters they have used so far
				cout << "So far, the word is: \n" << currentStance << endl; //shows the user how many correct letters of the secret word they have guessed, and where those letters are located in the word

				char guess; //variable for all of the guesses that the agent makes
				cout << "Enter your letter guess here, " << userName << ": ";
				cin >> guess; //takes user input from the agent and stores it in the variable 'guess'
				guess = tolower(guess); //makes sure all agent inputs are in lowercase, just to avoid any screwups in checking for the value of the letter in the secret word

				while (lettersUsed.find(guess) != string::npos) { //see if letter has been used before - yell at agent until they guess a letter that hasn't been used
					cout << "You have already guessed " << guess << endl; //^^
					cout << "Enter your guess here: "; //^^
					cin >> guess; //^^
					guess = tolower(guess); //^^
				}

				lettersUsed += guess; //adds the letters guessed by the agent to the 'lettersUsed' variable

				if (currentWord.find(guess) != string::npos) { //give the agent a cookie if their guess is correct
					cout << "You are correct! " << guess << " is in the word!\n"; //tell agent that they are correct in their guess
					cout << "Here, have a cookie!!"; //givs c00kee
					for (unsigned int i = 0; i < currentWord.length(); i++) //replaces the dash at the correctly guessed location with the guessed letter
					{
						if (currentWord[i] == guess) //ensures that all instances of properly guessed letter are replaced with that letter
						{
							currentStance[i] = guess; //sets the location of matching letters in the word to be the correctly guessed letter, rather than a dash
						}
					}
				}
				else { //doesn't give an agent a cookie cuz they are dead wrong and will never make it in this cruel and harsh world
					cout << "Sorry, " << userName << ", " << guess << " is not in the word.You will not get a cookie\n";
					++wrong; //add 1 to the number of wrong guesses they have made, the idiot
				}
			}

			if (wrong == maxIncorrect) { //agent has missed out on too many cookies. They guessed incorrectly too many times
				cout << "You are not CIA Material, Sorry Agent " << userName << "!\n"; //tell them that they can never become an agent - crush their hopes and dreams
			}
			else {
				cout << "\nAgent, You guessed it, Great Job!" << endl; //tyme for m3g@ c00keeeeeeee!!!!!!
				cout << "The word was : " << currentWord << "!" << endl; //tells agent what word they just successfully guessed
				cout << "Completed round " << roundNumber + 1 << " of 3!!!\n" << endl; //tells agent what round they have completed - pulls number from loop initialization
			}

			wrong = 0; //variable that stores what the agent got wrong
			lettersUsed = ""; //variable that stores the letters used by the agent
		}

		cout << "Do you want to try again? (y/n)" << endl; //asks agent if they want to play again
		cin >> again; //takes use input to see if they want to play again
		cout << "You have run " << simulations << " simulations." << endl; //tells the agent how many simulations they have played
		simulations++; //adds 1 to the number of simulations that have been played
	} while (again == 'y'); //if agent decides to type 'y' to play again. . .
}

void endGame() {
	cout << "You have reached the end, Agent " << userName << "!" << endl; //agent reached the end of the program. Congrats, they protected the world from yet another simulated threat!!
	system("pause"); //pauses the system
}

int main() { //runs everything (all functions from earlier in the program are initialized here)
	intro(); //show introduction to agent
	username(); //gets agent name and stores it in var for use later in program
	overview(); //shows overview of the CIA Codebreaker to the agent
	directions(); //shows agents the directions for operating the CIA Codebreaker program
	keywords(); //adds all of the selected keywords to the 'words' string vector
	mainGuessing(); //calls the main function that contains pretty much all of the actual program/user interaction
	endGame(); //function that either ends/restarts the game
	return 0; //exit the function and allow the user to close the window by pressing any key
}