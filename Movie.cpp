#include "pch.h"
#include "Movie.h"
#include <string>
#include "ActionHandler.h"
#include <fstream>

void Movie::set_title(string t)
{
	title = t;
}

void Movie::set_year(string y)
{
	year = y;
}

void Movie::set_rate(string r)
{
	rate = stoi(r);
}


string Movie::get_title()
{
	return title;
}

string Movie::get_year()
{
	return year;
}

int Movie::get_rate()
{
	return rate;
}

string Movie::get_text()
{
	return text;
}


void Movie::split_text(string path)
{
	system("cls");
	regex pattern("itle\":\"(.+)\",\"Year\":\"(.+)\",\"imdbID");
	smatch result;
	string text = this -> get_text();
	regex_search(text, result,  pattern);
	this -> set_title(result[1]);
	this -> set_year(result[2]);
	cout << endl<< "Position found\n"<<endl;
	cout << "Title: " << this->get_title()<<endl;
	cout << "Year of production: " << this->get_year()<<endl<<endl;
	cout << "Options:\n" << endl;
	cout << "1. Add this to my movie base" << endl;
	cout << "2. Next position" << endl;
	cout << "3. Back to main menu" << endl<<endl;
	cout << "Choose option: " << endl;
	int choice;
	cin >> choice;
	ActionHandler m;
	switch (choice)
	{
	case 1:
		this->add_to_base(path);
		break;
	case 2:
		break;
	case 3:
		m.main_menu();
		break;
	default :
		cout << "Wrong choice!" << endl;
		this->split_text(path);
		break;


	}


	
}

void Movie::add_to_base(string path)
{
	string title = this->get_title();
	string year = this->get_year();
	string rate;
	string ans;
	cout << "Have you seen this movie? (Add to seen movies list [y/n])" << endl;
	cin >> ans;
	
	if ((ans.compare("y")) == 0)
	{
		cout << "Rate movie (1-10)"<<endl;
		cin >> rate;
		this->set_rate(rate);
		this->add_to_seen();
		

	}
	string data;
	std::ifstream ifs(path);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	ifs.close();
	size_t found = content.find("</root>");
	content.insert(found, "  <row>\n\t\t<Title>"+title+"</Title>\n\t\t<Year>"+year+"</Year>\n\t\t<Rate>"+rate+"</Rate>\n\t</row>\n");
	cout << content;
	ofstream myfile;
	
	myfile.open(path);	
	myfile << content << endl;
	
	myfile.close();


}

void Movie::add_to_seen()
{
	string title = this->get_title();
	string year = this->get_year();
	string rate = to_string(this->get_rate());
	string data;
	std::ifstream ifs("seen_list.xml");
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	ifs.close();
	size_t found = content.find("</root>");
	content.insert(found, "  <row>\n\t\t<Title>" + title + "</Title>\n\t\t<Year>" + year + "</Year>\n\t\t<Rate>" + rate + "</Rate>\n\t</row>\n");
	cout << content;
	ofstream myfile;

	myfile.open("seen_list.xml");
	myfile << content << endl;

	myfile.close();

}

Movie::Movie()
{
}

Movie::Movie(string str, string path)
{
	text = str;
	this -> split_text(path);
}


Movie::~Movie()
{
}

