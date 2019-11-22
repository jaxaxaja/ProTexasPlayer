#ifndef CALL_H
#define CALL_H

#include <move/Move.h>

class Call : public Move
{
  public:
    Call() : Move(0) {}
    virtual void updatePlayer(Player* player, const float bb) override;
    virtual bool isCall() const override { return true; }
    ~Call() override = default;
};

#endif //CALL_H
