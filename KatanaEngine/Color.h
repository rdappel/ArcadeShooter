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
	/** @brief Represents a four-component color using red, green, blue, and alpha data. */
	class Color
	{

	public:

		/** @brief Instantiate a color object.
			@param red The red value of the color.
			@param green The green value of the color.
			@param blue The blue value of the color.
			@param alpha The alpha value (opacity) of the color. */
		Color(const float red = 1, const float green = 1, const float blue = 1, const float alpha = 1);


		/** @brief Linearly interpolate between two colors.
			@param start The result when the value is zero.
			@param end The result when the value is one.
			@param value A value between 0 and 1 that will indicate the resulting weight between start and end.
			@return Returns the interpolated color value between start and end. */
		static Color Lerp(const Color &start, const Color &end, const float value);

		/** @brief Multiplies each component by a scale factor.
			@param scalar The scale factor.
			@return Returns the scaled color. */
		const Color operator*(const float scalar) const;

		/** @brief Checks to see if two colors are equal.
			@param color The color to compare.
			@return Returns true if the colors are equal, false otherwise. */
		bool operator==(const Color& color) const;

		/** @brief Checks to see if two colors are not equal.
			@param color The color to compare.
			@return Returns true if the colors are not equal, false otherwise. */
		bool operator!=(const Color& color) const;

		/** @brief Get the color-equivalent allegro color.
			@return Returns the mapped allegro color. */
		ALLEGRO_COLOR GetAllegroColor() const { return al_map_rgba_f(red, green, blue, alpha); }

		#pragma region Static Colors
		static const Color AliceBlue;			/**< @brief AliceBlue */
		static const Color AntiqueWhite;		/**< @brief AntiqueWhite */
		static const Color Aqua;				/**< @brief Aqua */
		static const Color Aquamarine;			/**< @brief Aquamarine */
		static const Color Azure;				/**< @brief Azure */
		static const Color Beige;				/**< @brief Beige */
		static const Color Bisque;				/**< @brief Bisque */
		static const Color Black;				/**< @brief Black */
		static const Color BlanchedAlmond;		/**< @brief BlanchedAlmond */
		static const Color Blue;				/**< @brief Blue */
		static const Color BlueViolet;			/**< @brief BlueViolet */
		static const Color Brown;				/**< @brief Brown */
		static const Color Burlywood;			/**< @brief Burlywood */
		static const Color CadetBlue;			/**< @brief CadetBlue */
		static const Color Chartreuse;			/**< @brief Chartreuse */
		static const Color Chocolate;			/**< @brief Chocolate */
		static const Color Coral;				/**< @brief Coral */
		static const Color Cornflower;			/**< @brief Cornflower */
		static const Color Cornsilk;			/**< @brief Cornsilk */
		static const Color Crimson;				/**< @brief Crimson */
		static const Color Cyan;				/**< @brief Cyan */
		static const Color DarkBlue;			/**< @brief DarkBlue */
		static const Color DarkCyan;			/**< @brief DarkCyan */
		static const Color DarkGoldenrod;		/**< @brief DarkGoldenrod */
		static const Color DarkGray;			/**< @brief DarkGray */
		static const Color DarkGreen;			/**< @brief DarkGreen */
		static const Color DarkKhaki;			/**< @brief DarkKhaki */
		static const Color DarkMagenta;			/**< @brief DarkMagenta */
		static const Color DarkOliveGreen;		/**< @brief DarkOliveGreen */
		static const Color DarkOrange;			/**< @brief DarkOrange */
		static const Color DarkOrchid;			/**< @brief DarkOrchid */
		static const Color DarkRed;				/**< @brief DarkRed */
		static const Color DarkSalmon;			/**< @brief DarkSalmon */
		static const Color DarkSeaGreen;		/**< @brief DarkSeaGreen */
		static const Color DarkSlateBlue;		/**< @brief DarkSlateBlue */
		static const Color DarkSlateGray;		/**< @brief DarkSlateGray */
		static const Color DarkTurquoise;		/**< @brief DarkTurquoise */
		static const Color DarkViolet;			/**< @brief DarkViolet */
		static const Color DeepPink;			/**< @brief DeepPink */
		static const Color DeepSkyBlue;			/**< @brief DeepSkyBlue */
		static const Color DimGray;				/**< @brief DimGray */
		static const Color DodgerBlue;			/**< @brief DodgerBlue */
		static const Color Firebrick;			/**< @brief Firebrick */
		static const Color FloralWhite;			/**< @brief FloralWhite */
		static const Color ForestGreen;			/**< @brief ForestGreen */
		static const Color Fuchsia;				/**< @brief Fuchsia */
		static const Color Gainsboro;			/**< @brief Gainsboro */
		static const Color GhostWhite;			/**< @brief GhostWhite */
		static const Color Gold;				/**< @brief Gold */
		static const Color Goldenrod;			/**< @brief Goldenrod */
		static const Color Gray;				/**< @brief Gray */
		static const Color WebGray;				/**< @brief WebGray */
		static const Color Green;				/**< @brief Green */
		static const Color WebGreen;			/**< @brief WebGreen */
		static const Color GreenYellow;			/**< @brief GreenYellow */
		static const Color Honeydew;			/**< @brief Honeydew */
		static const Color HotPink;				/**< @brief HotPink */
		static const Color IndianRed;			/**< @brief IndianRed */
		static const Color Indigo;				/**< @brief Indigo */
		static const Color Ivory;				/**< @brief Ivory */
		static const Color Khaki;				/**< @brief Khaki */
		static const Color Lavender;			/**< @brief Lavender */
		static const Color LavenderBlush;		/**< @brief LavenderBlush */
		static const Color LawnGreen;			/**< @brief LawnGreen */
		static const Color LemonChiffon;		/**< @brief LemonChiffon */
		static const Color LightBlue;			/**< @brief LightBlue */
		static const Color LightCoral;			/**< @brief LightCoral */
		static const Color LightCyan;			/**< @brief LightCyan */
		static const Color LightGoldenrod;		/**< @brief LightGoldenrod */
		static const Color LightGray;			/**< @brief LightGray */
		static const Color LightGreen;			/**< @brief LightGreen */
		static const Color LightPink;			/**< @brief LightPink */
		static const Color LightSalmon;			/**< @brief LightSalmon */
		static const Color LightSeaGreen;		/**< @brief LightSeaGreen */
		static const Color LightSkyBlue;		/**< @brief LightSkyBlue */
		static const Color LightSlateGray;		/**< @brief LightSlateGray */
		static const Color LightSteelBlue;		/**< @brief LightSteelBlue */
		static const Color LightYellow;			/**< @brief LightYellow */
		static const Color Lime;				/**< @brief Lime */
		static const Color LimeGreen;			/**< @brief LimeGreen */
		static const Color Linen;				/**< @brief Linen */
		static const Color Magenta;				/**< @brief Magenta */
		static const Color Maroon;				/**< @brief Maroon */
		static const Color WebMaroon;			/**< @brief WebMaroon */
		static const Color MediumAquamarine;	/**< @brief MediumAquamarine */
		static const Color MediumBlue;			/**< @brief MediumBlue */
		static const Color MediumOrchid;		/**< @brief MediumOrchid */
		static const Color MediumPurple;		/**< @brief MediumPurple */
		static const Color MediumSeaGreen;		/**< @brief MediumSeaGreen */
		static const Color MediumSlateBlue;		/**< @brief MediumSlateBlue */
		static const Color MediumSpringGreen;	/**< @brief MediumSpringGreen */
		static const Color MediumTurquoise;		/**< @brief MediumTurquoise */
		static const Color MediumVioletRed;		/**< @brief MediumVioletRed */
		static const Color MidnightBlue;		/**< @brief MidnightBlue */
		static const Color MintCream;			/**< @brief MintCream */
		static const Color MistyRose;			/**< @brief MistyRose */
		static const Color Moccasin;			/**< @brief Moccasin */
		static const Color NavajoWhite;			/**< @brief NavajoWhite */
		static const Color NavyBlue;			/**< @brief NavyBlue */
		static const Color OldLace;				/**< @brief OldLace */
		static const Color Olive;				/**< @brief Olive */
		static const Color OliveDrab;			/**< @brief OliveDrab */
		static const Color Orange;				/**< @brief Orange */
		static const Color OrangeRed;			/**< @brief OrangeRed */
		static const Color Orchid;				/**< @brief Orchid */
		static const Color PaleGoldenrod;		/**< @brief PaleGoldenrod */
		static const Color PaleGreen;			/**< @brief PaleGreen */
		static const Color PaleTurquoise;		/**< @brief PaleTurquoise */
		static const Color PaleVioletRed;		/**< @brief PaleVioletRed */
		static const Color PapayaWhip;			/**< @brief PapayaWhip */
		static const Color PeachPuff;			/**< @brief PeachPuff */
		static const Color Peru;				/**< @brief Peru */
		static const Color Pink;				/**< @brief Pink */
		static const Color Plum;			 	/**< @brief Plum */
		static const Color PowderBlue;			/**< @brief PowderBlue */
		static const Color Purple;				/**< @brief Purple */
		static const Color WebPurple;			/**< @brief WebPurple */
		static const Color RebeccaPurple;		/**< @brief RebeccaPurple */
		static const Color Red;					/**< @brief Red */
		static const Color RosyBrown;			/**< @brief RosyBrown */
		static const Color RoyalBlue;			/**< @brief RoyalBlue */
		static const Color SaddleBrown;			/**< @brief SaddleBrown */
		static const Color Salmon;				/**< @brief Salmon */
		static const Color SandyBrown;			/**< @brief SandyBrown */
		static const Color SeaGreen;			/**< @brief SeaGreen */
		static const Color Seashell;			/**< @brief Seashell */
		static const Color Sienna;				/**< @brief Sienna */
		static const Color Silver;				/**< @brief Silver */
		static const Color SkyBlue;				/**< @brief SkyBlue */
		static const Color SlateBlue;			/**< @brief SlateBlue */
		static const Color SlateGray;			/**< @brief SlateGray */
		static const Color Snow;				/**< @brief Snow */
		static const Color SpringGreen;			/**< @brief SpringGreen */
		static const Color SteelBlue;			/**< @brief SteelBlue */
		static const Color Tan;					/**< @brief Tan */
		static const Color Teal;				/**< @brief Teal */
		static const Color Thistle;				/**< @brief Thistle */
		static const Color Tomato;				/**< @brief Tomato */
		static const Color Turquoise;			/**< @brief Turquoise */
		static const Color Violet;				/**< @brief Violet */
		static const Color Wheat;				/**< @brief Wheat */
		static const Color White;				/**< @brief White */
		static const Color WhiteSmoke;			/**< @brief WhiteSmoke */
		static const Color Yellow;				/**< @brief Yellow */
		static const Color YellowGreen;			/**< @brief YellowGreen */
		#pragma endregion


	private:

		float red, green, blue, alpha;

	};
}