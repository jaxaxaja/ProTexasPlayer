#ifndef RAISE_H
#define RAISE_H

#include <move/Move.h>

class Raise : public Move
{
  public:
    Raise(const float size) : Move(size) {}
    virtual void updatePlayer(Player* player, const float) override;
    virtual bool isRaise() const override {return true; }
    ~Raise() override = default;
};

#endif //RAISE_H
