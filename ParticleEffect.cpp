//*****************************************************************
// GAME 230 assignment 3
// ParticleEffect.cpp
// Zhihao Wang
// UCSC GPM FALL 2022
//*****************************************************************

#include "Particle.h"
#include "ParticleEffect.h"
#include <random>

//*****************************************************************
ParticleEffect::ParticleEffect()
{
	
}

//*****************************************************************
ParticleEffect::~ParticleEffect()
{
	Destroy();
}

//*****************************************************************
void ParticleEffect::CreateParticleArray(Vector2f MousePosition)
{
	for (int i = 0; i < PARTICLE_ARRAY_SIZE; i++)
	{
		Particle* SingleParticle = new Particle();
		Vector2f Velocity( ((float)(std::rand() % 1500 - 500)), ((float)(std::rand() % 1500 - 500)));
		Velocity = Normalize(Velocity);
		SingleParticle->Setup(MousePosition, Velocity);
		ParticleArray[i] = SingleParticle;
	}

}

//*****************************************************************
void ParticleEffect::Update(float DeltaTime)
{
	for (int i = 0; i < PARTICLE_ARRAY_SIZE; i++)
	{
		if (ParticleArray[i] != nullptr)
		{
			ParticleArray[i]->Update(DeltaTime);
			if (ParticleArray[i]->GetDuration() <= 0)
			{
				delete ParticleArray[i];
				ParticleArray[i] = nullptr;
			}
		}
	}
}
//*****************************************************************
void ParticleEffect::Draw(RenderWindow& Window)
{
	for (int i = 0; i < PARTICLE_ARRAY_SIZE; i++)
	{
		if (ParticleArray[i] != nullptr)
		{
			ParticleArray[i]->Draw(Window);
		}
	}
}

//*****************************************************************
Vector2f ParticleEffect::Normalize(Vector2f& vec)
{
	float Length = sqrt(vec.x * vec.x + vec.y * vec.y);

	return Length == 0 ? vec : Vector2f(vec.x / Length, vec.y / Length);
}

//*****************************************************************
void ParticleEffect::Destroy()
{
	for (int i = 0; i < PARTICLE_ARRAY_SIZE; i++)
	{
		delete ParticleArray[i];
		ParticleArray[i] = nullptr;
	}
}