#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "ActionHandler.h"

using namespace std;

class Show
{
public:
	Show();
	~Show();
	void show_base(string path_to_xml);
	void show_seen();
	void sort(string prosp);
};

