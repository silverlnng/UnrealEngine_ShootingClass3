// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBullect.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyBullect::AMyBullect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mySphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("MySphereComponent"));
	//myBoxComp �� ���������Ʈ �����ϱ� �Լ�(�𸮾����� �Լ�)
	SetRootComponent(mySphereComp);
	const float Radius = 6.0f;
	mySphereComp->SetSphereRadius(Radius);


	myMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshCompo"));
	
	myMeshComp->SetupAttachment(mySphereComp);
	const FVector Position = FVector(0, 0, -5.0f);
	const float Scale = 0.1f;
	myMeshComp->SetRelativeLocation(Position);
	myMeshComp->SetAllMassScale(Scale);


}

// Called when the game starts or when spawned
void AMyBullect::BeginPlay()
{
	Super::BeginPlay();
	
}

//�Ѿ��� �÷��̾ ����  ���ϴ� ��ġ�� �����ǰ� ������ ���󰡱⸸ �ϸ�� 
// Called every frame
void AMyBullect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//tick�� ���Ǹ� �ؼ� �������ڸ��� + ��� �����̵��� ����
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * 100 * GetWorld()->GetDeltaSeconds());
}

//enemy �� �浹�� ���� 

