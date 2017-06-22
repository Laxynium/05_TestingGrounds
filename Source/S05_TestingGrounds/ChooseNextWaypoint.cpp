// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	/*
		1)Find patrol route
		2)Set next waypoint
		3)Cycle index
	*/
	auto blackboardComponent=OwnerComp.GetBlackboardComponent();
	auto index = blackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);



	return EBTNodeResult::Succeeded;
}
