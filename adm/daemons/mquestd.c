#include <ansi.h>

//#pragma optimize
//#pragma save_binary

inherit F_SKILL;

string query_city(string filename);
string *levels = ({
	"10000",
	"20000",
	"30000",
	"40000",
	"50000",
	"60000",
	"70000",
	"80000",
	"90000",
	"100000",
	"150000",
	"200000",
	"250000",
	"300000",
	"350000",
	"400000",
	"450000",
	"500000",
	"600000",
	"800000",
	"1000000",
	"1200000",
	"1500000",
	"1800000",
	"2400000",
});
int give_job(object ob,object me);
int give_quest(object ob)
{
	mapping quest ;
	object me;
	int j, combatexp, timep,num;
	string where,tag;
	me = this_player();

	combatexp = (int)me->query("combat_exp");

	if(combatexp < 10000){
		tell_object(me,ob->name()+"说道：先把基本功练好了再说吧！\n");
		return 1;
	}
	if((int)me->query("quest_fail_time") > time()) {
		tell_object(me,ob->name()+"说道：任务已经交给其他人去做了，你等一下再来吧！\n");
		return 1;
	}
	if((quest =  me->query("quest"))){
		if( me->query("quest/type") == "把信交给"){
			tell_object(me,ob->name()+"疑道：我好象没给你这样的任务啊？\n");
			return 0;
		}
		if(me->query("quest/from") != "门派"){
			tell_object(me,ob->name() +"疑道：我还没有分配任务给你啊！\n");
			return 0;
		}
		if( ((int) me->query("quest/task_time")) >  time()){
		tell_object(me,ob->name()+"说道：交给你的任务，你做好了吗？\n");
		return 0;

	}
	else
		{
		tell_object(me,ob->name()+"说道：好吧，我就再给你一次机会。\n");
		me->add("qi",-(int)(me->query("qi")/100));
		}
	}

	for(j= sizeof(levels) - 1 ; j>=0; j--){
	     if( atoi(levels[j])  <= combatexp ){
		   num=random(j);
		   break;
	     }
	}
	if ((num<sizeof(levels)-1)&&(random(100)>60)){
			num=num+1;
	}

	tag=levels[num];
	quest = QUEST_D(tag)->query_quest();
	timep = quest["diff"] * 240 + random(70);
	where = HIY + quest["where"] + NOR;
	if(!quest["where"]) where = "某处";
	if(quest["quest_type"]=="杀")
		tell_object(me,ob->name()+"悄声说道：请你在" + CHINESE_D->chinese_time(timep) + "内去『"+ where +"』，把『"+quest["quest"]+"』给杀了。\n");
	else
		tell_object(me,ob->name()+"悄声说道：请你在" + CHINESE_D->chinese_time(timep) + "内去『"+ where +"』把『"+quest["quest"]+"』帮我找回来。\n");

		quest["exp_bonus"] = (quest["diff"] * 20 + random(20));
		quest["pot_bonus"] = (quest["diff"] * 25 + random(20));
		quest["score"]= 1;
		quest["from"] = "门派";
		quest["task_time"] = time() + timep;
		me->set("quest", quest);
		return 1;

}
int quest_reward(object me, object who,object obj)
{
	int bonus, exp, pot, score,count_point;
	mapping quest;
	object npc;

	if(!me->query("quest")) return 0;

	message_vision("$N拿出"+ obj->short()+"给$n。\n",me,who);

	if(obj->query("money_id")){
		if(!me->query("quest")){
			tell_object(me,who->name()+"疑道：你给我这个干什么？\n");
			return 0;
	}
	if(obj->value() < 2000) {
			tell_object(me,who->name()+"疑道：这点钱也太少了吧？\n");
			return 0;
	}
	if( me->query("quest/from") == "门派") {
		if( me->query("quest")) me->set("quest_fail_time",time() + 30);
		tell_object(me,who->name()+"叹道：唉，那好吧！我让其他人去做。\n");
		me->delete_temp("count");
		me->add("qi",-(int)(me->query("qi")/100));
		destruct(obj);
		if(objectp(npc = me->query("quest/obj"))) destruct(npc);
		me->delete("quest");
		return 1;
		}
	}

	if(!(quest =  me->query("quest"))){
		tell_object(me,who->name()+"摇了摇头，说道：这不是我想要的东西。\n");
		return 0;
	}

	if((string)obj->query("name") != me->query("quest/quest")){
		tell_object(me,who->name()+"摇了摇头，说道：这不是我想要的东西。\n");
		return 0;
	}
	if((int)me->query("quest/must") && obj->query("last_damage_from") != me){
		tell_object(me,who->name()+"怒道：我叫你去办事，你竟然叫人顶替？哼！\n");
		destruct(obj);
		return 1;
	}
	if((int)me->query("quest/must_ask") && obj->query("master") != me){
		tell_object(me,who->name()+"怒道：我叫你去办事，你竟然叫人顶替？哼！\n");
		destruct(obj);
		return 1;
	}
	if((int)me->query("quest/task_time") < time() ){
		tell_object(me,who->name()+"生气的喝道：连这点小事情都办不好，真没用。\n");
		destruct(obj);
		return 1;
	}
		else{
		message_vision(CYN"$N点了点头，说道：好！很好！\n"NOR,who);
		exp = quest["exp_bonus"];
		pot = quest["pot_bonus"];
		score = quest["score"];
		bonus = (int) me->query("combat_exp");
		bonus += exp;
		me->set("combat_exp", bonus);
		bonus = (int) me->query("potential");
		if( pot > 300) pot = 300;
		bonus = bonus + pot;
		me->set("potential", bonus );
		bonus = (int) me->query("score");
		bonus += score;
		me->set("score", bonus);
		tell_object(me,HIC"恭喜你完成一个任务！\n"NOR);
		tell_object(me,HIC"你被奖励了：" + chinese_number(exp)
		+ "点实战经验，"+ chinese_number(pot) + "点潜能，"
		+ chinese_number(score)+"点江湖阅历。\n"NOR);
		tell_object(me,"你得到了"+ MONEY_D->price_str(exp * 50) +"点的存款为报酬。\n");
		me->add("balance",exp * 50);
		me->delete("quest");
		me->add_temp("count",1);
		if( me->query_temp("count") > 15) {
			count_point = 3000;
			tell_object(me,sprintf(HIY"\n恭喜！由于你连续的完成十五个任务。\n你获得了%s点实战经验和一百点江湖威望的额外奖励。\n\n"NOR,chinese_number(count_point)));
			me->add("combat_exp",count_point);
			me->add("weiwang",100);
			me->delete_temp("count");
		}

		SCORE_D->set_score(me);
		destruct(obj);
		return 1;

	}
	return 1;

}
int give_job(object ob,object me)
{
	mapping quest;
	object obj;
	string where,family,path;

	family = (string)ob->query("family/family_name");

	if((int)me->query("combat_exp") >= 51200000){
		tell_object(me,ob->name()+"说道：嗯，很好！你已经学武有成，独自去江湖上闯荡一番吧！\n");
		return 1;
	}
	if((int)ob->query_temp("quest")){
		tell_object(me,ob->name()+"说道：任务刚分配他人去做，你等一下再来吧。\n");
		return 1;
	}
	if((int)me->query("quest_fail_time") > time()) {
		tell_object(me,ob->name()+"说道：任务已经交给其他人去做了，你等一下再来吧！\n");
		return 1;
	}
	if((quest =  me->query("quest"))){
		if( me->query("quest/type") == "把信交给"){
			tell_object(me,ob->name()+"疑道：我好象没给你这样的任务啊？\n");
			return 0;
		}
		if(((int)me->query("quest/task_time")) >  time()){
		tell_object(me,ob->name()+"说道：交给你的任务，你做好了吗？\n");
		return 0;

	}
	else
		{
		tell_object(me,ob->name()+"说道：好吧，我就再给你一次机会。\n");
		if(me->query("quest")) me->delete("quest");
		me->add("qi",-(int)(me->query("qi")/100));
		}
	}

	path = QUEST_D("3000000")->query_path();

	if(random(5) > 2){
		obj = new("clone/npc/pantu");
                                obj->set_name(npc_name("男性"),({me->query("id")+" pan tu"}));
		obj->create_quest(me);
		obj->move(path);                              
		where = query_city(path);
		me->set("quest/where",where);
		tell_object(me,ob->name()+"说道：据闻我派叛徒「"+ obj->name(1) +"」在「"HIW + where + NOR"」一带造谣生事，滥杀无辜，败坏我" + family +"声望。\n你速到「"HIW + where + NOR"」将其首级与我带来，以振我派声威。\n");
		return 1;
	}
	else {
		obj= new("clone/npc/jianxi");
                        switch(random(4)){
		case 1:
			obj->set("title","商旅");
			obj->set_name(npc_name("男性"),({me->query("id")+" shang lv"}));
			break;
		case 2:
			obj->set("title","旅客");
			obj->set_name(npc_name("男性"),({me->query("id")+" lv ke"}));
			break;
		case 3:
			obj->set("title","富商");
			obj->set_name(npc_name("男性"),({me->query("id")+" fu shang"}));
			break;
		default:
			obj->set("title","游客");
			obj->set_name(npc_name("男性"),({me->query("id")+" you ke"}));
			break;
	                                      }
		obj->create_quest(me);
		obj->move(path);
		where = query_city(path);
		me->set("quest/where",where);
		tell_object(me,ob->name()+"说道：有奸细混入我" + family +"，杀我弟子，盗我"+ family +"秘籍后扮成商旅往「"HIW + where + NOR"」一带潜逃。\n你速到「"HIW + where + NOR"」查探消息，务必将"+ family +"秘籍夺回来！\n");
		ob->delete_temp("quest");
		return 1;
	}
}
string query_city(string filename)
{
	string city_name;
	int len;
	len=strlen(filename);
	len--;
	while(filename[len]!='/' && len>0) {
		len--;
	}
	city_name = filename[1..(len-1)];
	switch(city_name){
		case "d/baituo": return "白驼山";
		case "d/center": return "桃源";
		case "d/city": return "扬州";
		case "d/city2": return "北京";
		case "d/city3": return "成都";
		case "d/city4": return "长安";
		case "d/dali": return "大理";
		case "d/emei": return "峨嵋山";
		case "d/foshan": return "佛山";
		case "d/fuzhou": return "福州";
		case "d/guanwai": return "关外";
		case "d/guiyun": return "归云庄";
		case "d/gumu": return "古墓新派";
		case "d/hangzhou": return "杭州";
		case "d/heimuya": return "黑木崖";
		case "d/hengshan": return "恒山派";
		case "d/henshan": return "衡阳";
		case "d/huanggon": return "皇宫";
		case "d/huanghe": return "黄河一带";
		case "d/huashan": return "华山";
		case "d/kunlun": return "昆仑山";
		case "d/kunming": return "昆明";
		case "d/lingjiu": return "灵鹫宫";
		case "d/lingzhou": return "灵州";
		case "d/meizhuang": return "梅庄";
		case "d/mingjiao": return "明教";
		case "d/qianjinlou": return "千金楼";
		case "d/qingcheng": return "青派";
		case "d/quanzhen": return "全真教";
		case "d/quanzhou": return "泉州";
		case "d/shaolin": return "少林寺";
		case "d/shenlong": return "神龙教";
		case "d/songshan": return "嵩山";
		case "d/suzhou": return "苏州";
		case "d/taishan": return "泰山";
		case "d/tangmen": return "唐门";
		case "d/taohua": return "桃花岛";
		case "d/tianlongsi": return "天龙寺";
		case "d/village": return "武功镇";
		case "d/wanjiegu": return "万劫谷";
		case "d/wudang": return "武当山";
		case "d/wudu": return "五毒教";
		case "d/xiakedao": return "侠客岛";
		case "d/xiangyang": return "襄阳";
		case "d/xiaoyao": return "逍遥派";
		case "d/xingbu": return "成都刑部";
		case "d/xingxiu": return "星宿海";
		case "d/xuedao": return "法元寺";
		case "d/xueshan": return "雪山派";
		case "d/yanziwu": return "燕子坞";
			default: return "扬州";
	}
}
