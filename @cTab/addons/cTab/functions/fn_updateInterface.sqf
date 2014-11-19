/*
 	Name: cTab_fnc_updateInterface
 	
 	Author(s):
		Gundy

 	Description:
		Update current interface (display or dialog) to match current settings.
		If no parameters are specified, all interface elements are updated

	Parameters:
	(Optional)
		0: ARRAY - Property pairs in the form of [["propertyName",propertyValue],[...]]
 	
 	Returns:
		BOOLEAN - Always true
 	
 	Example:
		[["mapType","SAT"],["mapScale","4"]] call cTab_fnc_updateInterface;
*/

#include "\cTab\cTab_gui_macros.hpp";

private ["_ifName","_settings","_display","_displayName","_null","_osdCtrl","_text","_mode","_mapTypes","_targetMapName","_targetMapIDC","_targetMapCtrl","_previousMapCtrl","_renderTarget"];
disableSerialization;

if (isNil "cTabIfOpen") exitWith {};
_displayName = cTabIfOpen select 1;
_display = uiNamespace getVariable _displayName;

if (count _this == 1) then {
	_settings = _this select 0;
} else {
	// Retrieve all settings for the currently open interface
	_settings = [_displayName] call cTab_fnc_getSettings;
};

{
	call {
		// ------------ MODE ------------
		if (_x select 0 == "mode") exitWith {
			call {
				if (_displayName == "cTab_Tablet_dlg") exitWith {
					_null = [_x select 1] execVM "\cTab\tablet\cTab_Tablet_modeSwitch.sqf";
				};
				if (_displayName == "cTab_Android_dlg") exitWith {
					_null = [_x select 1] execVM "\cTab\android\cTab_android_modeSwitch.sqf";
				};
			};
		};
		// ------------ SHOW ICON TEXT ------------
		if (_x select 0 == "showIconText") exitWith {
			_osdCtrl = _display displayCtrl IDC_CTAB_OSD_TXT_TGGL;
			if (_osdCtrl != controlNull) then {
				_text = if (_x select 1) then {"ON"} else {"OFF"};
				_osdCtrl ctrlSetText _text;
			};
		};
		// ------------ MAP SCALE ------------
		if (_x select 0 == "mapScale") exitWith {
			_osdCtrl = _display displayCtrl IDC_CTAB_OSD_MAP_SCALE;
			if (_osdCtrl != controlNull) then {
				// divide by 2 because we want to display the radius, not the diameter
				_osdCtrl ctrlSetText format ["%1",(_x select 1) / 2];
			};
		};
		// ------------ MAP TYPE ------------
		if (_x select 0 == "mapType") exitWith {
			_mode = [_displayName,"mode"] call cTab_fnc_getSettings;
			_mapTypes = [_displayName,"mapTypes"] call cTab_fnc_getSettings;
			if ((count _mapTypes > 1) && (_mode == "BFT")) then {
				_targetMapName = _x select 1;
				_targetMapIDC = [_mapTypes,_targetMapName] call cTab_fnc_getFromPairs;
				_targetMapCtrl = _display displayCtrl _targetMapIDC;
				_previousMapCtrl = controlNull;
				{
					_previousMapIDC = _x select 1;
					_previousMapCtrl = _display displayCtrl _previousMapIDC;
					if (ctrlShown _previousMapCtrl) exitWith {};
					_previousMapCtrl = controlNull;
				} count _mapTypes;
				// See if _targetMapCtrl is already being shown
				if ((!ctrlShown _targetMapCtrl) && (_targetMapCtrl != _previousMapCtrl)) then {
					// Update _targetMapCtrl to scale and position of _previousMapCtrl
					_targetMapCtrl ctrlMapAnimAdd [0,ctrlMapScale _previousMapCtrl,[_previousMapCtrl] call cTab_fnc_ctrlMapCenter];
					ctrlMapAnimCommit _targetMapCtrl;
					// Show _targetMapCtrl
					_targetMapCtrl ctrlShow true;
					_targetMapCtrl ctrlCommit 0;
				};
				// Hide all other map types
				{
					if (_x select 0 != _targetMapName) then {
						_previousMapCtrl = _display displayCtrl (_x select 1);
						_previousMapCtrl ctrlShow false;
						_previousMapCtrl ctrlCommit 0;
					};
				} count _mapTypes;
				// Update OSD element if it exists
				_osdCtrl = _display displayCtrl IDC_CTAB_OSD_MAP_TGGL;
				if (_osdCtrl != controlNull) then {_osdCtrl ctrlSetText _targetMapName;};
			};
		};
		// ------------ UAV CAM ------------
		if (_x select 0 == "uavCam") exitWith {
			_mode = [_displayName,"mode"] call cTab_fnc_getSettings;
			if (_mode == "UAV") then {
				_data = _x select 1;
				if (_data != "") then {
					[_data,[[0,"rendertarget8"],[1,"rendertarget9"]]] spawn cTab_fnc_createUavCam;
				};
			};
		};
		// ------------ HCAM ------------
		if (_x select 0 == "hCam") exitWith {
			_mode = [_displayName,"mode"] call cTab_fnc_getSettings;
			_renderTarget = call {
				if (_mode == "HCAM") exitWith {"rendertarget12"};
				if (_mode == "HCAM_FULL") exitWith {"rendertarget13"}
			};
			if (!isNil "_renderTarget") then {
				_data = _x select 1;
				if (_data != "") then {
					[_renderTarget,_data] spawn cTab_fnc_createHelmetCam;
				};
			};
		};
		// ------------ MAP TOOLS ------------
		if (_x select 0 == "mapTools") exitWith {
			cTabDrawMapTools = _x select 1;
			_mode = [_displayName,"mode"] call cTab_fnc_getSettings;
			if (_mode == "BFT") then {
				if !(_displayName in ["cTab_TAD_dlg","cTab_TAD_dsp"]) then {
					{
						_osdCtrl = _display displayCtrl _x;
						if (_osdCtrl != controlNull) then {
							_osdCtrl ctrlShow cTabDrawMapTools;
						};
					} count [IDC_CTAB_OSD_HOOK_GRID,IDC_CTAB_OSD_HOOK_DIR,IDC_CTAB_OSD_HOOK_DST,IDC_CTAB_OSD_HOOK_ELEVATION];
				};
				_osdCtrl = _display displayCtrl IDC_CTAB_OSD_HOOK_TGGL1;
				if (_osdCtrl != controlNull) then {
					_text = if (_x select 1) then {"OWN"} else {"CURS"};
					_osdCtrl ctrlSetText _text;
				};
				_osdCtrl = _display displayCtrl IDC_CTAB_OSD_HOOK_TGGL2;
				if (_osdCtrl != controlNull) then {
					_text = if (_x select 1) then {"CURS"} else {"OWN"};
					_osdCtrl ctrlSetText _text;
				};
			};
		};
		// ------------ MENU ------------
		if (_x select 0 == "showMenu") exitWith {
			_osdCtrl = _display displayCtrl IDC_CTAB_GROUP_MENU;
			if (_osdCtrl != controlNull) then {
				_mode = [_displayName,"mode"] call cTab_fnc_getSettings;
				if (_mode == "BFT") then {
					_osdCtrl ctrlShow (_x select 1);
				};
			};
		};
		// ----------------------------------
	};
} forEach _settings;

true