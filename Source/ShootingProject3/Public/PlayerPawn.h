// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class UInputMappingContext;

UCLASS()
class SHOOTINGPROJECT3_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveFourWay(float value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = Input)
	UInputMappingContext* PlayerMappingContext;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* myBoxComp;
	//��ü player��  �ڽ� �浹ü (=�ݸ��� ) ������Ʈ�� �ּ� ����  
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* myMeshComp;
	//�ּҸ� ������ �� 



};
