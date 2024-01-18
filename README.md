# doingCwork
 1.15 -월 - 수어부터


-----------------------

함수 , 클래스 - 어려움

함수 = Function();

-컴파일 과정 
header(h)
source(cpp)  - > 컴파일 -> 결과?
       	  (전처리)

#define = 매크로.   
ex: #define 정수 int  - > 함수에 있는 정수 a = 0을 int a = 0 으로 바꿔줌

#include
헤더 잘못 만지면 모든 인클루드를 실행시킴
헤더 건들지 말고 소드만 건드는걸 추천

//inline 함수?
-인라인 함수는 호출될 때 일반적인 함수의 호출 과정을 거치지 않고, 
함수의 모든 코드를 호출된 자리에 바로 삽입하는 방식의 함수

-컴파일 속도를 보장하기 위해 헤더와 소스를 나눈다.

언리얼의 규칙 include-what-you-use[IWYU]
ㄴ 헤더는 포인터 선언 , 소스는 그걸 가져다씀

이득우- 언리얼 소스깐 사람

alt + enter ( C++ 자체의 구현)
shift alt q    -   VassitX의 구현

AcodingPawn    (상속)      - myadd 선언 
   ㄴ BP_codingPawn    -	- myadd호출

UML(Unified Modeling Language) 다이어그램 - 상속 구조 

UPROPERTY 안쓰면 블루프린트에서 안보임 <- 매크로 함수

ctrl + atl + f11 = 자동 빌드(언리얼에서)

노드는 결국 함수

BlueprintCallable - 노드 실행핀 o 
BlueprintPure - 노드 실행핀 x
ㄴpublic 도 private도 가능 -> UPROPERTY 이게 더 훨 강력함[리플렉션]

BlueprintImplementableEvent 은 블루프린트에서 구현해야함- 함수
 호출 하려면 UFUNCTION(BlueprintImplementableEvent, BlueprintCallable) - call 같이 사용

BlueprintNativeEvent 부모에서 만들고 자식놈이 재정의 가능( C++ , 블프)

메소드(기능)
ㄴ addcalltoParntFunction

선언만 하고 구현은 따로 UFUNCTION();


레벨 맵에다가도 블프 코딩 가능 - 대신 다른데서 사용 불가능 ( 해당 맵에서만 가능)

레벨에 태어나는 애들은 액터(컴포넌트[기능] 붙여서 씀)
Uobject - 언리얼 객체
 ㄴ 레벨 , 액터, 컴포넌트 다 포함

인스턴스란 객체 지향 프로그래밍(Object Oriented Programming)에서 class에 소속된 개별적인 객체를 말함.

리플렉션-객체를 통해 클래스의 정보를 분석해내는 프로그램 기법.

디컴파일 - 해킹 조심

Uclass 필요한 이유? - 캐스팅( 형 변환)의 근거 자료 _ 형 체크?

CDO(클래스의 기본 객채) - 메모리카피? - 하나하나 만들면 빡세니까 메모리 카피해서 스탬프 팡팡

클래스 생성할때 - 생성자 함수 ( 디폴트 오브젝트 만 씀 _ 나머지는 메모리 카피) - 초기화?
ㄴ 처음 한번 생성할때 만듬.(생성자)


생성자는 엔진이 실행횔떄 호출됨. -> 초기화 ->  이를 통해 CDO가 만들어짐


---슈팅게임 C++ ㄲㄲ---

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
 // EditAnywhere 암대나 쓸 수 있음 _detail,  BlueprintReadOnly 읽기만 가능, BlueprintReadWrite 쓰기도 간으. 
 // read _ get 만 가능. write _ set 만 가능.
	float speed = 500;

//  category 로 언리얼내 구분 가능. _ 변수 관리 용이


// Called every frame
void ABP_player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//오른쪽 방향을 만들고 
	FVector P0 = GetActorLocation();
		//그 방향으로 이동하고싶다.
	FVector v = GetActorRightVector() * speed;
	FVector vt = v * DeltaTime; // DeltaTime = deltaSecond
	FVector newLoc = P0 + vt;
	SetActorLocation(newLoc);
}

};

///-/----//-/--/--/--/--/- 오후 시간

ctrl k c 주석
ctrl k u 주석해제

input binding action axis 차이 action은 안눌러도 값 들어감 axis 은 눌러야 값 들어감

지역변수랑 필드(맴버)면수 다르게 해야함 _ 언리얼 특 : C4458 에러

포인터 -> 원본이 넘어옴

입력 바인딩(액션, axis 두 가지 있음)으로 처리 


0-----------------\1.16-----------///

코디으이 논리적인 측면
문제를 해결하기 위해 목록을 만들고 순서대로 논리적으로 하나씩 해결해간다
사용자의 입력을 받고 그 입력값으로 방향을 만들고 그 방향으로 이동하고 싶다.
Preudo code(의사코드)

생성자 중요*
ㄴ 언리얼의 컴포넌트 , add 역활

컴포넌트를 C++에서 쓸때 U를 붙인다

전방선언

액터
ㄴ 헤더 , ㄴ CPP

RootComponent - C++ attch 할떄
생성자는 언리얼 시작할때 발동하기에 생성자 수정, 선언 할때는 언리얼 끄고 재시작

#pramaons 헤더가 한번만 실행되게

스마트포인터 _ 아라서 맞춰줌

생성자 작어할때는 언리얼 꺼라.

CreateDefaultSuboject - 언리얼 BP내 컴포넌트 추가 생성자, 계층구조 생각해서 써야함

컴포넌트 배치는 생성자 ATailActor::ATailActor() 에 그 외는 거의 다 begin play

액터 만들떄 코딩 순서도 중하다.

클래스가 자기 자신을 호출할떄 this. !

Generate Visual Sutido poreject files - cpp 솔루션 파일 없을떄 클릭

CDS - CreateDefulatSuboboject

this-지역, world_레벨 물어보자

C++ 에서 블루프린트를 생성 할 수 없어서 bulletFactory 생성
//1.16 끝 

------------------------

1.17 수업

UGameplayStatics::PlaySound2D

사운드 입히기, nullptr= 0 ;

PseudoCode
// PseudoCode : 

만약 isAutoFIre ture 라면
시간이 흐르다가 current Time += DeltaSec
     만약 발사시간이 되면 
	MakeBUllet 함수를 호출하고 싶다.
	currentTIme = 0;
{}

ctrl k d  //  주석정리

블루프린트 - > 메모장 -> 블루프린트 _ 복사 붙여넣기 가능

UKismetMathLibrary::RandomIntegerInRange

멀티쓰레드

쓰레드와 프로세스의 차이/?

쓰레드 = 최신 운영체제의 필수요소 중 하나. 프로세스보다도 작은 실행 흐름의 최소 단위.

프로세스 (OS단)
 ㄴ 메인 쓰레드 
    ㄴ 서브 쓰레드
 멀티스레드 -일반적으로 하나의 프로세스는 하나의 스레드를 가지고 작업을 수행하게 됩니다.
하지만 멀티 스레드(multi thread)란 하나의 프로세스 내에서 둘 이상의 스레드가 동시에 작업을 수행하는 것을 의미

오버렙 하나하나 바꾸는건 어려우니 collion -> pj setting - > prest 에서 하나 만들어서 통합적으로 써라

기능- 함수 virtual 찾아라



---1--.18

언리얼 엔진
물리엔진 API

노드 = 함수

Scene Compenet ? 
Actor Component

boxcomp begin overlap 잘 쓴당  
 ㄴ sweap reuslt : impact point _ 특정 부분으로 대미지

법선 백터(노멀) _ 어떤 면의 수직인 벡터

Phys Mat(tiral)

F12 - 정의 찾기? ctrl 이랑 뭐가다름?

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_SixParams( FComponentBeginOverlapSignature, UPrimitiveComponent, OnComponentBeginOverlap, 
UPrimitiveComponent*, OverlappedComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, int32, OtherBodyIndex, bool, bFromSweep, const FHitResult &, SweepResult);
/** Delegate for notification of end of overlap with a specific component */

void OnMyCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

자바 리스너 = C++ 델리게이터

AddDynamic - 자동 완성 안됌

spawn emiiter _ 폭발 처리 (캣캐이드)
캐스캐이드 _ 나이가라라 2개 있음

LogSelectionDetails: Warning: NavigateToFunctionSource:  Unable to find source file and line number for 'UGameplayStatics::SpawnEmitterAtLocation' [지정된 모듈을 찾을 수 없습니다.]
LogSelectionDetails: Warning: NavigateToFunctionSource:  Unable to find source file and line number for 'UGameplayStatics::PlaySound2D' [지정된 모듈을 찾을 수 없습니다.] 

<> = 탬플릿