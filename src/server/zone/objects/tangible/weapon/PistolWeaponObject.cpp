/*
 *	server/zone/objects/tangible/weapon/PistolWeaponObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "PistolWeaponObject.h"

#include "server/zone/Zone.h"

/*
 *	PistolWeaponObjectStub
 */

PistolWeaponObject::PistolWeaponObject() : RangedWeaponObject(DummyConstructorParameter::instance()) {
	_impl = new PistolWeaponObjectImplementation();
	_impl->_setStub(this);
}

PistolWeaponObject::PistolWeaponObject(DummyConstructorParameter* param) : RangedWeaponObject(param) {
}

PistolWeaponObject::~PistolWeaponObject() {
}


void PistolWeaponObject::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((PistolWeaponObjectImplementation*) _impl)->initializeTransientMembers();
}

bool PistolWeaponObject::isPistolWeapon() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithBooleanReturn();
	} else
		return ((PistolWeaponObjectImplementation*) _impl)->isPistolWeapon();
}

/*
 *	PistolWeaponObjectImplementation
 */

PistolWeaponObjectImplementation::PistolWeaponObjectImplementation(DummyConstructorParameter* param) : RangedWeaponObjectImplementation(param) {
	_initializeImplementation();
}

PistolWeaponObjectImplementation::~PistolWeaponObjectImplementation() {
}


void PistolWeaponObjectImplementation::finalize() {
}

void PistolWeaponObjectImplementation::_initializeImplementation() {
	_setClassHelper(PistolWeaponObjectHelper::instance());

	_serializationHelperMethod();
}

void PistolWeaponObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (PistolWeaponObject*) stub;
	RangedWeaponObjectImplementation::_setStub(stub);
}

DistributedObjectStub* PistolWeaponObjectImplementation::_getStub() {
	return _this;
}

PistolWeaponObjectImplementation::operator const PistolWeaponObject*() {
	return _this;
}

void PistolWeaponObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void PistolWeaponObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void PistolWeaponObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void PistolWeaponObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void PistolWeaponObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void PistolWeaponObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void PistolWeaponObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void PistolWeaponObjectImplementation::_serializationHelperMethod() {
	RangedWeaponObjectImplementation::_serializationHelperMethod();

	_setClassName("PistolWeaponObject");

}

PistolWeaponObjectImplementation::PistolWeaponObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/weapon/PistolWeaponObject.idl(54):  		Logger.setLoggingName("PistolWeaponObject");
	Logger::setLoggingName("PistolWeaponObject");
}

void PistolWeaponObjectImplementation::initializeTransientMembers() {
	// server/zone/objects/tangible/weapon/PistolWeaponObject.idl(58):  		super.initializeTransientMembers();
	RangedWeaponObjectImplementation::initializeTransientMembers();
	// server/zone/objects/tangible/weapon/PistolWeaponObject.idl(60):  		Logger.setLoggingName("PistolWeaponObject");
	Logger::setLoggingName("PistolWeaponObject");
}

bool PistolWeaponObjectImplementation::isPistolWeapon() {
	// server/zone/objects/tangible/weapon/PistolWeaponObject.idl(64):  		return true;
	return true;
}

/*
 *	PistolWeaponObjectAdapter
 */

PistolWeaponObjectAdapter::PistolWeaponObjectAdapter(PistolWeaponObjectImplementation* obj) : RangedWeaponObjectAdapter(obj) {
}

Packet* PistolWeaponObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		resp->insertBoolean(isPistolWeapon());
		break;
	default:
		return NULL;
	}

	return resp;
}

void PistolWeaponObjectAdapter::initializeTransientMembers() {
	((PistolWeaponObjectImplementation*) impl)->initializeTransientMembers();
}

bool PistolWeaponObjectAdapter::isPistolWeapon() {
	return ((PistolWeaponObjectImplementation*) impl)->isPistolWeapon();
}

/*
 *	PistolWeaponObjectHelper
 */

PistolWeaponObjectHelper* PistolWeaponObjectHelper::staticInitializer = PistolWeaponObjectHelper::instance();

PistolWeaponObjectHelper::PistolWeaponObjectHelper() {
	className = "PistolWeaponObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void PistolWeaponObjectHelper::finalizeHelper() {
	PistolWeaponObjectHelper::finalize();
}

DistributedObject* PistolWeaponObjectHelper::instantiateObject() {
	return new PistolWeaponObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* PistolWeaponObjectHelper::instantiateServant() {
	return new PistolWeaponObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PistolWeaponObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PistolWeaponObjectAdapter((PistolWeaponObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

