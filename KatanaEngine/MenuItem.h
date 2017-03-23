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

   File: MenuItem.h
   Description: Header file for a menu item.

/  --------------------------------------------------------------- */

#pragma once


class MenuScreen;

class MenuItem
{

public:

	MenuItem();
	virtual ~MenuItem() { }

	void (*OnSelect)(MenuScreen *menuScreen);
	
	virtual void Update(const GameTime *pGameTime) { }

	virtual void Draw(const GameTime *pGameTime);

	virtual void Select(MenuScreen *pMenuScreen);

	virtual void SetText(const std::string text) { m_text = text; }

	virtual void SetTextOffset(const Vector2 offset) { m_textOffset = offset; }

	virtual bool IsSelected() const { return m_isSelected; }

	virtual void SetSelected(const bool isSelected) { m_isSelected = isSelected; }

	virtual bool IsDisplayed() const { return m_isDisplayed; }

	virtual void SetDisplayed(const bool isDisplayed) { m_isDisplayed = isDisplayed; }

	virtual void SetFont(Font *pFont) { m_pFont = pFont; }

	virtual void SetPosition(const Vector2 position) { m_position = position; }

	virtual void SetColor(const Color color) { m_color = color; }

	virtual void SetAlpha(const float alpha) { m_alpha = alpha; }

	virtual void SetMenuScreen(MenuScreen *pMenuScreen) { m_pMenuScreen = pMenuScreen; }

	virtual void SetTextAlign(TextAlign textAlign) { m_textAlign = textAlign; }


protected:

	virtual MenuScreen *GetMenuScreen() const { return m_pMenuScreen; }

	virtual Vector2 GetPosition() const { return m_position; }

	virtual std::string GetText() const { return m_text; }


private:

	std::string m_text;

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