// story:rascal

#include <ansi.h>

private void create() { seteuid(getuid());}

string Rname;
string query_name();

static string *player_name;
string *query_all_name(){
	
	return player_name;
}
string query_name()
{
	object *ob,player;
	int i=0;
	
	player_name = ({});
	ob = filter_array(children(USER_OB),(: userp :));
	i = sizeof(ob);
	while(i--){
		if(!environment(ob[i])) continue;
		if( wizardp(ob[i])) continue;
		if((string)ob[i]->query("gender") == "女性") continue;
		player_name += ({ ob[i]->name() });
	}
	if(sizeof(player_name))
		Rname = player_name[random(sizeof(player_name))];
	else
		Rname = "小鬼";

	return Rname;
}

string prompt() {

	return HIM"【阴曹地府】"NOR;
}
private mixed *story = ({
	"地府阎罗殿上，" + query_name() +"被牛头马面押到判官崔珏跟前！",
	"崔珏一拍惊堂木，喝道：堂下何人？报上名来！",
	Rname+"连忙跪倒在地，胆颤心惊的说：小的...小的"+ Rname +"。",
	"崔珏：哪里人氏，因何而死，生前可有做过什么伤天害理之事呀？",
	Rname+"哭道：大人呀，你可要为小民做主呀，小人死得冤枉呀，小人是被人杀死的. . . ",
	"崔珏翻了翻《生死薄》道：因何被杀，杀你者何人？",
	Rname+"：俺是八路军侦察兵，有一天，俺被敌人捉住了。",
	Rname+"：第一天，敌人严刑拷打俺，俺没说，俺啥也没说。",
	"崔珏：嗯 . .",
	Rname+"：第二天，敌人又严刑拷打俺，俺还是没说。",
	"崔珏：嗯. . . . . .",
	Rname+"：第三天，敌人用"HIM"美女"NOR + WHT"诱惑俺，俺说了，俺啥都说了。",
	Rname+"：第四天，俺还想说，可敌人把俺给杀了。",
	Rname+"哭哭啼啼的，显得十分委屈。",
	"崔珏：我靠，来人啊，把"+ Rname+"押下去，先打入十八层地狱再说。",
	Rname+"：大人冤枉呀，大人冤枉呀！小的是无辜的呀～～～～",
	Rname+"被牛头马面拖了出去，哭声、喊声在阎罗殿上阵阵回荡～～",
	"崔珏：哼，又是一个色鬼！死了活该！！",
});
mixed query_story_message(int step)
{
	return step < sizeof(story) ? story[step] : 0;
}
