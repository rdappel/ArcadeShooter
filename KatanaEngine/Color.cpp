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

   File: Color.cpp
   Description: Source file for colors.

/  --------------------------------------------------------------- */

#include "KatanaEngine.h"


#pragma region Static Color Definitions
const Color Color::AliceBlue = Color(0.94f, 0.97f, 1.0f);
const Color Color::AntiqueWhite = Color(0.98f, 0.92f, 0.84f);
const Color Color::Aqua = Color(0.0f, 1.0f, 1.0f);
const Color Color::Aquamarine = Color(0.5f, 1.0f, 0.83f);
const Color Color::Azure = Color(0.94f, 1.0f, 1.0f);
const Color Color::Beige = Color(0.96f, 0.96f, 0.86f);
const Color Color::Bisque = Color(1.0f, 0.89f, 0.77f);
const Color Color::Black = Color(0.0f, 0.0f, 0.0f);
const Color Color::BlanchedAlmond = Color(1.0f, 0.92f, 0.8f);
const Color Color::Blue = Color(0.0f, 0.0f, 1.0f);
const Color Color::BlueViolet = Color(0.54f, 0.17f, 0.89f);
const Color Color::Brown = Color(0.65f, 0.16f, 0.16f);
const Color Color::Burlywood = Color(0.87f, 0.72f, 0.53f);
const Color Color::CadetBlue = Color(0.37f, 0.62f, 0.63f);
const Color Color::Chartreuse = Color(0.5f, 1.0f, 0.0f);
const Color Color::Chocolate = Color(0.82f, 0.41f, 0.12f);
const Color Color::Coral = Color(1.0f, 0.5f, 0.31f);
const Color Color::Cornflower = Color(0.39f, 0.58f, 0.93f);
const Color Color::Cornsilk = Color(1.0f, 0.97f, 0.86f);
const Color Color::Crimson = Color(0.86f, 0.08f, 0.24f);
const Color Color::Cyan = Color(0.0f, 1.0f, 1.0f);
const Color Color::DarkBlue = Color(0.0f, 0.0f, 0.55f);
const Color Color::DarkCyan = Color(0.0f, 0.55f, 0.55f);
const Color Color::DarkGoldenrod = Color(0.72f, 0.53f, 0.04f);
const Color Color::DarkGray = Color(0.66f, 0.66f, 0.66f);
const Color Color::DarkGreen = Color(0.0f, 0.39f, 0.0f);
const Color Color::DarkKhaki = Color(0.74f, 0.72f, 0.42f);
const Color Color::DarkMagenta = Color(0.55f, 0.0f, 0.55f);
const Color Color::DarkOliveGreen = Color(0.33f, 0.42f, 0.18f);
const Color Color::DarkOrange = Color(1.0f, 0.55f, 0.0f);
const Color Color::DarkOrchid = Color(0.6f, 0.2f, 0.8f);
const Color Color::DarkRed = Color(0.55f, 0.0f, 0.0f);
const Color Color::DarkSalmon = Color(0.91f, 0.59f, 0.48f);
const Color Color::DarkSeaGreen = Color(0.56f, 0.74f, 0.56f);
const Color Color::DarkSlateBlue = Color(0.28f, 0.24f, 0.55f);
const Color Color::DarkSlateGray = Color(0.18f, 0.31f, 0.31f);
const Color Color::DarkTurquoise = Color(0.0f, 0.81f, 0.82f);
const Color Color::DarkViolet = Color(0.58f, 0.0f, 0.83f);
const Color Color::DeepPink = Color(1.0f, 0.08f, 0.58f);
const Color Color::DeepSkyBlue = Color(0.0f, 0.75f, 1.0f);
const Color Color::DimGray = Color(0.41f, 0.41f, 0.41f);
const Color Color::DodgerBlue = Color(0.12f, 0.56f, 1.0f);
const Color Color::Firebrick = Color(0.7f, 0.13f, 0.13f);
const Color Color::FloralWhite = Color(1.0f, 0.98f, 0.94f);
const Color Color::ForestGreen = Color(0.13f, 0.55f, 0.13f);
const Color Color::Fuchsia = Color(1.0f, 0.0f, 1.0f);
const Color Color::Gainsboro = Color(0.86f, 0.86f, 0.86f);
const Color Color::GhostWhite = Color(0.97f, 0.97f, 1.0f);
const Color Color::Gold = Color(1.0f, 0.84f, 0.0f);
const Color Color::Goldenrod = Color(0.85f, 0.65f, 0.13f);
const Color Color::Gray = Color(0.75f, 0.75f, 0.75f);
const Color Color::WebGray = Color(0.5f, 0.5f, 0.5f);
const Color Color::Green = Color(0.0f, 1.0f, 0.0f);
const Color Color::WebGreen = Color(0.0f, 0.5f, 0.0f);
const Color Color::GreenYellow = Color(0.68f, 1.0f, 0.18f);
const Color Color::Honeydew = Color(0.94f, 1.0f, 0.94f);
const Color Color::HotPink = Color(1.0f, 0.41f, 0.71f);
const Color Color::IndianRed = Color(0.8f, 0.36f, 0.36f);
const Color Color::Indigo = Color(0.29f, 0.0f, 0.51f);
const Color Color::Ivory = Color(1.0f, 1.0f, 0.94f);
const Color Color::Khaki = Color(0.94f, 0.9f, 0.55f);
const Color Color::Lavender = Color(0.9f, 0.9f, 0.98f);
const Color Color::LavenderBlush = Color(1.0f, 0.94f, 0.96f);
const Color Color::LawnGreen = Color(0.49f, 0.99f, 0.0f);
const Color Color::LemonChiffon = Color(1.0f, 0.98f, 0.8f);
const Color Color::LightBlue = Color(0.68f, 0.85f, 0.9f);
const Color Color::LightCoral = Color(0.94f, 0.5f, 0.5f);
const Color Color::LightCyan = Color(0.88f, 1.0f, 1.0f);
const Color Color::LightGoldenrod = Color(0.98f, 0.98f, 0.82f);
const Color Color::LightGray = Color(0.83f, 0.83f, 0.83f);
const Color Color::LightGreen = Color(0.56f, 0.93f, 0.56f);
const Color Color::LightPink = Color(1.0f, 0.71f, 0.76f);
const Color Color::LightSalmon = Color(1.0f, 0.63f, 0.48f);
const Color Color::LightSeaGreen = Color(0.13f, 0.7f, 0.67f);
const Color Color::LightSkyBlue = Color(0.53f, 0.81f, 0.98f);
const Color Color::LightSlateGray = Color(0.47f, 0.53f, 0.6f);
const Color Color::LightSteelBlue = Color(0.69f, 0.77f, 0.87f);
const Color Color::LightYellow = Color(1.0f, 1.0f, 0.88f);
const Color Color::Lime = Color(0.0f, 1.0f, 0.0f);
const Color Color::LimeGreen = Color(0.2f, 0.8f, 0.2f);
const Color Color::Linen = Color(0.98f, 0.94f, 0.9f);
const Color Color::Magenta = Color(1.0f, 0.0f, 1.0f);
const Color Color::Maroon = Color(0.69f, 0.19f, 0.38f);
const Color Color::WebMaroon = Color(0.5f, 0.0f, 0.0f);
const Color Color::MediumAquamarine = Color(0.4f, 0.8f, 0.67f);
const Color Color::MediumBlue = Color(0.0f, 0.0f, 0.8f);
const Color Color::MediumOrchid = Color(0.73f, 0.33f, 0.83f);
const Color Color::MediumPurple = Color(0.58f, 0.44f, 0.86f);
const Color Color::MediumSeaGreen = Color(0.24f, 0.7f, 0.44f);
const Color Color::MediumSlateBlue = Color(0.48f, 0.41f, 0.93f);
const Color Color::MediumSpringGreen = Color(0.0f, 0.98f, 0.6f);
const Color Color::MediumTurquoise = Color(0.28f, 0.82f, 0.8f);
const Color Color::MediumVioletRed = Color(0.78f, 0.08f, 0.52f);
const Color Color::MidnightBlue = Color(0.1f, 0.1f, 0.44f);
const Color Color::MintCream = Color(0.96f, 1.0f, 0.98f);
const Color Color::MistyRose = Color(1.0f, 0.89f, 0.88f);
const Color Color::Moccasin = Color(1.0f, 0.89f, 0.71f);
const Color Color::NavajoWhite = Color(1.0f, 0.87f, 0.68f);
const Color Color::NavyBlue = Color(0.0f, 0.0f, 0.5f);
const Color Color::OldLace = Color(0.99f, 0.96f, 0.9f);
const Color Color::Olive = Color(0.5f, 0.5f, 0.0f);
const Color Color::OliveDrab = Color(0.42f, 0.56f, 0.14f);
const Color Color::Orange = Color(1.0f, 0.65f, 0.0f);
const Color Color::OrangeRed = Color(1.0f, 0.27f, 0.0f);
const Color Color::Orchid = Color(0.85f, 0.44f, 0.84f);
const Color Color::PaleGoldenrod = Color(0.93f, 0.91f, 0.67f);
const Color Color::PaleGreen = Color(0.6f, 0.98f, 0.6f);
const Color Color::PaleTurquoise = Color(0.69f, 0.93f, 0.93f);
const Color Color::PaleVioletRed = Color(0.86f, 0.44f, 0.58f);
const Color Color::PapayaWhip = Color(1.0f, 0.94f, 0.84f);
const Color Color::PeachPuff = Color(1.0f, 0.85f, 0.73f);
const Color Color::Peru = Color(0.8f, 0.52f, 0.25f);
const Color Color::Pink = Color(1.0f, 0.75f, 0.8f);
const Color Color::Plum = Color(0.87f, 0.63f, 0.87f);
const Color Color::PowderBlue = Color(0.69f, 0.88f, 0.9f);
const Color Color::Purple = Color(0.63f, 0.13f, 0.94f);
const Color Color::WebPurple = Color(0.5f, 0.0f, 0.5f);
const Color Color::RebeccaPurple = Color(0.4f, 0.2f, 0.6f);
const Color Color::Red = Color(1.0f, 0.0f, 0.0f);
const Color Color::RosyBrown = Color(0.74f, 0.56f, 0.56f);
const Color Color::RoyalBlue = Color(0.25f, 0.41f, 0.88f);
const Color Color::SaddleBrown = Color(0.55f, 0.27f, 0.07f);
const Color Color::Salmon = Color(0.98f, 0.5f, 0.45f);
const Color Color::SandyBrown = Color(0.96f, 0.64f, 0.38f);
const Color Color::SeaGreen = Color(0.18f, 0.55f, 0.34f);
const Color Color::Seashell = Color(1.0f, 0.96f, 0.93f);
const Color Color::Sienna = Color(0.63f, 0.32f, 0.18f);
const Color Color::Silver = Color(0.75f, 0.75f, 0.75f);
const Color Color::SkyBlue = Color(0.53f, 0.81f, 0.92f);
const Color Color::SlateBlue = Color(0.42f, 0.35f, 0.8f);
const Color Color::SlateGray = Color(0.44f, 0.5f, 0.56f);
const Color Color::Snow = Color(1.0f, 0.98f, 0.98f);
const Color Color::SpringGreen = Color(0.0f, 1.0f, 0.5f);
const Color Color::SteelBlue = Color(0.27f, 0.51f, 0.71f);
const Color Color::Tan = Color(0.82f, 0.71f, 0.55f);
const Color Color::Teal = Color(0.0f, 0.5f, 0.5f);
const Color Color::Thistle = Color(0.85f, 0.75f, 0.85f);
const Color Color::Tomato = Color(1.0f, 0.39f, 0.28f);
const Color Color::Turquoise = Color(0.25f, 0.88f, 0.82f);
const Color Color::Violet = Color(0.93f, 0.51f, 0.93f);
const Color Color::Wheat = Color(0.96f, 0.87f, 0.7f);
const Color Color::White = Color(1.0f, 1.0f, 1.0f);
const Color Color::WhiteSmoke = Color(0.96f, 0.96f, 0.96f);
const Color Color::Yellow = Color(1.0f, 1.0f, 0.0f);
const Color Color::YellowGreen = Color(0.6f, 0.8f, 0.2f);
#pragma endregion
	

Color::Color(const float r, const float g, const float b, const float a)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = a;
}

Color Color::Lerp(const Color &start, const Color &end, const float value)
{
	if (value <= 0) return start;
	if (value >= 1) return end;
	
	float r = Math::Lerp(start.Get().r, end.Get().r, value);
	float g = Math::Lerp(start.Get().g, end.Get().g, value);
	float b = Math::Lerp(start.Get().b, end.Get().b, value);
	float a = Math::Lerp(start.Get().a, end.Get().a, value);

	return Color(r, g, b, a);
}

const Color Color::operator*(const float scalar) const
{
	Color color = Color(*this);
	color.m_color.r *= scalar;
	color.m_color.g *= scalar;
	color.m_color.b *= scalar;
	color.m_color.a *= scalar;
	return color;
}


 
bool Color::operator== (const Color& color2) const
{
	return ((Get().r == color2.Get().r) && (Get().g == color2.Get().g)
		&& (Get().b == color2.Get().b) && (Get().a == color2.Get().a));
}
 
bool Color::operator!= (const Color& color2) const
{
	return !((Get().r == color2.Get().r) && (Get().g == color2.Get().g)
		&& (Get().b == color2.Get().b) && (Get().a == color2.Get().a));
}