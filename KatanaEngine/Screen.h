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

/  --------------------------------------------------------------- */

#pragma once

namespace KatanaEngine
{
	class ScreenManager;
	class Screen;

	/** @brief Callback function for when Exit() is called on a screen and
		it begins to transition out.
		@remark This callback is run automatically when Exit() is called.
		@see Screen::Exit()
		@see OnRemove */
	typedef void(*OnExit)(Screen *pScreen);

	/** @brief Callback function for when a screen has completely exited
		and is about to be removed by the screen manager.
		@remark This callback will be run before UnloadContent(). Therefore
		resourses can be passed before the screen is removed.
		@see ScreenManager
		@see Screen::UnloadContent()
		@see OnExit */
	typedef void(*OnRemove)(Screen *pScreen);

	/** @brief Base class for all game screens and menus. */
	class Screen
	{
		friend class ScreenManager;

	public:

		Screen();
		virtual ~Screen() { }


		/** @brief Called when resources need to be loaded.
			@param pResourceManager The game's resource manager, used for loading
			and managing game resources. */
		virtual void LoadContent(ResourceManager *pResourceManager) { }

		/** @brief Called when resources need to be unloaded. Override this method to unload
			any screen-specific resources. */
		virtual void UnloadContent() { }

		/** @brief Called when the game has determined that player input needs to be processed.
			@param pInput The current state of all player input devices. */
		virtual void HandleInput(const InputState *pInput) { }

		/** @brief Called when the game has determined that screen logic needs to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime) = 0;

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch) = 0;

		/** @brief Determines if the screen is currently exiting.
			@return Returns true if the screen is exiting, false otherwise. */
		virtual bool IsExiting() const { return m_isExiting; }

		/** @brief Gets the overall screen transition alpha value (or opacity).
			This is handy for fading screens in and out.
			@return Returns the alpha value.
			@remark This function is an alias for the protected GetTransitionValue().
			@see GetTransitionValue() */
		float GetAlpha() const { return m_transitionValue; }

		/** @brief Gets a pointer to the ScreenManager, for managing game screens.
			@return A pointer to the game's ScreenManager instance. */
		virtual ScreenManager *GetScreenManager() { return m_pScreenManager; }

		/** @brief Gets a pointer to the Game.
			@return A pointer to the game instance. */
		virtual Game *GetGame() const;

		/** @brief Gets a pointer to the ParticleManager, for creating and managing particles.
			@return A pointer to the game's ParticleManager instance. */
		virtual ParticleManager *GetParticleManager() const;

		/** @brief Gets a pointer to the ScreenManager, for managing game screens.
			@return A pointer to the game's ScreenManager instance. */
		virtual void SetScreenManager(ScreenManager *pScreenManager);

		/** @brief Tells the screen to transition in. */
		virtual void Show();

		/** @brief Tells the screen to transition out. When the screen has completed
			its transition, UnloadContent() will be called, and the ScreenManager
			will remove it.
			@remark SetExitCallback() and SetRemoveCallback() can be used to trigger
			events involving the exiting process. */
		virtual void Exit();

		/** @brief Sets the callback function for when the Exit() is called.
			@param callback The callback function. */
		virtual void SetExitCallback(OnExit callback) { m_onExit = callback; }

		/** @brief Sets the callback function for when the screen is about to be
			removed by the screen manager.
			@param callback The callback function. */
		virtual void SetRemoveCallback(OnRemove callback) { m_onRemove = callback; }

		/** @brief Get the time in seconds that the screen will transition out.
			@return Returns the transition time in seconds. */
		virtual double GetTransitionOutTime() const { return m_transitionOutTime; }

		/** @brief Get index of the controlling player.
			@return Returns the player index. An result of -1 indicates that there is no controlling player. */
		virtual int8_t GetControllingPlayerIndex() const { return m_controllingPlayerIndex; }


	protected:

		/** @brief Defines the state of the transition between screens. */
		enum class ScreenTransition
		{
			NONE,	/**< @brief The screen is not transitioning. */
			IN,		/**< @brief The screen is transitioning in. */
			OUT		/**< @brief The screen is transitioning out. */
		};


		/** @brief Sets the flags that determine if the underlaying screen should handle input, update,
			and/or render.
			@param draw Set this flag to true if the underlaying screen should render.
			@param update Set this flag to true if the underlaying screen should update.
			@param handleInput Set this flag to true if the underlaying screen should handle user input. */
		virtual void SetPassthroughFlags(const bool draw = false, const bool update = false, const bool handleInput = false);

		/** @brief Set the time in seconds that the screen should transition in.
			@param seconds The transition time. */
		virtual void SetTransitionInTime(double seconds) { m_transitionInTime = seconds; }

		/** @brief Set the time in seconds that the screen should transition out.
			@param seconds The transition time. */
		virtual void SetTransitionOutTime(double seconds) { m_transitionOutTime = seconds; }

		/** @brief Get the time in seconds that the screen will transition in.
			@return Returns the transition time in seconds. */
		virtual double GetTransitionInTime() const { return m_transitionInTime; }

		/** @brief Get the current transition state of the screen.
			@return Returns the current transition. */
		virtual ScreenTransition GetTransition() const { return m_transition; }

		/** @brief Get the interpolated value (between zero and one) of the screen transition.
			@return Returns a value that represents the percentage of the transition. Zero means
			the screen is entirely transitioned of, and one means it's entirely on. */
		virtual float GetTransitionValue() const { return m_transitionValue; }

		/** @brief Determines if the screen has completely faded out and needs to be removed by
			the ScreenManager.
			@return Returns true if the screen needs to be removed, false otherwise. */
		virtual bool NeedsToBeRemoved() const { return m_needsToBeRemoved; }

		/** @brief Forces all screen rendering to a render target. */
		virtual void UseRenderTarget();

		/** @brief Get screen's render target.
			@return Returns a pointer to the render target, or nullptr if the screen doesn't
			use one. */
		virtual RenderTarget *GetRenderTarget() const { return m_pRenderTarget; }

		/** @brief Get the color that will be used to tint the render target.
			@return Returns the render target draw tint. */
		virtual Color GetRenderTargetColor() const { return Color::White * GetAlpha(); }


	private:

		void *m_onExit;
		void *m_onRemove;

		bool m_handleInputBelow;
		bool m_updateBelow;
		bool m_drawBelow;
		bool m_isExiting;

		bool m_needsToBeRemoved;

		int8_t m_controllingPlayerIndex;

		double m_transitionInTime;
		double m_transitionOutTime;

		ScreenTransition m_transition;

		float m_transitionValue;
		double m_transitionTime;

		ScreenManager *m_pScreenManager;

		RenderTarget *m_pRenderTarget;

		void TransitionIn();
		void TransitionOut();

		void UpdateTransition(const GameTime *pGameTime);

		bool UpdateBelow() const { return m_updateBelow; }
		bool DrawBelow() const { return m_drawBelow; }
		bool HandleInputBelow() const { return m_handleInputBelow; }

	};
}