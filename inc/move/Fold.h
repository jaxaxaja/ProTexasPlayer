#ifndef FOLD_H
#define FOLD_H

#include <move/Move.h>

class Fold : public Move
{
  public:
    Fold() : Move(0) {}
    virtual void updatePlayer(Player* player, const float) override;
    virtual bool isFold() const override { return true; }
    virtual ~Fold() = default;
};

#endif //FOLD_H
