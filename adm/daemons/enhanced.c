// enhanced.c
// Design By Robert 蝴蝶君

//#pragma optimize
//#pragma save_binary

#include <ansi.h>
#include <combat.h>

string enhance_weapon(object ob, int bonus, string weapon_type)
{
	int major = random(15), minor = random(20);
	string new_name = "";
	string id = ob->query("id");
	mapping weapon;
	weapon = ob->query("weapon_prop");
	id = replace_string(id,"my ","");
	if( major < 6 )
	switch( random(14) ) {
		case 0:
			new_name += CYN "青铜"; weapon["defense"] += 10;
			id = "bronze " + id;
			break;
		case 1:
			new_name += RED "镔铁"; weapon["strength"] += 4;
			id = "iron " + id;
			break;
		case 2:
			new_name += HIW "点钢"; weapon["attack"] += 5; weapon["strength"] += 2;
			id = "steel " + id;
			break;
		case 3:
			new_name += HIB "青钢"; weapon["attack"] += 5; weapon["defense"] += 5;
			id = "steel " + id;
			break;
		case 4:
			new_name += HIK "黑铁"; weapon["strength"] += 2; weapon["defense"] += 5;
			id = "iron " + id;
			break;
		case 5:
			new_name += MAG "松纹"; weapon["strength"] += 3; weapon["attack"] += 5;
			id = "fine " + id;
			break;
		case 6:
			new_name += HIM "雕花"; weapon["dexerity"] += 3; weapon["defense"] += 5;
			id = "fine " + id;
			break;
		case 7:
			new_name += HIK "缠布"; weapon["spirituality"] += 3; weapon["dodge"] += 3;
			id = "wrapped-hilt " + id;
			break;
		case 8:
			new_name += HIK "铁棘"; weapon["strength"] += 3; weapon["dexerity"] += 2;
			id = "thorny " + id;
			break;
		case 9:
			new_name += HIW  "太极"; weapon["spirituality"] = 3; weapon["defense"] += 5;
			id = "taiji " + id;
			break;
		case 10:
			new_name += HIW  "阴阳"; weapon["intelligence"] += 3; weapon["attack"] += 5;
			id = "yinyang " + id;
			break;
		case 11:
			new_name += HIR "硃砂"; weapon["personality"] += 5; weapon["constitution"] += 5;
			id = "cinnabar " + id;
			break;
		case 12:
			new_name += HIY "日月"; weapon["constitution"] += 3; weapon["personality"] += 5;
			id = "glowing " + id;
			break;
		case 13:
			new_name += HIK "厌火"; weapon["constitution"] += 3; weapon["strength"] += 2;
			id = "yenholdish " + id;
			break;
		}
	else if( major < 10 )
		switch( random(22) ) {
		case 0:
			new_name += HIW "精钢"; weapon["attack"] += 10; weapon["strength"] = 3;
			id = "highsteel " + id;
			break;
		case 1:
			new_name += HIW "白银"; weapon["defense"] += 15;
			id = "silver " + id;
			break;
		case 2:
			new_name += HIK "黑钢"; weapon["attack"] += 15;
			id = "darksteel " + id;
			break;
		case 3:
			new_name += YEL "古锭"; weapon["defense"] += 10; weapon["spirituality"] += 3;
			id = "darkmetal " + id;
			break;
		case 4:
			new_name += RED "雏铁"; weapon["attack"] += 10; weapon["defense"] += 10;
			id = "iron" + id;
			break;
		case 5:
			new_name += HIR "彤云"; weapon["spirituality"] += 3; weapon["cor"] += 3;
			id = "cloudy " + id;
			break;
		case 6:
			new_name += MAG "紫电"; weapon["dexerity"] += 3; weapon["strength"] += 3;
			id = "thunder " + id;
			break;
		case 7:
			new_name += HIY "金镶"; weapon["constitution"] += 3; weapon["intelligence"] += 3;
			id = "golden " + id;
			break;
		case 8:
			new_name += HIW "太玄"; weapon["dodge"] += 3; weapon["constitution"] += 10;
			id = "mystic " + id;
			break;
		case 9:
			new_name += HIB "太清"; weapon["spirituality"] += 3; weapon["constitution"] += 10;
			id = "mystic " + id;
			break;
		case 10:
			new_name += HIC "太乙"; weapon["intelligence"] += 3; weapon["constitution"] += 10;
			id = "mystic " + id;
			break;
		case 11:
			new_name += HIK "太阴"; weapon["intelligence"] += 2;
			id = "moon " + id;
			break;
		case 12:
			new_name += HIY "太阳"; weapon["constitution"] += 2;
			id = "sun " + id;
			break;
		case 13:
			new_name += HIB "辟妖"; weapon["personality"] += 15;
			id = "demonbane " + id;
			break;
		case 14:
			new_name += BLU "辟邪"; weapon["constitution"] += 15;
			id = "devilbane " + id;
			break;
		case 15:
			new_name += HIK "镇鬼"; weapon["personality"] += 10; weapon["constitution"] += 10;
			id = "nether " + id;
			break;
		case 16:
			new_name += RED "赤血"; weapon["strength"] += 5;
			id = "blood " + id;
			break;
		case 17:
			new_name += HIR "碧血"; weapon["dodge"] += 5;
			id = "blood " + id;
			break;
		case 18:
			new_name += CYN "无肠"; weapon["intelligence"] += 3; weapon["constitution"] -= 3;
			id = "woochanian " + id;
			break;
		case 19:
			new_name += HIG "焦侥"; weapon["dexerity"] += 3; weapon["strength"] -= 3;
			id = "jiaojao " + id;
			break;
		case 20:
			new_name += HIM "紫阳"; weapon["spirituality"] += 2;
			id = "dawn " + id;
			break;
		case 21:
			new_name += HIC "青阳"; weapon["spirituality"] += 2;
			id = "shining " + id;
			break;
	}

	if( new_name=="" ) return ob->name();
	if( minor < 3 )
		switch( random(13) ) {
		case 4:
			new_name += HIR "火炎";
			id += " of flame";
			break;
		case 5:
			new_name += HIB "寒冰";
			id += " of freeze";
			break;
		case 6:
			new_name += HIC "风波";
			id += " of wind";
			break;
		case 7:
			new_name += HIB "震雷";
			id += " of lightning";
			break;
		case 8:
			new_name += YEL "罗汉";
			id += " of guardian";
			break;
		case 9:
			new_name += HIW "天龙";
			id += " of wyvern";
			break;
		case 10:
			new_name += HIR "赤龙";
			id += " of red dragon";
			break;
		case 11:
			new_name += HIY "金鹰";
			id += " of eagle";
			break;
		case 12:
			new_name += HIC "天鹰";
			id += " of falcon";
			break;
    }
		new_name += weapon_type + NOR;
		ob->set("name", new_name);
		ob->set("id", id);
		return new_name;
	return ob->name();
}
