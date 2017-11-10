
/*
     ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC
			    http://www.shurikenstudios.com
*/

#pragma once

namespace KatanaEngine
{
	/** @brief Represents timing and framing values for texture animations. */
	class Animation : public Resource
	{

	public:

		Animation();
		virtual ~Animation();


		/** @brief Updates the animation.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Load the desired animation into memory.
			@param path The path to the desired animation.
			@param pManager A pointer to the resource manager that will manage the animation.
			@return Returns true if the animation was loaded, false otherwise. */
		virtual bool Load(const std::string &path, ResourceManager *pManager);

		/** @brief Used to determine if the animation is cloneable.
			@return Returns true if the animation is clonable, false otherwise.
			@remark Animations should usually be kept as cloneable. Sharing an animation will
			result in the animations playing syncronized. */
		virtual bool IsCloneable() const { return true; }

		/** @brief Used to create a clone of the animation.
			@return Returns a clone of the animation. */
		virtual Resource *Clone();

		/** @brief Gets a pointer to the current frame.
			@return Returns a Region that defines the size and position of the current frame. */
		virtual Region *GetCurrentFrame() { return m_frames[m_currentIndex]; }

		/** @brief Gets the index of the current frame.
			@return Returns the current frame's index. */
		virtual int GetCurrentIndex() { return m_currentIndex; }

		/** @brief Gets a pointer to the indexed frame.
			@return Returns a Region that defines the size and position of the indexed frame. */
		virtual Region *GetFrame(const int index) { return m_frames[index]; }

		/** @brief Gets a pointer to the texture of the animation.
			@return Returns a pointer to the texture. */
		virtual Texture *GetTexture() const { return m_pTexture; }

		/** @brief Sets the texture of the animation.
			@param pTexture A pointer to the texture resource. */
		virtual void SetTexture(Texture *pTexture) { m_pTexture = pTexture; }

		/** @brief Sets the current frame of the animation.
			@param index The index of the frame to set as the current frame.
			@remark If the indexed frame is invalid it will be ignored. */
		virtual void SetCurrentFrame(const unsigned int index);

		/** @brief Determines if the animation is playing.
			@return Returns true if the animation is playing, false otherwise. */
		virtual bool IsPlaying() const { return m_isPlaying; }

		/** @brief Starts or resumes the animation. */
		virtual void Play() { m_isPlaying = true; }

		/** @brief Pauses the animation. */
		virtual void Pause() { m_isPlaying = false; }

		/** @brief Stops the animation. */
		virtual void Stop();

		/** @brief Sets how many times the animation will run before it stops.
			@param loops The number of loops to play. Setting loops to -1 will
			make the animation loop infinitely. */
		virtual void SetLoopCount(uint16_t loops = -1) { m_loopCounter = loops; }


	private:

		std::vector<Region *> m_frames;

		Texture *m_pTexture;

		double m_secondsPerFrame;

		double m_currentFrameTime;

		int m_currentIndex;

		int m_loopCounter;

		bool m_isPlaying;

	};
}