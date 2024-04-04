// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "YangGeunsoo_TestCharacter.generated.h"


UCLASS(config=Game)
class AYangGeunsoo_TestCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/** Zoom Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ZoomAction;

	/** Aim Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* AimAction;

	/** Perspective Change Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* PerspectiveChangeAction;

	/** Variables */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
	float MinZoomLength = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
	float MaxZoomLength = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables, meta = (AllowPrivateAccess = "true"))
	float ZoomStep = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Variables, meta = (AllowPrivateAccess = "true"))
	bool IsAiming;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Variables, meta = (AllowPrivateAccess = "true"))
	bool IsFirstPerson;

public:
	AYangGeunsoo_TestCharacter();
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for Zoom input */
	void Zoom(const FInputActionValue& Value);

	/** Called for Aim input */
	void StartAiming(const FInputActionValue& Value);

	void StopAiming(const FInputActionValue& Value);

	/** Called for Perspective Change input */
	void PerspectiveChange(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

