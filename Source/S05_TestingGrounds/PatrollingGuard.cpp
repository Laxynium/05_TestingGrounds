// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "PatrollingGuard.h"

const TArray<AActor*>& APatrollingGuard::PatrolPoints()const
{
	return patrolPoints;
}


