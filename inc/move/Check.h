#ifndef CHECK_H
#define CHECK_H

#include <move/Move.h>

class Check : public Move
{
  public:
    Check() : Move(0) {}
    virtual void updatePlayer(Player*, const float) override {}
    virtual bool isCheck() const override { return true; }
    ~Check() override = default;
};

#endif //CHECK_H
