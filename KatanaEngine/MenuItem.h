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

	class MenuScreen;

	/** @brief Callback function for when a menu item is selected.
		@see MenuItem */
	typedef void(*OnSelect)(MenuScreen *pMenuScreen);
	
	/** @brief Class for menu items contained in a MenuScreen. */
	class MenuItem
	{
		friend class MenuScreen;

	public:


		/** @brief Instantiate a menu item. */
		MenuItem();

		/** @brief Instantiate a menu item.
			@param text The text that the item will display.
			
			@overload */
		MenuItem(std::string text);

		virtual ~MenuItem() { }

		/** @brief Called when the game has determined that screen logic needs to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime) { }

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch);

		/** @brief Called when the picks this menu option.
			@param pMenuScreen A pointer to the menu screen. */
		virtual void Select(MenuScreen *pMenuScreen);

		/** @brief Sets the text of the menu item.
			@param text The text. */
		virtual void SetText(const std::string text) { m_text = text; }

		/** @brief Sets the offset from the items normal position. Usually used to animate the
			currently selected menu item.
			@param offset The offset. */
		virtual void SetTextOffset(const Vector2 offset) { m_textOffset = offset; }

		/** @brief Determines whether or not this menu item is the one that is currently selected.
			@return Returns true if this item is the currently selected one, false otherwise. */
		virtual bool IsSelected() const { return m_isSelected; }

		/** @brief Sets whether or not this menu item is the one that is currently selected.
			@param isSelected Pass true to make this item the selected one, and false to when
			you no longer want it selected. */
		virtual void SetSelected(const bool isSelected) { m_isSelected = isSelected; }

		/** @brief Determines whether or not this menu item is currently displayed.
			@return Returns true if this item is currently displayed, false otherwise. */
		virtual bool IsDisplayed() const { return m_isDisplayed; }

		/** @brief Sets whether or not this menu item is currently displayed.
			@param isDisplayed Pass true to display this item, and false to hide it. */
		virtual void SetDisplayed(const bool isDisplayed) { m_isDisplayed = isDisplayed; }

		/** @brief Sets the font of the menu item.
			@param pFont A pointer to the font. */
		virtual void SetFont(Font *pFont) { m_pFont = pFont; }

		/** @brief Sets the screen position of the menu item.
			@param position The new position. */
		virtual void SetPosition(const Vector2 position) { m_position = position; }

		/** @brief Sets the color of the menu item.
			@param color The color. */
		virtual void SetColor(const Color color) { m_color = color; }

		/** @brief Sets the alpha value (opacity) of the menu item.
			@param alpha The alpha value. */
		virtual void SetAlpha(const float alpha) { m_alpha = alpha; }

		/** @brief Sets the text alignment for the menu item.
			@param textAlign The text alignment. */
		virtual void SetTextAlign(TextAlign textAlign) { m_textAlign = textAlign; }

		/** @brief Sets containing menu screen.
			@param pMenuScreen A pointer to the menu screen.
			@remark This should not be called manually. It is called automatically when an
			item is added to a menu screen via MenuScreen::AddMenuItem().
			@see MenuScreen::AddMenuItem() */
		virtual void SetMenuScreen(MenuScreen *pMenuScreen) { m_pMenuScreen = pMenuScreen; }

		/** @brief Sets the callback function for when the menu item is selected.
			@param callback The callback function. */
		virtual void SetSelectCallback(OnSelect callback) { m_onSelect = callback; }

		/** @brief Gets the index of the menu item.
			@return Returns the menu item's index. */
		virtual int GetIndex() const { return m_index; }


	protected:

		/** @brief Sets the index of the menu item.
			@param index The index value. */
		virtual void SetIndex(const int index) { m_index = index; }

		/** @brief Gets the menu screen that contains this item.
			@return Returns a pointer to the menu screen. */
		virtual MenuScreen *GetMenuScreen() const { return m_pMenuScreen; }

		/** @brief Gets the position of the menu item.
			@return Returns the menu item's position on the screen. */
		virtual Vector2 GetPosition() const { return m_position; }

		/** @brief Gets the text of the menu item.
			@return Returns the menu item's text. */
		virtual std::string GetText() const { return m_text; }


	private:

		int m_index;

		std::string m_text;

		void *m_onSelect;

		bool m_isSelected;

		bool m_isDisplayed;

		Font *m_pFont;

		Color m_color;

		float m_alpha;

		Vector2 m_position;

		Vector2 m_textOffset;

		MenuScreen *m_pMenuScreen;

		TextAlign m_textAlign;

	};
}