/*
===========================================================================
Copyright (C) 1999 - 2005, Id Software, Inc.
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2003 - 2008, OJP contributors

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

//[CoOp]
//
// g_camera.c

#define MAX_CAMERA_GROUP_SUBJECTS	16
#define MAX_ACCEL_PER_FRAME			10.0f
#define MAX_SHAKE_INTENSITY			16.0f
#define	CAMERA_DEFAULT_FOV			90.0f
#define CAMERA_WIDESCREEN_FOV		120.0f
#define	BAR_DURATION				1000.0f
#define BAR_RATIO					48.0f

#define CAMERA_MOVING		0x00000001
#define CAMERA_PANNING		0x00000002
#define CAMERA_ZOOMING		0x00000004
#define	CAMERA_BAR_FADING	0x00000008
#define	CAMERA_FADING		0x00000010
#define	CAMERA_FOLLOWING	0x00000020
#define	CAMERA_TRACKING		0x00000040
#define CAMERA_ROFFING		0x00000080
#define CAMERA_SMOOTHING	0x00000100
#define CAMERA_CUT			0x00000200
#define CAMERA_ACCEL		0x00000400

typedef struct camera_s
{
	//Position / Facing information
	vec3_t	origin;
	vec3_t	angles;
	
	vec3_t	origin2;
	vec3_t	angles2;

	//Movement information
	float	move_duration;
	float	move_time;
	int		move_type;	//CMOVE_LINEAR, CMOVE_BEZIER

	//FOV information
	float	FOV;
	float	FOV2;
	float	FOV_duration;
	float	FOV_time;
	float	FOV_vel;
	float	FOV_acc;

	//Pan information
	float	pan_time;
	float	pan_duration;

	//Following information
	char	cameraGroup[MAX_QPATH];
	float	cameraGroupZOfs;
	char	cameraGroupTag[MAX_QPATH];
	vec3_t	subjectPos;
	float	subjectSpeed;
	float	followSpeed;
	qboolean followInitLerp;
	float	distance;
	qboolean distanceInitLerp;
	//int		aimEntNum;//FIXME: remove

	//Tracking information
	int		trackEntNum;
	vec3_t	trackToOrg;
	vec3_t	moveDir;
	float	speed;
	float	initSpeed;
	float	trackInitLerp;
	int		nextTrackEntUpdateTime;

	//Cine-bar information
	float	bar_alpha;
	float	bar_alpha_source;
	float	bar_alpha_dest;
	float	bar_time;
	
	float	bar_height_source;
	float	bar_height_dest;
	float	bar_height;

	vec4_t	fade_color;
	vec4_t	fade_source;
	vec4_t	fade_dest;
	float	fade_time;
	float	fade_duration;

	//State information
	int		info_state;

	//Shake information
	float	shake_intensity;
	int		shake_duration;
	int		shake_start;

	//Smooth information
	float	smooth_intensity;
	int		smooth_duration;
	int		smooth_start;
	vec3_t	smooth_origin;
	qboolean	smooth_active; // means smooth_origin and angles are valid


	// ROFF information
	char	sRoff[MAX_QPATH];	// name of a cached roff 
	int		roff_frame;		// current frame in the roff data
	int		next_roff_time;	// time when it's ok to apply the next roff frame 

} camera_t;

extern	qboolean		in_camera;
extern	camera_t	client_camera;

void GCam_Init( void );

void GCam_Enable( void );
void GCam_Disable( void );

void GCam_SetPosition( vec3_t org );
void GCam_SetAngles( vec3_t ang );
void GCam_SetFOV( float FOV );

void GCam_Zoom( float FOV, float duration );
//void CGCam_Pan( vec3_t	dest, float duration );
void GCam_Pan( vec3_t dest, vec3_t panDirection, float duration );
void GCam_Move( vec3_t dest, float duration );
void GCam_Fade( vec4_t source, vec4_t dest, float duration );

void GCam_UpdateFade( void );

void GCam_Update( void );
void GCam_RenderScene( void );
void GCam_DrawWideScreen( void );

void GCam_Shake( float intensity, int duration );
void GCam_UpdateShake( vec3_t origin, vec3_t angles );

void GCam_Follow( int cameraGroup[MAX_CAMERA_GROUP_SUBJECTS], float speed, float initLerp );
void GCam_Track( const char *trackName, float speed, float initLerp );
void GCam_Distance( float distance, float initLerp );
void GCam_Roll( float	dest, float duration );

void GCam_StartRoff( char *roff );

void GCam_Smooth( float intensity, int duration );
void GCam_UpdateSmooth( vec3_t origin, vec3_t angles );

void GCam_FollowUpdate ( void );

void DisablePlayerCameraPos(void);
//[CoOp]

