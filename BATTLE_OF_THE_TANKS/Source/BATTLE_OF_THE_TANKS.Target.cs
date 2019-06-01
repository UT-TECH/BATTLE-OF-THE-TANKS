// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BATTLE_OF_THE_TANKSTarget : TargetRules
{
	public BATTLE_OF_THE_TANKSTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "BATTLE_OF_THE_TANKS" } );
	}
}
