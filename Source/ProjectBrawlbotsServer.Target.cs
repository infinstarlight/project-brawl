// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class ProjectBrawlbotsServerTarget : TargetRules
{
    public ProjectBrawlbotsServerTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Server;
        //DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("ProjectBrawlbots");
    }
}





