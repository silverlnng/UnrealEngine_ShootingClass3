// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "PlayerPawn.generated.h"

class UInputMappingContext;
class UInputAction;

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = Input)
	UInputMappingContext* PlayerMappingContext;
	// �����ϰ� ������ Input Mapping Context ��  �����Ϳ��� �Ҵ�  "Category = Input"

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAxis;
	// �����ϰ� ������ InputAction  ��  �����Ϳ��� �Ҵ�  "Category = Input"

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* fireInputAsset;


	void Move(const FInputActionValue& value);
	void Fire(const FInputActionValue& value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//����� �Է¿� �����ϱ� ���ؼ� ȣ��� 
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* myBoxComp;
	//��ü player��  �ڽ� �浹ü (=�ݸ��� ) ������Ʈ�� �ּ� ����  
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* myMeshComp;
	//�ּҸ� ������ �� 

	UPROPERTY(EditAnywhere)
	class UArrowComponent* firePosition;
	//�ѱ� ����

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AMyBullect> bullectFactory;
	// �Ѿ�Ŭ������ ��ӹ޾� ���� �������Ʈ �� ������ ���� �����Ű�� 
	// <Ŭ����> ���� ������ ���� = Ŭ������ ��Ʈ �� �����ϱ�

};
