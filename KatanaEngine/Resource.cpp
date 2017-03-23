/* ---------------------------------------------------------------  /

	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC


   Author: Ryan Appel
   Date: 5/8/2015

   File: Resource.cpp
   Description: Source file for resources.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


void Resource::Split(const std::string &line, const char delimeter, std::vector<std::string> &elements)
{
	if (line.empty()) return;

	elements.clear();

	std::stringstream ss(line);
	std::string element;

	while (std::getline(ss, element, delimeter))
	{
		elements.push_back(element);
	}
}

void Resource::ParseComments(std::string &line)
{
	if (line.empty()) return;

	std::size_t position = line.find("//");
	if (position == std::string::npos) return;

	line = line.substr(0, position);
	
	TrimLine(line);
}

void Resource::TrimLine(std::string &line)
{
    if (line.empty()) return;

	std::size_t pos;

	pos = line.find_first_not_of(" \t");
	if(pos != std::string::npos) line = line.substr(pos);

	pos = line.find_last_not_of(" \t");
	if(pos != std::string::npos) line = line.substr(0, pos + 1);
}