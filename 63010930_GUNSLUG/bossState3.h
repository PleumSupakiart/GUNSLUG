

#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include <SFML/Audio.hpp>
#include "bulletEnemy.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Birdstate3.h"
class BossState3
{
public:
    BossState3(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position);
    ~BossState3();

    void setHP(int x);

    int getHP();

    void Update(float deltatime, Player* player);
    void Draw(sf::RenderWindow& window);
    void DrawBullet(sf::RenderWindow& window);
    void onCollision(sf::Vector2f direction);
    void setPosition(float x, float y);
    void updateBullet();

    sf::FloatRect GetGlobalBounds() { return body.getGlobalBounds(); }
    sf::Vector2f getPosition() { return body.getPosition(); }
    Collider GetCollider() { return Collider(body); }




private:
    std::vector<Birdstate3*> bird;
    std::vector<bulletEnemy*> bullets;
    std::vector<bulletEnemy*> bullet;
    Animation animation;
    unsigned int row;
    unsigned int stop;
    float speed;
    bool faceRight;
    sf::RectangleShape body;
    sf::SoundBuffer soundJump;
    sf::Sound sJump;
    sf::Clock clockShoot;
    sf::Clock clockShoot1;
    sf::Clock clockShoot2;
    sf::Clock clockShoot3;
    sf::Clock damageClock;
    sf::Clock onGround;

    int hp;
    int r;

    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;

    sf::Texture bulletTexture;
    sf::Texture IceTexture;

    void initTexture();
};
