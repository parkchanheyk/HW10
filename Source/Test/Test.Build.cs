using UnrealBuildTool;

public class Test : ModuleRules
{
	public Test(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		// 헤더(.h)와 소스(.cpp) 모두에서 사용할 필수 모듈 등록
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		// 이 모듈 내부(.cpp)에서만 사용할 모듈이 있다면 여기에 추가 (현재는 비워둠)
		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}