// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class SHOOTINGPROJECT3_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void TracePlayerMove();
	void Fire();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	class UBoxComponent* myBoxComp;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* myMeshComp;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* firePosition;
	//총구 선언

	UPROPERTY(EditAnywhere)
	float moveSpeed;

	UPROPERTY(EditAnywhere)
	int32 traceRate;

	bool tracePlayer;


	UPROPERTY(EditAnywhere)
	TSubclassOf<class AMyBullect> bullectFactory;
	
	UPROPERTY(EditAnywhere)
	float fireCoolTime;

	UPROPERTY(EditAnywhere)
	class USoundBase* firesound;

private:
	UPROPERTY(VisibleAnywhere)
	float currentTime;

	//회전각도
	UPROPERTY(VisibleAnywhere)
	FVector dir;

};
