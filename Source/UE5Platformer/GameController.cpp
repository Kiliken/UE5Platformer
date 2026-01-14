// Fill out your copyright notice in the Description page of Project Settings.

#include "GameController.h"
#include "imgui.h"

// Sets default values
AGameController::AGameController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGameController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (g_showMenu)
		ShowMenuWindow();
	
}

void AGameController::ShowMenuWindow(){

	ImGuiIO& io = ImGui::GetIO();

    // Calculate center of the screen
    ImVec2 center = ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f);

    // Set next window position to center, with pivot at the center
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    // Optionally set fixed size (so user can’t resize)
    ImGui::SetNextWindowSize(ImVec2(400.0f, 250.0f), ImGuiCond_Always);

    // Window flags: no resize, no move, no collapse, no title bar (optional)
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoSavedSettings;

    ImGui::Begin("Centered Menu", nullptr, flags);

    ImGui::Text("This is a centered, locked menu.");
    ImGui::Separator();
    ImGui::Text("You can add your controls here.");
	ImGui::Separator();

    if(ImGui::Button("QUIT")) UE_LOG(LogTemp, Log, TEXT("QUIT"));

    ImGui::End();
}
