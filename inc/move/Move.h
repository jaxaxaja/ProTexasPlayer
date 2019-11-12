#ifndef MOVE_H
#define MOVE_H

#include <memory>
#include <ostream>

class Player;
class Croupier;

class Move
{
protected:
    float size_ = 0;
public:
    Move(float size) : size_(size) {}
    static std::unique_ptr<Move> createMove(const std::string& move, float size); //factory method
    virtual void updatePlayer(Player* player, const float bb) = 0;
    virtual bool isBet() const { return false; }
    virtual bool isRaise() const { return false; }
    virtual bool isFold() const { return false; }
    virtual bool isCheck() const { return false; }
    virtual bool isCall() const {return false; }
    float moveSize() const { return size_; }
    virtual ~Move() = default;
};

std::ostream& operator<<(std::ostream& os, const Move& p);

#endif //MOVE_H
