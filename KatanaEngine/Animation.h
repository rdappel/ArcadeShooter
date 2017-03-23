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

   File: Animation.cpp
   Description: Source file for animated texture resources.

/  --------------------------------------------------------------- */

#pragma once

class Animation : public Resource
{

public:

	Animation();
	virtual ~Animation();


	virtual void Update(const GameTime *pGameTime);

	virtual bool Load(const std::string &path, ResourceManager *pManager);


	virtual bool IsCloneable() { return true; }

	virtual Resource *Clone();

	virtual Region *GetCurrentFrame() { return m_frames[m_currentIndex]; }

	virtual Texture *GetTexture() { return m_pTexture; }

	virtual void SetTexture(Texture *pTexture) { m_pTexture = pTexture; }

	virtual void SetCurrentFrame(const unsigned int index);

	virtual bool IsPlaying() const { return m_isPlaying; }

	virtual void Play() { m_isPlaying = true; }

	virtual void Pause() { m_isPlaying = false; }

	virtual void Stop();


private:

	std::vector<Region *> m_frames;

	Texture *m_pTexture;
	
	double m_secondsPerFrame;

	double m_currentFrameTime;

	int m_currentIndex;

	int m_loopCounter;

	bool m_isPlaying;

};