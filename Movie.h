#pragma once
#include <iostream>
#include <string>
#include <regex>
#include "ActionHandler.h"

using namespace std;

class Movie:
	public ActionHandler
{
protected:
	string text;
	string title;
	string year;
	int rate;


public:
	void set_title(string t);
	void set_year(string y);
	void set_rate(string r);
	string get_title();
	string get_year();
	int get_rate();
	string get_text();
	void split_text(string path);
	void add_to_base(string path);
	void add_to_seen();
	
	Movie();
	Movie(string str, string path);
	~Movie();
	
};

