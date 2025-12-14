// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class CouchGame2025 : ModuleRules
{
    public CouchGame2025(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
            
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "MultiplayerModule", "CableComponentBis", "DeveloperSettings"});


        PrivateIncludePaths.AddRange(new string[]
        {
            "CouchGame2025/Runtime/Private/",
            "CouchGame2025/Editor/Private/",
        });

        PublicIncludePaths.AddRange(new string[]
        {
           "CouchGame2025/Runtime/Public/",
           "CouchGame2025/Editor/Public/",
        });
    }
}
