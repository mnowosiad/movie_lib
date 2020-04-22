#pragma once
#include <iostream>
#include "Show.h"
using namespace std;

class ActionHandler
{
protected:
	string path_to_xml;
public:
	ActionHandler();
	~ActionHandler();
	void main_menu();
	void find_movie();
	void split_json(string json);
	void add_position();
	void import_base();
	void export_base();
};

