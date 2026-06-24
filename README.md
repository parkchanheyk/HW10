# 🎮 UE5 프로젝트: 모듈(Module) 및 플러그인(Plugin) 수동 구축과 UObject 데이터 관리

---

## 🛠️ 개발 환경
- **Engine**: Unreal Engine 5.5 (C++ 템플릿)
- **IDE**: Rider
- **Development Configuration**: Development Editor

---

## 🚀 핵심 구현 기능

### 1. 새 프로젝트 및 수동 C++ 모듈 (`Test`) 구축
- **Third Person C++ 기반** 프로젝트(`ModuleAndPlugin`) 생성.
- `Source/Test/` 폴더 내부에 모듈 필수 파일인 `Test.Build.cs`, `Test.h`, `Test.cpp` 수동 생성 및 구성.
- `IMPLEMENT_MODULE(FDefaultModuleImpl, Test);` 매크로를 통한 일반 런타임 모듈 선언.

### 2. 빌드 시스템(UBT) 등록 및 연결
- 프로젝트 전체 빌드 타겟 파일인 `*Target.cs` 및 `*Editor.Target.cs` 파일의 `ExtraModuleNames` 배열에 새로 만든 `"Test"` 모듈 등록.
- `ModuleAndPlugin.uproject` 파일의 `Modules` 리스트에 등록하고 `LoadingPhase`를 `PreDefault`로 설정하여 엔진 기본 모듈보다 먼저 로드되도록 제어.
- 타 모듈에서 접근 가능하도록 클래스 이름 앞에 모듈 API 매크로(`TEST_API`) 적용 및 `Build.cs` 의존성(Dependency) 추가.

### 3. 독립 재사용 플러그인 (`Temporary`) 구축
- 프로젝트와 격리되어 독립적으로 재사용 가능한 `Plugins/Temporary/` 구조 수동 설계.
- 플러그인 메타데이터를 담은 JSON 포맷의 `Temporary.uplugin` 파일 작성.
- 모듈 인터페이스(`IModuleInterface`)를 상속받아 플러그인 수명 주기 함수인 `StartupModule` 및 `ShutdownModule` 구현 및 로드 로그 검증.

### 4. [도전 구현] `UObject` 기반 지능형 데이터 매니저 설계
- 무거운 `AActor` 대신 가벼운 **`UObject` 기반의 자식 클래스 `UCharacterData`** 설계로 메모리 최적화 실현.
- 플레이어 캐릭터 클래스의 `BeginPlay()`에서 **`NewObject<T>()`**를 통해 동적 할당하고 수치 및 기능을 스크린 메시지로 검증.

---
