#include <iostream>
#include "gameObject.h"

void GameObject::setPhyxValue(vec3 acceleratcion, vec3 veloctiy, float mass)
{
	obj_accel = acceleratcion;
	obj_velocity = veloctiy;
	obj_mass = mass;
}

void GameObject::setAcc(float x, float y, float z)
{
	obj_accel.x = x;
	obj_accel.y = y;
	obj_accel.z = z;
}

void GameObject::setVel(vec3 veloctiy)
{
	obj_velocity = veloctiy;
}

void GameObject::setMass(float mass)
{
	obj_mass = mass;
}

vec3 GameObject::getAcc()
{
	return obj_accel;
}

vec3 GameObject::getVel()
{
	return obj_velocity;
}

float GameObject::getMass()
{
	return obj_mass;
}

void GameObject::setProperty(vec3 pos, vec3 rot, vec3 scale)
{

}

void GameObject::setPos(float x, float y, float z)
{
	obj_Position.x = x;
	obj_Position.y = y;
	obj_Position.z = z;
}

void GameObject::setRot(vec3 rot)
{
	obj_Rotation = rot;
}

void GameObject::setScale(vec3 scale)
{
	obj_scale = scale;
}

float GameObject::getPosX()
{
	return obj_Position.x;
}
float GameObject::getPosY()
{
	return obj_Position.y;
}
float GameObject::getPosZ()
{
	return obj_Position.z;
}

vec3 GameObject::getRot()
{
	return obj_Rotation;
}

vec3 GameObject::getScale()
{
	return obj_scale;
}

void kinematic::move(vec3 accl)
{

	
	obj_Position.x = obj_Position.x + (obj_velocity.x*time) + (0.5 * time * time*accl.x);
	obj_Position.y = obj_Position.y + (obj_velocity.y*time) + (0.5 * time * time*accl.y);
	obj_Position.z = obj_Position.z + (obj_velocity.z*time) + (0.5 * time * time*accl.z);

	obj_velocity.x = obj_velocity.x + (time*accl.x);
	obj_velocity.y = obj_velocity.y + (time*accl.y);
	obj_velocity.z = obj_velocity.z + (time*accl.z);


}

vec3 kinematic::addForce()
{
	return vec3();
}


