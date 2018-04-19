#include "Application.h"
#include "PowerUp.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

PowerUp::PowerUp(int x, int y) : position(x, y)
{}

PowerUp::~PowerUp()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* PowerUp::GetCollider() const
{
	return collider;
}

void PowerUp::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (animation != nullptr)
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}
