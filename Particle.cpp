//*****************************************************************
// GAME 230 assignment 3
// Particle.cpp
// Zhihao Wang
// UCSC GPM FALL 2022
//*****************************************************************

#include "Particle.h"

//*****************************************************************
Particle::Particle()
{
	Duration = PARTICLE_DURATION;
}

//*****************************************************************
Particle::~Particle()
{

}

//*****************************************************************
void Particle::Setup(Vector2f MousePosition, Vector2f ParticleVelocity)
{
	Circle.setRadius(PARTICLE_SIZE);
	Position = MousePosition;
	Velocity = ParticleVelocity;
	ParticleColor = Color::White;
	Duration = PARTICLE_DURATION;

}

//*****************************************************************
void Particle::Update(float DeltaTime)
{
	Position.x = PARTICLE_SPEED * Velocity.x * DeltaTime + Position.x;
	Position.y = PARTICLE_SPEED * Velocity.y * DeltaTime + Position.y;
	Circle.setPosition(Position);

	Duration -= DeltaTime;

}

//*****************************************************************
void Particle::Draw(RenderWindow& Window)
{
	Window.draw(Circle);
}

float Particle::GetDuration()
{
	return Duration;
}