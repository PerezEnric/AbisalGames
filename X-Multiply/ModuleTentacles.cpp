#include "ModuleTentacles.h"
#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"


ModuleTentacles::ModuleTentacles()
{
	graphics = nullptr;
	current_animation = nullptr;


	// idle animation
	tentacl.PushBack({ 817, 746, 19, 9 });
	tentacl.PushBack({ 849, 747, 19, 7 });
	tentacl.PushBack({ 881, 748, 19, 6 });
	tentacl.PushBack({ 913, 748, 19, 7 });
	tentacl.speed = 0.2f;

	/*tentaclearm.PushBack({ 733,747,4,11 }); *///vertical - 0
	//toptentacle.PushBack({ 748,747,7,10 }); //1st front - 1 
	//toptentacle.PushBack({ 763,748,9,8 });  //2nd front - 2
	//toptentacle.PushBack({ 778,749,10,6 }); //3rd front - 3
	//toptentacle.PushBack({ 794, 750,11,4 }); //horitzontal front - 4
	//toptentacle.PushBack({ 215,37,10,6 }); //5st front down - 5
	//toptentacle.PushBack({ 200,36,9,8 }); //6st front - 6
	//toptentacle.PushBack({ 186,35,7,10 }); //7st front - 7
	//toptentacleback.PushBack({ 913,763,7,10 }); //1st back - 8
	//toptentacleback.PushBack({ 927,764,9,8 }); //2nd back - 9
	//toptentacleback.PushBack({ 942,765,10,6 }); //3rd back - 10
	//toptentacleback.PushBack({ 939,824,11,4 }); //horitzontal back - 11
	//toptentacle.PushBack({ 211,77,10,6 }); //5st back - 12
	//toptentacle.PushBack({ 227,76,9,8 }); //6st back - 13
	//toptentacle.PushBack({ 243,75,7,10 }); //7st back - 14

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
	arm5.x = 215;
	arm5.y = 37;
	arm5.w = 10;
	arm5.h = 6;
	//6st front - 6
	arm6.x = 200;
	arm6.y = 36;
	arm6.w = 9;
	arm6.h = 8;
	//7st front - 7
	arm7.x = 186;
	arm7.y = 35;
	arm7.w = 7;
	arm7.h = 10;
	//1st back - 8
	arm8.x = 913;
	arm8.y = 763;
	arm8.w = 7;
	arm8.h = 10;
	//2nd back - 9
	arm9.x = 927;
	arm9.y = 764;
	arm9.w = 9;
	arm9.h = 8;
	//3rd back - 10
	arm10.x = 942;
	arm10.y = 765;
	arm10.w = 10;
	arm10.h = 6;
	//horitzontal back - 11
	arm11.x = 939;
	arm11.y = 824;
	arm11.w = 11;
	arm11.h = 4;
	//5st back - 12
	arm12.x = 211;
	arm12.y = 77;
	arm12.w = 10;
	arm12.h = 6;
	//6st back - 13
	arm13.x = 227;
	arm13.y = 76;
	arm13.w = 9;
	arm13.h = 8;
	//7st back - 14
	arm14.x = 243;
	arm14.y = 75;
	arm14.w = 7;
	arm14.h = 10;
	
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

	posArm0.y = App->player->position.y - 8;
	posArm1.y = App->player->position.y - 16;
	posArm2.y = App->player->position.y - 24;
	posArm3.y = App->player->position.y - 32;
	posArm4.y = App->player->position.y - 40;
	posArm0.x = posArm1.x = posArm2.x = posArm3.x = posArm4.x = App->player->position.x;
	return true;
}

bool ModuleTentacles::CleanUp()
{
	graphics = nullptr;
	return true;
}

update_status ModuleTentacles::Update()
{
	hand_down.x = position.x;
	
	limitTentacles();//tentacle limits

	/*current_animationTentacle = &toptentacle;
	if (gofront == true)
	{
		current_animationTentacle = &toptentacle;
		toptentacleback.Reset();
	}

	else if (goback == true)
	{
		current_animationTentacle = &toptentacleback;
		toptentacle.Reset();
	}*/
	posArm0.x = posArm1.x = posArm2.x = posArm3.x = posArm4.x = App->player->position.x + 10;
	posArm0.y = App->player->position.y - 8;
	posArm1.y = App->player->position.y - 16;
	posArm2.y = App->player->position.y - 24;
	posArm3.y = App->player->position.y - 32;
	posArm4.y = App->player->position.y - 40;



	movetentacle();
	current_animation = &tentacl;
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	App->render->Blit(graphics, hand_down.x, hand_down.y, &(current_animation->GetCurrentFrame()));
	return UPDATE_CONTINUE;
}

void ModuleTentacles::limitTentacles()
{
	int limit = 43;
	
	if (position.y > App->player->position.y)
	{
		position.y = App->player->position.y;
	}
	if (position.y < App->player->position.y - limit)
	{
		position.y = App->player->position.y - limit;
	}
	if (position.x < App->player->position.x - limit)
	{
		position.x = App->player->position.x - limit;
		
	}
	if (position.x > App->player->position.x + limit)
	{
		position.x = App->player->position.x + limit;
	}

	if (hand_down.y < App->player->position.y)
	{
		hand_down.y = App->player->position.y;
	}
	if (hand_down.y > App->player->position.y + limit)
	{
		hand_down.y = App->player->position.y + limit;
	}
	if (hand_down.x < App->player->position.x - limit)
	{
		hand_down.x = App->player->position.x - limit;

	}
	if (hand_down.x > App->player->position.x + limit)
	{
		hand_down.x = App->player->position.x + limit;
	}
}

void ModuleTentacles::movetentacle()
{
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		cd++;
	}
	else if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		cd--;
	}
	/*else if (cd < 0)
	{
		cd += 0.5;
	}*/
	else if (cd > 0)
	{
		cd -= 0.5;
	}

	if (cd < -40)
	{
		cd = -39;
	}
	else if (cd < -35)
	{
		posArm1.x = posArm0.x;
		posArm2.x = posArm1.x;
		posArm3.x = posArm2.x;
		posArm4.x = posArm3.x;
		position.x = posArm4.x - 4;
		position.x = posArm4.x - 12;

		posArm1.y = posArm0.y - 8;
		posArm2.y = posArm1.y - 8;
		posArm3.y = posArm2.y - 8;
		posArm4.y = posArm3.y - 8;
		position.y = posArm4.y - 4;
		position.y = posArm4.y + 4;

		App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
		App->render->Blit(graphics, posArm1.x, posArm1.y, &arm9);
		App->render->Blit(graphics, posArm2.x, posArm2.y, &arm12); // no es veu
		App->render->Blit(graphics, posArm3.x, posArm3.y, &arm13); // no es veu
		App->render->Blit(graphics, posArm4.x, posArm4.y, &arm14); // no es veu

	}
	else if (cd < -30) 
	{
		posArm1.x = posArm0.x;
		posArm2.x = posArm1.x;
		posArm3.x = posArm2.x;
		posArm4.x = posArm3.x;
		position.x = posArm4.x - 14;

		posArm1.y = posArm0.y - 8;
		posArm2.y = posArm1.y - 8;
		posArm3.y = posArm2.y - 8;
		posArm4.y = posArm3.y - 8;
		position.y = posArm4.y + 2;

		App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
		App->render->Blit(graphics, posArm1.x, posArm1.y, &arm9);
		App->render->Blit(graphics, posArm2.x, posArm2.y, &arm11);
		App->render->Blit(graphics, posArm3.x, posArm3.y, &arm12); // no es veu
		App->render->Blit(graphics, posArm4.x, posArm4.y, &arm13); // no es veu

	}
	else if (cd < -25)
	{
		posArm1.x = posArm0.x - 3;
		posArm2.x = posArm1.x - 7;
		posArm3.x = posArm2.x - 11;
		posArm4.x = posArm3.x - 11;
		position.x = posArm4.x - 16;

		posArm1.y = posArm0.y - 6;
		posArm2.y = posArm1.y - 3;
		posArm3.y = posArm2.y;
		posArm4.y = posArm3.y + 2;
		position.y = posArm4.y;

		App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
		App->render->Blit(graphics, posArm1.x, posArm1.y, &arm8);
		App->render->Blit(graphics, posArm2.x, posArm2.y, &arm10);
		App->render->Blit(graphics, posArm3.x, posArm3.y, &arm11);
		App->render->Blit(graphics, posArm4.x, posArm4.y, &arm12); // no es veu

	}
	else if (cd < -20)
	{
		posArm1.x = posArm0.x - 3;
		posArm2.x = posArm1.x - 6;
		posArm3.x = posArm2.x - 9;
		posArm4.x = posArm3.x - 11;
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
	}
	else if (cd < -15)
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
	}
	else if (cd < -10)
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
	}
	else if (cd < -5)
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
		
	}
	else if(cd < 15)
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
		position.y = posArm4.y + 1;

		App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
		App->render->Blit(graphics, posArm1.x, posArm1.y, &arm1);
		App->render->Blit(graphics, posArm2.x, posArm2.y, &arm2);
		App->render->Blit(graphics, posArm3.x, posArm3.y, &arm3);
		App->render->Blit(graphics, posArm4.x, posArm4.y, &arm4);

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
	
	}

	else if (cd < 35)
	{
		posArm1.x = posArm0.x ;
		posArm2.x = posArm1.x ;
		posArm3.x = posArm2.x ;
		posArm4.x = posArm3.x ;
		position.x = posArm4.x + 1;

		posArm1.y = posArm0.y - 8;
		posArm2.y = posArm1.y - 8;
		posArm3.y = posArm2.y - 8;
		posArm4.y = posArm3.y - 8;
		position.y = posArm4.y + 6;

		App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
		App->render->Blit(graphics, posArm1.x, posArm1.y, &arm2);
		App->render->Blit(graphics, posArm2.x, posArm2.y, &arm4);
		App->render->Blit(graphics, posArm3.x, posArm3.y, &arm5); // no es veu
		App->render->Blit(graphics, posArm4.x, posArm4.y, &arm6); // no es veu
	}

	else if (cd < 40)
	{
		posArm1.x = posArm0.x;
		posArm2.x = posArm1.x;
		posArm3.x = posArm2.x;
		posArm4.x = posArm3.x;
		position.x = posArm4.x + 3;

		posArm1.y = posArm0.y - 8;
		posArm2.y = posArm1.y - 8;
		posArm3.y = posArm2.y - 8;
		posArm4.y = posArm3.y - 8;
		position.y = posArm4.y + 8;

		App->render->Blit(graphics, posArm0.x, posArm0.y, &arm0);
		App->render->Blit(graphics, posArm1.x, posArm1.y, &arm2);
		App->render->Blit(graphics, posArm2.x, posArm2.y, &arm5); // no es veu
		App->render->Blit(graphics, posArm3.x, posArm3.y, &arm6); // no es veu
		App->render->Blit(graphics, posArm4.x, posArm4.y, &arm7); // no es veu
	}
	else if (cd >= 40)
	{
		cd = 39;
	}
}