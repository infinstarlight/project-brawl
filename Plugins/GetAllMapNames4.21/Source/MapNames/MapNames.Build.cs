// Some copyright should be here...

using UnrealBuildTool;

public class MapNames : ModuleRules
{

public MapNames(ReadOnlyTargetRules Target) : base(Target)
{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        {
		
		PublicIncludePaths.AddRange(
			new string[] {
				"MapNames/Public"
				
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"MapNames/Private",
				
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",

				// ... add private dependencies that you statically link with here ...	
			}
			);
		}
	}
}