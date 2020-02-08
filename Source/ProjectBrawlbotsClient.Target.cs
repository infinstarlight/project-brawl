// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProjectBrawlbotsTarget : TargetRules
{
    public ProjectBrawlbotsTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Client;
        
        ExtraModuleNames.Add("ProjectBrawlbots");
    }
}
