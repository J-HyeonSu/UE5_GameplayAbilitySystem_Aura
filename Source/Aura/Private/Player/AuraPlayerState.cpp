// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	/*
	 * Replication Mode
	 * Full(SinglePlayer) - Gameplay Effects are replicated to all clients
	 * Mixed(Multiplayer, Player-Controlled) - Gameplay Effects are replicated to the owning client only.
	 * Gameplay Cues and Gameplay Tags replicated to all clients.
	 * Minimal(Multiplayer, AI-COntrolled) - Gameplay Effects are not replicated.
	 * Gameplay Cues and Gameplay Tags replicated to all clients.
	 */

	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	
	//서버가 클라이언트 업데이트 시도 빈도
	NetUpdateFrequency = 100.f;
	//더 빨리 업데이트하기위해
	
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
