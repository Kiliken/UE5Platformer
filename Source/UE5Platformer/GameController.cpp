// Fill out your copyright notice in the Description page of Project Settings.

#include "GameController.h"
#include "imgui.h"
#include "ImGuiModule.h"

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

    PC = GetWorld()->GetFirstPlayerController();

    EnableInput(PC);
    InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AGameController::OpenMenu);
}

// Called every frame
void AGameController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    g_timer += DeltaTime;

    ImGuiIO &io = ImGui::GetIO();
    io.WantCaptureKeyboard = g_showMenu;
    io.WantCaptureMouse = g_showMenu;

    ShowTimer();

    if (g_showMenu)
        ShowMenuWindow();
}

void AGameController::OpenMenu()
{
    g_showMenu = !g_showMenu;

    if (g_showMenu)
    {
        FImGuiModule::Get().SetInputMode(true);
    }
    else
    {
        FImGuiModule::Get().SetInputMode(false);
    }
}

void AGameController::ShowMenuWindow()
{
    ImGuiIO &io = ImGui::GetIO();
    // Calculate center of the screen
    ImVec2 center = ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f);

    // Set next window position to center, with pivot at the center
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    // Optionally set fixed size (so user can’t resize)
    ImGui::SetNextWindowSize(ImVec2(400.0f, 125.0f), ImGuiCond_Always);

    // Window flags: no resize, no move, no collapse, no title bar (optional)
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoSavedSettings;

    // Set Style
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.4f, 0.4f, 0.4f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.4f, 0.4f, 0.4f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.5f, 0.5f, 0.5f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.3f, 0.3f, 0.3f, 1.0f));

    ImGui::Begin("MENU", nullptr, flags);

    ImGui::SetWindowFontScale(1.3f);

    // Centered buttons
    float windowWidth = ImGui::GetWindowSize().x;
    float buttonWidth = 200.0f;

    ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);
    if (ImGui::Button("CONTINUE", ImVec2(buttonWidth, 0)))
        OpenMenu();

    ImGui::Separator();

    ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);
    if (ImGui::Button("RESTART", ImVec2(buttonWidth, 0))){
        OpenMenu();
        PC->ConsoleCommand("RestartLevel");
    }
        
    
    ImGui::Separator();

    ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);
    if (ImGui::Button("QUIT", ImVec2(buttonWidth, 0)))
        PC->ConsoleCommand("quit");

    ImGui::End();

    // Restore colors
    ImGui::PopStyleColor(4);
}

void AGameController::ShowTimer()
{

    int totalSeconds = static_cast<int>(g_timer);
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", minutes, seconds);

    ImGuiIO &io = ImGui::GetIO();
    // Calculate center of the screen
    ImVec2 center = ImVec2(io.DisplaySize.x * 0.05f, io.DisplaySize.y * 0.05f);

    // Set next window position to center, with pivot at the center
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    // Optionally set fixed size (so user can’t resize)
    ImGui::SetNextWindowSize(ImVec2(150.0f, 60.0f), ImGuiCond_Always);

    // Window flags: no resize, no move, no collapse, no title bar (optional)
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoSavedSettings;

    // Set Style
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.4f, 0.4f, 0.4f, 1.0f));

    ImGui::Begin("TIME", nullptr, flags);

    float windowWidth = ImGui::GetWindowSize().x;
    float textWidth = 100.0f;

    ImGui::SetWindowFontScale(1.3f);

    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::Text("%s", buffer, ImVec2(textWidth, 0));

    ImGui::End();

    // Restore colors
    ImGui::PopStyleColor(1);
}
