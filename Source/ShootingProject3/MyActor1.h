// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor1.generated.h"

UCLASS()
class SHOOTINGPROJECT3_API AMyActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	// 생성자
	AMyActor1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//수정과 재정의 는 다름
	// 수정은 원본을 건드림 => 부모 것을 건드리는 것
	// 재정의는 원래 내용이 없던것의 내용을 정의 해주는 것

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int32 number1 = 10;

	UPROPERTY(VisibleAnywhere);
	float number2 = 1.23456f;
	//UPROPERTY(EditinstanceOnly); : 프로퍼티 창에서 편집할수있음, 원본이 아니라 인스턴스 의
	UPROPERTY(EditinstanceOnly);
	FString myname = "Unreal";
	// string은  => const char[] 
	//

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Damage")
	int32 Damage=10;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Damage")
	int32 Damage2=10;

	void InitializeDamages();

};
