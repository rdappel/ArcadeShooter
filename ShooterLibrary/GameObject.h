
#pragma once

class Level;

class GameObject
{
	friend class Game;

public:

	struct CollisionInstructions
	{
		float damageToObject;
		bool removeObject;
		bool spawnsExplosion;
	};

	enum CollisionMasks
	{
		COLLISION_NONE = 0,
		COLLISION_PLAYERSHIP = 1,
		COLLISION_PLAYERPROJECTILE = 2,
		COLLISION_ENEMYSHIP = 4,
		COLLISION_ENEMYPROJECTILE = 8,
		COLLISION_POWERUP = 16,
		COLLISION_MISSILE = 32
	};


	GameObject();
	virtual ~GameObject() { }

	static void SetCurrentLevel(Level *pLevel) { s_pCurrentLevel = pLevel; }

	static bool AreObjectsColliding(GameObject *pObject1, GameObject *pObject2, CollisionInstructions *pIns1, CollisionInstructions *pIns2);

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(const GameTime *pGameTime) = 0;

	virtual bool IsActive() const { return m_isActive; }

	virtual void Activate() { m_isActive = true; }

	virtual void Deactivate() { m_isActive = false; }

	virtual Vector2 &GetPosition() { return m_position; }

	virtual std::string ToString() const { return "GameObject"; }

	virtual Vector2 GetHalfDimensions() const { return Vector2(); }

	virtual int GetIndex() const { return m_index; }

	virtual int GetCollisionMask() const = 0;

	virtual void Hit(const float damage) { }


protected:

	static Level *s_pCurrentLevel;

	static int s_count;

	int m_index;

	bool m_isActive;

	Vector2 m_position;
	Vector2 m_previousPosition;

	float m_collisionRadius;


private:

	static void ResetInstructions(CollisionInstructions *pInstructions);

};