
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

#include "ShooterLibrary.h"
//#include <allegro5\allegro_primitives.h>

namespace ShooterLibrary
{
	Level::Level()
	{
		m_sectorSize.X = 64;
		m_sectorSize.Y = 64;

		m_sectorCount.X = (Game::GetScreenWidth() / (int)m_sectorSize.X) + 1;
		m_sectorCount.Y = (Game::GetScreenHeight() / (int)m_sectorSize.Y) + 1;

		m_totalSectorCount = m_sectorCount.X * m_sectorCount.Y;

		m_pSectors = new std::vector<GameObject *>[m_totalSectorCount];

		m_pBackground = nullptr;

		GameObject::SetCurrentLevel(this);
	}


	Level::~Level()
	{
		delete[] m_pSectors;

		if (GetCollisionManager())
		{
			delete m_pCollisionManager;
		}

		std::vector<ProjectilePool *>::iterator it = m_pProjectilePools.begin();
		for (; it != m_pProjectilePools.end(); it++) delete *it;
	}


	void Level::LoadContent(ResourceManager *pResourceManager)
	{
		InitializeCollisionManager();

		AddGameObject(GetPlayerShip());
		
		if (m_pBackground) m_pBackground->LoadContent(pResourceManager);

		//al_init_primitives_addon();
	}


	void Level::UnloadContent()
	{
		if (m_pBackground) m_pBackground->UnloadContent();
	}


	void Level::HandleInput(const InputState *pInput)
	{
		GetPlayerShip()->HandleInput(pInput);
	}


	void Level::Update(const GameTime *pGameTime)
	{
		if (m_pBackground) m_pBackground->Update(pGameTime);

		for (unsigned int i = 0; i < m_totalSectorCount; i++)
		{
			m_pSectors[i].clear();
		}

		m_gameObjectIt = m_gameObjects.begin();
		for (; m_gameObjectIt != m_gameObjects.end(); m_gameObjectIt++)
		{
			GameObject *pGameObject = (*m_gameObjectIt);
			pGameObject->Update(pGameTime);
		}


		if (m_pCollisionManager)
		{
			for (unsigned int i = 0; i < m_totalSectorCount; i++)
			{
				if (m_pSectors[i].size() > 1)
				{
					CheckCollisions(m_pSectors[i]);
				}
			}
		}
	}


	void Level::CheckCollisions(std::vector<GameObject *> &gameObjects)
	{
		const unsigned int objectCount = (unsigned int)gameObjects.size();

		GameObject *pI, *pJ;

		for (unsigned int i = 0; i < objectCount - 1; i++)
		{
			pI = gameObjects[i];
			if (pI->IsActive())
			{
				for (unsigned int j = i + 1; j < objectCount; j++)
				{
					if (!pI->IsActive()) continue;

					pJ = gameObjects[j];
					if (pJ->IsActive())
					{
						m_pCollisionManager->CheckCollision(pI, pJ);
					}
				}
			}
		}
	}


	void Level::Draw(SpriteBatch *pSpriteBatch)
	{
		if (m_pBackground) m_pBackground->Draw(pSpriteBatch);

		//al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
		//if (m_pBackground) m_pBackground->Draw(pGameTime);

		//al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
		//m_particleManager.Draw(pGameTime);

		//al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);

		//// Draw the sector primitive if it contains a game object
		//for (unsigned int i = 0; i < m_totalSectorCount; i++)
		//{
		//	if (m_pSectors[i].size() > 0)
		//	{
		//		int x = (i % (int)m_sectorCount.X) * m_sectorSize.X;
		//		int y = (i / (int)m_sectorCount.X) * m_sectorSize.Y;

		//		al_draw_filled_rectangle(x, y, x + m_sectorSize.X, y + m_sectorSize.Y, al_map_rgba_f(1, 1, 1, 0.2f));
		//	}
		//}

		GetParticleManager()->Draw(pSpriteBatch);

		pSpriteBatch->Begin(SpriteSortMode::BACK_TO_FRONT, BlendState::ALPHA);

		m_gameObjectIt = m_gameObjects.begin();
		for (; m_gameObjectIt != m_gameObjects.end(); m_gameObjectIt++)
		{
			GameObject *pGameObject = (*m_gameObjectIt);
			if (pGameObject->IsActive())
			{
				pGameObject->Draw(pSpriteBatch);
			}
		}

		pSpriteBatch->End();

		//// Draw explosions
		//al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ONE);
		//m_explosionIt = m_explosions.begin();
		//for (; m_explosionIt != m_explosions.end(); m_explosionIt++)
		//{
		//	Explosion *pExplosion = (*m_explosionIt);
		//	if (pExplosion->IsActive())
		//	{
		//		pExplosion->Draw(pGameTime);
		//	}
		//}

		//al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
	}
	
	void Level::UpdateSectorPosition(GameObject *pGameObject)
	{
		Vector2 position = pGameObject->GetPosition();
		//Vector2 previousPosition = pGameObject->GetPreviousPosition();
		Vector2 halfDimensions = pGameObject->GetHalfDimensions();

		int minX = (int)(position.X - halfDimensions.X - 0.5f);
		int maxX = (int)(position.X + halfDimensions.X + 0.5f);
		int minY = (int)(position.Y - halfDimensions.Y - 0.5f);
		int maxY = (int)(position.Y + halfDimensions.Y + 0.5f);

		//// Expand to contain the previous positions
		//minX = Math::Min(minX, (int)(previousPosition.X - halfDimensions.X - 0.5f));
		//maxX = Math::Max(maxX, (int)(previousPosition.X + halfDimensions.X + 0.5f));
		//minY = Math::Min(minY, (int)(previousPosition.Y - halfDimensions.Y - 0.5f));
		//maxY = Math::Max(maxY, (int)(previousPosition.Y + halfDimensions.Y + 0.5f));

		minX = (int)Math::Clamp(0, m_sectorCount.X - 1, minX / (int)m_sectorSize.X);
		maxX = (int)Math::Clamp(0, m_sectorCount.X - 1, maxX / (int)m_sectorSize.X);
		minY = (int)Math::Clamp(0, m_sectorCount.Y - 1, minY / (int)m_sectorSize.Y);
		maxY = (int)Math::Clamp(0, m_sectorCount.Y - 1, maxY / (int)m_sectorSize.Y);


		for (int x = minX; x <= maxX; x++)
		{
			for (int y = minY; y <= maxY; y++)
			{
				int index = y * (int)m_sectorCount.X + x;

				m_pSectors[index].push_back(pGameObject);
			}
		}
	}
}