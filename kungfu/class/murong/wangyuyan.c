// master-mu.c 

#include <ansi.h>
inherit NPC;
string ask_book();

void create()
{
        set_name("王语嫣", ({ "wang yuyan", "wang","yuyan" }));
        set("long",@LONG
她是曼陀山庄王夫人的千金王语嫣，也是慕容复的表妹。亭亭玉立，眉清
目秀，虽然不识武功，但却饱读诗书，对一些武功的招式颇有心得。
LONG
);

        set("nickname",HIM"神仙姐姐"NOR);
        set("rank_info/respect", "姑娘");
        set("gender", "女性" );
        set("age", 20);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 35);
        set("kar", 30);

	set("jing",1000);
	set("max_jing",1000);
        set("jing",1000);
        set("max_neili",1500);
        set("neili",1500);
        set("jiali",75);

        set("inquiry",([
                "武籍": (: ask_book :),
                "秘籍": (: ask_book :),
                "慕容复": "慕容复是我表哥，从小与我一起长大，对我可好了。",
                "段誉": "段公子为人心地善良，文质彬彬，是个好人。",
        ]));

        set("book_give",1);
        set("shen_type",1);
        set("combat_exp",100000);

        set_skill("force",    100);     
        set_skill("sword",    100);     
        set_skill("unarmed",  100);     
        set_skill("parry",    100);
        set_skill("dodge",    100);
        set_skill("literate", 500);
        
        setup();
       
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/misc/shoe")->wear();
        add_money("silver",20);
}
string ask_book()
{
        object me,obj;
        me = this_player();
        
        if((string)me->query("family/family_name") != "慕容世家"){
                return "这位"+ RANK_D->query_close(me) +"与慕容世家毫无关联，何来武籍呢？";
        }
        if((int)me->query_temp("get_book")) {
                return "这位"+ RANK_D->query_close(me) +"刚才不是已经拿过了吗？";
        }
        if( !query("book_give")){
                return "这位"+ RANK_D->query_close(me) +"来晚了，武籍都被人拿光了。";
        }
        
        switch(random(5)){
                case 0:
                        obj=new("/d/yanziwu/obj/force_book");
                        obj->move(me);
                        break;
                case 1:
                        obj=new("/d/yanziwu/obj/sword_book");
                        obj->move(me);
                        break;
                case 2:
                        obj=new("/d/yanziwu/obj/dodge_book");
                        obj->move(me);
                        break;
                case 3:
                        obj=new("/d/yanziwu/obj/parry_book");
                        obj->move(me);
                        break;
                case 4:
                        obj=new("/d/yanziwu/obj/unarmed_book");
                        obj->move(me);
                        break;
        }
        add("book_give",-1);
        me->set_temp("get_book",1);
        return "这本武籍你拿去看看，或许对你的武功造诣有些帮助。";
}
