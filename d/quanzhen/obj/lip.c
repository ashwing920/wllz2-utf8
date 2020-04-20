// lip.c 炼丹炉

#include <ansi.h>

inherit ITEM;

string *liandan_msg =({
        YEL"丹转一，冥冥海底升红日，祥云烟霭遍三千，种出玄珠如黍粒。\n"NOR,
        BLU"丹转二，炎炎朱雀烧天地，霞光入鼎虎龙蟠，一粒黄芽如大齿。\n"NOR,
        MAG"丹转三，三才混象结成丹，形容斫块随人意，天质人生已造端。\n"NOR,
        WHT"丹转四，蓬壶灵户常关闭，静中暗转法长轮，无限灵光照真宇。\n"NOR,
        CYN"丹转五，灵真耀日修仙所，重重道气添光明，为吾增长神明主。\n"NOR,
        HIY"丹转六，昼夜河车驰圣轴，灵泉直上昆仑顶，一轴明月瑶池浴。\n"NOR,
        HIB"丹转七，无为光里藏灵质，四时道气真官形，千神降福来神室。\n"NOR,
        HIM"丹转八，炼得丹心如满月，同行同望又同眠，虽在尘中人不识。\n"NOR,
        HIW"丹转九，圣功完满胎仙就，已证虚无自在身，此后不须行火候。\n"NOR,
});

void create()
{
        set_name("炼丹炉", ({ "lip", "danlu" }) );
        set_weight(3000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是全真教的道士用来炼丹药的炉子。\n");
                set("value", 1000);
                set("material", "wood");
                set("no_get",1);
                set("no_drop",1);
                set("amount",30);
        }
        setup();
}

void init()
{
        add_action("do_look","look");
        add_action("do_fangyao","fang");
        add_action("do_shenghuo","shenghuo");
        add_action("do_shanhuo","shanhuo");
        add_action("do_quyao","quyao");
}
int do_look(string arg)
{
        mapping inlip;
        string *base_name,msg;
        int i;

        if(!arg || !id(arg)) return 0;

        if(mapp(inlip = query("yao")) )
                base_name = keys(inlip);

        if(!sizeof(inlip))
                return notify_fail("这是全真教的道士用来炼丹药的炉子。里面什么也没有。\n");

        msg = "这是全真教的道士用来炼丹药的炉子。里面放着：\n";

        for(i = 0; i < sizeof(base_name); i++) {
                msg += sprintf("%s，分量：%d\n",base_name[i],inlip[base_name[i]]);
        }
        tell_object(this_player(),msg);
        return 1;
}

int do_fangyao(string arg)
{
        object me,ob;

        me = this_player();

        if(!arg || arg == "")
                return notify_fail("指令格式：fang <药材>\n");

        if(!objectp(ob = present(arg,me)))
                return notify_fail("你要放什么东西到炼丹炉里去？\n");

        if( !ob->is_yaocai())
                return notify_fail(ob->name()+"并不是药材呀！\n");

        if(query("danyao") > 5)
                return notify_fail("炼丹炉里的药材太多了。\n");

        message_vision("$N将$n放进炼丹炉里准备炼造丹药。\n",me,ob);
        add("yao/"+ ob->query("name"),1);
        destruct(ob);
        return 1;
}
int do_shenghuo(string arg)
{
        object me;

        me = this_player();
        
        if(!arg || !id(arg))
                return notify_fail("你要给什么升火？\n");
        
        if(!present("fire",me))
                return notify_fail("你身上没有火折子，怎么给炼丹炉升火？\n");

        if(!query("yao"))
                return notify_fail("炼丹炉里什么药也没有，你想把炉子烧坏呀？\n");

        if(query("light"))
                return notify_fail("炼丹炉已经点燃了。\n");
        
        message_vision("$N拿起火折子，将炼丹炉点燃，屋子里立刻一片通红。\n",me);
        set("light",1);
        return 1;
}
int do_shanhuo(string arg)
{
        object me;
        
        me = this_player();
        
        if(!arg || !id(arg))
                return notify_fail("你要给什么煽火？\n");
        
        if(!present("shan zi",me))
                return notify_fail("你没有扇子，怎么给炼丹炉煽火？\n");

        if(!query("light"))
                return notify_fail("炼丹炉还没有点燃，被你一煽，炉灰飞得你满脸都是。\n");

        if(me->query_temp("shanhuo"))
                return notify_fail("你还在煽火呢！\n");

        if(query("light_up"))
                return notify_fail("你想放火呀？炼丹炉里的火候已经够旺的了。\n");
        
        set("light_up",1);      
        message_vision("$N拿着扇子，缓缓的在炼丹炉旁煽火，一边念着口诀。炼丹炉的火势逐渐变大了。\n",me);
        me->set_temp("shanhuo",1);
        call_out("wait_for_finish",2,me,0);
        return 1;
}
void wait_for_finish(object me,int stage)
{
        object obj;
        mapping inlip;
        string *base_name;
        int skill,i;
        skill = (int)me->query_skill("liandanshu",1);

        if(mapp(inlip = query("yao")) ) base_name = keys(inlip);
                for(i = 0; i < sizeof(base_name); i++)

        if( !me || !present(me) ) return;
 
        message_vision("$N念道："+ liandan_msg[stage],me);
        if( ++stage < sizeof(liandan_msg) ) {
                call_out("wait_for_finish", 5,me,stage);
                return;
        } else

                tell_object(me,"时间差不多了，炼丹炉里的丹药也应该炼好了。\n");
                me->delete_temp("shanhuo");
        

                if(skill < 50){
                        message_vision("$N打开炼丹炉一看，炼丹炉里的药材全部烧成了焦碳。\n",me);
                }
                else if(base_name[i] == HIG"甘草"NOR && inlip[base_name[i]] > 3){
                        obj = new("/d/quanzhen/obj/gancaodan");
                        message_vision("$N打开炼丹炉一看，炼丹炉炼成了一颗$n。\n",me,obj);
                        obj->move(me);
                }
                else if(base_name[i] == HIG"越橘草"NOR && inlip[base_name[i]] > 2){
                        obj = new("/d/quanzhen/obj/jingqiwan");
                        message_vision("$N打开炼丹炉一看，炼丹炉炼成了一颗$n。\n",me,obj);
                        obj->move(me);
                }
                else if(base_name[i] == HIG"越橘草"NOR && inlip[base_name[i]] > 2
                        && base_name[i] == HIG"甘草"NOR && inlip[base_name[i]] > 2){
                        obj = new("/d/quanzhen/obj/huanshendan");
                        message_vision("$N打开炼丹炉一看，炼丹炉炼成了一颗$n。\n",me,obj);
                        obj->move(me);
                }
                else {
                        message_vision("$N打开炼丹炉一看，炼丹炉空空如夜，什么也没炼成。\n",me);
                }

        delete("yao");
        delete("light");
        delete("light_up");

}
