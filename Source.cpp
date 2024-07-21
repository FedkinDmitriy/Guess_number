#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int Return_Rand_Numb()
{
	srand(time(NULL));
	return  rand() % 100;
}

bool write_to_table(ofstream& file,const string user_name,const int attempts)
{
	
	file << user_name << "\t" << attempts << "\n";
	if (!file.is_open()) return false;
	file.close();
	return true;
}


int main(int argc, char* argv[])
{
	bool win = false;
	int user_numb = 0, attempts = 0;
	int secret_numb = Return_Rand_Numb();
	string user_name;
	const string name_table = "hight_scores.txt";
	ofstream out_file{ name_table, ios_base::app }; // создаём файл для записи в режиме append - добавления

	//user_name = argv[1];
	//cout << "Hello, " << user_name << ", let's play!" << endl;

	cout << "Let's play!" << endl;
	cout << "What is your name ?" << endl;
	cin >> user_name;
	do
	{
		cout << "Enter your guess: " << endl;
		++attempts;
		cin >> user_numb;

		if (user_numb < secret_numb)
		{ 
			cout << "Your guess is less than the hidden number" << endl;
		}
		else if(user_numb > secret_numb) 
		{
			cout << "Your guess is greater than the hidden number" << endl;
		}
		else
		{
			cout << user_name << ", you WIN !!!" << endl;
			cout << "Amount attempts = " << attempts << endl;
			if(!write_to_table(out_file, user_name, attempts)) cout << "Failed to open file for write" << endl;
			win = true;
		}
	} while (!win);

	
}