// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "MyBullect.h"

//헤더에 BoxComponent 가 무엇인지 선언해주기 
//헤더에 많이 넣는다고 성능차이는 안나지만 컴파일러에서 차이가 남 ! 


// 생성자 자리 = 초기화 하는 자리 
// 생성자에서 작성한 내용 반영 된거 볼려면 사용시 반영된걸 볼려면 재빌드를 하기 (=에디터를 껏다가 다시 키고 리빌드 )
// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));
	//myBoxComp 를 서브오브젝트 생성하기 함수(언리얼제공 함수)
	SetRootComponent(myBoxComp);
	//PlayerPawn의 최상단 컴포넌트 정하는 함수 
	//최상단이 액터의 mobility를 결정하게 됨 ! 

	
	const FVector boxsize = FVector(32, 32, 50);
	myBoxComp->SetBoxExtent(boxsize);
	// 박스콜라이더의 extent 를 설정
	// const : 변하지 않을 값 = 성능이 메모리 변수보다 더 빠르다
	// 변하지 않을값으로 , 바꾸려고 하면 바로 에러 발생 

	myMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshCompo"));
	//정적 : 플레이 중에 내용물이 바뀌지 않는다 = 컴퓨터가 알 필요 없다 = 미리 연산
	//동적 : 플레이 중에 내용물이 바뀐다 = 컴퓨터가 알고 있고 주시해야함 
	
	myMeshComp-> SetupAttachment(myBoxComp);
	//SetupAttachment : myMeshComp의 부모를 myBoxComp으로 정함   
	const FVector meshlocation = FVector(0, 0, -50);
	myMeshComp-> SetRelativeLocation(meshlocation);


	// 언리얼에서 애셋 레퍼런스(경로 참조) 는 추천하지 않는 방법
	// mesh의 static mesh 를 정해주는 것
	// ConstructorHelpers : 생성 , 
	//
	//임베이디드 
	//모바일 (사진저장 기능/ 핸드폰의 갤러리 경로에 접근 해야할때)
	//static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshRef(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));

	//if (MeshRef.Succeeded() && MeshRef.Object != nullptr)
	//{
	//	//myMeshComp 는 주소이다 그래서 ->을 사용  
	//	myMeshComp->SetStaticMesh(MeshRef.Object);
	//}
	
	
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowCompo"));
	firePosition->SetupAttachment(myMeshComp);
	//총구생성시키기

	currentTime = 0.0f;
	delayTime = 3.0f;
	timePassed = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PlayerMappingContext, 0);
		}
		
	}

}

void APlayerPawn::Move(const FInputActionValue& value)
{
	const FVector CurrentValue = value.Get<FVector>();
	//여기서 value값은 IA_Move가 Axis으로 설정되있어서 0~1 값을 받는다

	//게임모드의 디폴트 pawn 인지 확인하는 것 
	if (Controller)
	{
		//UE_LOG(LogTemp, Warning, TEXT("%f"), CurrentValue.X);
		//UE_LOG(LogTemp, Warning, TEXT("%f"), CurrentValue.Y);

		SetActorLocation(GetActorLocation() + CurrentValue * 100.0f * GetWorld()->GetDeltaSeconds());
	}

}

void APlayerPawn::Fire(const FInputActionValue& value)
{
	//여기서 총알 블루프린트를  fire position 에 생성시키기
	// fireInputAsset 에서 받은 value값이 온다 .
	// fireInputAsset 은 digital으로 설정으로 value값은 0 또는 1 이다.

	if (Controller && value.Get<bool>() == true && timePassed)
	{
		//여기서 쿨타임을 설정할수있음 !!
		//쏠수있는 상태가 된다면 총알을 발사 
		//총알을 쏘는순간 타이머를 작동시킴 
		//타이머가 일정시간을 지나야 총알을 쏘는게 가능
		AMyBullect* bullect = GetWorld()->SpawnActor<AMyBullect>(bullectFactory, firePosition->GetComponentLocation(), firePosition->GetComponentRotation());
		//GetWorld 는 레벨에서 세상을 의미

		bullectTimerStarted = true;
		currentTime = 0;
	}

}


// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bullectTimerStarted)
	{
		if (currentTime >= delayTime)
		{
			timePassed = true;
		}
		else
		{
			timePassed = false;
			currentTime += DeltaTime;
		}
	}
}


// 인풋 을 바인딩 하는 구역
// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked< UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAxis, ETriggerEvent::Triggered, this, &APlayerPawn::Move);
		EnhancedInputComponent->BindAction(fireInputAsset, ETriggerEvent::Started, this, &APlayerPawn::Fire);

		// ETriggerEvent::Started,Completed ,,등 을 조절해서 바인드 액션을 조절할수있다
		

	}

}

