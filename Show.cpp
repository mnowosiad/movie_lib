#include "pch.h"
#include "Show.h"



Show::Show()
{
}


Show::~Show()
{
}

void Show::show_base(string path_to_xml)
{
	ActionHandler menu;
	system("cls");
	int option;
	string answer;
	cout << "Do you want to export base to another file? [y/n]"<<endl;
	cin >> answer;

	cout << "Sort by: " << endl;
	cout << "1. Title" << endl;
	cout << "2. Year" << endl;
	cout << "3. Rate" << endl;
	cin >> option;
	switch (option)
	{
	case 1:
		sort("Title");
		break;
	case 2:
		sort("Year");
		break;
	case 3:
		sort("Rate");
		break;
	default:
		cout << "Wrong choice!" << endl;
		system("cls");
		menu.main_menu();
	}
	system("pause");
	if ((answer.compare("y")) == 0)
	{
		menu.export_base();
	}
	system("pause");
	system(("start iexplore.exe " + path_to_xml).c_str());
	menu.main_menu();
}

void Show::show_seen()
{
	ActionHandler menu;
	system("cls");
	system(R"("start iexplore.exe C:\Users\Magda\source\repos\MovieLib\MovieLib\MovieLib\seen_list.xml)");
	menu.main_menu();
}

void Show::sort(string prosp)
{
	std::ifstream ifs("XSLTFile.xsl");
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	ifs.close();
	int found = content.find("<xsl:sort select ");
	int len;
	if (content.find("<xsl:sort select =\"Rate\"") != std::string::npos)
	{
		len = 24;
	}


	else if (content.find("<xsl:sort select =\"Title\"") != std::string::npos)
	{
		
		len = 25;
	}
	else if (int found = content.find("<xsl:sort select =\"Year\"") != std::string::npos)
	{
		
		len = 24;
	}
	content = content.substr(0, found) + R"(<xsl:sort select =")" + prosp + R"(")" + content.substr(found + len, content.length() - found);



	ofstream myfile;

	myfile.open("XSLTFile.xsl");
	myfile << content << endl;

	myfile.close();
}
