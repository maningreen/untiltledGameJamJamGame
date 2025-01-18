#include "include.h"
#include "powerup.h"
#include "missile.h"
#include "circle.h"
#include "enemy.h"
#include <stdlib.h> //for big number

short shouldDropPowerup() {
  return randSingle() <= powerUpChance ? rand() % 1 == 0 ? deadeyeCode : timeSlowCode : 0; //i'd apologize for the nesting here but i won't
}

void applyPowerup(Missile* misArr, unsigned int misCount, circle* target) {
  while(--misCount > 0)
    misArr[misCount].target = target;
}

int shouldApplyPowerup(Camera2D camera, enemy* enArr, unsigned int enCount) {
  if(enCount == 0)
    return false;
  Vector2 mousePos = Vector2Scale(GetMousePosition(), 1/camera.zoom);
  float distanceSqr = (powerUpDeadeyeGive + enArr[0].body.radius) * (powerUpDeadeyeGive + enArr[0].body.radius);
  unsigned int closestEnemyI = 0; //can't be null or negative /shrug
  float closestEnemyDist = RAND_MAX; //(big number)
  for(unsigned int i = 0; i < enCount; i++) {
    float dist = Vector2DistanceSqr(enArr[i].body.position, mousePos);
    if(dist > closestEnemyDist) //avoid nesting !1!1111 (makes it faster too! (i think (not really i lied)))
      continue;
    closestEnemyDist = dist;
    closestEnemyI = i;
  }
  return closestEnemyDist > distanceSqr ? -1 : closestEnemyI;
}