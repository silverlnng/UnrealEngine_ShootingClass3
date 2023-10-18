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
	// 선언하고 만들어둔 Input Mapping Context 를  에디터에서 할당  "Category = Input"

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAxis;
	// 선언하고 만들어둔 InputAction  를  에디터에서 할당  "Category = Input"

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* fireInputAsset;


	void Move(const FInputActionValue& value);
	void Fire(const FInputActionValue& value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//기능을 입력에 연결하기 위해서 호출됨 
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* myBoxComp;
	//주체 player의  박스 충돌체 (=콜리전 ) 컴포넌트를 주소 선언  
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* myMeshComp;
	//주소를 선언한 것 

	UPROPERTY(EditAnywhere)
	class UArrowComponent* firePosition;
	//총구 선언

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AMyBullect> bullectFactory;
	// 총알클래스를 상속받아 만든 블루프린트 를 에디터 에서 연결시키기 
	// <클래스> 들의 복수개 모임 = 클래스의 세트 로 생각하기

};
