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

   File: Resource.h
   Description: Header file for resources.

/  --------------------------------------------------------------- */

#pragma once


class ResourceManager;

class Resource
{
	friend class ResourceManager;

public:

	virtual ~Resource() { }

	virtual bool Load(const std::string &path, ResourceManager *pManager) = 0;

	unsigned short GetResourceID() const { return m_id; }


protected:

	void Split(const std::string &line, const char delimeter, std::vector<std::string> &elements);

	void ParseComments(std::string &line);

	void TrimLine(std::string &line);

	ResourceManager *GetResourceManager() { return m_pResourceManager; }


private:

	void SetResourceID(const int id) { m_id = id; }

	virtual bool IsCloneable() { return false; }

	virtual Resource *Clone() { return this; };

	unsigned short m_id;

	ResourceManager *m_pResourceManager;

};
