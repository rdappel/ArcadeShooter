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
   Date: 5/6/2015

   File: MenuScreen.h
   Description: Header file for a menu screen.

/  --------------------------------------------------------------- */

#pragma once


class SpriteBatch;

class MenuScreen : public Screen
{

public:

	MenuScreen();
	virtual ~MenuScreen();

	virtual void LoadContent() { Screen::LoadContent(); }

	virtual void HandleInput(InputState *pInput);

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime);

	virtual void SetItemListWrapping(const bool wraps) { m_itemListWraps = wraps; }

	virtual SpriteBatch *GetSpriteBatch() const;


protected:

	virtual void AddMenuItem(MenuItem *item) { m_menuItems.push_back(item); item->SetMenuScreen(this); }

	MenuItem *GetSelectedItem() const { return m_menuItems[m_selectedItemIndex]; }

	MenuItem *GetMenuItem(const int itemIndex) const { return m_menuItems[itemIndex]; }

	void SetSelectedItem(const int itemIndex) { m_selectedItemIndex = itemIndex; }

	void SetDisplayCount(const unsigned int count) { m_displayCount = count; }

	int GetDisplayCount() const { return m_displayCount; }

	int GetDisplayStartIndex() const { return m_displayStartIndex; }

	virtual void UpdateItem(MenuItem *pItem, const int index) { }


private:

	std::vector<MenuItem *> m_menuItems;

	unsigned int m_selectedItemIndex;

	unsigned int m_displayCount;

	unsigned int m_displayStartIndex;

	bool m_itemListWraps;

};