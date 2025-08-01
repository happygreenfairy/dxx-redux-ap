/*
THE COMPUTER CODE CONTAINED HEREIN IS THE SOLE PROPERTY OF PARALLAX
SOFTWARE CORPORATION ("PARALLAX").  PARALLAX, IN DISTRIBUTING THE CODE TO
END-USERS, AND SUBJECT TO ALL OF THE TERMS AND CONDITIONS HEREIN, GRANTS A
ROYALTY-FREE, PERPETUAL LICENSE TO SUCH END-USERS FOR USE BY SUCH END-USERS
IN USING, DISPLAYING,  AND CREATING DERIVATIVE WORKS THEREOF, SO LONG AS
SUCH USE, DISPLAY OR CREATION IS FOR NON-COMMERCIAL, ROYALTY OR REVENUE
FREE PURPOSES.  IN NO EVENT SHALL THE END-USER USE THE COMPUTER CODE
CONTAINED HEREIN FOR REVENUE-BEARING PURPOSES.  THE END-USER UNDERSTANDS
AND AGREES TO THE TERMS HEREIN AND ACCEPTS THE SAME BY USE OF THIS FILE.
COPYRIGHT 1993-1998 PARALLAX SOFTWARE CORPORATION.  ALL RIGHTS RESERVED.
*/

/*
 *
 * Header for playsave.c
 *
 */

#ifndef _PLAYSAVE_H
#define _PLAYSAVE_H

#include "pstypes.h"
#include "kconfig.h"
#include "mission.h"
#include "weapon.h"
#include "multi.h"
#include "player.h"

#define N_SAVE_SLOTS    10
#define GAME_NAME_LEN   25      // +1 for terminating zero = 26

#define MOUSE_CONTROL_FLIGHT_SIM 1   /* Old School Mouse */
#define MOUSE_CONTROL_REBIRTH 0
#define MOUSE_CONTROL_OLDSCHOOL 2

// NOTE: Obsolete structure - only kept for compability of shareware plr file
typedef struct saved_game_sw {
	char		name[GAME_NAME_LEN+1];		//extra char for terminating zero
	struct player_rw sg_player;
	int		difficulty_level;		//which level game is played at
	int		primary_weapon;		//which weapon selected
	int		secondary_weapon;		//which weapon selected
	int		cockpit_mode;			//which cockpit mode selected
	int		window_w,window_h;	//size of player's window
	int		next_level_num;		//which level we're going to
	int		auto_leveling_on;		//does player have autoleveling on?
} __pack__ saved_game_sw;

typedef struct hli {
	char	Shortname[9];
	ubyte	LevelNum;
} hli;

typedef struct player_config
{
	ubyte ControlType;
	ubyte PrimaryOrder[MAX_PRIMARY_WEAPONS+2];
	ubyte SecondaryOrder[MAX_SECONDARY_WEAPONS+1];
	ubyte KeySettings[3][MAX_CONTROLS];
	ubyte KeySettingsD1X[MAX_D1X_CONTROLS];
	int DefaultDifficulty;
	int AutoLeveling;
	short NHighestLevels;
	hli HighestLevels[MAX_MISSIONS];
	int KeyboardSens[5];
	int JoystickSens[6];
	int JoystickDead[6];
	int JoystickUndercalibrate[6];
	ubyte MouseControlStyle; /* Old School Mouse -- ubyte MouseFlightSim; */ 
	int MouseImpulse; /* Old School Mouse */ 
	int MouseSens[6];
    int MouseOverrun[6];
	int MouseFSDead;
	int MouseFSIndicator;
	int PreferredCockpitMode;
	int CurrentCockpitMode; // Also includes letterbox/rear, which are not persisted in the player profile
	char NetworkMessageMacro[4][MAX_MESSAGE_LEN];
	int NetlifeKills;
	int NetlifeKilled;
	ubyte ReticleType;
	int ReticleRGBA[4];
	int ReticleSize;
	int HudMode;
	int PersistentDebris;
	int PRShot;
	int DemoRecordingIndicator;
	ubyte NoRedundancy;
	ubyte MultiMessages;
	ubyte NoRankings;
	ubyte BombGauge;
	ubyte AutomapFreeFlight;
	ubyte NoFireAutoselect;
	ubyte CycleAutoselectOnly;
	ubyte VulcanAmmoWarnings;
	ubyte ShieldWarnings; 
	ubyte AutoDemoSp;
	ubyte AutoDemoMp;
	ubyte AutoDemoHideUi;
	ubyte ShowCustomColors; 
	ubyte PreferMyTeamColors;
	ubyte QuietPlasma; 
	int AlphaEffects;
	int DynLightColor;
	ubyte DisableCockpit;  /* DisableCockpit */ 
	ubyte StickyRearview; /* StickyRearview */ 
	ubyte SelectAfterFire; /* SelectAfterFire */ 
	int maxFps;
	int ShipColor; 
	int MissileColor; 
	int MyTeamColor;
	int OtherTeamColor;
	ubyte ObsShareSettings;
	ubyte ObsTurbo[NUM_OBS_MODES];
	ubyte ObsShowCockpit[NUM_OBS_MODES];
	ubyte ObsShowScoreboardShieldText[NUM_OBS_MODES];
	ubyte ObsShowScoreboardShieldBar[NUM_OBS_MODES];
	ubyte ObsShowAmmoBars[NUM_OBS_MODES];
	ubyte ObsShowPrimary[NUM_OBS_MODES];
	ubyte ObsShowSecondary[NUM_OBS_MODES];
	ubyte ObsShowNames[NUM_OBS_MODES];
	ubyte ObsShowDamage[NUM_OBS_MODES];
	ubyte ObsShowShieldText[NUM_OBS_MODES];
	ubyte ObsShowShieldBar[NUM_OBS_MODES];
	ubyte ObsShowKillFeed[NUM_OBS_MODES];
	ubyte ObsShowDeathSummary[NUM_OBS_MODES];
	ubyte ObsShowStreaks[NUM_OBS_MODES];
	ubyte ObsShowKillGraph[NUM_OBS_MODES];
	ubyte ObsShowBreakdown[NUM_OBS_MODES];
	ubyte ObsShowObs[NUM_OBS_MODES];
	ubyte ObsChat[NUM_OBS_MODES];
	ubyte ObsPlayerChat[NUM_OBS_MODES];
	ubyte ObsShowBombTimes[NUM_OBS_MODES];
	ubyte ObsTransparentThirdPerson[NUM_OBS_MODES];
	ubyte ObsIncreaseThirdPersonDist[NUM_OBS_MODES];
	ubyte ObsHideEnergyWeaponMuzzle[NUM_OBS_MODES];
	ubyte NoChatSound;
	ubyte ClassicAutoselectWeapon;
	// new stuff for archipelago fork -happygreenfairy
	int AutomapRenderItems; // show important items on automap at all times
	int AutomapUnveilFromStart; // replicates map power-ups
	int InfiniteLives; // don't lose lives on death when enabled
} __pack__ player_config;

extern struct player_config PlayerCfg;

extern int Default_leveling_on;

// adb: EZERO looks like a watcom extension that's only used here
#ifndef EZERO
#define EZERO 0
#endif

// Used to save kconfig values to disk.
int write_player_file();

int new_player_config();

int read_player_file();

// set a new highest level for player for this mission
void set_highest_level(int levelnum);

// gets the player's highest level from the file for this mission
int get_highest_level(void);

void plyr_read_stats();
void plyr_save_stats();

void read_netgame_profile(netgame_info *ng);
void write_netgame_profile(netgame_info *ng);

int read_netgame_settings_file(const char *filename, netgame_info *ng, int no_name);
int write_netgame_settings_file(const char *filename, netgame_info *ng, int no_name);

#endif
