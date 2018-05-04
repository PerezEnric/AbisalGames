#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// Black background
	background.x = 0;
	background.y = 128;
	background.w = 512;
	background.h = 256;

	// Sprite of Monster's Head
	head.x = 96;
	head.y = 98;
	head.w = 61;
	head.h = 64;

	// Sprite of Monster's body
	body.x = 0;
	body.y = 148;
	body.w = 512;
	body.h = 216;

	// Sprite of Monster's Tail
	tail.x = 77;
	tail.y = 69;
	tail.w = 364;
	tail.h = 186;


}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	// Loading black background
	black_background = App->textures->Load("Sprites_Assets/Background2.png");
	// Loading Monster's Head
	monster_head = App->textures->Load("Sprites_Assets/head.png");
	// Loading Monster's Body
	monster_body = App->textures->Load("Sprites_Assets/body.png");
	// Loading Monster's Tail
	monster_tail = App->textures->Load("Sprites_Assets/tail.png");
	// Loading second level music
	secondlvlmusic = App->audio->LoadMusic("Audio_Assets/Stage_2_Music.ogg");
	// Playing second level music
	App->audio->PlayMusic(secondlvlmusic);

	//Head colliders
	App->collision->AddCollider({ 182, 157, 30, 30 }, COLLIDER_WALL);
	App->collision->AddCollider({ 242, 148, 12, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 256, 142, 30, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 275, 139, 10, 5 }, COLLIDER_WALL);
	App->collision->AddCollider({ 285, 135, 20, 5 }, COLLIDER_WALL); //fin
	App->collision->AddCollider({ 295, 130, 20, 5 }, COLLIDER_WALL); // fin
	App->collision->AddCollider({ 307, 123, 20, 5 }, COLLIDER_WALL); // fin
	App->collision->AddCollider({ 296, 142, 50, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 347, 145, 10, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 188, 180, 31, 20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 214, 197, 61, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 203, 152, 40, 15 }, COLLIDER_WALL);
	App->collision->AddCollider({ 260, 201, 35, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 290, 210, 35, 10 }, COLLIDER_WALL);

	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything --------------------------------------
	
	App->render->Blit(black_background, 0, 0, &background); // background
	App->render->Blit(monster_head, 180, 150, &head); // head
	App->render->Blit(monster_body, 241, 119, &body); // body
	App->render->Blit(monster_tail, 753, 160, &tail); // tail

	return UPDATE_CONTINUE;
}