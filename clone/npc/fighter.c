// man.c

#include <ansi.h>
inherit NPC;
string *family_name = ({
        "古墓新派",
        "云龙门",
        "逍遥派",
        "武当派",
        "华山剑派",
        "灵鹫宫",
        "少林派",
        "雪山派",
        "丐帮",
        "血刀门",
        "星宿派",
        "五毒神教",
        "昆仑派",
        "唐门",
        "神龙教",
        "明教",
        "峨嵋剑派",
});
void make_skill();
void checking(object ob);
void create()
{
        string family;
        int n;
        n = random(sizeof(family_name));
        family = family_name[n];
        set("family/family_name",family);
        set_name(npc_name("男性"), ({ "fighter","hero" }) );
        set("title","关外挑战者");
        set("long","他是从关外远道而来的挑战者。\n");
        set("attitude", "heroism");
        set("age", random(20) + 20);
        set("gender","男性");

        set("chat_chance_combat",120);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "regenerate" :),
        }));

        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali",40);

        set_skill("force", random(40) + 10 );
        set_skill("unarmed", random(40) + 10 );
        set_skill("parry", random(40) + 10 );
        set_skill("dodge", random(40) + 10 );
        set("combat_exp", random(4000) + 1000);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("gold", 10);

}
void init()
{
        object ob;
        if( interactive(ob = this_player()) && !is_fighting() ) {
                checking(ob);
                call_out("back_home",120,ob);
        }
        if(living(this_object()))
        add_action("do_halt","halt");
}
void make_skill()
{
        int i, n, m;
        object *ob, me;

        ob = users();
        me = this_object();

        if(sizeof(ob) == 0) return;
        n = 0;
        m = ob[0]->query("combat_exp");
        i = sizeof(ob);
        while(i--)
                if( !ob[i])continue;
                else if( m < ob[i]->query("combat_exp") ) {
                        n = i;
                        m = ob[i]->query("combat_exp");
                }
        m = n;
        n = ob[m]->query("combat_exp");
        if( n <= 0 ) n = random(50000) + 1;
        set("combat_exp", n);
        NPC_D->full_init(this_object());
}
void checking(object ob)
{
        object me;
        me = this_object();

        if(interactive(ob) && !is_fighting()) {
                command("say 在下"+ me->name()+"，今日特前来挑战，出招吧！");
                command("fight " + ob->query("id"));
                make_skill();
        }
        return;
}
void back_home(object ob)
{
        ob = this_object();

        if( ob->is_fighting()) {
              call_out("back_home",30,ob);
              return;
        }
        if( living(ob))
        CHANNEL_D->do_channel(ob,"chat",sprintf("哈哈，堂堂中原武林，居然无人应战，原来也是一帮无能鼠辈！"));
        destruct(ob);
}
int accept_fight(object ob)
{
        object me;
        string where, family;
        me = this_object();
        ob = this_player();
        where = environment(ob)->query("short");
        family = ob->query("family/family_name");
        if(!family) {
                command("say 就你这点皮毛？我可不想人家说我大欺小。");
                return 0;
        }
        if(me->is_fighting()){
                command("say 以少胜多？算什么英雄好汉啊？");
                return 0;
        }
        message("channel:chat",HIW"【武林宗师】"NOR + sprintf(WHT"听说%s的%s[%s]挺身而出，应约赴战，在%s与%s展开激战！\n"NOR,
                family,ob->name(),capitalize(ob->query("id")),where,me->name()),users());
        message("channel:chat",HIW"【武林宗师】"NOR + sprintf(WHT"%s一抱拳：在下%s，特来领教这位壮士高招！出手吧！\n"NOR,
                ob->name(),ob->name()),users());
        remove_call_out("check_status");
        call_out("check_status",1,me);
        return 1;
}
void check_status(object ob)
{
        object me;
        int me_max_qi,ob_max_qi;
        me =this_object();
        ob = this_player();
        me_max_qi = (int)me->query("max_qi");
        ob_max_qi = (int)ob->query("max_qi");

        if(me->is_fighting()) {
                remove_call_out("check_status");
                call_out("check_status",1,me);
        }
        if( !present(me, environment()) ) return;
        if(((int)me->query("qi") * 100 / me_max_qi) <= 50){
                message("channel:chat",HIW"【武林宗师】"NOR + sprintf(WHT"%s败在了%s的%s掌下了。\n"NOR,me->name(),ob->query("family/family_name"),ob->name()),users());
                message("channel:chat",HIW"【武林宗师】"NOR + WHT + me->query("name") +"：中原武学果然名不虚传！今日一战，令在下受益非浅！佩服！佩服！\n"NOR,users());
                message("channel:chat",HIW"【武林宗师】"NOR + sprintf(WHT"%s[%s]打败了%s[%s]，受到了武林盟主的嘉奖。\n"NOR,ob->name(),capitalize(ob->query("id")),me->name(),capitalize(me->query("id"))),users());
                tell_object(ob,"\n你打败了"+ me->name() +"，为中原武林扬眉吐气了！\n你的经验增加了五百点，潜能增加了一千点。\n");
                tell_object(ob,"你的江湖阅历增加了五十点，你的威望提高了五点。\n");
                ob->add("combat_exp",500);
                ob->add("potential",1000);
                ob->add("score",50);
                ob->add("weiwang",5);
                destruct(me);
        }
        else if(((int)ob->query("qi") * 100 / ob_max_qi) < 50) {
                message("channel:chat",HIW"【武林宗师】"NOR + sprintf(WHT"%s[%s]身受重伤，败下阵来！！\n"NOR,ob->name(),capitalize(ob->query("id"))),users());
                message("channel:chat",HIW"【武林宗师】"NOR + WHT + me->query("name") +"：哈哈，原来中原武艺也不过如此，竟是些无能鼠辈！\n"NOR,users());
                destruct(me);
        }

}
int do_halt(string arg)
{
        object ob,me;
        me = this_player();
        ob = this_object();
        if( ob->is_fighting(me) && me->is_fighting(ob)){
        message("channel:chat",HIW"【武林宗师】"NOR + sprintf(WHT"%s向%s跪地求饶，败下阵来，令中原武林蒙羞！！\n"NOR,me->name(),name()),users());
        message("channel:chat",HIW"【武林宗师】"NOR + WHT + name() +"：哼哼～～原来中原武艺也不过如此，竟是些无能鼠辈！\n"NOR,users());
        destruct(ob);
        }
}
