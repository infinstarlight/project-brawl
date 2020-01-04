// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class ProjectBrawlServerTarget : TargetRules
{
    public ProjectBrawlServerTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Server;
        //bUsesSteam = true;

        ExtraModuleNames.Add("ProjectBrawl");
    }

}

