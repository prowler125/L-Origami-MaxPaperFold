class Combatant
{
public:
    virtual ~Combatant() {}

    virtual void attack(Combatant *target) = 0;
    virtual void defend() = 0;
    virtual int getHealth() const = 0;
    virtual void setHealth(int health) = 0;
};

class Hero : public Combatant
{
public:
    Hero(int health) : health_(health) {}

    void attack(Combatant *target) override
    {
    }

    void defend() override
    {
    }

    int getHealth() const override
    {
        return health_;
    }

    void setHealth(int health) override
    {
        health_ = health;
    }

private:
    int health_;
};

class Enemy : public Combatant
{
public:
    Enemy(int health, int attackPower) : health_(health), attackPower_(attackPower) {}

    void attack(Combatant *target) override
    {
    }

    void defend() override
    {
    }

    int getHealth() const override
    {
        return health_;
    }

    void setHealth(int health) override
    {
        health_ = health;
    }

private:
    int health_;
    int attackPower_;
};

void combat(Combatant *hero, Combatant *enemy)
{
    while (hero->getHealth() > 0 && enemy->getHealth() > 0)
    {
        hero->attack(enemy);

        enemy->attack(hero);
    }

    if (hero->getHealth() > 0)
    {
        // ...
    }

    else
    {
        // ...
    }
}