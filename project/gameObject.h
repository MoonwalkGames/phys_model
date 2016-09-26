
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm\vec3.hpp>
using glm::vec3;

class GameObject {

public:
	GameObject(){

		obj_Position.x = 0.0f;
		obj_Position.y = 0.0f;
		obj_Position.z = 0.0f;

		obj_Rotation.x = 0.0f;
		obj_Rotation.y = 0.0f;
		obj_Rotation.z = 0.0f;

		obj_scale.x = 0.0f;
		obj_scale.y = 0.0f;
		obj_scale.z = 0.0f;

		obj_accel.x = 0.0f;
		obj_accel.y = 0.0f;
		obj_accel.z = 0.0f;
	
		obj_velocity.x = 0.0f;
		obj_velocity.y = 0.0f;
		obj_velocity.z = 0.0f;

		obj_mass = 0.0f;
	}
	~GameObject(){}

	void setPhyxValue(vec3 acceleratcion, vec3 veloctiy, float mass);
	void setAcc(float x, float y, float z);
	void setVel(vec3 veloctiy);
	void setMass(float mass);

	vec3 getAcc();
	vec3 getVel();
	float getMass();

	void setProperty(vec3 pos, vec3 rot, vec3 scale);
	void setPos(float x, float y, float z);
	void setRot(vec3 rot);
	void setScale(vec3 scale);

	float getPosX();
	float getPosY();
	float getPosZ();
	vec3 getRot();
	vec3 getScale();
	

protected:
	// property
	vec3 obj_Position ;
	vec3 obj_Rotation;
	vec3 obj_scale;
	
	//physics
	vec3 obj_accel;
	vec3 obj_velocity;
	float obj_mass;

	const float time = 1;

};

class kinematic : public GameObject {

public:

	void move(vec3 accl);
	vec3 addForce();

};

class friction : public GameObject {

public:

};

#endif GAMEOBJECT_H