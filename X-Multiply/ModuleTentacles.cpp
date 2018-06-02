#include "ModuleTentacles.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"


ModuleTentacles::ModuleTentacles()
{
	graphics = nullptr;
	current_animation = nullptr;


	// idle animation
	tentacl.PushBack({ 817, 746, 19, 9 });
	tentacl.PushBack({ 849, 747, 19, 7 });
	tentacl.PushBack({ 881, 748, 19, 6 });
	tentacl.PushBack({ 913, 748, 19, 7 });
	tentacl.speed = 0.1f;

	//vertical arm
	 arm0.x = 733;
	 arm0.y = 747;
	 arm0.w = 4;
	 arm0.h = 11;

	//1st front - 1 
	arm1.x = 748;
	arm1.y = 747;
	arm1.w = 7;
	arm1.h = 10;
	//2nd front - 2
	arm2.x = 763;
	arm2.y = 748;
	arm2.w = 9;
	arm2.h = 8;
	//3rd front - 3
	arm3.x = 778;
	arm3.y = 749;
	arm3.w = 10;
	arm3.h = 6;
	//horitzontal front - 4
	arm4.x = 794;
	arm4.y = 750;
	arm4.w = 11;
	arm4.h = 4;
	//5st front down - 5
	arm5.x = 942;
	arm5.y = 765;
	arm5.w = 10;
	arm5.h = 6;
	//6st front - 6
	arm6.x = 927;
	arm6.y = 764;
	arm6.w = 9;
	arm6.h = 8;
	//7st front - 7
	arm7.x = 913;
	arm7.y = 763;
	arm7.w = 7;
	arm7.h = 10;
	//1st back - 8
	arm8.x = 968;
	arm8.y = 781;
	arm8.w = 7;
	arm8.h = 10;
	//2nd back - 9
	arm9.x = 951;
	arm9.y = 782;
	arm9.w = 9;
	arm9.h = 8;
	//3rd back - 10
	arm10.x = 935;
	arm10.y = 783;
	arm10.w = 10;
	arm10.h = 6;
	//horitzontal back - 11
	arm11.x = 939;
	arm11.y = 824;
	arm11.w = 11;
	arm11.h = 4;
	//5st back - 12
	arm12.x = 938;
	arm12.y = 805;
	arm12.w = 10;
	arm12.h = 6;
	//6st back - 13
	arm13.x = 954;
	arm13.y = 804;
	arm13.w = 9;
	arm13.h = 8;
	//7st back - 14
	arm14.x = 970;
	arm14.y = 803;
	arm14.w = 7;
	arm14.h = 10;
	// vertical down
	arm15.x = 723;
	arm15.y = 747;
	arm15.w = 4;
	arm15.h = 11;


}

ModuleTentacles::~ModuleTentacles()
{}

bool ModuleTentacles::Start()
{
	position.x = App->player->position.x + 10;
	position.y = App->player->position.y - 43;
	hand_down.x = position.x;
	hand_down.y = App->player->position.y + 57;
	graphics = App->textures->Load("Sprites_Assets/all_enemies.png");
	basic_shot = App->audio->LoadSoundEffect("Audio_Assets/shotp.wav");

	posArm0.y = App->player->position.y - 8;
	posArm1.y = App->player->position.y - 16;
	posArm2.y = App->player->position.y - 24;
	posArm3.y = App->player->position.y - 32;
	posArm4.y = App->player->position.y - 40;
	posArm0.x = posArm1.x = posArm2.x = posArm3.x = posArm4.x = App->player->position.x;

	posArm10.x = posArm11.x = posArm12.x = posArm13.x = posArm14.x = App->player->position.x + 10;
	posArm10.y = App->player->position.y + 8;
	posArm11.y = posArm10.y + 8;
	posArm12.y = posArm11.y + 8;
	posArm13.y = posArm12.y + 8;
	posArm14.y = posArm13.y + 8;
	cd = 0;

	//collider and damage to hands
	colhandtop = App->collision->AddCollider({ position.x, position.y, 19, 9 }, COLLIDER_HANDS, this);
	colhandtop->damage = 0.1;
	colhanddown = App->collision->AddCollider({ hand_down.x, hand_down.y, 19, 9 }, COLLIDER_HANDS, this);
	colhanddown->damage = 0.1;

	//colliders arms
	colArm0 = App->collision->AddCollider({ posArm0.x, posArm0.y, 9, 11 }, COLLIDER_ARMS, this);
	colArm1 = App->collision->AddCollider({ posArm1.x, posArm1.y, 9, 11 }, COLLIDER_ARMS, this);
	colArm2 = App->collision->AddCollider({ posArm2.x, posArm2.y, 9, 11 }, COLLIDER_ARMS, this);
	colArm3 = App->collision->AddCollider({ posArm3.x, posArm3.y, 9, 11 }, COLLIDER_ARMS, this);
	colArm4 = App->collision->AddCollider({ posArm4.x, posArm4.y, 9, 11 }, COLLIDER_ARMS, this);
	colArm10 = App->collision->AddCollider({ posArm10.x, posArm10.y, 9, 11 }, COLLIDER_ARMS, this);
	colArm11 = App->collision->AddCollider({ posArm11.x, posArm11.y, 9, 11 }, COLLIDER_ARMS, this);
	colArm12 = App->collision->AddCollider({ posArm12.x, posArm12.y, 9, 11 }, COLLIDER_ARMS, this);
	colArm13 = App->collision->AddCollider({ posArm13.x, posArm13.y, 9, 11 }, COLLIDER_ARMS, this);
	colArm14 = App->collision->AddCollider({ posArm14.x, posArm14.y, 9, 11 }, COLLIDER_ARMS, this);
	return true;
}

bool ModuleTentacles::CleanUp()
{
	App->textures->Unload(graphics);
	graphics = nullptr;

	App->audio->UnloadSoundEffect(basic_shot);
	basic_shot = nullptr;
	return true;
}

update_status ModuleTentacles::Update()
{
	if (App->player->tentacles)
	{
		hand_down.x = position.x;
	
		posArm0.x = posArm1.x = posArm2.x = posArm3.x = posArm4.x = App->player->position.x + 10;
		posArm0.y = App->player->position.y - 8;
		posArm1.y = App->player->position.y - 16;
		posArm2.y = App->player->position.y - 24;
		posArm3.y = App->player->position.y - 32;
		posArm4.y = App->player->position.y - 40;

		posArm10.x = posArm11.x = posArm12.x = posArm13.x = posArm14.x = App->player->position.x + 10;
		posArm10.y = App->player->position.y + 8;
		posArm11.y = posArm10.y + 8;
		posArm12.y = posArm11.y + 8;
		posArm13.y = posArm12.y + 8;
		posArm14.y = posArm13.y + 8;

		movetentacle();
		current_animation = &tentacl;

		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
		colhandtop->SetPos(position.x, position.y);
		App->render->Blit(graphics, hand_down.x, hand_down.y, &(current_animation->GetCurrentFrame()));
		colhanddown->SetPos(hand_down.x, hand_down.y);
	}
	return UPDATE_CONTINUE;
}


void ModuleTentacles::movetentacle()
{
	if (App->player->tentacles = true)
	{
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			cd += 2;
		}
		else if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			cd -= 2;
		}
		else if (cd < 0)
		{
			cd += 1;
		}
		else if (cd > 0)
		{
			cd -= 1;
		}

		if (cd < -30)
		{
			cd = -29;

			posArm1.x = posArm0.x - 5;
			posArm2.x = posArm1.x - 9;
			posArm3.x = posArm2.x - 6;
			posArm4.x = posArm3.x - 5;
			position.x = posArm4.x - 10;

			posArm1.y = posArm0.y - 5;
			posArm2.y = posArm1.y + 1;
			posArm3.y = posArm2.y + 2;
			posArm4.y = posArm3.y + 6;
			position.y = posArm4.y + 4;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm9);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm12);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm13);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm14);

			posArm11.x = posArm10.x - 5;
			posArm12.x = posArm11.x - 8;
			posArm13.x = posArm12.x - 6;
			posArm14.x = posArm13.x - 6;
			hand_down.x = posArm14.x - 10;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 1;
			posArm13.y = posArm12.y - 5;
			posArm14.y = posArm13.y - 8;
			hand_down.y = posArm14.y - 3;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm13);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm10);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm9);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm8);
		}
		else if (cd < -25)
		{
			posArm1.x = posArm0.x - 5;
			posArm2.x = posArm1.x - 9;
			posArm3.x = posArm2.x - 6;
			posArm4.x = posArm3.x - 5;
			position.x = posArm4.x - 10;

			posArm1.y = posArm0.y - 5;
			posArm2.y = posArm1.y + 1;
			posArm3.y = posArm2.y + 2;
			posArm4.y = posArm3.y + 6;
			position.y = posArm4.y + 4;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm9);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm12);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm13);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm14);

			posArm11.x = posArm10.x - 5;
			posArm12.x = posArm11.x - 8;
			posArm13.x = posArm12.x - 6;
			posArm14.x = posArm13.x - 6;
			hand_down.x = posArm14.x - 10;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 1;
			posArm13.y = posArm12.y - 5;
			posArm14.y = posArm13.y - 8;
			hand_down.y = posArm14.y - 3;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm13);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm10);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm9);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm8);
		}
		else if (cd < -20)
		{
			posArm1.x = posArm0.x - 6;
			posArm2.x = posArm1.x - 8;
			posArm3.x = posArm2.x - 9;
			posArm4.x = posArm3.x - 7;
			position.x = posArm4.x - 11;

			posArm1.y = posArm0.y - 7;
			posArm2.y = posArm1.y - 1;
			posArm3.y = posArm2.y + 2;
			posArm4.y = posArm3.y + 5;
			position.y = posArm4.y + 5;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm9);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm11);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm12);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm13);

			posArm11.x = posArm10.x - 7;
			posArm12.x = posArm11.x - 7;
			posArm13.x = posArm12.x - 10;
			posArm14.x = posArm13.x - 7;
			hand_down.x = posArm14.x - 11;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 5;
			posArm13.y = posArm12.y - 3;
			posArm14.y = posArm13.y - 5;
			hand_down.y = posArm14.y - 5;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm13);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm11);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm10);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm9);
		}
		else if (cd < -15)
		{
			posArm1.x = posArm0.x - 3;
			posArm2.x = posArm1.x - 7;
			posArm3.x = posArm2.x - 11;
			posArm4.x = posArm3.x - 9;
			position.x = posArm4.x - 12;

			posArm1.y = posArm0.y - 6;
			posArm2.y = posArm1.y - 3;
			posArm3.y = posArm2.y;
			posArm4.y = posArm3.y + 2;
			position.y = posArm4.y + 2;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm8);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm10);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm11);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm12);

			posArm11.x = posArm10.x - 5;
			posArm12.x = posArm11.x - 7;
			posArm13.x = posArm12.x - 7;
			posArm14.x = posArm13.x - 7;
			hand_down.x = posArm14.x - 16;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 10;
			posArm13.y = posArm12.y + 2;
			posArm14.y = posArm13.y - 2;
			hand_down.y = posArm14.y - 2;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm14);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm12);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm11);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm10);

		}
		else if (cd < -10)
		{
			posArm1.x = posArm0.x - 3;
			posArm2.x = posArm1.x - 6;
			posArm3.x = posArm2.x - 9;
			posArm4.x = posArm3.x - 10;
			position.x = posArm4.x - 15;

			posArm1.y = posArm0.y - 8;
			posArm2.y = posArm1.y - 6;
			posArm3.y = posArm2.y - 4;
			posArm4.y = posArm3.y - 1;
			position.y = posArm4.y - 1;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm8);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm9);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm10);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm11);

			posArm11.x = posArm10.x - 3;
			posArm12.x = posArm11.x - 6;
			posArm13.x = posArm12.x - 9;
			posArm14.x = posArm13.x - 11;
			hand_down.x = posArm14.x - 15;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 6;
			posArm13.y = posArm12.y + 5;
			posArm14.y = posArm13.y + 2;
			hand_down.y = posArm14.y - 1;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm14);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm13);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm12);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm11);
		}
		else if (cd < -5)
		{
			posArm1.x = posArm0.x;
			posArm2.x = posArm1.x - 3;
			posArm3.x = posArm2.x - 6;
			posArm4.x = posArm3.x - 9;
			position.x = posArm4.x - 15;

			posArm1.y = posArm0.y - 8;
			posArm2.y = posArm1.y - 8;
			posArm3.y = posArm2.y - 6;
			posArm4.y = posArm3.y - 4;
			position.y = posArm4.y - 2;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm0);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm8);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm9);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm10);

			posArm11.x = posArm10.x;
			posArm12.x = posArm11.x - 3;
			posArm13.x = posArm12.x - 6;
			posArm14.x = posArm13.x - 9;
			hand_down.x = posArm14.x - 15;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 8;
			posArm13.y = posArm12.y + 6;
			posArm14.y = posArm13.y + 7;
			hand_down.y = posArm14.y + 2;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm15);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm14);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm13);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm12);
		}
		else if (cd < -5)
		{
			posArm1.x = posArm0.x;
			posArm2.x = posArm1.x;
			posArm3.x = posArm2.x - 3;
			posArm4.x = posArm3.x - 6;
			position.x = posArm4.x - 14;

			posArm1.y = posArm0.y - 8;
			posArm2.y = posArm1.y - 8;
			posArm3.y = posArm2.y - 8;
			posArm4.y = posArm3.y - 6;
			position.y = posArm4.y - 2;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm0);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm0);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm8);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm9);

			posArm11.x = posArm10.x;
			posArm12.x = posArm11.x;
			posArm13.x = posArm12.x - 3;
			posArm14.x = posArm13.x - 6;
			hand_down.x = posArm14.x - 14;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 8;
			posArm13.y = posArm12.y + 8;
			posArm14.y = posArm13.y + 6;
			hand_down.y = posArm14.y + 2;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm15);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm15);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm14);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm13);
		}
		else if (cd < 0)
		{
			posArm1.x = posArm0.x;
			posArm2.x = posArm1.x;
			posArm3.x = posArm2.x;
			posArm4.x = posArm3.x - 2;
			position.x = posArm4.x - 14;

			posArm1.y = posArm0.y - 8;
			posArm2.y = posArm1.y - 8;
			posArm3.y = posArm2.y - 8;
			posArm4.y = posArm3.y - 8;
			position.y = posArm4.y - 4;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm0);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm0);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm0);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm8);

			posArm11.x = posArm10.x;
			posArm12.x = posArm11.x;
			posArm13.x = posArm12.x;
			posArm14.x = posArm13.x - 2;
			hand_down.x = posArm14.x - 14;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 8;
			posArm13.y = posArm12.y + 8;
			posArm14.y = posArm13.y + 8;
			hand_down.y = posArm14.y + 4;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm15);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm15);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm15);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm14);
		}
		else if (cd < 5)
		{
			posArm1.x = posArm0.x;
			posArm2.x = posArm1.x;
			posArm3.x = posArm2.x;
			posArm4.x = posArm3.x;
			position.x = posArm4.x - 12;

			posArm1.y = posArm0.y - 8;
			posArm2.y = posArm1.y - 8;
			posArm3.y = posArm2.y - 8;
			posArm4.y = posArm3.y - 8;
			position.y = posArm4.y - 4;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm0);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm0);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm0);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm0);

			posArm11.x = posArm10.x;
			posArm12.x = posArm11.x;
			posArm13.x = posArm12.x;
			posArm14.x = posArm13.x;
			hand_down.x = posArm14.x - 12;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 8;
			posArm13.y = posArm12.y + 8;
			posArm14.y = posArm13.y + 8;
			hand_down.y = posArm14.y + 4;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm15);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm15);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm15);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm15);
		}
		else if (cd < 10)
		{
			posArm1.x = posArm0.x;
			posArm2.x = posArm1.x;
			posArm3.x = posArm2.x;
			posArm4.x = posArm3.x + 2;
			position.x = posArm4.x - 10;

			posArm1.y = posArm0.y - 8;
			posArm2.y = posArm1.y - 8;
			posArm3.y = posArm2.y - 8;
			posArm4.y = posArm3.y - 8;
			position.y = posArm4.y - 4;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm0);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm0);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm0);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm1);

			posArm11.x = posArm10.x;
			posArm12.x = posArm11.x;
			posArm13.x = posArm12.x;
			posArm14.x = posArm13.x + 2;
			hand_down.x = posArm14.x - 10;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 8;
			posArm13.y = posArm12.y + 8;
			posArm14.y = posArm13.y + 8;
			hand_down.y = posArm14.y + 4;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm15);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm15);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm15);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm7);
		}
		else if (cd < 15)
		{
			posArm1.x = posArm0.x;
			posArm2.x = posArm1.x;
			posArm3.x = posArm2.x + 2;
			posArm4.x = posArm3.x + 4;
			position.x = posArm4.x - 7;

			posArm1.y = posArm0.y - 8;
			posArm2.y = posArm1.y - 8;
			posArm3.y = posArm2.y - 8;
			posArm4.y = posArm3.y - 6;
			position.y = posArm4.y - 2;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm0);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm0);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm1);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm2);

			posArm11.x = posArm10.x;
			posArm12.x = posArm11.x;
			posArm13.x = posArm12.x + 2;
			posArm14.x = posArm13.x + 4;
			hand_down.x = posArm14.x - 7;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 8;
			posArm13.y = posArm12.y + 8;
			posArm14.y = posArm13.y + 6;
			hand_down.y = posArm14.y + 2;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm15);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm15);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm7);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm6);

		}
		else if (cd < 20)
		{
			posArm1.x = posArm0.x;
			posArm2.x = posArm1.x + 2;
			posArm3.x = posArm2.x + 4;
			posArm4.x = posArm3.x + 6;
			position.x = posArm4.x - 5;

			posArm1.y = posArm0.y - 8;
			posArm2.y = posArm1.y - 8;
			posArm3.y = posArm2.y - 6;
			posArm4.y = posArm3.y - 4;
			position.y = posArm4.y;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm0);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm1);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm2);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm3);

			posArm11.x = posArm10.x;
			posArm12.x = posArm11.x + 2;
			posArm13.x = posArm12.x + 4;
			posArm14.x = posArm13.x + 6;
			hand_down.x = posArm14.x - 5;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 8;
			posArm13.y = posArm12.y + 6;
			posArm14.y = posArm13.y + 4;
			hand_down.y = posArm14.y;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm15);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm7);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm6);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm5);
		}
		else if (cd < 25)
		{
			posArm1.x = posArm0.x + 2;
			posArm2.x = posArm1.x + 4;
			posArm3.x = posArm2.x + 6;
			posArm4.x = posArm3.x + 8;
			position.x = posArm4.x - 3;

			posArm1.y = posArm0.y - 8;
			posArm2.y = posArm1.y - 6;
			posArm3.y = posArm2.y - 4;
			posArm4.y = posArm3.y - 1;
			position.y = posArm4.y - 1;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm1);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm2);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm3);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm4);

			posArm11.x = posArm10.x + 2;
			posArm12.x = posArm11.x + 4;
			posArm13.x = posArm12.x + 6;
			posArm14.x = posArm13.x + 8;
			hand_down.x = posArm14.x - 3;

			posArm11.y = posArm10.y + 8;
			posArm12.y = posArm11.y + 6;
			posArm13.y = posArm12.y + 4;
			posArm14.y = posArm13.y + 1;
			hand_down.y = posArm14.y - 1;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm7);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm6);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm5);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm4);

		}

		else if (cd < 30)
		{
			posArm1.x = posArm0.x + 2;
			posArm2.x = posArm1.x + 6;
			posArm3.x = posArm2.x + 9;
			posArm4.x = posArm3.x + 9;
			position.x = posArm4.x - 1;

			posArm1.y = posArm0.y - 6;
			posArm2.y = posArm1.y - 3;
			posArm3.y = posArm2.y;
			posArm4.y = posArm3.y + 2;
			position.y = posArm4.y + 4;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm1);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm3);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm4);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm5); // no es veu


			posArm11.x = posArm10.x + 2;
			posArm12.x = posArm11.x + 6;
			posArm13.x = posArm12.x + 9;
			posArm14.x = posArm13.x + 9;
			hand_down.x = posArm14.x - 3;

			posArm11.y = posArm10.y + 6;
			posArm12.y = posArm11.y + 8;
			posArm13.y = posArm12.y + 2;
			posArm14.y = posArm13.y - 3;
			hand_down.y = posArm14.y - 4;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm7);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm5);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm4);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm3);
		}

		else if (cd < 35)
		{
			posArm1.x = posArm0.x + 2;
			posArm2.x = posArm1.x + 6;
			posArm3.x = posArm2.x + 9;
			posArm4.x = posArm3.x + 7;
			position.x = posArm4.x - 5;

			posArm1.y = posArm0.y - 7;
			posArm2.y = posArm1.y;
			posArm3.y = posArm2.y + 1;
			posArm4.y = posArm3.y + 2;
			position.y = posArm4.y + 6;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm2);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm4);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm5);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm6);

			posArm11.x = posArm10.x + 2;
			posArm12.x = posArm11.x + 6;
			posArm13.x = posArm12.x + 9;
			posArm14.x = posArm13.x + 7;
			hand_down.x = posArm14.x - 5;

			posArm11.y = posArm10.y + 9;
			posArm12.y = posArm11.y + 4;
			posArm13.y = posArm12.y - 3;
			posArm14.y = posArm13.y - 4;
			hand_down.y = posArm14.y - 4;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm6);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm4);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm3);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm2);
		}

		else if (cd < 40)
		{
			posArm1.x = posArm0.x + 2;
			posArm2.x = posArm1.x + 6;
			posArm3.x = posArm2.x + 9;
			posArm4.x = posArm3.x + 7;
			position.x = posArm4.x - 8;

			posArm1.y = posArm0.y - 7;
			posArm2.y = posArm1.y;
			posArm3.y = posArm2.y + 4;
			posArm4.y = posArm3.y + 7;
			position.y = posArm4.y + 7;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm2);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm5);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm6);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm7);

			posArm11.x = posArm10.x + 2;
			posArm12.x = posArm11.x + 6;
			posArm13.x = posArm12.x + 9;
			posArm14.x = posArm13.x + 7;
			hand_down.x = posArm14.x - 8;

			posArm11.y = posArm10.y + 9;
			posArm12.y = posArm11.y + 2;
			posArm13.y = posArm12.y - 5;
			posArm14.y = posArm13.y - 9;
			hand_down.y = posArm14.y - 5;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm6);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm3);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm2);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm1);
		}
		else if (cd >= 40)
		{
			cd = 39;

			posArm1.x = posArm0.x + 2;
			posArm2.x = posArm1.x + 6;
			posArm3.x = posArm2.x + 9;
			posArm4.x = posArm3.x + 7;
			position.x = posArm4.x - 8;

			posArm1.y = posArm0.y - 7;
			posArm2.y = posArm1.y;
			posArm3.y = posArm2.y + 4;
			posArm4.y = posArm3.y + 7;
			position.y = posArm4.y + 5;

			App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
			App->render->Blit(graphics, posArm1.x, posArm1.y, &arm2);
			App->render->Blit(graphics, posArm2.x, posArm2.y, &arm5);
			App->render->Blit(graphics, posArm3.x, posArm3.y, &arm6);
			App->render->Blit(graphics, posArm4.x, posArm4.y, &arm7);

			posArm11.x = posArm10.x + 2;
			posArm12.x = posArm11.x + 6;
			posArm13.x = posArm12.x + 9;
			posArm14.x = posArm13.x + 7;
			hand_down.x = posArm14.x - 8;

			posArm11.y = posArm10.y + 9;
			posArm12.y = posArm11.y + 2;
			posArm13.y = posArm12.y - 5;
			posArm14.y = posArm13.y - 9;
			hand_down.y = posArm14.y - 5;

			App->render->Blit(graphics, posArm10.x, posArm10.y, &arm15);
			App->render->Blit(graphics, posArm11.x, posArm11.y, &arm6);
			App->render->Blit(graphics, posArm12.x, posArm12.y, &arm3);
			App->render->Blit(graphics, posArm13.x, posArm13.y, &arm2);
			App->render->Blit(graphics, posArm14.x, posArm14.y, &arm1);
		}

		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || App->input->controller[BUTTON_A] == KEY_STATE::KEY_DOWN)
		{
			if (App->player->wave == false)
			{
				App->particles->AddParticle(App->particles->tentacle_shot, position.x + 38, position.y + 6, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->tentacle_shot, hand_down.x + 38, hand_down.y + 6, COLLIDER_PLAYER_SHOT);
				/*App->audio->PlaySoundEffect(shot_particle);*/
			}
			if (App->player->wave == true)
			{
				App->particles->speed_waves(position);
				App->particles->AddParticle(App->particles->waves_shot, position.x + 12, position.y + 6, COLLIDER_PLAYER_SHOT);
				App->particles->speed_waves(hand_down);
				App->particles->AddParticle(App->particles->waves_shot, hand_down.x + 12, hand_down.y + 6, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(basic_shot);
			}
			
			
		}
	}
	colArm0->SetPos(posArm0.x, posArm0.y);
	colArm1->SetPos(posArm1.x, posArm1.y);
	colArm2->SetPos(posArm2.x, posArm2.y);
	colArm3->SetPos(posArm3.x, posArm3.y);
	colArm4->SetPos(posArm4.x, posArm4.y);
	colArm10->SetPos(posArm10.x, posArm10.y);
	colArm11->SetPos(posArm11.x, posArm11.y);
	colArm12->SetPos(posArm12.x, posArm12.y);
	colArm13->SetPos(posArm13.x, posArm13.y);
	colArm14->SetPos(posArm14.x, posArm14.y);
}