// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProjectBrawlServerTarget : TargetRules
{
	public ProjectBrawlServerTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
        
        ExtraModuleNames.AddRange( new string[] { "ProjectBrawl" } );
	}
}
