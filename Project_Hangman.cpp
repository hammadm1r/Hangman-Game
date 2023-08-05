#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<time.h>
#include<cstdlib>
using namespace std;
void PrintMessage(string message, bool printTop = true,bool printBottom =true){       //SEPRATOR WITH MESSAGE
	if (printTop)
	{
		cout<<" +=================================+"<<endl;
		cout<<"||";
	}
	else 
	{
		cout<<"||";
	}
	bool front = true;
	for (int i=message.length(); i<33; i++)
	{
		if(front)
		{
			message =" "+message;
		}
		else
		{
			message = message+ " ";
		}
		front =!front;
	}
	cout<< message.c_str();
	if (printTop)
	{
		cout<<"||"<< endl;
		cout<<" +=================================+"<<endl;
	}	
	else 
	{
		cout<<"||"<<endl;
	}
}
void DrawHangman(int guessCount = 0){                                                //HANGMAN DRAW WHEN GUESS IS WRONG
	if (guessCount >= 1)
	PrintMessage("|",0,0);
	else
	PrintMessage("",false,false);
	if (guessCount >= 2)
	PrintMessage("|",false,false);
	else
	PrintMessage("",false,false);
	if (guessCount >= 3)
	PrintMessage("O",false,false);
	else
	PrintMessage("",false,false);
	if (guessCount >= 4)
	PrintMessage("/|\\",false,false);
	else
	PrintMessage("",false,false);
	if (guessCount >= 5)
	PrintMessage("|",false,false);
	else
	PrintMessage("",false,false);
	if (guessCount >= 6)
	PrintMessage("/ \\",false,false);
	else
	PrintMessage("",false,false);
}
void PrintLetters(string input, char from, char to){                                //SHOWING LATTER ON SCREEN
	string s;
	for(char i = from; i<= to ; i++)
	{
		if(input.find(i) == string :: npos ){
		s += i ;
		s += " ";
		}
		else{
		s +="_ ";
		}
	}
	PrintMessage(s,false,false);
}
void PrintAvailableLetters(string taken){                                          //AVAILABLE LATTER ON SCREEN
	PrintMessage("Available Letters");
	PrintLetters(taken,'A','M');
	PrintLetters(taken,'N','Z');
}
bool PrintWordAndCheckWin(string word, string guessed){                           //WON OR NOT DESIDE
	bool won = true;
	string s;
	for (int i=0; i<word.length(); i++)
	{
		if (guessed.find(word[i]) == string :: npos )
		{
			won = false;
			s +="_ ";
		}
		else
		{
			s += word[i];
			s +=" ";
		}
	}
	PrintMessage(s,false);
	return won;
}
string LoadRandomWord(string path){                                              //LOADING WORD FROM FILE
	int lineCount = 0;
	 srand(time (0) );
	string word;
	vector<string> v;
	ifstream reader(path.c_str());
	if (reader.is_open())
	{
		while (std::getline(reader, word))
		v.push_back(word);
		
		int randomLine = rand() % v.size();
		word = v.at(randomLine);
		
		reader.close();
	}
	return word;
}
int TriesLeft(string word,string guessed){                                      //SHOWING HOW MUCH TRIES ARE LEFT 
	int error=0;
	for(int i=0; i<guessed.length();i++)
	{
		if(word.find(guessed[i]) == string::npos)
		error++;
	}
	return error;
}
int main(){                                                                    //MAIN HA
	string guessed; // Wo word jo user enter krvay ga 
	string wordToGuess;//wo word jo file main se uthayain gay 
	wordToGuess = LoadRandomWord("words.txt");
	int tries = 0;
	bool win = false;
	do {
		system("cls");
		PrintMessage("HANGMAN is COOLMAN");
		DrawHangman(tries);
		PrintMessage("HELP ME PLZ!!!",false,false);
		PrintAvailableLetters(guessed);
		PrintMessage("GUESS THE WORD");
		win = PrintWordAndCheckWin(wordToGuess,guessed);
		if (win)
			break;
			
		char x;
		cout << "==>";cin >> x;
		if (guessed.find(x) == string::npos)
		guessed +=x;
		tries=TriesLeft(wordToGuess,guessed);
		
	}while(tries<7);
	if(win){
	system("cls");
	cout<<endl<<endl<<endl;	
	PrintMessage("YOU WON....YOHO ");	
	cout<<endl<<endl<<endl;
	PrintMessage("ALL WRITES RESERVERD ");	
	PrintMessage("BY HAMMAD MIR");}
	else
	{
	system("cls");
	cout<<endl<<endl<<endl;	
	PrintMessage("OHO... YOU LOSE ");
	PrintMessage("TRY AGAIN NExT TIME ");	
	cout<<endl<<endl<<endl;
	PrintMessage("ALL WRITES RESERVERD ");	
	PrintMessage("BY HAMMAD MIR");
    }
	
	getchar();
	
	
	return 0;
}
