#include "Actor.h"

#include "Game.h"

Actor::Actor(Game* game) : mState(EActive), mGame(game) {
  mGame->AddActor(this);
}

Actor::~Actor() {
  mGame->RemoveActor(this);
  while (!mComponents.empty()) {
    delete mComponents.back();
  }
}

void Actor::Update(float deltaTime) {
  if (mState == EActive) {
    UpdateComponents(deltaTime);
    UpdateActor(deltaTime);
  }
}

void Actor::UpdateComponents(float deltaTime) {
  for (auto comp : mComponents) {
    // comp->Update(deltaTime);
  }
}

void Actor::UpdateActor(float deltaTime) {}
