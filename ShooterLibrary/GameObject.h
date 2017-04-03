
#pragma once

using namespace KatanaEngine;

namespace ShooterLibrary
{
	class Level;

	class GameObject
	{
		friend class Game;

	public:
		
		GameObject();
		virtual ~GameObject() { }

		static void SetCurrentLevel(Level *pLevel) { s_pCurrentLevel = pLevel; }

		//static bool AreObjectsColliding(GameObject *pObject1, GameObject *pObject2, CollisionInstructions *pIns1, CollisionInstructions *pIns2);

		virtual void Update(const GameTime *pGameTime);

		virtual void Draw(const GameTime *pGameTime) = 0;

		virtual bool IsActive() const { return m_isActive; }

		virtual void Activate() { m_isActive = true; }

		virtual void Deactivate() { m_isActive = false; }

		virtual Vector2 &GetPosition() { return m_position; }

		virtual Vector2 GetPreviousPosition() { return m_previousPosition; }

		virtual std::string ToString() const { return "GameObject"; }

		virtual Vector2 GetHalfDimensions() const;

		virtual int GetIndex() const { return m_index; }

		virtual uint32_t GetCollisionMask() const = 0;

		virtual float GetCollisionRadius() const { return m_collisionRadius; }

		virtual void Hit(const float damage) { }

		virtual void SetSpriteBatch(SpriteBatch *pSpriteBatch) { m_pSpriteBatch = pSpriteBatch; }

		virtual bool HasMask(uint32_t mask) const { return (GetCollisionMask() & mask) > 0; }

		virtual bool IsMask(uint32_t mask) const { return (GetCollisionMask() == mask); }


	protected:

		static Level *GetCurrentLevel() { return s_pCurrentLevel; }

		virtual SpriteBatch *GetSpriteBatch() const { return m_pSpriteBatch; }

		virtual void SetCollisionRadius(const int radius) { m_collisionRadius = radius; }

		virtual void SetPosition(const float x, const float y);

		virtual void SetPosition(const Vector2 &position);

		virtual void TranslatePosition(const float x, const float y);

		virtual void TranslatePosition(const Vector2 &offset);


	private:

		static Level *s_pCurrentLevel;

		static int s_count;

		int m_index;

		bool m_isActive;

		Vector2 m_position;
		Vector2 m_previousPosition;

		float m_collisionRadius;

		SpriteBatch *m_pSpriteBatch = nullptr;

	};
}