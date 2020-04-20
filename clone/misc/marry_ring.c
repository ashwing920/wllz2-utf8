// marry_ring.c - 结婚戒指

#include <ansi.h>
#include <armor.h>

inherit FINGER;

int do_coupletalk(string arg, int emote);

void create()
{
        set_name( HIY "结婚戒指" NOR, ({"marry ring", "ring"}) );
        set_weight(400);
        set("no_get", 1);
        set("no_put", 1 );
        set("no_get_from",1);
        set( "no_drop", "你的结婚戒指不能丢弃，只能去红娘庄解除婚约。\n");
        set( "long", @LONG
这是一枚结婚戒指。你可以使用以下命令：

coupletalk ( ct )       和伴侣对话。
couple                  收听伴侣的信息。

支持命令：ct, ct*



LONG
        );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("material", "gold");
                set("armor_type", "finger");
                set("armor_prop/armor", 10);
                set("armor_prop/defense", 10);
                set("wear_msg", "$N将$n拿出来小心地戴在手指上。\n");
                set("unequip_msg", "$N将$n小心地从手指上摘下来放好。\n");
        }
}

string couplename( object ob ) {
        if( ob ) {
                if( (string)ob->query("gender") == "女性" ) return "夫人" + ob->name(1);
                if( (string)ob->query("gender") == "男性" ) return "丈夫" + ob->name(1);
                return "旧伴侣" + ob->name(1);
        }
}

void init()
{
        object me, couple_ob;

        me = this_player();
        if( me->query("marry") ) {
                couple_ob = find_player(me->query("marry"));
                if(couple_ob && environment(couple_ob) ){
                        if ( couple_ob->query("marry")!=me->query("id") ){
                        tell_object(me,HIY "你的伴侣已经重新投胎了,如果有缘...\n"+NOR);
                        me->delete("marry_name");
                        me->delete("marry");
                        destruct(this_object());
                        return;
                }
                if( couple_ob->query("name") != me->query("marry_name")
                || me->query("marry_name") != couple_ob->query("name")){
                        me->set("marry_name",couple_ob->query("name"));
                        couple_ob->set("marry_name",me->query("name"));
                        return;
                }
                if( !me->query_temp("marry_logo")) {
                        write( HIM"\n你的" + couplename( couple_ob ) + "也在这里，快去找啦....\n\n" NOR);
                        tell_object(couple_ob , sprintf(HIM"\n你的%s来啦，快去接啦....\n\n" NOR, couplename( me ) ));
                        me->set_temp("marry_logo",1);
                        }
                }
                set("name",HIY + me->query("name") +"和" + me->query("marry_name") +"的结婚戒指"NOR);
        }

        add_action("do_coupletalk_0", "ct");
        add_action("do_coupletalk_1", "ct*");
        add_action("do_snoop_couple","couple");
}

int do_coupletalk_0(string arg) { return do_coupletalk( arg, 0 ); }
int do_coupletalk_1(string arg) { return do_coupletalk( arg, 1 ); }
int do_coupletalk(string arg, int emote)
{
        object me, couple_ob;

        me = this_player();

        if(me->ban_say()) return 0;
        if ( !stringp(me->query("marry")) )
                return notify_fail("你没有伴侣。\n");

        couple_ob = find_player( me->query("marry") );
        if( !couple_ob )
                return  notify_fail("你的伴侣现在无法听见你，或者已经离开游戏了。\n");

        if ((string)couple_ob->query("gender") == "无性")
                return  notify_fail("你原来的伴侣已经做了太监，你还是把他忘了吧。\n");

        if ( !arg ) {
                write(HIM"你又深情地想念你的爱侣了。\n" NOR);
                tell_room(environment(me), CYN + (string)me->name() + "又在深情地想念自己的爱侣"
                        + (string)couple_ob->name() + "了。\n" + NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(HIM "%s又在深情地想念你了。\n"NOR, couplename( me ) ) );

                return 1;
        }

        if (!stringp(arg) || arg == "" || arg == " ") arg = "...";

        // Support of channel emote
        if( emote ) {
                string vb, emote_arg;

                if( sscanf(arg, "%s %s", vb, emote_arg) != 2 ) {
                        vb = arg;
                        emote_arg = "";
                }
                //arg = EMOTE_D->do_emote(me,vb,emote_arg, 2);
                arg = EMOTE_D->do_emote(me,vb,emote_arg,1);

                // If out support of channel emote and still send this message
                if (!arg && emote == 2)
                        arg = me->name() + vb + "\n";

                // If not Support of channel emote ruturn
                if (! arg) return 0;

                //arg = replace_string( arg, me->name(), couplename( me ) );
		arg = CHANNEL_D->remove_addresses(arg,0);
                tell_object( me,HIM"【绵绵情话】" + replace_string(arg, couplename( me ),"你" ) + NOR );
                tell_object( couple_ob, HIM"【绵绵情话】" + arg + NOR );
        }
        else {
                write(sprintf(WHT"『情话』"HIM"你对%s说：%s\n" NOR, couplename( couple_ob ), arg ));
                tell_object(couple_ob, sprintf(WHT"『情话』"HIM"%s对你说：%s\n" NOR, couplename( me ), arg ));
        }

        return 1;
}
int do_snoop_couple(string arg)
{
        object me,ob;
        me = this_player();

        if(me->ban_say()) return 0;
        if( !arg ) {
                if( objectp(ob = query_snooping(me)) )
                        write("你现在正在收听" + ob->query("name") + "所收到的讯息。\n");
                return 1;
        } else if( arg=="none"){
                snoop(me);
                write("你终止了收听信息。\n");
                return 1;
        }

        ob = find_player(arg);
        if(!ob) ob = find_living(arg);
        if(!ob || !me->visible(ob) || wizardp(ob))
                return notify_fail("没有这个人。\n");

        if( ob->query("id") != me->query("marry"))
                return notify_fail("你只能收听你的伴侣所收到的信息。\n");

        if( ob->query_temp("netdead"))
                return notify_fail(ob->name()+"当前正属于断线状态，你无法收听信息。\n");

        if( me==ob )
                return notify_fail("难道你是瞎子？看不到你自己的信息请和巫师联系。\n");

        snoop(me, ob);
        write(HIM"你现在开始收听" + couplename(ob) + "所收到的讯息。\n"NOR);
        tell_object(ob,HIM + couplename(me)+"开始收听你的信息。\n"NOR);
        return 1;
}
void owner_is_killed() { destruct(this_object()); }
