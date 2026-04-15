private _unit = _this;
        _unit setSkill 1;
        _unit enableFatigue false;
        _unit setCombatBehaviour 'COMBAT';
	    _unit setUnitCombatMode 'RED'; 
		[_unit, 'BSKULLS_Nam_Insignia'] call BIS_fnc_setUnitInsignia;
		reload _unit;
