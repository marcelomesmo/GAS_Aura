// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);		// Hold exc if condition fails. Equiv. to throw?

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem) Subsystem->AddMappingContext(AuraContext, 0);

	// Handles Mouse
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);		// Crash if cast fails

	// Bind move input actions to the EnhancedInputComponent
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
	// Triggered = OnHold
}

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;		// Send down data updates from the Server down to Clients
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();	// Get hit result under the cursor from PlayerController class
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor =	CursorHit.GetActor();

	/**
	 *	Line trace from cursor. There are several scenarios:
	 *	A. LastActor is null && ThisActor is null
	 *		- No cast on enemy last frame or this frame.
	 *		- Do nothing.
	 *	B. LastActor is null && ThisActor is valid
	 *		- Hovering over this actor for the first time this frame.
	 *		- Call highlight on this actor.
	 *	C. LastActor is valid && ThisActor is null
	 *		- Hovering over an enemy interface last frame, but no longer is over it.
	 *		- Unhighlight LastActor.
	 *	D. LastACtor is valid && ThisActor is valid && LastActor != ThisActor
	 *		- Hovering over an enemy last frame but hovering a new enemy this frame.
	 *		- Highlight ThisActor, Unhighlight LastActor.
	 *	E. Both actor are valid, and are the same actor
	 *		- Hovering over an enemy this frame, and it's the same we hovering last frame.
	 *		- Do nothing.
	 */
	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr) ThisActor->HighlightActor();	// Case B
	}
	else // LastActor is valid
	{
		if (ThisActor == nullptr) LastActor->UnHighlightActor(); // Case C
		else if (LastActor != ThisActor)
		{
			// Case D
			LastActor->UnHighlightActor();
			ThisActor->HighlightActor();
		}
	}
}
