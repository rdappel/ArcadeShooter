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
	class SpriteBatch;

	/** @brief Base class for all game menu screens. */
	class MenuScreen : public Screen
	{

	public:

		MenuScreen();
		virtual ~MenuScreen();

		/** @brief Called when the game has determined that player input needs to be processed.
			@param pInput The current state of all player input devices. */
		virtual void HandleInput(const InputState *pInput);

		/** @brief Called when the game has determined that screen logic needs to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch);

		/** @brief Sets whether scrolling past the end of the menu returns the selection back
			to the first item.
			@param wraps Pass true if you want the menu items to wrap. */
		virtual void SetItemListWrapping(const bool wraps) { m_itemListWraps = wraps; }


	protected:

		/** @brief Adds a menu item to the screen.
			@param item A pointer to the item that will be added. */
		virtual void AddMenuItem(MenuItem *item) { m_menuItems.push_back(item); item->SetMenuScreen(this); }

		/** @brief Get the currently selected menu item.
			@return Returns a pointer to the currently selected menu item. */
		MenuItem *GetSelectedItem() const { return m_menuItems[m_selectedItemIndex]; }

		/** @brief Get a menu item by providing it's index.
			@return Returns a pointer to a menu item. */
		MenuItem *GetMenuItem(const int itemIndex) const { return m_menuItems[itemIndex]; }

		/** @brief Set the selected menu item by providing it's index.
			@param itemIndex The index of the menu item. */
		void SetSelectedItem(const int itemIndex) { m_selectedItemIndex = itemIndex; }

		/** @brief Set how many menu items to display.
			@param count The number of menu items to display. */
		void SetDisplayCount(const unsigned int count) { m_displayCount = count; }

		/** @brief Get the number of menu items that are set to display.
			@return Returns the number of displayed menu items. */
		int GetDisplayCount() const { return m_displayCount; }

		/** @brief Get the index corresponding to the first displayed menu item.
			@return Returns index of the first displayed menu item. */
		int GetDisplayStartIndex() const { return m_displayStartIndex; }


	private:

		std::vector<MenuItem *> m_menuItems;

		unsigned int m_selectedItemIndex;

		unsigned int m_displayCount;

		unsigned int m_displayStartIndex;

		bool m_itemListWraps;

	};
}