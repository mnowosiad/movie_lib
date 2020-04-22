#include "pch.h"
#include "ActionHandler.h"
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
#include <curl.h>

#include "Movie.h"

using namespace std;


ActionHandler::ActionHandler()
{
	path_to_xml = "C:\\Users\\Magda\\source\\repos\\MovieLib\\MovieLib\\MovieLib\\movie_base.xml";
}


ActionHandler::~ActionHandler()
{
}



std::string exec(const char* cmd) {
	char buffer[128];
	std::string result = "";
	FILE* pipe = _popen(cmd, "r");
	if (!pipe) throw std::runtime_error("popen() failed!");
	try {
		while (fgets(buffer, sizeof buffer, pipe) != NULL) {
			result += buffer;
		}
	}
	catch (...) {
		_pclose(pipe);
		throw;
	}
	_pclose(pipe);
	return result;
}

void ActionHandler::find_movie()
{
	system("cls");
	string title;
	cout << "Find a movie\n\nTitle: ";
	cin.ignore();
	getline(cin, title);

	int space = title.find(" ");
	if (space!= std::string::npos)
	{
		title = title.substr(0, space) + "%20" + title.substr(space+1, title.length() - space);
		
	}
	
	string answer;
	answer = exec(("curl https://www.omdbapi.com/?s=" + title + "^&apikey=ba1f4581").c_str());
 
	this->split_json(answer);
	this->main_menu();


}
void ActionHandler::split_json(string json)
{
	int position = 0;
	int results_num = 0;
	while (json.find("Title", position) != std::string::npos)
	{
		size_t found = json.find("Title", position);
	
		if (position != 0)
		{	
			string movie = json.substr(position, found - position);
			if (movie.length() > 4)
			{
				Movie object(movie, path_to_xml);
			}

		}

		position = found+1;
		results_num++;
	}
	if (results_num == 1)
	{

	}
}

void ActionHandler::add_position()
{
	system("cls");
	string title;
	string year;

	cout << "Title: " << endl;
	cin.ignore();
	getline(cin, title);
	cout << "Year of production: " << endl;
	getline(cin, year);

	Movie object;
	object.set_title(title);
	object.set_year(year);
	object.add_to_base(path_to_xml);
	this->main_menu();

}

void ActionHandler::import_base()
{
	string path;
	system("cls");
	cout << "Import base" << endl;
	cout << "XML file path:" << endl;
	cin >> path;
	system(("copy "+path+" "+path_to_xml).c_str());
	this->main_menu();
	
}

void ActionHandler::export_base()
{
	string path;
	system("cls");
	cout << "Export base" << endl;
	cout << "Location:" << endl;
	cin >> path;
	system(("copy " + path_to_xml + " " + path).c_str());

}

void ActionHandler::main_menu()
{
	
	Show show;
	system("cls");
	int option;
	cout << "MY MOVIE LIBRARY\n" << endl;
	cout << "*MAIN MENU*" << endl;
	cout << "1. Find a movie." << endl;
	cout << "2. Add your own position." << endl;
	cout << "3. Show My Movie Base" << endl;
	cout << "4. Show seen movies list" << endl;
	cout << "5. Import from XML" << endl;
	cout << "6. Exit" << endl << endl;
	cout << "Choose option: " << endl;
	cin >> option;
	switch (option)
	{
	case 1:
		this->find_movie();
		break;
	case 2:
		this->add_position();
		break;
	case 3:
		show.show_base(path_to_xml);
		break;
	case 4:
		show.show_seen();
		break;
	case 5:
		this->import_base();
		break;
	case 6:
		exit(0);

	default:
		cout << "Wrong choice!" << endl;
		system("cls");
		this->main_menu();
	}
	

}
