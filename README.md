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