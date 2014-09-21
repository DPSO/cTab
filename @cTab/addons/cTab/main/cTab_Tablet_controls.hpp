// Background definition
#define GUI_GRID_PX_W 1024 // width in pixels
#define GUI_GRID_PX_H 1024 // hight in pixels

// Base macros to convert pixel space to screen space
#define pxToScreen_X(PIXEL) (PIXEL) / GUI_GRID_PX_W * GUI_GRID_W + GUI_GRID_X
#define pxToScreen_Y(PIXEL) (PIXEL) / GUI_GRID_PX_H * GUI_GRID_H + GUI_GRID_Y
#define pxToScreen_W(PIXEL) (PIXEL) / GUI_GRID_PX_W * GUI_GRID_W
#define pxToScreen_H(PIXEL) (PIXEL) / GUI_GRID_PX_H * GUI_GRID_H

// Map position within background, pixel based
#define cTab_GUI_tablet_MAP_X (193)
#define cTab_GUI_tablet_MAP_Y (237)
#define cTab_GUI_tablet_MAP_W (681)
#define cTab_GUI_tablet_MAP_H (520)

// Base macros to convert pixel space to screen space, but for groups (same size as map)
#define pxToGroup_X(PIXEL) ((PIXEL) / GUI_GRID_PX_W * GUI_GRID_W + GUI_GRID_X) - (cTab_GUI_tablet_MAP_X / GUI_GRID_PX_W * GUI_GRID_W + GUI_GRID_X)
#define pxToGroup_Y(PIXEL) ((PIXEL) / GUI_GRID_PX_H * GUI_GRID_H + GUI_GRID_Y) - (cTab_GUI_tablet_MAP_Y / GUI_GRID_PX_H * GUI_GRID_H + GUI_GRID_Y)

// Task bar absolute size, pixel based (from source)
#define cTab_GUI_tablet_TASKBAR_PX_W (1024)
#define cTab_GUI_tablet_TASKBAR_PX_H (28)

// Translate task bar size to pixel based size in background
#define cTab_GUI_tablet_TASKBAR_W (cTab_GUI_tablet_MAP_W)
#define cTab_GUI_tablet_TASKBAR_H (cTab_GUI_tablet_TASKBAR_W / cTab_GUI_tablet_TASKBAR_PX_W * cTab_GUI_tablet_TASKBAR_PX_H)

// Set task bar position at the bottom of the screen area
#define cTab_GUI_tablet_TASKBAR_X (cTab_GUI_tablet_MAP_X)
#define cTab_GUI_tablet_TASKBAR_Y (cTab_GUI_tablet_MAP_Y + cTab_GUI_tablet_MAP_H - cTab_GUI_tablet_TASKBAR_H)

// Window background (application windows) absolute size, pixel based (from source)
#define cTab_GUI_tablet_WINDOW_BACK_PX_W (293)
#define cTab_GUI_tablet_WINDOW_BACK_PX_H (272)

// Window content (application windows) position within window background, pixel based
#define cTab_GUI_tablet_WINDOW_CONTENT_PX_X (9)
#define cTab_GUI_tablet_WINDOW_CONTENT_PX_Y (30)
#define cTab_GUI_tablet_WINDOW_CONTENT_PX_W (276)
#define cTab_GUI_tablet_WINDOW_CONTENT_PX_H (232)

// Translate window background size to pixel based position in background (heith is 49 % of tablet screen height)
#define cTab_GUI_tablet_WINDOW_BACK_H ((cTab_GUI_tablet_MAP_H - cTab_GUI_tablet_TASKBAR_H) * 0.49)
#define cTab_GUI_tablet_WINDOW_BACK_W (cTab_GUI_tablet_WINDOW_BACK_PX_W / cTab_GUI_tablet_WINDOW_BACK_PX_H * cTab_GUI_tablet_WINDOW_BACK_H)

// Translate window content size to pixel based position in background
#define cTab_GUI_tablet_WINDOW_CONTENT_W (cTab_GUI_tablet_WINDOW_CONTENT_PX_W / cTab_GUI_tablet_WINDOW_BACK_PX_W * cTab_GUI_tablet_WINDOW_BACK_W)
#define cTab_GUI_tablet_WINDOW_CONTENT_H (cTab_GUI_tablet_WINDOW_CONTENT_PX_H / cTab_GUI_tablet_WINDOW_BACK_PX_H * cTab_GUI_tablet_WINDOW_BACK_H)

// Translate window content offsets (from edges of window background) to pixel based positions in background
#define cTab_GUI_tablet_WINDOW_CONTENT_OFFSET_X (cTab_GUI_tablet_WINDOW_CONTENT_PX_X / cTab_GUI_tablet_WINDOW_BACK_PX_W * cTab_GUI_tablet_WINDOW_BACK_W)
#define cTab_GUI_tablet_WINDOW_CONTENT_OFFSET_Y (cTab_GUI_tablet_WINDOW_CONTENT_PX_Y / cTab_GUI_tablet_WINDOW_BACK_PX_H * cTab_GUI_tablet_WINDOW_BACK_H)

// Distribute window backgrounds evenly on the available screen space for 2x2 windows
#define cTab_GUI_tablet_WINDOW_BACK_L_X (cTab_GUI_tablet_MAP_X + (cTab_GUI_tablet_MAP_W - 2 * cTab_GUI_tablet_WINDOW_BACK_W) / 3)
#define cTab_GUI_tablet_WINDOW_BACK_R_X (cTab_GUI_tablet_MAP_X + cTab_GUI_tablet_WINDOW_BACK_W + (cTab_GUI_tablet_MAP_W - 2 * cTab_GUI_tablet_WINDOW_BACK_W) / 3 * 2)
#define cTab_GUI_tablet_WINDOW_BACK_T_Y (cTab_GUI_tablet_MAP_Y + (cTab_GUI_tablet_MAP_H - cTab_GUI_tablet_TASKBAR_H - 2 * cTab_GUI_tablet_WINDOW_BACK_H) / 3)
#define cTab_GUI_tablet_WINDOW_BACK_B_Y (cTab_GUI_tablet_MAP_Y + cTab_GUI_tablet_WINDOW_BACK_H + (cTab_GUI_tablet_MAP_H - cTab_GUI_tablet_TASKBAR_H - 2 * cTab_GUI_tablet_WINDOW_BACK_H) / 3 * 2)

// Place window content within window background
#define cTab_GUI_tablet_WINDOW_CONTENT_L_X (cTab_GUI_tablet_WINDOW_BACK_L_X + cTab_GUI_tablet_WINDOW_CONTENT_OFFSET_X)
#define cTab_GUI_tablet_WINDOW_CONTENT_R_X (cTab_GUI_tablet_WINDOW_BACK_R_X + cTab_GUI_tablet_WINDOW_CONTENT_OFFSET_X)
#define cTab_GUI_tablet_WINDOW_CONTENT_T_Y (cTab_GUI_tablet_WINDOW_BACK_T_Y + cTab_GUI_tablet_WINDOW_CONTENT_OFFSET_Y)
#define cTab_GUI_tablet_WINDOW_CONTENT_B_Y (cTab_GUI_tablet_WINDOW_BACK_B_Y + cTab_GUI_tablet_WINDOW_CONTENT_OFFSET_Y)

// Desktop icon size and offset from tablet screen edge in pixels
#define cTab_GUI_tablet_DESKTOP_ICON_OFFSET_X (15)
#define cTab_GUI_tablet_DESKTOP_ICON_OFFSET_Y (15)
#define cTab_GUI_tablet_DESKTOP_ICON_W (60)
#define cTab_GUI_tablet_DESKTOP_ICON_H (60)

// Message element positions in pixels
#define cTab_GUI_tablet_MESSAGE_MARGIN_OUTER (10)
#define cTab_GUI_tablet_MESSAGE_MARGIN_INNER (5)

#define cTab_GUI_tablet_MESSAGE_BUTTON_W (90)
#define cTab_GUI_tablet_MESSAGE_BUTTON_H (30)

#define cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_X (cTab_GUI_tablet_MAP_X + cTab_GUI_tablet_MESSAGE_MARGIN_OUTER)
#define cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_Y (cTab_GUI_tablet_MAP_Y + cTab_GUI_tablet_MESSAGE_MARGIN_OUTER)
#define cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_W (cTab_GUI_tablet_MAP_W - cTab_GUI_tablet_MESSAGE_MARGIN_OUTER * 2)
#define cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_H ((cTab_GUI_tablet_MAP_H - cTab_GUI_tablet_TASKBAR_H - cTab_GUI_tablet_MESSAGE_MARGIN_OUTER - cTab_GUI_tablet_MESSAGE_MARGIN_INNER * 2) / 2)

#define cTab_GUI_tablet_MESSAGE_MESSAGELIST_X (cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_X + cTab_GUI_tablet_MESSAGE_MARGIN_INNER)
#define cTab_GUI_tablet_MESSAGE_MESSAGELIST_Y (cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_Y + cTab_GUI_tablet_MESSAGE_MARGIN_OUTER)
#define cTab_GUI_tablet_MESSAGE_MESSAGELIST_W ((cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_W - cTab_GUI_tablet_MESSAGE_MARGIN_INNER * 3) / 3)
#define cTab_GUI_tablet_MESSAGE_MESSAGELIST_H (cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_H - cTab_GUI_tablet_MESSAGE_MARGIN_INNER - cTab_GUI_tablet_MESSAGE_MARGIN_OUTER)

#define cTab_GUI_tablet_MESSAGE_MESSAGETEXT_X (cTab_GUI_tablet_MESSAGE_MESSAGELIST_X + cTab_GUI_tablet_MESSAGE_MESSAGELIST_W + cTab_GUI_tablet_MESSAGE_MARGIN_INNER)
#define cTab_GUI_tablet_MESSAGE_MESSAGETEXT_Y (cTab_GUI_tablet_MESSAGE_MESSAGELIST_Y)
#define cTab_GUI_tablet_MESSAGE_MESSAGETEXT_W (cTab_GUI_tablet_MESSAGE_MESSAGELIST_W * 2)
#define cTab_GUI_tablet_MESSAGE_MESSAGETEXT_H (cTab_GUI_tablet_MESSAGE_MESSAGELIST_H - cTab_GUI_tablet_MESSAGE_MARGIN_INNER - cTab_GUI_tablet_MESSAGE_BUTTON_H)

#define cTab_GUI_tablet_MESSAGE_COMPOSE_FRAME_X (cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_X)
#define cTab_GUI_tablet_MESSAGE_COMPOSE_FRAME_Y (cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_Y + cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_H + cTab_GUI_tablet_MESSAGE_MARGIN_INNER)
#define cTab_GUI_tablet_MESSAGE_COMPOSE_FRAME_W (cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_W)
#define cTab_GUI_tablet_MESSAGE_COMPOSE_FRAME_H (cTab_GUI_tablet_MESSAGE_MESSAGETEXT_FRAME_H)

#define cTab_GUI_tablet_MESSAGE_PLAYERLIST_X (cTab_GUI_tablet_MESSAGE_MESSAGELIST_X)
#define cTab_GUI_tablet_MESSAGE_PLAYERLIST_Y (cTab_GUI_tablet_MESSAGE_COMPOSE_FRAME_Y + cTab_GUI_tablet_MESSAGE_MARGIN_OUTER)
#define cTab_GUI_tablet_MESSAGE_PLAYERLIST_W (cTab_GUI_tablet_MESSAGE_MESSAGELIST_W)
#define cTab_GUI_tablet_MESSAGE_PLAYERLIST_H (cTab_GUI_tablet_MESSAGE_MESSAGELIST_H)

#define cTab_GUI_tablet_MESSAGE_COMPOSE_TEXT_X (cTab_GUI_tablet_MESSAGE_MESSAGETEXT_X)
#define cTab_GUI_tablet_MESSAGE_COMPOSE_TEXT_Y (cTab_GUI_tablet_MESSAGE_PLAYERLIST_Y)
#define cTab_GUI_tablet_MESSAGE_COMPOSE_TEXT_W (cTab_GUI_tablet_MESSAGE_MESSAGETEXT_W)
#define cTab_GUI_tablet_MESSAGE_COMPOSE_TEXT_H (cTab_GUI_tablet_MESSAGE_MESSAGETEXT_H)

#define cTab_GUI_tablet_MESSAGE_BUTTON_SEND_X (cTab_GUI_tablet_MESSAGE_COMPOSE_FRAME_X + cTab_GUI_tablet_MESSAGE_COMPOSE_FRAME_W - cTab_GUI_tablet_MESSAGE_MARGIN_INNER - cTab_GUI_tablet_MESSAGE_BUTTON_W)
#define cTab_GUI_tablet_MESSAGE_BUTTON_SEND_Y (cTab_GUI_tablet_MESSAGE_COMPOSE_TEXT_Y + cTab_GUI_tablet_MESSAGE_COMPOSE_TEXT_H + cTab_GUI_tablet_MESSAGE_MARGIN_INNER)

#define cTab_GUI_tablet_MESSAGE_BUTTON_DELETE_X (cTab_GUI_tablet_MESSAGE_BUTTON_SEND_X)
#define cTab_GUI_tablet_MESSAGE_BUTTON_DELETE_Y (cTab_GUI_tablet_MESSAGE_MESSAGETEXT_Y + cTab_GUI_tablet_MESSAGE_MESSAGETEXT_H + cTab_GUI_tablet_MESSAGE_MARGIN_INNER)

// Height of header and footer OSD elements
#define cTab_GUI_tablet_OSD_HEADER_H (94)
#define cTab_GUI_tablet_OSD_FOOTER_H (cTab_GUI_tablet_OSD_HEADER_H)

// On-screen edge positions (left, right, top, bottom)
#define cTab_GUI_tablet_OSD_MARGIN (24)
#define cTab_GUI_tablet_OSD_EDGE_L (cTab_GUI_tablet_OSD_MARGIN + cTab_GUI_tablet_MAP_X)
#define cTab_GUI_tablet_OSD_EDGE_R (-cTab_GUI_tablet_OSD_MARGIN + cTab_GUI_tablet_MAP_X + cTab_GUI_tablet_MAP_W)
#define cTab_GUI_tablet_OSD_EDGE_T (cTab_GUI_tablet_OSD_MARGIN + cTab_GUI_tablet_MAP_Y)
#define cTab_GUI_tablet_OSD_EDGE_B (-cTab_GUI_tablet_OSD_FOOTER_H + cTab_GUI_tablet_MAP_Y + cTab_GUI_tablet_MAP_H)

// On-screen element base width and height
#define cTab_GUI_tablet_OSD_ELEMENT_STD_W ((cTab_GUI_tablet_MAP_W - cTab_GUI_tablet_OSD_MARGIN * 4) / 3)
#define cTab_GUI_tablet_OSD_ELEMENT_STD_H (cTab_GUI_tablet_OSD_HEADER_H - cTab_GUI_tablet_OSD_MARGIN)

// On-screen element X-coord for left, center and right elements
#define cTab_GUI_tablet_OSD_LEFT_X (cTab_GUI_tablet_OSD_EDGE_L)
#define cTab_GUI_tablet_OSD_CENTER_X (cTab_GUI_tablet_OSD_EDGE_L + cTab_GUI_tablet_OSD_MARGIN + cTab_GUI_tablet_OSD_ELEMENT_STD_W)
#define cTab_GUI_tablet_OSD_RIGHT_X (cTab_GUI_tablet_OSD_EDGE_R - cTab_GUI_tablet_OSD_ELEMENT_STD_W)

// On-screen text sizes, hight in pixels
// Standard text elements
#define cTab_GUI_tablet_OSD_TEXT_STD_SIZE (60)
#define cTab_GUI_tablet_OSD_ICON_STD_SIZE (50)

// On-screen map centre cursor
#define cTab_GUI_tablet_CURSOR (38)

// define colours
#define COLOR_NEON_GREEN {57/255,255/255,20/255,1}
#define COLOR_BLACK {0,0,0,1}
#define COLOR_WHITE {1,1,1,1}

class cTab_Tablet_background: cTab_RscPicture
{
	idc = IDC_CTAB_BACKGROUND;
	text = "\cTab\img\15th_rugged_tab.paa";
	x = GUI_GRID_X;
	y = GUI_GRID_Y;
	w = GUI_GRID_W;
	h = GUI_GRID_H;
};
class cTab_Tablet_window_back_TL: cTab_RscPicture
{
	text = "\cTab\img\window_2.jpg";
	x = pxToScreen_X(cTab_GUI_tablet_WINDOW_BACK_L_X);
	y = pxToScreen_Y(cTab_GUI_tablet_WINDOW_BACK_T_Y);
	w = pxToScreen_W(cTab_GUI_tablet_WINDOW_BACK_W);
	h = pxToScreen_H(cTab_GUI_tablet_WINDOW_BACK_H);
};
class cTab_Tablet_window_back_BL: cTab_Tablet_window_back_TL
{
	y = pxToScreen_Y(cTab_GUI_tablet_WINDOW_BACK_B_Y);
};
class cTab_Tablet_window_back_TR: cTab_Tablet_window_back_TL
{
	x = pxToScreen_X(cTab_GUI_tablet_WINDOW_BACK_R_X);
};
class cTab_Tablet_window_back_BR: cTab_Tablet_window_back_TR
{
	y = pxToScreen_Y(cTab_GUI_tablet_WINDOW_BACK_B_Y);
};
class cTab_Tablet_btnF1: cTab_RscButtonInv
{
	x = pxToScreen_X(322);
	y = pxToScreen_Y(783);
	w = pxToScreen_W(23);
	h = pxToScreen_H(25);
};
class cTab_Tablet_btnF2: cTab_Tablet_btnF1
{
	x = pxToScreen_X(354);
};
class cTab_Tablet_btnF3: cTab_Tablet_btnF1
{
	x = pxToScreen_X(387);
};
class cTab_Tablet_btnF4: cTab_Tablet_btnF1
{
	x = pxToScreen_X(420);
};
class cTab_Tablet_btnF5: cTab_Tablet_btnF1
{
	x = pxToScreen_X(452);
};
class cTab_Tablet_btnF6: cTab_Tablet_btnF1
{
	x = pxToScreen_X(485);
};
class cTab_Tablet_btnFn: cTab_Tablet_btnF1
{
	x = pxToScreen_X(556);
	y = pxToScreen_Y(784);
};
class cTab_Tablet_btnPower: cTab_Tablet_btnFn
{
	x = pxToScreen_X(588);
};
class cTab_Tablet_btnBrtDn: cTab_Tablet_btnFn
{
	x = pxToScreen_X(621);
};
class cTab_Tablet_btnBrtUp: cTab_Tablet_btnFn
{
	x = pxToScreen_X(654);
};
class cTab_Tablet_btnTrackpad: cTab_Tablet_btnFn
{
	x = pxToScreen_X(703);
	y = pxToScreen_Y(785);
	w = pxToScreen_W(24);
	h = pxToScreen_H(24);
};
class cTab_Tablet_btnMouse: cTab_Tablet_btnTrackpad
{
	x = pxToScreen_X(778);
	w = pxToScreen_W(42);
	h = pxToScreen_H(25);
};
class cTab_Tablet_btnHome: cTab_Tablet_btnMouse
{
	x = pxToScreen_X(520);
	y = pxToScreen_Y(780);
	w = pxToScreen_W(25);
	h = pxToScreen_H(20);
};
class cTab_Tablet_notificationLight
{
	x = pxToScreen_X(749);
	y = pxToScreen_Y(794);
	w = pxToScreen_W(8);
	h = pxToScreen_H(9);
};