using UnrealBuildTool;

public class MultiplayerModule : ModuleRules
{
    public MultiplayerModule(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "DeveloperSettings", "EnhancedInput", "InputCore"});
    }
}