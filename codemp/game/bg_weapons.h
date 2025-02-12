/*
===========================================================================
Copyright (C) 1999 - 2005, Id Software, Inc.
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2003 - 2008, OJP contributors
Copyright (C) 2013 - 2015, OpenJK contributors

This file is part of the OpenJK-OJP source code.

OpenJK-OJP is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/

#pragma once

// Filename:-	bg_weapons.h
//
// This crosses both client and server.  It could all be crammed into bg_public, but isolation of this type of data is best.

typedef enum {
	WP_NONE,

	WP_STUN_BATON,
	WP_MELEE,
	WP_SABER,
	WP_BRYAR_PISTOL,
	WP_BLASTER,
	WP_DISRUPTOR,
	WP_BOWCASTER,
	WP_REPEATER,
	WP_DEMP2,
	WP_FLECHETTE,
	WP_ROCKET_LAUNCHER,
	WP_THERMAL,
	WP_TRIP_MINE,
	WP_DET_PACK,
	WP_CONCUSSION,
	WP_BRYAR_OLD,
	WP_EMPLACED_GUN,
	WP_TURRET,

//	WP_GAUNTLET,
//	WP_MACHINEGUN,			// Bryar
//	WP_SHOTGUN,				// Blaster
//	WP_GRENADE_LAUNCHER,	// Thermal
//	WP_LIGHTNING,			//
//	WP_RAILGUN,				//
//	WP_GRAPPLING_HOOK,

	WP_NUM_WEAPONS
} weapon_t;

#define WP_BOT_LASER WP_NUM_WEAPONS+1 // 20
#define WP_RAPID_FIRE_CONC WP_BOT_LASER+1 // 21
#define WP_JAWA WP_RAPID_FIRE_CONC+1 // 22
#define WP_TUSKEN_RIFLE WP_JAWA+1 // 23
#define WP_TUSKEN_STAFF WP_TUSKEN_RIFLE+1 // 24
#define WP_SCEPTER WP_TUSKEN_STAFF+1 // 25
#define WP_NOGHRI_STICK WP_SCEPTER+1 // 26
#define WP_ATST_MAIN WP_NOGHRI_STICK+1 // 27
#define WP_ATST_SIDE WP_ATST_MAIN+1 // 28

//anything > this will be considered not player useable
#define LAST_USEABLE_WEAPON			WP_BRYAR_OLD

//[MOREWEAPOPTIONS]
#define WP_MELEEONLY		524283
#define WP_SABERSONLY		524279
#define WP_MELEESABERS		524275
#define WP_NOEXPLOS			28672				

#define WP_ALLDISABLED		524287
#define FP_ALLDISABLED		262143
//[/MOREWEAPOPTIONS]

typedef enum //# ammo_e
{
	AMMO_NONE,
	AMMO_FORCE,		// AMMO_PHASER
	AMMO_BLASTER,	// AMMO_STARFLEET,
	AMMO_POWERCELL,	// AMMO_ALIEN,
	AMMO_METAL_BOLTS,
	AMMO_ROCKETS,
	AMMO_EMPLACED,
	AMMO_THERMAL,
	AMMO_TRIPMINE,
	AMMO_DETPACK,
	AMMO_MAX
} ammo_t;


typedef struct weaponData_s
{
//	char	classname[32];		// Spawning name

	int		ammoIndex;			// Index to proper ammo slot
	int		ammoLow;			// Count when ammo is low

	int		energyPerShot;		// Amount of energy used per shot
	int		fireTime;			// Amount of time between firings
	int		range;				// Range of weapon

	int		altEnergyPerShot;	// Amount of energy used for alt-fire
	int		altFireTime;		// Amount of time between alt-firings
	int		altRange;			// Range of alt-fire

	int		chargeSubTime;		// ms interval for subtracting ammo during charge
	int		altChargeSubTime;	// above for secondary

	int		chargeSub;			// amount to subtract during charge on each interval
	int		altChargeSub;		// above for secondary

	int		maxCharge;			// stop subtracting once charged for this many ms
	int		altMaxCharge;		// above for secondary
} weaponData_t;


typedef struct  ammoData_s
{
//	char	icon[32];	// Name of ammo icon file
	int		max;		// Max amount player can hold of ammo
} ammoData_t;


extern weaponData_t weaponData[WP_NUM_WEAPONS];
extern ammoData_t ammoData[AMMO_MAX];
extern ammoData_t ammoPool[4][WP_NUM_WEAPONS];


// Specific weapon information

#define FIRST_WEAPON		WP_BRYAR_PISTOL		// this is the first weapon for next and prev weapon switching
//[CoOp]
#define MAX_PLAYER_WEAPONS	WP_BRYAR_OLD		// this is the max you can switch to and get with the give all.
//[/CoOp]


#define DEFAULT_SHOTGUN_SPREAD	700
#define DEFAULT_SHOTGUN_COUNT	11

#define	LIGHTNING_RANGE		768

#define MAX_WEAPONS_IN_SLOT	4
#define MAX_WEAP_SLOTS		10
#define LAST_USABLE_SLOT	7

extern int weaponSlots[MAX_WEAP_SLOTS][MAX_WEAPONS_IN_SLOT];
