// Copyright 2020 Property of Digiplay Gaming
using UnrealBuildTool;
using System.Collections.Generic;

public class ProjectBrawlEditorTarget : TargetRules
{
    public ProjectBrawlEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        //PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        //bLegacyPublicIncludePaths = false;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.AddRange(new string[] { "ProjectBrawl" });
    }
}
