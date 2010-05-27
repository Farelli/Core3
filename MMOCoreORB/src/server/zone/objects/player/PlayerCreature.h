/*
 *	server/zone/objects/player/PlayerCreature.h generated by engine3 IDL compiler 0.60
 */

#ifndef PLAYERCREATURE_H_
#define PLAYERCREATURE_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class ZoneClientSession;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerObject;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace building {

class BuildingObject;

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class Container;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class PlayerDisconnectEvent;

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class PlayerRecoveryEvent;

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;

namespace server {
namespace chat {
namespace room {

class ChatRoom;

} // namespace room
} // namespace chat
} // namespace server

using namespace server::chat::room;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace weapon {

class WeaponObject;

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

namespace server {
namespace zone {
namespace objects {
namespace group {

class GroupObject;

} // namespace group
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::group;

namespace server {
namespace zone {
namespace objects {
namespace waypoint {

class WaypointObject;

} // namespace waypoint
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::waypoint;

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/creature/CreatureFlag.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "system/lang/Time.h"

#include "system/util/SortedVector.h"

#include "system/util/VectorMap.h"

#include "engine/util/QuadTreeEntry.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "engine/service/proto/BasePacket.h"

#include "engine/lua/LuaObject.h"

#include "system/lang/ref/Reference.h"

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature : public CreatureObject {
public:
	static const int ONLINE = 1;

	static const int OFFLINE = 2;

	static const int LINKDEAD = 3;

	static const int LOGGINGIN = 4;

	static const int LOGGINGOUT = 5;

	static const int LOADING = 6;

	PlayerCreature();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void disconnect(bool closeClient, bool doLock);

	void unload();

	void reload(ZoneClientSession* client);

	void logout(bool doLock);

	void activateRecovery();

	void doRecovery();

	void insertToBuilding(BuildingObject* building);

	void removeFromBuilding(BuildingObject* building);

	void sendMessage(BasePacket* msg);

	void sendToOwner(bool doClose = true);

	void sendBadgesResponseTo(PlayerCreature* player);

	void unloadSpawnedChildren();

	void notifyCloseContainer(PlayerCreature* player);

	bool isAggressiveTo(PlayerCreature* object);

	void setLastNpcConvStr(const String& conv);

	void setLastNpcConvMessStr(const String& mess);

	String getLastNpcConvStr();

	String getLastNpcConvMessStr();

	String getLastNpcConvOption(int idx);

	void addLastNpcConvOptions(const String& option);

	int countLastNpcConvOptions();

	void clearLastNpcConvOptions();

	void addToDuelList(PlayerCreature* targetPlayer);

	void removeFromDuelList(PlayerCreature* targetPlayer);

	PlayerCreature* getDuelListObject(int index);

	bool requestedDuelTo(PlayerCreature* targetPlayer);

	bool isDuelListEmpty();

	int getDuelListSize();

	void notifySceneReady();

	SortedVector<unsigned long long>* getPersistentMessages();

	void addPersistentMessage(unsigned long long id);

	void dropPersistentMessage(unsigned long long id);

	PlayerObject* getPlayerObject();

	bool isOnline();

	bool isOffline();

	bool isLoading();

	bool isLinkDead();

	bool isLoggingIn();

	bool isLoggingOut();

	unsigned int getAccountID();

	ZoneClientSession* getClient();

	byte getRaceID();

	unsigned long long getSavedParentID();

	int getSavedZoneID();

	String getFirstName();

	String getLastName();

	void setSavedParentID(unsigned long long id);

	void setSavedZoneID(int id);

	void setSkillPoints(int points);

	void addSkillPoints(int points);

	void setClient(ZoneClientSession* cli);

	void setBiography(const UnicodeString& bio);

	void setRaceID(byte id);

	void setConversatingCreature(CreatureObject* creature);

	void setClientLastMovementStamp(unsigned int stamp);

	void setOffline();

	void setLinkDead();

	void setOnline();

	void setLoggingOut();

	void setAccountID(unsigned int id);

	void clearDisconnectEvent();

	void clearRecoveryEvent();

	void addChatRoom(ChatRoom* room);

	void removeChatRoom(ChatRoom* room);

	int getSkillPoints();

	unsigned int getNewSuiBoxID(unsigned int type);

	bool hasSuiBox(unsigned int boxID);

	SuiBox* getSuiBox(unsigned int boxID);

	void removeSuiBox(unsigned int boxID, bool closeWindowToClient = false);

	void addSuiBox(SuiBox* sui);

	int getLotsRemaining();

	int getFactionStatus();

	UnicodeString getBiography();

	unsigned int getClientLastMovementStamp();

	void setSurveyTool(SurveyTool* tool);

	SurveyTool* getSurveyTool();

	void setSurveyWaypoint(WaypointObject* waypoint);

	WaypointObject* getSurveyWaypoint();

	CreatureObject* getConversatingCreature();

protected:
	PlayerCreature(DummyConstructorParameter* param);

	virtual ~PlayerCreature();

	String _return_getFirstName;
	String _return_getLastName;
	String _return_getLastNpcConvMessStr;
	String _return_getLastNpcConvOption;
	String _return_getLastNpcConvStr;

	UnicodeString _return_getBiography;

	friend class PlayerCreatureHelper;
};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreatureImplementation : public CreatureObjectImplementation {
protected:
	ManagedReference<ZoneClientSession* > owner;

	int savedZoneID;

	unsigned long long savedParentID;

	int onlineStatus;

	Time logoutTimeStamp;

	unsigned int clientLastMovementStamp;

	unsigned int accountID;

	unsigned int suiBoxNextID;

	String raceFile;

	byte raceID;

	String startingLocation;

	String startingProfession;

	UnicodeString biography;

	int lotsRemaining;

	PlayerDisconnectEvent* disconnectEvent;

	PlayerRecoveryEvent* recoveryEvent;

	int skillPoints;

	Badges badges;

	Time nextTip;

	SortedVector<ManagedReference<ChatRoom* > > chatRooms;

	byte incapacitationCounter;

	Time firstIncapacitationTime;

	VectorMap<unsigned int, ManagedReference<SuiBox* > > suiBoxes;

	int pvpRating;

	int factionStatus;

	SortedVector<unsigned long long> persistentMessages;

	SortedVector<ManagedReference<PlayerCreature* > > duelList;

	ManagedReference<SurveyTool* > surveyTool;

	ManagedReference<WaypointObject* > surveyWaypoint;

	String lastNpcConvoMessage;

	String lastNpcConvo;

	Vector<String> lastNpcConvoOptions;

	ManagedReference<CreatureObject* > conversatingCreature;

public:
	static const int ONLINE = 1;

	static const int OFFLINE = 2;

	static const int LINKDEAD = 3;

	static const int LOGGINGIN = 4;

	static const int LOGGINGOUT = 5;

	static const int LOADING = 6;

	PlayerCreatureImplementation();

	PlayerCreatureImplementation(DummyConstructorParameter* param);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void disconnect(bool closeClient, bool doLock);

	void unload();

	void reload(ZoneClientSession* client);

	void logout(bool doLock);

	void activateRecovery();

	void doRecovery();

	void insertToBuilding(BuildingObject* building);

	void removeFromBuilding(BuildingObject* building);

	void sendMessage(BasePacket* msg);

	void sendToOwner(bool doClose = true);

	void sendBadgesResponseTo(PlayerCreature* player);

	void unloadSpawnedChildren();

	void notifyCloseContainer(PlayerCreature* player);

	bool isAggressiveTo(PlayerCreature* object);

	void setLastNpcConvStr(const String& conv);

	void setLastNpcConvMessStr(const String& mess);

	String getLastNpcConvStr();

	String getLastNpcConvMessStr();

	String getLastNpcConvOption(int idx);

	void addLastNpcConvOptions(const String& option);

	int countLastNpcConvOptions();

	void clearLastNpcConvOptions();

	void addToDuelList(PlayerCreature* targetPlayer);

	void removeFromDuelList(PlayerCreature* targetPlayer);

	PlayerCreature* getDuelListObject(int index);

	bool requestedDuelTo(PlayerCreature* targetPlayer);

	bool isDuelListEmpty();

	int getDuelListSize();

	void notifySceneReady();

	SortedVector<unsigned long long>* getPersistentMessages();

	void addPersistentMessage(unsigned long long id);

	void dropPersistentMessage(unsigned long long id);

	PlayerObject* getPlayerObject();

	bool isOnline();

	bool isOffline();

	bool isLoading();

	bool isLinkDead();

	bool isLoggingIn();

	bool isLoggingOut();

	unsigned int getAccountID();

	ZoneClientSession* getClient();

	byte getRaceID();

	unsigned long long getSavedParentID();

	int getSavedZoneID();

	String getFirstName();

	String getLastName();

	void setSavedParentID(unsigned long long id);

	void setSavedZoneID(int id);

	void setSkillPoints(int points);

	void addSkillPoints(int points);

	void setClient(ZoneClientSession* cli);

	void setBiography(const UnicodeString& bio);

	void setRaceID(byte id);

	void setConversatingCreature(CreatureObject* creature);

	void setClientLastMovementStamp(unsigned int stamp);

	void setOffline();

	void setLinkDead();

	void setOnline();

	void setLoggingOut();

	void setAccountID(unsigned int id);

	void clearDisconnectEvent();

	void clearRecoveryEvent();

	void addChatRoom(ChatRoom* room);

	void removeChatRoom(ChatRoom* room);

	int getSkillPoints();

	unsigned int getNewSuiBoxID(unsigned int type);

	bool hasSuiBox(unsigned int boxID);

	SuiBox* getSuiBox(unsigned int boxID);

	void removeSuiBox(unsigned int boxID, bool closeWindowToClient = false);

	void addSuiBox(SuiBox* sui);

	int getLotsRemaining();

	int getFactionStatus();

	UnicodeString getBiography();

	unsigned int getClientLastMovementStamp();

	void setSurveyTool(SurveyTool* tool);

	SurveyTool* getSurveyTool();

	void setSurveyWaypoint(WaypointObject* waypoint);

	WaypointObject* getSurveyWaypoint();

	CreatureObject* getConversatingCreature();

	PlayerCreature* _this;

	operator const PlayerCreature*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~PlayerCreatureImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class PlayerCreature;
};

class PlayerCreatureAdapter : public CreatureObjectAdapter {
public:
	PlayerCreatureAdapter(PlayerCreatureImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void disconnect(bool closeClient, bool doLock);

	void unload();

	void reload(ZoneClientSession* client);

	void logout(bool doLock);

	void activateRecovery();

	void doRecovery();

	void insertToBuilding(BuildingObject* building);

	void removeFromBuilding(BuildingObject* building);

	void sendMessage(BasePacket* msg);

	void sendToOwner(bool doClose);

	void sendBadgesResponseTo(PlayerCreature* player);

	void unloadSpawnedChildren();

	void notifyCloseContainer(PlayerCreature* player);

	bool isAggressiveTo(PlayerCreature* object);

	void setLastNpcConvStr(const String& conv);

	void setLastNpcConvMessStr(const String& mess);

	String getLastNpcConvStr();

	String getLastNpcConvMessStr();

	String getLastNpcConvOption(int idx);

	void addLastNpcConvOptions(const String& option);

	int countLastNpcConvOptions();

	void clearLastNpcConvOptions();

	void addToDuelList(PlayerCreature* targetPlayer);

	void removeFromDuelList(PlayerCreature* targetPlayer);

	PlayerCreature* getDuelListObject(int index);

	bool requestedDuelTo(PlayerCreature* targetPlayer);

	bool isDuelListEmpty();

	int getDuelListSize();

	void notifySceneReady();

	void addPersistentMessage(unsigned long long id);

	void dropPersistentMessage(unsigned long long id);

	PlayerObject* getPlayerObject();

	bool isOnline();

	bool isOffline();

	bool isLoading();

	bool isLinkDead();

	bool isLoggingIn();

	bool isLoggingOut();

	unsigned int getAccountID();

	ZoneClientSession* getClient();

	byte getRaceID();

	unsigned long long getSavedParentID();

	int getSavedZoneID();

	String getFirstName();

	String getLastName();

	void setSavedParentID(unsigned long long id);

	void setSavedZoneID(int id);

	void setSkillPoints(int points);

	void addSkillPoints(int points);

	void setClient(ZoneClientSession* cli);

	void setBiography(const UnicodeString& bio);

	void setRaceID(byte id);

	void setConversatingCreature(CreatureObject* creature);

	void setClientLastMovementStamp(unsigned int stamp);

	void setOffline();

	void setLinkDead();

	void setOnline();

	void setLoggingOut();

	void setAccountID(unsigned int id);

	void clearDisconnectEvent();

	void clearRecoveryEvent();

	void addChatRoom(ChatRoom* room);

	void removeChatRoom(ChatRoom* room);

	int getSkillPoints();

	unsigned int getNewSuiBoxID(unsigned int type);

	bool hasSuiBox(unsigned int boxID);

	SuiBox* getSuiBox(unsigned int boxID);

	void removeSuiBox(unsigned int boxID, bool closeWindowToClient);

	void addSuiBox(SuiBox* sui);

	int getLotsRemaining();

	int getFactionStatus();

	UnicodeString getBiography();

	unsigned int getClientLastMovementStamp();

	void setSurveyTool(SurveyTool* tool);

	SurveyTool* getSurveyTool();

	void setSurveyWaypoint(WaypointObject* waypoint);

	WaypointObject* getSurveyWaypoint();

	CreatureObject* getConversatingCreature();

protected:
	String _param0_setLastNpcConvStr__String_;
	String _param0_setLastNpcConvMessStr__String_;
	String _param0_addLastNpcConvOptions__String_;
	UnicodeString _param0_setBiography__UnicodeString_;
};

class PlayerCreatureHelper : public DistributedObjectClassHelper, public Singleton<PlayerCreatureHelper> {
	static PlayerCreatureHelper* staticInitializer;

public:
	PlayerCreatureHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PlayerCreatureHelper>;
};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

#endif /*PLAYERCREATURE_H_*/
