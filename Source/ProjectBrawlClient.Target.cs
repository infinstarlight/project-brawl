// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProjectBrawlClientTarget : TargetRules
{
    public ProjectBrawlClientTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Client;

        ExtraModuleNames.Add("ProjectBrawl");
    }
}
