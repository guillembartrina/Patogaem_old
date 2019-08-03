#ifndef DUCK_HPP
#define DUCK_HPP

#include "PhysicEntity.hpp"

enum MovementSide
{
  MovementSide_RIGHT = 0,
  MovementSide_LEFT
};

enum MovementState
{
  MovementState_STANDING = 0,
  MovementState_JUMPING,
  MovementState_FLYING,
  MovementState_DOWNING,
  MovementState_FLOORING
};

class Duck : public PhysicEntity
{
    public:

    Duck(Core core, Scene_Play* play, const sf::Vector2f& position, b2World& world);
    ~Duck();

    void update(sf::Time deltatime) override;

    void handleEvents(const sf::Event& event);

    void onCollision(int fixtureid, PhysicEntity* collided) override;
    void onDecollision(int fixtureid, PhysicEntity* collided) override;

    void changeState(MovementState newstate);

    MovementState getState() const;

    private:

    MovementState state;
    MovementSide side;

    int groundings, headings;

    bool lc, rc, uc, dc;
    bool gr, hr;

    b2Body* bodies[3]; //1:down, 2:floor, 0:others
};

#endif