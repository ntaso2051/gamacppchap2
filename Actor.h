#pragma once

#include <vector>

#include "Math.h"

class Actor {
 public:
  enum State { EActive, EPaused, EDead };

  Actor(class Game* game);
  virtual ~Actor();

  void Update(float deltaTime);
  void UpdateComponents(float deltaTime);
  virtual void UpdateActor(float deltaTime);

  State GetState() const { return mState; }
  const Vector2& GetPosition() const { return mPosition; }
  void SetPosition(const Vector2& pos) { mPosition = pos; }
  float GetScale() const { return mScale; }
  void SetScale(float scale) { mScale = scale; }
  float GetRotation() const { return mRotation; }
  void SetRotation(float rotation) { mRotation = rotation; }
  void SetState(State state) { mState = state; }

  class Game* GetGame() {
    return mGame;
  }

  void AddComponent(class Component* component);
  void RemoveComponent(class Component* component);

 protected:
  int mUpdateOrder;
  State mState;
  class Game* mGame;
  std::vector<class Component*> mComponents;

  Vector2 mPosition;
  float mScale;
  float mRotation;
};