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

   File: ResourceManager.h
   Description: Header file for resource management.

/  --------------------------------------------------------------- */

#pragma once


class ResourceManager
{

public:

	ResourceManager() { m_nextResourceID = 0; }

	void SetContentPath(const std::string &path) { m_contentPath = path; }

	void UnloadAllResources()
	{
		std::map<std::string, Resource *>::iterator it;
		for (it = m_resources.begin(); it != m_resources.end(); ++it)
		{
			Resource *resource = it->second;
			delete resource;
		}
		m_resources.clear();

		std::vector<Resource *>::iterator cloneIt;
		for (cloneIt = m_clones.begin(); cloneIt != m_clones.end(); ++cloneIt)
		{
			delete *cloneIt;
		}
		m_clones.clear();
	}

	template <typename T>
	T *Load(const std::string &path, const bool cache = true, const bool appendContentPath = true)
	{
		if (m_resources.find(path) != m_resources.end())
		{
			T *pResource = dynamic_cast<T *>(m_resources[path]);

			if (pResource->IsCloneable())
			{
				T *pClone = dynamic_cast<T*>(pResource->Clone());
				
				pClone->SetResourceID(m_nextResourceID);

				m_nextResourceID++;

				m_clones.push_back(pClone);

				return pClone;
			}

			return pResource;
		}

		T *pT = new T;

		pT->m_pResourceManager = this;

		std::string fullPath;

		if (appendContentPath)
		{
			fullPath = m_contentPath;
			fullPath.append(path);
		}
		else fullPath = path;

		//std::cout << fullPath << std::endl;
			
		if (pT->Load(fullPath, this))
		{
			if (cache) m_resources[path] = pT;
			
			pT->SetResourceID(m_nextResourceID);

			m_nextResourceID++;

			return pT;
		}

		delete pT;
		return nullptr;
	}

private:
	
	std::map<std::string, Resource *> m_resources;

	std::vector<Resource *> m_clones;

	std::string m_contentPath;

	unsigned short m_nextResourceID;

};