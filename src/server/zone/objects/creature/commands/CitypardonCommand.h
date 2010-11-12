/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#ifndef CITYPARDONCOMMAND_H_
#define CITYPARDONCOMMAND_H_

#include "../../scene/SceneObject.h"

class CitypardonCommand : public QueueCommand {
public:

	CitypardonCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!creature->isPlayerCreature())
			return GENERALERROR;

		if (!checkInvalidPostures(creature))
			return INVALIDPOSTURE;

		ManagedReference<PlayerCreature*> player = (PlayerCreature*) creature;

		ManagedReference<SceneObject*> targetObject = player->getZoneServer()->getObject(target);

		if (targetObject == NULL || !targetObject->isPlayerCreature())
			return INVALIDTARGET;

		PlayerCreature* targetPlayer = (PlayerCreature*) targetObject.get();

		ManagedReference<ActiveArea*> activeRegion = player->getActiveRegion();

		if (activeRegion == NULL || !activeRegion->isRegion())
			return GENERALERROR;

		Region* region = (Region*) activeRegion.get();

		ManagedReference<CityHallObject*> cityHall = region->getCityHall();

		if (cityHall == NULL)
			return GENERALERROR;

		Locker _locker(cityHall);

		//Can't unban someone who isn't banned...
		if (!cityHall->isBanned(target))
			return GENERALERROR;

		if (!cityHall->isMayor(player->getObjectID()) && !cityHall->isMilitiaMember(player->getObjectID())) {
			player->sendSystemMessage("@city/city:not_militia"); //You must be a member of the city militia to use this command.
			return GENERALERROR;
		}

		cityHall->removeBannedPlayer(target);
		cityHall->updateToDatabaseWithoutChildren();

		targetPlayer->sendSystemMessage("@city/city:city_pardoned"); //You have been pardoned and are once again able to use city services.

		StringIdChatParameter params;
		params.setStringId("@city/city:city_pardon_done");
		params.setTT(targetPlayer);
		player->sendSystemMessage(params); //%TT has been pardoned and is now able to use city services.

		return SUCCESS;
	}

};

#endif //CITYPARDONCOMMAND_H_
