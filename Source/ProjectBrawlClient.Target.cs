// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProjectBrawlClientTarget : TargetRules
{
	public ProjectBrawlClientTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Client;
        //DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.AddRange( new string[] { "ProjectBrawl" } );
	}
}
