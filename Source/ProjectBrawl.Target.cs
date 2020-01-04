// Copyright 2020 Property of Digiplay Gaming

using UnrealBuildTool;
using System.Collections.Generic;

public class ProjectBrawlTarget : TargetRules
{
	public ProjectBrawlTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "ProjectBrawl" } );
	}
}
