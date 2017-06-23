// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrollingGuard.h"
#include "AIController.h"
#include "PatrolRoute.h"
EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto patrolRouteComp = FindPatrolRoute(OwnerComp);
	if (ensure(patrolRouteComp==nullptr))return EBTNodeResult::Failed;

	auto patrolPoints = patrolRouteComp->PatrolPoints();

	if  (ensure(patrolPoints.Num()==0))return EBTNodeResult::Failed;

	auto blackboardComponent=OwnerComp.GetBlackboardComponent();
	auto index = blackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);

	if(patrolPoints.IsValidIndex(index))
	blackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, patrolPoints[index]);
	
	blackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, (++index)%patrolPoints.Num());

	return EBTNodeResult::Succeeded;
}

UPatrolRoute* UChooseNextWaypoint::FindPatrolRoute(UBehaviorTreeComponent & OwnerComp)
{
	return  OwnerComp.GetAIOwner()->GetControlledPawn()->FindComponentByClass<UPatrolRoute>();
}
