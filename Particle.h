//*****************************************************************
// GAME 230 assignment 3
// Particle.h
// Zhihao Wang
// UCSC GPM FALL 2022
//*****************************************************************


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>

using namespace sf;

class Particle
{
private:

	CircleShape Circle;
	Vector2f	Position;
	Vector2f	Velocity;
	Color		ParticleColor;
	float		Duration = 0;
	//float		Size;

	const float PARTICLE_SIZE = 7.0f;
	const float PARTICLE_DURATION = 2.0f;
	const float PARTICLE_SPEED = 105.0f;

public:
	Particle();
	~Particle();

	void Setup(Vector2f MousePostition, Vector2f ParticleVelocity);
	void Update(float DeltaTime);
	void Draw(RenderWindow& Window);
	float GetDuration();
};