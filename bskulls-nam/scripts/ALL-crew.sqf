        _this setSkill 1;
        _this enableFatigue false;
        _this setCombatBehaviour 'COMBAT';
	    _this setUnitCombatMode 'RED'; 
		[_this, 'BSKULLS_Nam_Insignia'] call BIS_fnc_setUnitInsignia;
		reload _this;