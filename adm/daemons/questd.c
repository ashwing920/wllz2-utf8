// questd.c
// Design By 蝴蝶君(Robert) email:robert@cnmuds.com
//
//#pragma optimize
//#pragma save_binary

#define QUEST_OB		"/quest/questob"

#include <ansi.h>

inherit F_DBASE;

string *name = ({
	"巴天石","刀白凤","段正淳","范骅","傅思归","高升泰","古笃诚","华赫艮","朱丹臣",
	"褚万里","贝锦仪","丁敏君","方碧琳","静慧师太","纪晓芙","静迦师太","静空师太",
	"李明霞","赵灵珠","灭绝师太","苏梦清","静闲师太","静虚师太","静玄师太","静照师太",
	"静真师太","周芷若","何不净","洪七公","简长老","江上游","快活三","李斧头","黎生",
	"梁长老","鲁有脚","马俱为","莫不收","彭有敬","裘万家","全冠清","余洪兴","赵狗儿",
	"左全","林朝英","小龙女","杨过","矮老者","成不忧","丛不弃","封不平","风清扬",
	"高老者","令狐冲","岳不群","宁中则","班淑娴","何太冲","何足道","卫四娘","西华子",
	"梅剑","天山童姥","虚竹","黛绮丝","范遥","韦一笑","谢逊","杨逍","殷天正","包不同",
	"邓百川","风波恶","公冶乾","慕容博","慕容复","陈志益","程瑶迦","房志起","郝大通",
	"李志常","刘处玄","马钰","祁志诚","丘处机","申志凡","孙不二","谭处端","王重阳",
	"王处一","王志坦","尹志平","东方不败","计无施","贾布","蓝凤凰","任我行","上官云",
	"童百熊","向问天","洪安通","陆高轩","胖头陀","瘦头陀","苏荃","殷锦","张淡月",
	"章老三","唐老太太","唐不平","唐亮","唐猛","唐无火","唐无情","冯默风","黄药师",
	"陆乘风","曲灵风","黄蓉","本参","本尘","本观","本相","本因","枯荣大师","谷虚道长",
	"莫声谷","清虚道长","张翠山","守园道长","宋远桥","宋青书","俞岱岩","殷梨亭","俞莲舟",
	"张三丰","制香道长","岑其斯","何红药","何铁手","齐云","龙亦凡","冯阿三","苟读",
	"康广陵","苏星河","逍遥子","薛慕华","出尘子","丁春秋","狮吼子","天狼子","摘星子",
	"宝象","善勇","胜谛","随喜","血刀老祖","达而巴","金轮法王","葛伦布","贡唐仓国师",
	"嘉木活佛","鸠摩智","拉章活佛","灵智上人","萨木活佛","陈近南","马超兴","玄贞道长",
});

mapping create_quest()
{
	mapping quest;
	string owner;

	quest = QUEST_OB->query_quest();
	owner = name[random(sizeof(name))];
	quest["owner_name"] = owner;
	quest["task_time"] = 180 + random(300);
	quest["exp_bonus"] = 120 + random(70);
	quest["pot_bonus"] = 150 + random(70);
	quest["score"] = 1;
	quest["weiwang"] = 5;
	quest["from"] = "江湖";
	return quest;
}
int random_quest(object me,object ob)
{
	mapping quest;
	string owner_name,obname;

	if(mapp(quest = me->query_temp("quest"))){
		if(quest["quest_type"] == "找" && quest["from"] == "江湖"){
			message_vision("$N说道：如果你能够帮"+ quest["owner_name"] +"找到"
			+ quest["quest"]+"的话，应该会有所收获。\n",ob,me);
			return 1;
		}
		else {
			message_vision("$N无奈的说道：唉，象我们这种人，每天都是起早贪黑，养家糊口。\n"
			"要知道江湖上的消息，只能多向一些过往的客官打听了。\n",ob);
			return 1;
		}
	}
	
	quest = create_quest();
	me->set_temp("quest",quest);
	message("vision",ob->name() +"凑在"+ me->name() +"的耳边悄悄的说了一些话。\n",environment(me),me);

	obname = (string)me->query_temp("quest/quest");
	owner_name = (string)me->query_temp("quest/owner_name");

	switch(random(7)){
		case 1:
		case 2:
			tell_object(me,sprintf("%s说道：我听说，江湖上大名鼎鼎的%s，最近不知道是何缘故，\n"
			"明查暗访，四处找寻%s的下落。江湖上的人都说，这当中一定有很大的秘密。\n",
			ob->name(),owner_name,obname));
			break;
		case 3:
			tell_object(me,sprintf("%s神秘的说道：%s的事情你听说了吗？据说最近正急着在寻找%s的下落。\n"
			"%s你要是见过，还得赶紧给送去，听说报酬可是不少啊。\n",
			ob->name(),owner_name,obname,RANK_D->query_respect(me)));
			break;
		case 4:
			tell_object(me,sprintf("%s神秘兮兮的说：嘿，最近江湖上，可数%s的事最轰动了。\n"
			"听说他为了得到%s，悬赏江湖中人，承诺寻其者必定重金酬谢。\n"
			"%s若是知道%s的下落，还得趁早给送去呀。\n",
			ob->name(),owner_name,obname,RANK_D->query_respect(me),obname));
			break;
		default:
			tell_object(me,sprintf("%s摇摇头道：最近没听说有什么大事，要是%s有什么消息，还请告诉%s一声呀！\n",
			ob->name(),RANK_D->query_respect(me),RANK_D->query_self(ob)));
			break;
	}
	return 1;		
	
}
		
void do_bonus(object me)
{
	mapping quest;
	int exp,pot,score,weiwang;
	
	if(mapp(quest = me->query_temp("quest/quest"))){
		if(intp(exp = quest["exp_bonus"])) me->add("combat_exp",exp);
		if(intp(pot = quest["pot_bonus"])) me->add("potential",pot);
		if(intp(score = quest["score"])) me->add("score",score);
		if(intp(weiwang = quest["weiwang"])) me->add("weiwang",weiwang);
	
		tell_object(me,sprintf(	"你的经验提高了%s点。\n"
					"你的潜能提高了%s点。\n"
					"你的江湖阅历提高了%s点。\n"
					"你的江湖威望提高了%s点。\n",
					chinese_number(exp),
					chinese_number(pot),
					chinese_number("score"),
					chinese_number(weiwang)));
		return;
	}
}