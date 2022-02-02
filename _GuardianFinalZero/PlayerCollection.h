
/*                '888 88888888888 888888888',8888'
                    88 888888888888 8888888',8888'
                     8 8888             ,8',8888'
          ==̲=̲=̲=̲=̲=̲=== 8 8888 ========== ,8 ,̲8̲88̲8_==============
          /  ____/__ 8_̲88̲8̲8̲8̲88̲88̲8̲8̲8__ ,̲8__/ //_/____ _ ____
         / /  __ / / / /ˊ __ `// ___/ˊ __  /__ ˊ __ `// __ \
        / /__/ // /_/ // /_/ // /   / /_/ // // /_/ // / / /
        \_____/ \__,_/ \__,_//_/    \__,_//_/ \__,_//_/ /_/
      ============== 8 8888 ===== ,8',8888' ===============
                    88 8888      ,8',8888888888888
                   ,88 8888     ,8',888888888888888,

                           ファイナル ゼロ

               Guardian FZ © 2017 - Shuriken Studios LLC          */

#pragma once

namespace GuardianFinalZero
{
    class PlayerCollection
    {

    public:

        PlayerCollection();
        virtual ~PlayerCollection() { }

        virtual void HandleInput(const InputState* pInput);

        virtual PlayerShip *GetPlayerShip(const uint8_t playerIndex) const { return m_pPlayerShips[playerIndex]; }

    protected:

        virtual void InitializeShip(uint8_t index);

    private:

        const uint8_t MAX_PLAYERS = InputState::MAX_NUM_GAMEPADSTATES;

        PlayerShip* m_pPlayerShips[InputState::MAX_NUM_GAMEPADSTATES];
    };
}