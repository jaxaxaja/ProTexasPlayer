#ifndef BET_H
#define BET_H

#include <move/Move.h>

class Bet : public Move
{
  public:
    Bet(const float size) : Move(size) {}
    virtual void updatePlayer(Player* player, const float) override;
    virtual bool isBet() const override { return true; }
    virtual ~Bet() = default;
};

#endif //BET_H
