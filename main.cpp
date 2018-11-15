/*	Project:    Project #4
	Name:       Adam Davis
    Partner:    N/A
    Class:      CSC 1810 - Section 1
*/

#include <iostream>
#include <vector>

using namespace std;

void Choice1(string &Post)
{

	cout << "Please input a new post:" << endl;
	Post.clear();
	cin.clear();
	cin.ignore(1000, '\n');
	getline(cin, Post);

	while (Post.size() < 3 || Post.size() > 128)
	{
		cout << "Please enter a valid Post." << endl;
		Post.clear();
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, Post);
	}
}

void Choice2(string &Post)
{
	cout << Post << endl;
}
void Choice3(string &Post)
{
	string vecIn = "";
	int numWords = 1;
	vector<string> Wordcount(1);
	Wordcount.resize(0);

	for (unsigned int i = 0; i < Post.size(); i++)
	{
		if (Post.at(i) != ' ')
		{
			vecIn = vecIn + Post.at(i);
		}
		else
		{
			Wordcount.push_back(vecIn);
			vecIn.clear();
		}
	}

	vecIn.clear();
	numWords = Wordcount.size() + 1;

	cout << "Total word count is " << numWords << " words." << endl;
	Wordcount.resize(0);
}
void Choice4(string &Post)
{
	string repWord;
	string newWord;
	int numReps = 1;
	cout << "How many words do you want to change?" << endl;
	cin >> numReps;
	for (int i = numReps; i > 0; i--)
	{
		cout << "Please input a acronym you would like to replace: " << endl;
		cin >> repWord;
		int pos = Post.find(repWord);
		while (pos < 0)
		{
			cout << "Please enter a word used in the phrase: " << endl;
			cin >> repWord;
			pos = Post.find(repWord);
		}
		cout << "Please input the text you would like to replace " << repWord << " with: " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, newWord);
		pos = Post.find(repWord);
		Post.replace(pos, repWord.size(), newWord);
		cout << Post << endl;
	}
}

void Choice5(string &Post)
{
	cout << "1 - Input post" << endl;
	cout << "2 - Output Post" << endl;
	cout << "3 - Get total Word Count" << endl;
	cout << "4 - Replace acronyms" << endl;
	cout << "5 - Repeat Menu" << endl;
	cout << "6 - Computer Replace acronyms" << endl;
	cout << "7 - Quit" << endl;
}
void Choice6(string &Post)
{
	vector<string> List(6);
	List.at(0) = " ";
	List.at(1) = "wyd";
	List.at(2) = "ttyl";
	List.at(3) = "brb";
	List.at(4) = "hml";
	List.at(5) = "lol";

	vector<string> Listr(6);
	Listr.at(0) = " ";
	Listr.at(1) = "What are you doing?";
	Listr.at(2) = "Talk to you later.";
	Listr.at(3) = "Be right back";
	Listr.at(4) = "Hit my line";
	Listr.at(5) = "Laugh out Loud";

	string Newmean;
	string Answer;
	Post.insert(0, " ");
	for (unsigned int i = 0; i < 6; i++)
	{
		int pos = Post.find(List.at(i));
		if (pos > 0)
		{
			Post.replace(pos, List.at(i).size(), Listr.at(i));
		}
	}
	Post.replace(0, 1, "");
	cout << "Acronyms Replaced. " << endl;
	cout << Post << endl;
}
int main(int argc, char *argv[])
{

	int Userinput = 0;
	string Post = "lol hml wyd";

	cout << "1 - Input post" << endl;
	cout << "2 - Output Post" << endl;
	cout << "3 - Get total Word Count" << endl;
	cout << "4 - Replace acronyms" << endl;
	cout << "5 - Repeat Menu" << endl;
	cout << "6 - Computer Replace acronyms" << endl;
	cout << "7 - Quit" << endl;
	cout << "Hello User. Please input a number to select a menu option. " << endl;

	cin >> Userinput;

	while (Userinput != 7)
	{

		if (Userinput == 1)
		{
			Choice1(Post);
		}
		else if (Userinput == 2)
		{
			Choice2(Post);
		}
		else if (Userinput == 3)
		{
			Choice3(Post);
		}
		else if (Userinput == 4)
		{
			Choice4(Post);
		}
		else if (Userinput == 5)
		{
			Choice5(Post);
		}
		else if (Userinput == 6)
		{
			Choice6(Post);
		}
		else
		{
			cout << "Invalid Input." << endl;
		}
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please Enter a new input number: " << endl;
		cin >> Userinput;
	}

	{
		cin.clear();
		cin.ignore(1000, '\n');
		char c;
		cout << "Hit enter to exit:";
		cin.get(c);
	}
	return 0;
}