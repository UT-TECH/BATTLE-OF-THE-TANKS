// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BATTLE_OF_THE_TANKSEditorTarget : TargetRules
{
	public BATTLE_OF_THE_TANKSEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "BATTLE_OF_THE_TANKS" } );
	}
}
