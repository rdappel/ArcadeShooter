﻿
/*      .                         ,'`.       .                         
   .                  .."    _.-;' ⁄‚ `.              .			`      
              _.-"`.##%"_.--" ,' ⁄`     `.           "#"     ___,,od000
           ,'"-_ _.-.--"\   ,'            `-_       '%#%',,/00000000000
         ,'     |_.'     )`/-     __..--""`-_`-._    J L/00000000000000
 . +   ,'   _.-"        / /   _-""           `-._`-_/___\///0000   000M
     .'_.-""      '    :_/_.-'                 _,`-/__V__\0000    00MMM
 . _-""                         .        '   _,/000\  |  /000    0MMMMM
_-"   .       '     .              .        ,/   000\ | /000000000MMMMM
       `       Shooter Library       '     ,/     000\|/000000000MMMMMM
.       © 2017 - Shuriken Studios LLC     ,/0    00000|0000000000MMMMMM */

#pragma once

using namespace KatanaEngine;

namespace ShooterLibrary
{

	class Level;
	class GameObject;

	/** @brief Callback function for when a game object is deactivated.
		@see MenuItem */
	typedef void(*OnDeactivate)(GameObject *pGameObject);
	
	/** @brief Base class for all objects that will be updated and rendered on a GameplayScreen. */
	class GameObject
	{
		friend class Game;

	public:
		
		GameObject();
		virtual ~GameObject() { s_count--; }

		
		/** @brief Sets the current game level.
			@param pLevel A pointer to the current level.
			@remark This is called automatically when a Level is constructed. */
		static void SetCurrentLevel(Level *pLevel) { s_pCurrentLevel = pLevel; }

		/** @brief Gets the current level.
			@return Returns a pointer to the current level. */
		static Level *GetCurrentLevel() { return s_pCurrentLevel; }

		/** @brief Sets the callback function for when the menu item is selected.
			@param callback The callback function. */
		virtual void SetDeactivateCallback(OnDeactivate callback) { m_onDeactivate = callback; }

		/** @brief Updates the game object.
			@param pGameTime Timing values including time since last update.
			@remark This should be called automatically by the Level, as long as the gameobject is
			added to the Level by calling Level::AddGameObject().
			@see Level::AddGameObject() */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Renders the game object.
			@param pSpriteBatch The game's sprite batch, used for rendering.
			@remark This should be called automatically by the Level, as long as the gameobject is
			added to the Level by calling Level::AddGameObject().
			@see Level::AddGameObject() */
		virtual void Draw(SpriteBatch *pSpriteBatch) = 0;

		/** @brief Determines if the game object is active.
			@return Returns true if the game object is active, false otherwise. */
		virtual bool IsActive() const { return m_isActive; }

		/** @brief Activates the game object. */
		virtual void Activate() { m_isActive = true; }

		/** @brief Deactivates the game object. */
		virtual void Deactivate();

		/** @brief Gets the position of the game object.
			@return Returns the object's position on the screen. */
		virtual Vector2 &GetPosition() { return m_position; }

		/** @brief Gets the previous position of the game object.
			@return Returns the object's position on the screen during the previous frame. */
		virtual Vector2 &GetPreviousPosition() { return m_previousPosition; }

		/** @brief Gets a string representation of the game object.
			@return Returns a string displaying the type of object. */
		virtual std::string ToString() const = 0;

		/** @brief Gets the half dimensions of the game object.
			@return Returns the half dimensions of the object. */
		virtual Vector2 GetHalfDimensions() const;

		/** @brief Gets the index of the game object.
			@return Returns the index of the object. */
		virtual uint32_t GetIndex() const { return m_index; }

		/** @brief Gets the collision type mask.
			@return Returns bit-mask value for the collision type.
			@see CollisionTypes
			@see CollisionManager */
		virtual CollisionType GetCollisionType() const = 0;

		/** @brief Gets the collision radius.
			@return Returns the collision radius. */
		virtual float GetCollisionRadius() const { return m_collisionRadius; }

		/** @brief Hits the object, dealing damage to it.
			@param damage The amount of damage to inflict. */
		virtual void Hit(const float damage) { }

		/** @brief Determines if the object contains part of a collision bit-mask.
			@param mask The mask to test.
			@return Returns true if the object's collision mask matches or contains
			part of the bit-mask, false otherwise. */
		virtual bool HasMask(CollisionType mask) const { return mask.Contains(GetCollisionType()); }

		/** @brief Determines if the object matches a collision bit-mask.
			@param mask The mask to test.
			@return Returns true if the object's collision mask matches the bit-mask,
			false otherwise. */
		virtual bool IsMask(CollisionType mask) const { return (GetCollisionType() == mask); }


		/** @brief Determines if the level should draw the game object.
			@return Returns true if the level should be responsible for drawing the
			game object. 
			@remark Override this method if you want to manually draw it. */
		virtual bool IsDrawnByLevel() const { return true; }


	protected:
		
		/** @brief Sets the collision radius for the object.
			@param radius The collision radius. */
		virtual void SetCollisionRadius(const int radius) { m_collisionRadius = radius; }

		/** @brief Sets the screen position of the object.
			@param x The horizontal position.
			@param y The vertical position. */
		virtual void SetPosition(const float x, const float y);

		/** @brief Sets the screen position of the object.
			@param position The new position.
			
			@overload */
		virtual void SetPosition(const Vector2 &position);

		/** @brief Offsets the current screen position of the object.
			@param x The horizontal distance to offset.
			@param y The vertical distance to offset. */
		virtual void TranslatePosition(const float x, const float y);

		/** @brief Offsets the current screen position of the object.
			@param offset The offset.

			@overload */
		virtual void TranslatePosition(const Vector2 &offset);

		/** @brief Determines if the game object is on the screen.
			@return Returns true if the game object is on the screen,
			false otherwise. */
		virtual bool IsOnScreen() const;


	private:

		static Level *s_pCurrentLevel;
		static uint32_t s_count;

		OnDeactivate m_onDeactivate;

		uint32_t m_index;

		bool m_isActive;

		Vector2 m_position;
		Vector2 m_previousPosition;

		float m_collisionRadius;

	};
}